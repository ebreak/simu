#ifndef _PRT_CLIENT_H
#define _PRT_CLIENT_H

#include "functional"
#include "map"

#include <mocutils/channel.h>

#include "define.h"
#include "package.h"

namespace prt {
class client {
  int         server_fd;
  sockaddr_in server_addr;
  std::map<std::string, std::function<bytes(bytes)>> router;
  int sequence;
  std::map<int, moc::channel<prt::package>*> promise_buf;
 public:
  connection_state state;
  client(const char* ip, int port);
  ~client();
  void start();
  void async();
  bool set_handler(std::string identifier, std::function<bytes(bytes)> handler);
  static void *process(void *_args);
  void tell(std::string identifier, bytes body);
  bytes promise(std::string identifer, bytes body);
};
}  // namespace prt

#endif