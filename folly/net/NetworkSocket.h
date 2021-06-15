#pragma once

#include <iostream>

#include <folly/net/detail/SocketFileDescriptorMap.h>

namespace folly {

struct NetworkSocket {
    using native_handle_type = int;
    static constexpr native_handle_type invalid_handle_value = -1;
    
    native_handle_type data;

    constexpr NetworkSocket() : data(invalid_handle_value) {}
    constexpr explicit NetworkSocket(native_handle_value d) : data(d) {}

    template <typename T>
    static NetworkSocket fromFd(T) = delete;
    static NetworkSocket fromFd(int fd) {
        return NetworkSocket(
            netops::detail::SocketFileDescriptorMap::fdToSocket(fd));
    }

    int toFd() const {
        return netops::detail::SocketFileDescriptorMap::socketToFd(data);
    }

    friend constexpr bool operator==(
        const NetworkSocket& a, const NetworkSocket& b) noexcept {
        return a.data == b.data;
    }

    friend constexpr bool operator!=(
        const NetworkSocket& a, const NetworkSocket& b) noexcept {
        return !(a == b);
    }
};

template <class CharT, class Traits>
inline std::basic_ostream<CharT, Traits>& operator<<(
    std::basic_ostream<CharT, Traits>& os, const NetworkSocket& addr) {
    os << "folly::NetworkSocket(" << addr.data << ")";
    return os;
}
}

namespace std {
template <>
struct hash<folly::NetworkSocket> {
    size_t operator()(const folly::NetworkSocket& s) const noexcept {
        return std::hash<folly::NetworkSocket::native_handle_type>()(s.data);
    }
};
}
