/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RtcSendPxiCommand SDK_data_0214e17c
#define RTCi_WriteRawStatus2Async Rtc_WriteRawStatus2Async
#include "PXI_fifo.h"
#include "RTC_internal.h"
#include "code32.h"
extern BOOL RtcSendPxiCommand(u8 command);
BOOL RTCi_WriteRawStatus2Async(void)
{
    return RtcSendPxiCommand(39);
}
