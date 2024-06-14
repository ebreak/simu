#ifndef __MOC_SEMAPHORE_H
#define __MOC_SEMAPHORE_H

#include <mutex>
#include <queue>
#include "log.h"

namespace moc {

template <int _cap>
struct semaphore{
  int cap, val;
  std::queue<std::mutex*> wait;
  std::mutex vlock, wlock;

  semaphore(): cap(_cap), val(0) {}
  semaphore(int _val): cap(_cap), val(_val) {}

  void acquire() {
    std::mutex *local = nullptr;
    vlock.lock();
    wlock.lock();
    if (val < 0)
      moc::panic("internal bug: semaphore val < 0");
    if (val) {
      if (wait.size()) {
        wait.front()->unlock();
        wait.pop();
      } else val -= 1;
    } else {
      local = new std::mutex;
      local->lock();
      wait.push(local);
    }
    wlock.unlock();
    vlock.unlock();
    if (local == nullptr) return;
    local->lock();
    delete local;
  }

  void release() {
    std::mutex *local = nullptr;
    vlock.lock();
    wlock.lock();
    if (val > cap)
      moc::panic("internal bug: semaphore val > cap");
    if (val < cap) {
      if (wait.size()) {
        wait.front()->unlock();
        wait.pop();
      } else val += 1;
    } else {
      local = new std::mutex;
      local->lock();
      wait.push(local);
    }
    wlock.unlock();
    vlock.unlock();
    if (local == nullptr) return;
    local->lock();
    delete local;
  }
};

};

#endif