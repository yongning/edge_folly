#pragma once

#include <unistd.h>

namespace folly {
namespace netops {
namespace detail {
struct SocketFileDescriptorMap {
    static int close(int fd) noexcept { return ::close(fd); }
    static int fdToSocket(int fd) noexcept { return fd; }
    static int socketToFd(int sock) noexcept { return sock; }
};
}
}
}
