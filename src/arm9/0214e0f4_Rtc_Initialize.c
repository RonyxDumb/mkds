#define PXI_Init func_0214d5b8
#define PXI_IsCallbackReady Fifo_IsHandlerReady
#define PXI_SetFifoRecvCallback Fifo_RegisterHandler
#define RTC_Init Rtc_Initialize
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#include <nitro/os.h>
#include <nitro/rtc.h>

typedef enum RTCLock {
    RTC_LOCK_OFF = 0,
    RTC_LOCK_ON,
    RTC_LOCK_MAX
} RTCLock;

typedef enum RTCSequence {
    RTC_SEQ_GET_DATE = 0,
    RTC_SEQ_GET_TIME,
    RTC_SEQ_GET_DATETIME,
    RTC_SEQ_SET_DATE,
    RTC_SEQ_SET_TIME,
    RTC_SEQ_SET_DATETIME,
    RTC_SEQ_GET_ALARM1_STATUS,
    RTC_SEQ_GET_ALARM2_STATUS,
    RTC_SEQ_GET_ALARM_PARAM,
    RTC_SEQ_SET_ALARM1_STATUS,
    RTC_SEQ_SET_ALARM2_STATUS,
    RTC_SEQ_SET_ALARM1_PARAM,
    RTC_SEQ_SET_ALARM2_PARAM,
    RTC_SEQ_SET_HOUR_FORMAT,
    RTC_SEQ_SET_REG_STATUS2,
    RTC_SEQ_SET_REG_ADJUST,
    RTC_SEQ_MAX
} RTCSequence;

typedef struct RTCWork {
    u32 lock;
    RTCCallback callback;
    void * buffer[2];
    void * callbackArg;
    u32 sequence;
    u32 index;
    RTCInterrupt interrupt;
    RTCResult commonResult;
} RTCWork;

static u16 SDK_data_021803ac;
static RTCWork SDK_data_021803b0;
static u16 rtcTickInitialized;
static OSTick rtcInitialTotalTicks;

static void SDK_data_0214d9e8(PXIFifoTag tag, u32 data, BOOL err);
static u32 RtcBCD2HEX(u32 bcd);
static u32 RtcHEX2BCD(u32 hex);
static BOOL RtcCheckAlarmParam(const RTCAlarmParam * param);
static RTCRawAlarm RtcMakeAlarmParam(const RTCAlarmParam * param);
static BOOL RtcCheckDate(const RTCDate * date, RTCRawDate * raw);
static BOOL RtcCheckTime(const RTCTime * time, RTCRawTime * raw);
static void RtcGetResultCallback(RTCResult result, void * arg);
static void RtcWaitBusy(void);
static RTCResult RtcTickInit(void);
static void RtcConvertTickToDateTimeEx(RTCDate * date, RTCTimeEx * time, OSTick tick);

void Rtc_Initialize (void)
{
    if (SDK_data_021803ac) {
        return;
    }

    SDK_data_021803ac = 1;

    SDK_data_021803b0.lock = RTC_LOCK_OFF;
    SDK_data_021803b0.callback = NULL;
    SDK_data_021803b0.interrupt = NULL;
    SDK_data_021803b0.buffer[0] = NULL;
    SDK_data_021803b0.buffer[1] = NULL;

    func_0214d5b8();
    while (!Fifo_IsHandlerReady(PXI_FIFO_TAG_RTC, PXI_PROC_ARM7)) {
    }

    Fifo_RegisterHandler(PXI_FIFO_TAG_RTC, SDK_data_0214d9e8);
}

RTCResult RTC_GetDateAsync (RTCDate * date, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_ASSERT(date != NULL);
    SDK_ASSERT(callback != NULL);

    enabled = OS_DisableInterrupts();

    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }

    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_GET_DATE;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.buffer[0] = (void *)date;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_ReadRawDateAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_GetDate (RTCDate * date)
{
    SDK_data_021803b0.commonResult = RTC_GetDateAsync(date, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult RTC_GetTimeAsync (RTCTime * time, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(time);
    SDK_NULL_ASSERT(callback);

    enabled = OS_DisableInterrupts();

    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }

    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_GET_TIME;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.buffer[0] = (void *)time;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_ReadRawTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_GetTime (RTCTime * time)
{
    SDK_data_021803b0.commonResult = RTC_GetTimeAsync(time, RtcGetResultCallback, NULL);

    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }

    return SDK_data_021803b0.commonResult;
}

RTCResult RTC_GetDateTimeAsync (RTCDate * date, RTCTime * time, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(date);
    SDK_NULL_ASSERT(time);
    SDK_NULL_ASSERT(callback);

    enabled = OS_DisableInterrupts();

    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }

    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_GET_DATETIME;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.buffer[0] = (void *)date;
    SDK_data_021803b0.buffer[1] = (void *)time;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_ReadRawDateTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_GetDateTime (RTCDate * date, RTCTime * time)
{
    SDK_data_021803b0.commonResult = RTC_GetDateTimeAsync(date, time, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult RTC_GetDateTimeExByTick (RTCDate * date, RTCTimeEx * time)
{
    RTCResult result;
    OSTick totalTicks;

    if(!rtcTickInitialized) {
        result = RtcTickInit();
    } else {
        result = RTC_RESULT_SUCCESS;
    }

    SDK_ASSERT(OS_IsTickAvailable());

    totalTicks = OS_GetTick() + rtcInitialTotalTicks;

    RtcConvertTickToDateTimeEx(date, time, totalTicks);

    return result;
}

RTCResult RTC_SetDateAsync (const RTCDate * date, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(date);
    SDK_NULL_ASSERT(callback);

    if (!RtcCheckDate(date, &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.date))) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_SET_DATE;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_WriteRawDateAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_SetDate (const RTCDate * date)
{
    SDK_data_021803b0.commonResult = RTC_SetDateAsync(date, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult RTC_SetTimeAsync (const RTCTime * time, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(time);
    SDK_NULL_ASSERT(callback);

    if (!RtcCheckTime(time, &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.time))) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_SET_TIME;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_WriteRawTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_SetTime (const RTCTime * time)
{
    SDK_data_021803b0.commonResult = RTC_SetTimeAsync(time, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult
RTC_SetDateTimeAsync (const RTCDate * date, const RTCTime * time, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(date);
    SDK_NULL_ASSERT(time);
    SDK_NULL_ASSERT(callback);

    if (!RtcCheckDate(date, &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.date))) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    if (!RtcCheckTime(time, &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.time))) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_SET_DATETIME;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_WriteRawDateTimeAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_SetDateTime (const RTCDate * date, const RTCTime * time)
{
    SDK_data_021803b0.commonResult = RTC_SetDateTimeAsync(date, time, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult RTCi_SetRegStatus2Async (const RTCRawStatus2 * status2, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(status2);
    SDK_NULL_ASSERT(callback);

    ((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.status2.intr_mode = status2->intr_mode;
    ((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.status2.intr2_mode = status2->intr2_mode;
    ((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.status2.test = status2->test;

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_SET_REG_STATUS2;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_WriteRawStatus2Async()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTCi_SetRegStatus2 (const RTCRawStatus2 * status2)
{
    SDK_data_021803b0.commonResult = RTCi_SetRegStatus2Async(status2, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult RTCi_SetRegAdjustAsync (const RTCRawAdjust * adjust, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(adjust);
    SDK_NULL_ASSERT(callback);

    ((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.adjust.adjust = adjust->adjust;

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_SET_REG_ADJUST;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_WriteRawAdjustAsync()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTCi_SetRegAdjust (const RTCRawAdjust * Adjust)
{
    SDK_data_021803b0.commonResult = RTCi_SetRegAdjustAsync(Adjust, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult RTC_GetAlarmStatusAsync (RTCAlarmChan chan, RTCAlarmStatus * status, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(status);
    SDK_NULL_ASSERT(callback);

    if (chan >= RTC_ALARM_CHAN_MAX) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    switch (chan) {
    case RTC_ALARM_CHAN_1:
        SDK_data_021803b0.sequence = RTC_SEQ_GET_ALARM1_STATUS;
        break;
    case RTC_ALARM_CHAN_2:
        SDK_data_021803b0.sequence = RTC_SEQ_GET_ALARM2_STATUS;
        break;
    }

    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.buffer[0] = (void *)status;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_ReadRawStatus2Async()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_GetAlarmStatus (RTCAlarmChan chan, RTCAlarmStatus * status)
{
    SDK_data_021803b0.commonResult = RTC_GetAlarmStatusAsync(chan, status, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult
RTC_GetAlarmParamAsync (RTCAlarmChan chan, RTCAlarmParam * param, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(param);
    SDK_NULL_ASSERT(callback);

    if (chan >= RTC_ALARM_CHAN_MAX) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.sequence = RTC_SEQ_GET_ALARM_PARAM;
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.buffer[0] = (void *)param;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (chan == RTC_ALARM_CHAN_1) {
        if (RTCi_ReadRawAlarm1Async()) {
            return RTC_RESULT_SUCCESS;
        } else {
            return RTC_RESULT_SEND_ERROR;
        }
    }

    if (RTCi_ReadRawAlarm2Async()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_GetAlarmParam (RTCAlarmChan chan, RTCAlarmParam * param)
{
    SDK_data_021803b0.commonResult = RTC_GetAlarmParamAsync(chan, param, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

void RTC_SetAlarmInterrupt (RTCInterrupt interrupt)
{
    SDK_data_021803b0.interrupt = interrupt;
}

RTCResult RTC_SetAlarmStatusAsync (RTCAlarmChan chan, const RTCAlarmStatus * status, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;

    SDK_NULL_ASSERT(status);
    SDK_NULL_ASSERT(callback);

    if (chan >= RTC_ALARM_CHAN_MAX) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    if (*status > RTC_ALARM_STATUS_ON) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    switch (chan) {
    case RTC_ALARM_CHAN_1:
        SDK_data_021803b0.sequence = RTC_SEQ_SET_ALARM1_STATUS;
        break;
    case RTC_ALARM_CHAN_2:
        SDK_data_021803b0.sequence = RTC_SEQ_SET_ALARM2_STATUS;
        break;
    }
    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.buffer[0] = (void *)status;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;

    if (RTCi_ReadRawStatus2Async()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

RTCResult RTC_SetAlarmStatus (RTCAlarmChan chan, const RTCAlarmStatus * status)
{
    SDK_data_021803b0.commonResult = RTC_SetAlarmStatusAsync(chan, status, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

RTCResult RTC_SetAlarmParamAsync (RTCAlarmChan chan, const RTCAlarmParam * param, RTCCallback callback, void * arg)
{
    OSIntrMode enabled;
    RTCRawAlarm * pAlarm = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.alarm);
    BOOL result = FALSE;

    SDK_NULL_ASSERT(param);
    SDK_NULL_ASSERT(callback);

    if (chan >= RTC_ALARM_CHAN_MAX) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    if (!RtcCheckAlarmParam(param)) {
        return RTC_RESULT_ILLEGAL_PARAMETER;
    }

    enabled = OS_DisableInterrupts();
    if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
        (void)OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    SDK_data_021803b0.lock = RTC_LOCK_ON;
    (void)OS_RestoreInterrupts(enabled);

    SDK_data_021803b0.index = 0;
    SDK_data_021803b0.callback = callback;
    SDK_data_021803b0.callbackArg = arg;
    ((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.alarm = RtcMakeAlarmParam(param);

    switch (chan) {
    case RTC_ALARM_CHAN_1:
        SDK_data_021803b0.sequence = RTC_SEQ_SET_ALARM1_PARAM;
        result = RTCi_WriteRawAlarm1Async();
        break;
    case RTC_ALARM_CHAN_2:
        SDK_data_021803b0.sequence = RTC_SEQ_SET_ALARM2_PARAM;
        result = RTCi_WriteRawAlarm2Async();
        break;
    }

    if (result) {
        return RTC_RESULT_SUCCESS;
    }

    return RTC_RESULT_SEND_ERROR;
}

RTCResult RTC_SetAlarmParam (RTCAlarmChan chan, const RTCAlarmParam * param)
{
    SDK_data_021803b0.commonResult = RTC_SetAlarmParamAsync(chan, param, RtcGetResultCallback, NULL);
    if (SDK_data_021803b0.commonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return SDK_data_021803b0.commonResult;
}

static void SDK_data_0214d9e8 (PXIFifoTag tag, u32 data, BOOL err)
{
#pragma unused(tag)

    RTCResult result;
    RTCPxiResult pxiresult;
    u8 command;
    RTCCallback cb;

    if (err) {
        if (SDK_data_021803b0.index) {
            SDK_data_021803b0.index = 0;
        }

        if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
            SDK_data_021803b0.lock = RTC_LOCK_OFF;
        }

        if (SDK_data_021803b0.callback) {
            cb = SDK_data_021803b0.callback;
            SDK_data_021803b0.callback = NULL;
            cb(RTC_RESULT_FATAL_ERROR, SDK_data_021803b0.callbackArg);
        }

        return;
    }

    command = (u8)((data & RTC_PXI_COMMAND_MASK) >> RTC_PXI_COMMAND_SHIFT);
    pxiresult = (RTCPxiResult)((data & RTC_PXI_RESULT_MASK) >> RTC_PXI_RESULT_SHIFT);

    if (command == RTC_PXI_COMMAND_INTERRUPT) {
        if (SDK_data_021803b0.interrupt) {
            SDK_data_021803b0.interrupt();
        }
        return;
    }

    if (pxiresult == RTC_PXI_RESULT_SUCCESS) {
        result = RTC_RESULT_SUCCESS;
        switch (SDK_data_021803b0.sequence) {

        case RTC_SEQ_GET_DATE:
        {
            RTCDate * pDst = (RTCDate *)(SDK_data_021803b0.buffer[0]);
            RTCRawDate * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.date);

            pDst->year = RtcBCD2HEX(pSrc->year);
            pDst->month = RtcBCD2HEX(pSrc->month);
            pDst->day = RtcBCD2HEX(pSrc->day);
            pDst->week = RTC_GetDayOfWeek(pDst);
        }
        break;
        case RTC_SEQ_GET_TIME:
        {
            RTCTime * pDst = (RTCTime *)(SDK_data_021803b0.buffer[0]);
            RTCRawTime * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.time);

            pDst->hour = RtcBCD2HEX(pSrc->hour);
            pDst->minute = RtcBCD2HEX(pSrc->minute);
            pDst->second = RtcBCD2HEX(pSrc->second);
        }
        break;
        case RTC_SEQ_GET_DATETIME:
        {
            RTCDate * pDst = (RTCDate *)(SDK_data_021803b0.buffer[0]);
            RTCRawDate * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.date);

            pDst->year = RtcBCD2HEX(*(u32 *)pSrc & 0x000000ff);
            pDst->month = RtcBCD2HEX(pSrc->month);
            pDst->day = RtcBCD2HEX(pSrc->day);
            pDst->week = RTC_GetDayOfWeek(pDst);
        }
            {
                RTCTime * pDst = (RTCTime *)(SDK_data_021803b0.buffer[1]);
                RTCRawTime * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->t.time);

                pDst->hour = RtcBCD2HEX(pSrc->hour);
                pDst->minute = RtcBCD2HEX(pSrc->minute);
                pDst->second = RtcBCD2HEX(pSrc->second);
            }
            break;

        case RTC_SEQ_SET_DATE:
        case RTC_SEQ_SET_TIME:
        case RTC_SEQ_SET_DATETIME:
            break;
        case RTC_SEQ_GET_ALARM1_STATUS:
        {
            RTCAlarmStatus * pDst = (RTCAlarmStatus *)(SDK_data_021803b0.buffer[0]);
            RTCRawStatus2 * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.status2);

            switch (pSrc->intr_mode) {
            case RTC_INTERRUPT_MODE_ALARM:
                *pDst = RTC_ALARM_STATUS_ON;
                break;
            default:
                *pDst = RTC_ALARM_STATUS_OFF;
            }
        }
        break;

        case RTC_SEQ_GET_ALARM2_STATUS:
        {
            RTCAlarmStatus * pDst = (RTCAlarmStatus *)(SDK_data_021803b0.buffer[0]);
            RTCRawStatus2 * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.status2);

            if (pSrc->intr2_mode) {
                *pDst = RTC_ALARM_STATUS_ON;
            } else {
                *pDst = RTC_ALARM_STATUS_OFF;
            }
        }
        break;

        case RTC_SEQ_GET_ALARM_PARAM:
        {
            RTCAlarmParam * pDst = (RTCAlarmParam *)(SDK_data_021803b0.buffer[0]);
            RTCRawAlarm * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.alarm);

            pDst->week = (RTCWeek)(pSrc->week);
            pDst->hour = RtcBCD2HEX(pSrc->hour);
            pDst->minute = RtcBCD2HEX(pSrc->minute);
            pDst->enable = RTC_ALARM_ENABLE_NONE;
            if (pSrc->we)
                pDst->enable += RTC_ALARM_ENABLE_WEEK;
            if (pSrc->he)
                pDst->enable += RTC_ALARM_ENABLE_HOUR;
            if (pSrc->me)
                pDst->enable += RTC_ALARM_ENABLE_MINUTE;
        }
        break;
        case RTC_SEQ_SET_ALARM1_STATUS:
            if (SDK_data_021803b0.index == 0) {
                RTCRawStatus2 * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.status2);

                if (*(RTCAlarmStatus *)(SDK_data_021803b0.buffer[0]) == RTC_ALARM_STATUS_ON) {
                    if (pSrc->intr_mode != RTC_INTERRUPT_MODE_ALARM) {
                        SDK_data_021803b0.index++;
                        pSrc->intr_mode = RTC_INTERRUPT_MODE_ALARM;
                        if (!RTCi_WriteRawStatus2Async()) {
                            SDK_data_021803b0.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {
                    if (pSrc->intr_mode != RTC_INTERRUPT_MODE_NONE) {
                        SDK_data_021803b0.index++;
                        pSrc->intr_mode = RTC_INTERRUPT_MODE_NONE;
                        if (!RTCi_WriteRawStatus2Async()) {
                            SDK_data_021803b0.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                SDK_data_021803b0.index = 0;
            }
            break;
        case RTC_SEQ_SET_ALARM2_STATUS:
            if (SDK_data_021803b0.index == 0) {
                RTCRawStatus2 * pSrc = &(((RTCRawData *)(OS_GetSystemWork()->real_time_clock))->a.status2);

                if (*(RTCAlarmStatus *)(SDK_data_021803b0.buffer[0]) == RTC_ALARM_STATUS_ON) {
                    if (!pSrc->intr2_mode) {
                        SDK_data_021803b0.index++;
                        pSrc->intr2_mode = 1;
                        if (!RTCi_WriteRawStatus2Async()) {
                            SDK_data_021803b0.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {

                    if (pSrc->intr2_mode) {

                        SDK_data_021803b0.index++;
                        pSrc->intr2_mode = 0;
                        if (!RTCi_WriteRawStatus2Async()) {
                            SDK_data_021803b0.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                SDK_data_021803b0.index = 0;
            }
            break;
        case RTC_SEQ_SET_ALARM1_PARAM:
        case RTC_SEQ_SET_ALARM2_PARAM:
        case RTC_SEQ_SET_HOUR_FORMAT:
        case RTC_SEQ_SET_REG_STATUS2:
        case RTC_SEQ_SET_REG_ADJUST:
            break;
        default:
            result = RTC_RESULT_INVALID_COMMAND;
            SDK_data_021803b0.index = 0;
        }
    } else {
        SDK_data_021803b0.index = 0;

        switch (pxiresult) {
        case RTC_PXI_RESULT_INVALID_COMMAND:
            result = RTC_RESULT_INVALID_COMMAND;
            break;
        case RTC_PXI_RESULT_ILLEGAL_STATUS:
            result = RTC_RESULT_ILLEGAL_STATUS;
            break;
        case RTC_PXI_RESULT_BUSY:
            result = RTC_RESULT_BUSY;
            break;
        case RTC_PXI_RESULT_FATAL_ERROR:
        default:
            result = RTC_RESULT_FATAL_ERROR;
        }
    }

    if (SDK_data_021803b0.index == 0) {
        if (SDK_data_021803b0.lock != RTC_LOCK_OFF) {
            SDK_data_021803b0.lock = RTC_LOCK_OFF;
        }

        if (SDK_data_021803b0.callback) {
            cb = SDK_data_021803b0.callback;
            SDK_data_021803b0.callback = NULL;
            cb(result, SDK_data_021803b0.callbackArg);
        }
    }
}

static u32 RtcBCD2HEX (u32 bcd)
{
    u32 hex = 0;
    s32 i;
    s32 w;

    for (i = 0; i < 8; i++) {
        if (((bcd >> (i * 4)) & 0x0000000f) >= 0x0a) {
            return hex;
        }
    }

    for (i = 0, w = 1; i < 8; i++, w *= 10) {
        hex += (((bcd >> (i * 4)) & 0x0000000f) * w);
    }

    return hex;
}

static u32 RtcHEX2BCD (u32 hex)
{
    u32 bcd = 0;
    s32 i;
    u32 w;

    if (hex > 99999999) {
        return 0;
    }

    for (i = 0, w = hex; i < 8; i++) {
        bcd += ((w % 10) << (i * 4));
        w /= 10;
    }

    return bcd;
}

static BOOL RtcCheckAlarmParam (const RTCAlarmParam * param)
{
    if (param->week >= RTC_WEEK_MAX)
        return FALSE;
    if (param->hour >= 24)
        return FALSE;
    if (param->minute >= 60)
        return FALSE;
    if (param->enable & ~RTC_ALARM_ENABLE_ALL)
        return FALSE;

    return TRUE;
}

static RTCRawAlarm RtcMakeAlarmParam (const RTCAlarmParam * param)
{
    RTCRawAlarm dst;

    *((u32 *)(&dst)) = 0;

    if (!RtcCheckAlarmParam(param)) {
        return dst;
    }

    dst.week = (u32)(param->week);

    if (param->hour >= 12) {
        dst.afternoon = 1;
    }

    dst.hour = RtcHEX2BCD(param->hour);
    dst.minute = RtcHEX2BCD(param->minute);

    if (param->enable & RTC_ALARM_ENABLE_WEEK) {
        dst.we = 1;
    }

    if (param->enable & RTC_ALARM_ENABLE_HOUR) {
        dst.he = 1;
    }

    if (param->enable & RTC_ALARM_ENABLE_MINUTE) {
        dst.me = 1;
    }

    return dst;
}

static BOOL RtcCheckDate (const RTCDate * date, RTCRawDate * raw)
{

    if (date->year >= 100)
        return FALSE;

    if ((date->month < 1) || (date->month > 12))
        return FALSE;

    if ((date->day < 1) || (date->day > 31))
        return FALSE;

    if (date->week >= RTC_WEEK_MAX)
        return FALSE;

    *(u32 *)raw = RtcHEX2BCD(date->year);

    raw->month = RtcHEX2BCD(date->month);
    raw->day = RtcHEX2BCD(date->day);
    raw->week = (u32)(date->week);

    return TRUE;
}

static BOOL RtcCheckTime (const RTCTime * time, RTCRawTime * raw)
{
    if (time->hour >= 24)
        return FALSE;

    if (time->minute >= 60)
        return FALSE;

    if (time->second >= 60)
        return FALSE;

    if (time->hour >= 12) {
        raw->afternoon = 1;
    } else {
        raw->afternoon = 0;
    }

    raw->hour = RtcHEX2BCD(time->hour);
    raw->minute = RtcHEX2BCD(time->minute);
    raw->second = RtcHEX2BCD(time->second);

    return TRUE;
}

static void RtcGetResultCallback (RTCResult result, void * arg)
{
#pragma unused(arg)

    SDK_data_021803b0.commonResult = result;
}

static void RtcConvertTickToDateTimeEx (RTCDate * date, RTCTimeEx * time, OSTick tick)
{
    RTC_ConvertSecondToDateTime(date, (RTCTime *)time, (s64) OS_TicksToSeconds(tick));
    time->millisecond = (s32) (OS_TicksToMilliSeconds(tick) % 1000);
}

static RTCResult RtcTickInit (void)
{
    RTCDate currentDate;
    RTCTime currentTime;
    s64 totalSeconds;
    RTCResult result;

    SDK_ASSERT(OS_IsTickAvailable());

    result = RTC_GetDateTime(&currentDate, &currentTime);
    totalSeconds = RTC_ConvertDateTimeToSecond(&currentDate, &currentTime);

    rtcInitialTotalTicks = OS_SecondsToTicks(totalSeconds) - OS_GetTick();
    rtcTickInitialized = TRUE;

    return result;
}

#include <nitro/code32.h>
#undef PXI_Init
#undef PXI_IsCallbackReady
#undef PXI_SetFifoRecvCallback
#undef RTC_Init

extern void RtcWaitBusy (void);

#include <nitro/codereset.h>
