/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define RtcSendPxiCommand SDK_data_0214e17c
#define RTCi_ReadRawTimeAsync Rtc_ReadRawTimeAsync
#include "PXI_fifo.h"
#include "RTC_internal.h"
#include "code32.h"
extern BOOL RtcSendPxiCommand(u8 command);
BOOL RTCi_ReadRawTimeAsync(void)
{
    return RtcSendPxiCommand(18);
}
