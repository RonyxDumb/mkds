/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PXI_SendWordByFifo Fifo_SendWord
#define RtcSendPxiCommand Rtc_SendFifoWord
#include "PXI_fifo.h"
#include "RTC_internal.h"
#include "code32.h"

BOOL RtcSendPxiCommand(u8 command)
{
    s32 data = command << 8 & 0x7f00;
    return PXI_SendWordByFifo(PXI_FIFO_TAG_RTC, (u32)data, FALSE) >= 0;
}
