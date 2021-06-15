#pragma once

#include <folly/net/NetOps.h>

// #include <folly/Portability.h>

namespace folly {
namespace portability {
namespace sockets {
using ::accept;
using ::bind;
using ::connect;
using ::getpeername;
using ::getsockname;
using ::getsockopt;
using ::inet_ntop;
using ::listen;
using ::poll;
using ::recv;
using ::recvfrom;
using ::send;
using ::sendmsg;
using ::sendto;
using ::setsockopt;
using ::shutdown;
using ::socket;
}
}
}
