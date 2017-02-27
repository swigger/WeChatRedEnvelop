#include "xpruntime.h"
#include <unistd.h>
#include <assert.h>
#include <sys/sysctl.h>
#include <mach/clock.h>
#include <mach/clock_types.h>
#include <mach/mach_host.h>
#include <mach/mach.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdlib.h>

static int get_clock_ref()
{
    clock_serv_t clock_ref = 0;
    host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &clock_ref);
    return clock_ref;
}

static int darwin_clock_gettime_MONOTONIC(struct timespec *tp)
{
    static int clockinit = 0;
    static clock_serv_t clock_ref = 0;
    mach_timespec_t mach_tp = {0};
    
    if (clockinit == 0)
    {
        clockinit = 1;
        clock_ref = get_clock_ref();
    }
    
    kern_return_t ret = clock_get_time(clock_ref, &mach_tp);
    if (ret != KERN_SUCCESS) return -1;
    
    tp->tv_sec = mach_tp.tv_sec;
    tp->tv_nsec = mach_tp.tv_nsec;
    return 0;
}

int64_t GetTickCount64b()
{
    struct timespec ts = {0};
    int r = darwin_clock_gettime_MONOTONIC(&ts);
    if (r<0) return 1;
    int64_t a = (int64_t)ts.tv_sec * 1000 + ts.tv_nsec/1000000;
    return a;
}

