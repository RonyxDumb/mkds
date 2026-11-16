#include "clock_chip_access.h"
#include "registers.h"

#include "reset_interrupts_halt.h"
#include "arm_fifo_messaging.h"

u16 g_Rtc_Initialized;
RTCWork g_Rtc_Context;

// Sends the command that reads the date word.
BOOL Rtc_ReadRawDateAsync(void) {
    return Rtc_SendFifoWord(0x11);
}

// Sends the command that reads the time word.
BOOL Rtc_ReadRawTimeAsync(void) {
    return Rtc_SendFifoWord(0x12);
}

// Sends the command that writes status register 2.
BOOL Rtc_WriteRawStatus2Async(void) {
    return Rtc_SendFifoWord(0x27);
}

// Sends command number command on tag 5; TRUE when the FIFO took the word.
BOOL Rtc_SendFifoWord(u32 command) {
    return Fifo_SendWord(5, (command << 8) & 0x7f00, 0) >= 0;
}

// Sets up the clock channel on the first call only.
void Rtc_Initialize(void) {
    if (g_Rtc_Initialized != 0) {
        return;
    }
    g_Rtc_Initialized = 1;
    g_Rtc_Context.mLock = 0;
    g_Rtc_Context.mCallback = 0;
    g_Rtc_Context.mInterrupt = 0;
    g_Rtc_Context.mBuffer[0] = 0;
    g_Rtc_Context.mBuffer[1] = 0;
    j_Fifo_Initialize();
    while (Fifo_IsHandlerReady(5, 1) == 0) {
    }
    Fifo_RegisterHandler(5, Rtc_FifoHandler);
}

// Reads the date into date; callback is called with the result and arg when the reply is in.
RTCResult Rtc_GetDateAsync(RTCDate *date, RTCCallback callback, void *arg) {
    OSIntrMode enabled;

    enabled = Os_DisableIrq();
    if (g_Rtc_Context.mLock != 0) {
        Os_RestoreIrq(enabled);
        return RTC_RESULT_BUSY;
    }
    g_Rtc_Context.mLock = 1;
    Os_RestoreIrq(enabled);
    g_Rtc_Context.mSequence = RTC_SEQ_GET_DATE;
    g_Rtc_Context.mIndex = 0;
    g_Rtc_Context.mBuffer[0] = date;
    g_Rtc_Context.mCallback = callback;
    g_Rtc_Context.mCallbackArg = arg;
    return Rtc_ReadRawDateAsync() != 0 ? RTC_RESULT_SUCCESS : RTC_RESULT_SEND_ERROR;
}

// Reads the date and waits for the reply.
RTCResult Rtc_GetDate(RTCDate *date) {
    g_Rtc_Context.mCommonResult = Rtc_GetDateAsync(date, Rtc_GetTimeAsync_ErrorFunction, 0);
    if (g_Rtc_Context.mCommonResult == RTC_RESULT_SUCCESS) {
        Rtc_WaitBusy();
    }
    return g_Rtc_Context.mCommonResult;
}

// Reads the time into time; callback is called with the result and arg when the reply is in.
RTCResult Rtc_GetTimeAsync(RTCTime *time, RTCCallback callback, void *arg) {
    OSIntrMode enabled;

    enabled = Os_DisableIrq();
    if (g_Rtc_Context.mLock != 0) {
        Os_RestoreIrq(enabled);
        return RTC_RESULT_BUSY;
    }
    g_Rtc_Context.mLock = 1;
    Os_RestoreIrq(enabled);
    g_Rtc_Context.mSequence = RTC_SEQ_GET_TIME;
    g_Rtc_Context.mIndex = 0;
    g_Rtc_Context.mBuffer[0] = time;
    g_Rtc_Context.mCallback = callback;
    g_Rtc_Context.mCallbackArg = arg;
    return Rtc_ReadRawTimeAsync() != 0 ? RTC_RESULT_SUCCESS : RTC_RESULT_SEND_ERROR;
}

// Reads the time and waits for the reply.
RTCResult Rtc_GetTime(RTCTime *time) {
    g_Rtc_Context.mCommonResult = Rtc_GetTimeAsync(time, Rtc_GetTimeAsync_ErrorFunction, 0);
    if (g_Rtc_Context.mCommonResult == RTC_RESULT_SUCCESS) {
        Rtc_WaitBusy();
    }
    return g_Rtc_Context.mCommonResult;
}

// Receives the reply of the other processor: decodes the shared date and time words into the buffer by mSequence,
// then ends the request and calls its callback.
void Rtc_FifoHandler(u32 tag, u32 data, BOOL err) {
    u8 pxiCommand;
    u32 status;
    RTCResult result;
    RTCDate *date;
    RTCTime *time;
    RTCAlarmParam *alarm;
    RTCAlarmStatus *alarmStatus;
    RTCCallback callback;

    if (err != 0) {
        if (g_Rtc_Context.mIndex != 0) {
            g_Rtc_Context.mIndex = 0;
        }
        if (g_Rtc_Context.mLock != 0) {
            g_Rtc_Context.mLock = 0;
        }
        callback = g_Rtc_Context.mCallback;
        if (callback != 0) {
            g_Rtc_Context.mCallback = 0;
            callback(RTC_RESULT_FATAL_ERROR, g_Rtc_Context.mCallbackArg);
        }
        return;
    }
    pxiCommand = (data & 0x7f00) >> 8;
    status = data & 0xff;
    if (pxiCommand == 0x30) {
        if (g_Rtc_Context.mInterrupt != 0) {
            g_Rtc_Context.mInterrupt();
        }
        return;
    }
    if (status == 0) {
        result = RTC_RESULT_SUCCESS;
        switch (g_Rtc_Context.mSequence) {
            case RTC_SEQ_GET_DATE:
                date = g_Rtc_Context.mBuffer[0];
                date->mYear = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mYear);
                date->mMonth = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mMonth);
                date->mDay = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mDay);
                date->mWeek = SYSTEM_WORK->mRealTimeClock.mDate.mWeek;
                break;
            case RTC_SEQ_GET_TIME:
                time = g_Rtc_Context.mBuffer[0];
                time->mHour = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mHour);
                time->mMinute = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mMinute);
                time->mSecond = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mSecond);
                break;
            case RTC_SEQ_GET_DATETIME:
                date = g_Rtc_Context.mBuffer[0];
                date->mYear = RtcBCD2HEX(*(u32 *) HW_REAL_TIME_CLOCK_BUF & 0xff);
                date->mMonth = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mMonth);
                date->mDay = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mDay);
                date->mWeek = SYSTEM_WORK->mRealTimeClock.mDate.mWeek;
                time = g_Rtc_Context.mBuffer[1];
                time->mHour = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mHour);
                time->mMinute = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mMinute);
                time->mSecond = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mSecond);
                break;
            case RTC_SEQ_SET_DATE:
            case RTC_SEQ_SET_TIME:
            case RTC_SEQ_SET_DATETIME:
            case RTC_SEQ_SET_ALARM1_PARAM:
            case RTC_SEQ_SET_ALARM2_PARAM:
            case RTC_SEQ_SET_HOUR_FORMAT:
            case RTC_SEQ_SET_REG_STATUS2:
            case RTC_SEQ_SET_REG_ADJUST:
                break;
            case RTC_SEQ_GET_ALARM1_STATUS:
                alarmStatus = g_Rtc_Context.mBuffer[0];
                switch (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode) {
                    case CLOCK_ALARM_INTR_MODE_ALARM1:
                        alarmStatus[0] = RTC_ALARM_STATUS_ON;
                        break;
                    default:
                        alarmStatus[0] = RTC_ALARM_STATUS_OFF;
                        break;
                }
                break;
            case RTC_SEQ_GET_ALARM2_STATUS:
                alarmStatus = g_Rtc_Context.mBuffer[0];
                if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode) {
                    alarmStatus[0] = RTC_ALARM_STATUS_ON;
                } else {
                    alarmStatus[0] = RTC_ALARM_STATUS_OFF;
                }
                break;
            case RTC_SEQ_GET_ALARM_PARAM:
                alarm = g_Rtc_Context.mBuffer[0];
                alarm->mWeek = SYSTEM_WORK->mRealTimeClock.mAlarm.mValue.mWeek;
                alarm->mHour = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mAlarm.mValue.mHour);
                alarm->mMinute = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mAlarm.mValue.mMinute);
                alarm->mEnable = 0;
                if (SYSTEM_WORK->mRealTimeClock.mAlarm.mValue.mWe) {
                    alarm->mEnable += 1;
                }
                if (SYSTEM_WORK->mRealTimeClock.mAlarm.mValue.mHe) {
                    alarm->mEnable += 2;
                }
                if (SYSTEM_WORK->mRealTimeClock.mAlarm.mValue.mMe) {
                    alarm->mEnable += 4;
                }
                break;
            case RTC_SEQ_SET_ALARM1_STATUS:
                if (g_Rtc_Context.mIndex == 0) {
                    if (*(RTCAlarmStatus *) g_Rtc_Context.mBuffer[0] == RTC_ALARM_STATUS_ON) {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode != CLOCK_ALARM_INTR_MODE_ALARM1) {
                            g_Rtc_Context.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode = CLOCK_ALARM_INTR_MODE_ALARM1;
                            if (Rtc_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                g_Rtc_Context.mIndex = 0;
                            }
                        }
                    } else {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode != CLOCK_ALARM_INTR_MODE_NONE) {
                            g_Rtc_Context.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode = CLOCK_ALARM_INTR_MODE_NONE;
                            if (Rtc_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                g_Rtc_Context.mIndex = 0;
                            }
                        }
                    }
                } else {
                    g_Rtc_Context.mIndex = 0;
                }
                break;
            case RTC_SEQ_SET_ALARM2_STATUS:
                if (g_Rtc_Context.mIndex == 0) {
                    if (*(RTCAlarmStatus *) g_Rtc_Context.mBuffer[0] == RTC_ALARM_STATUS_ON) {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode == 0) {
                            g_Rtc_Context.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode = 1;
                            if (Rtc_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                g_Rtc_Context.mIndex = 0;
                            }
                        }
                    } else {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode != 0) {
                            g_Rtc_Context.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode = 0;
                            if (Rtc_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                g_Rtc_Context.mIndex = 0;
                            }
                        }
                    }
                } else {
                    g_Rtc_Context.mIndex = 0;
                }
                break;
            default:
                g_Rtc_Context.mIndex = 0;
                result = RTC_RESULT_INVALID_COMMAND;
                break;
        }
    } else {
        g_Rtc_Context.mIndex = 0;
        switch (status) {
            case CLOCK_REPLY_STATUS_INVALID_COMMAND:
                result = RTC_RESULT_INVALID_COMMAND;
                break;
            case CLOCK_REPLY_STATUS_ILLEGAL_STATUS:
                result = RTC_RESULT_ILLEGAL_STATUS;
                break;
            case CLOCK_REPLY_STATUS_BUSY:
                result = RTC_RESULT_BUSY;
                break;
            case CLOCK_REPLY_STATUS_OK:
            case CLOCK_REPLY_STATUS_FATAL_ERROR:
            default:
                result = RTC_RESULT_FATAL_ERROR;
                break;
        }
    }
    if (g_Rtc_Context.mIndex != 0) {
        return;
    }
    if (g_Rtc_Context.mLock != 0) {
        g_Rtc_Context.mLock = 0;
    }
    callback = g_Rtc_Context.mCallback;
    if (callback != 0) {
        g_Rtc_Context.mCallback = 0;
        callback(result, g_Rtc_Context.mCallbackArg);
    }
}

// Returns bcd read as 8 decimal digits (4 bits each, least significant first), or 0 when a digit is above 9.
u32 RtcBCD2HEX(u32 bcd) {
    u32 hex;
    u32 scale;
    s32 digitIndex;

    hex = 0;
    for (digitIndex = 0; digitIndex < 8; digitIndex++) {
        if (((bcd >> (digitIndex * 4)) & 0xf) >= 10) {
            return 0;
        }
    }
    scale = 1;
    for (digitIndex = 0; digitIndex < 8; digitIndex++) {
        hex += scale * ((bcd >> (digitIndex * 4)) & 0xf);
        scale *= 10;
    }
    return hex;
}

// Stores the result of the waiting calls.
void Rtc_GetTimeAsync_ErrorFunction(RTCResult result, void *arg) {
    g_Rtc_Context.mCommonResult = result;
}

// clang-format off
// Waits while the lock word of g_Rtc_Context is 1.
asm void Rtc_WaitBusy(void) {
    ldr ip, =g_Rtc_Context
wait_loop:
    ldr r0, [ip]
    cmp r0, #0x1
    beq wait_loop
    bx lr
}
// clang-format on
