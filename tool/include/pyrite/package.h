#ifndef _PRT_PACKAGE
#define _PRT_PACKAGE

#include "string"
#include <sys/types.h>
#ifdef Windows
#include <winsock2.h>
#include <windows.h>
typedef int socklen_t;
#define MSG_CONFIRM 0
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#endif

#include "mocutils/byte.h"

#include "define.h"

namespace prt {
typedef moc::bytes bytes;
class package {
 public:
  i32 sequence;
  std::string identifier;
  bytes body;

  package();
  package(bytes raw);
  package(package *old);
  package(i32 sequence, std::string identifier, bytes body);
  bytes to_bytes();
  bool operator==(const package& other);
  bool operator!=(const package& other);
  bool operator<(prt::package &other);

  void set_body(std::string text);
  std::string body_as_string();
  void send_to(int socket_fd, sockaddr_in socket_addr);
};

typedef struct {
  void *ptr;
  sockaddr_in addr;
  package pkg;
} process_args;
}  // namespace prt

#endif