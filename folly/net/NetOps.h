#pragma once

#include <cstdint>

#include <folly/net/NetworkSocket.h>

#include <netdb.h>
#include <poll.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <sys/un.h>

#ifdef MSG_ERRQUEUE
#define FOLLY_HAVE_MSG_ERRQUEUE 1
#ifndef FOLLY_HAVE_SO_TIMESTAMPING
#define FOLLY_HAVE_SO_TIMESTAMPING 1
#endif

#include <linux/errqueue.h>
#endif

#ifndef SO_EE_ORIGIN_ZEROCOPY
#define SO_EE_ORIGIN_ZEROCOPY 5
#endif

#ifndef SO_EE_CODE_ZEROCOPY_COPIED
#define SO_EE_CODE_ZEROCOPY_COPIED 1
#endif

#ifndef SO_ZEROCOPY
#define SO_ZEROCOPY 60
#endif

#ifndef SO_TXTIME
#define SO_TXTIME 61
#define SCM_TXTIME SO_TXTIME
#endif

#ifndef MSG_ZEROCOPY
#define MSG_ZEROCOPY 0x4000000
#endif

#ifndef SOL_UDP
#define SOL_UDP 17
#endif

#ifndef ETH_MAX_MTU
#define ETH_MAX_MTU 0xFFFFU
#endif

namespace folly {
namespace netops {
struct PollDescriptor {
    NetworkSocket fd;
    int16_t events;
    int16_t revents;
};

NetworkSocket accept(NetworkSocket s, sockaddr* addr, socklen_t* addrlen);
int bind(NetworkSocket s, const sockaddr* name, socklen_t namelen);
int close(NetworkSocket s);
int connect(
