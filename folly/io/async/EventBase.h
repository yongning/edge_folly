#pragma once

#include <atomic>
#include <cerrno>
#include <cmath>

class EventBase : public TimeoutManager,
                  public DrivableExecutor,
                  public IOExecutor,
                  public SequencedExecutor,
                  public ScheduledExecutor {
public:
    friend class ScopedEventBaseThread;

    using Func = folly::Function<void()>;

    
