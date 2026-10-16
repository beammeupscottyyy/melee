#include "lbtime.h"

u32 lbTime_8000AEC8(u32 a, u32 b)
{
    return -1 - a > b ? a + b : -1;
}

u32 lbTime_8000AEE4(u32 a, int b)
{
    if (b > 0) {
        return -1 - a > (unsigned) b ? a + b : -1;
    } else {
        return a > (unsigned) -b ? a + b : 0;
    }
}

u32 lbTime_8000AF24(u32 a, int b)
{
    int c;
    if (b > 0) {
        unsigned int ab = a & U16_MAX;
        c = U16_MAX;
        if (c - ab > (unsigned) b) {
            return a + b;
        } else {
            return c;
        }
    } else {
        c = a & U16_MAX;

        if (c > -b) {
            return a + b;
        } else {
            return 0;
        }
    }
}

u32 lbTime_8000AF74(u32 a, int b)
{
    if (b > 0) {
        u32 lo = a & U8_MAX;
        lo = U8_MAX - lo;
        return (lo > b) ? a + b : U8_MAX;
    }
    {
        int c = a & U8_MAX;
        return (c > -b) ? a + b : 0;
    }
}

u32 lbTime_GetTimeInSeconds(void)
{
    u64 secs = OSTicksToSeconds(OSGetTime());
    if (secs > U32_MAX) {
        secs = U32_MAX;
    }
    return secs;
}

void lbTime_8000B028(OSCalendarTime* td, unsigned int secs)
{
    OSTicksToCalendarTime(OSSecondsToTicks((u64) secs), td);
}
