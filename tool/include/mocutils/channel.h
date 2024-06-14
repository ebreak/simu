#ifndef __MOC_CHANNEL_H
#define __MOC_CHANNEL_H

#include <mutex>
#include <utility>
#include <queue>
#include <memory>
#include "./semaphore.h"

namespace moc {

template <typename T, int _cap = 0>
class channel {
public:
  int size, cap;
  channel(): size(0), cap(_cap) {}
  virtual void operator<<(T _value) = 0;
  virtual void operator>>(T &_value) = 0;
};

template <typename T>
class nbchannel: public channel<T> {
  std::queue<std::pair<std::mutex*, T>*> read, write;
  std::mutex clock;
 public:
  nbchannel(): channel<T>() {}
  void operator<<(T _value);
  void operator>>(T &_value);
};

// write
template <typename T>
void nbchannel<T>::operator<<(T _value) {
  std::pair<std::mutex*, T> *local = nullptr;
  clock.lock();
  if (read.size()) {
    read.front()->second = _value;
    read.front()->first->unlock();
    read.pop();
  } else {
    local = new std::pair<std::mutex*, T>{new std::mutex, _value};
    local->first->lock();
    write.push(local);
  }
  clock.unlock();
  if (local == nullptr) return;
  local->first->lock();
  delete local->first;
  delete local;
}

// read
template <typename T>
void nbchannel<T>::operator>>(T &_value) {
  std::pair<std::mutex*, T> *local = nullptr;
  clock.lock();
  if (write.size()) {
    _value = write.front()->second;
    write.front()->first->unlock();
    write.pop();
  } else {
    local = new std::pair<std::mutex*, T>{new std::mutex, _value};
    local->first->lock();
    read.push(local);
  }
  clock.unlock();
  if (local == nullptr) return;
  local->first->lock();
  _value = local->second;
  delete local->first;
  delete local;
}

template<typename T, int _cap>
class bchannel: public channel<T, _cap> {
  std::queue<T> content;
  std::mutex clock;
  semaphore<_cap> full, empty;
public:
  bchannel(): channel<T, _cap>(), empty(semaphore<_cap>(_cap)) {}
  void operator<<(T _value);
  void operator>>(T &_value);
};

// write
template<typename T, int _cap>
void bchannel<T, _cap>::operator<<(T _value) {
  empty.acquire();
  clock.lock();
  this->size += 1;
  content.push(_value);
  clock.unlock();
  full.release();
}

// read
template<typename T, int _cap>
void bchannel<T, _cap>::operator>>(T &_value) {
  full.acquire();
  clock.lock();
  this->size -= 1;
  _value = content.front();
  content.pop();
  clock.unlock();
  empty.release();
}

template <typename T>
nbchannel<T> make_channel() {
  return nbchannel<T>();
}

template <typename T, int _cap>
bchannel<T, _cap> make_channel() {
  return bchannel<T, _cap>();
}

template <typename T>
nbchannel<T>* makeptr_channel() {
  return new nbchannel<T>;
}

template <typename T, int _cap>
bchannel<T, _cap>* makeptr_channel() {
  return new bchannel<T, _cap>;
}

#include "./macro.h"

};  // namespace moc

#endif