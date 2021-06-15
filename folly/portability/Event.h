#pragma once

#include <event.h>
#include <folly/net/detail/SocketFileDescriptorMap.h>

namespace folly {
using libevent_fd_t = evutil_socket_t;
}

