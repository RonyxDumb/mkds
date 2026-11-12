#include "code_0214d93c.h"
#include "registers.h"

#include "code_0200fc8c.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/code_0200f000.h"

u16 gClockInitialized;

// Sends the command that reads the date word.
BOOL RTCi_ReadRawDateAsync(void) {
    return RtcSendPxiCommand(0x11);
}

// Sends the command that reads the time word.
BOOL RTCi_ReadRawTimeAsync(void) {
    return RtcSendPxiCommand(0x12);
}

// Sends the command that writes status register 2.
BOOL RTCi_WriteRawStatus2Async(void) {
    return RtcSendPxiCommand(0x27);
}

// Sends command number command on tag 5; TRUE when the FIFO took the word.
BOOL RtcSendPxiCommand(u32 command) {
    return PXI_SendWordByFifo(5, (command << 8) & 0x7f00, 0) >= 0;
}

// Sets up the clock channel on the first call only.
void RTC_Init(void) {
    if (gClockInitialized != 0) {
        return;
    }
    gClockInitialized = 1;
    gClockRequest.mLock = 0;
    gClockRequest.mCallback = 0;
    gClockRequest.mInterrupt = 0;
    gClockRequest.mBuffer[0] = 0;
    gClockRequest.mBuffer[1] = 0;
    PXI_Init();
    while (PXI_IsCallbackReady(5, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(5, RtcCommonCallback);
}

// Reads the date into date; callback is called with the result and arg when the reply is in.
RTCResult RTC_GetDateAsync(RTCDate *date, RTCCallback callback, void *arg) {
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();
    if (gClockRequest.mLock != 0) {
        OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    gClockRequest.mLock = 1;
    OS_RestoreInterrupts(enabled);
    gClockRequest.mSequence = RTC_SEQ_GET_DATE;
    gClockRequest.mIndex = 0;
    gClockRequest.mBuffer[0] = date;
    gClockRequest.mCallback = callback;
    gClockRequest.mCallbackArg = arg;
    return RTCi_ReadRawDateAsync() != 0 ? RTC_RESULT_SUCCESS : RTC_RESULT_SEND_ERROR;
}

// Reads the date and waits for the reply.
RTCResult RTC_GetDate(RTCDate *date) {
    gClockRequest.mCommonResult = RTC_GetDateAsync(date, RtcGetResultCallback, 0);
    if (gClockRequest.mCommonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return gClockRequest.mCommonResult;
}

// Reads the time into time; callback is called with the result and arg when the reply is in.
RTCResult RTC_GetTimeAsync(RTCTime *time, RTCCallback callback, void *arg) {
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();
    if (gClockRequest.mLock != 0) {
        OS_RestoreInterrupts(enabled);
        return RTC_RESULT_BUSY;
    }
    gClockRequest.mLock = 1;
    OS_RestoreInterrupts(enabled);
    gClockRequest.mSequence = RTC_SEQ_GET_TIME;
    gClockRequest.mIndex = 0;
    gClockRequest.mBuffer[0] = time;
    gClockRequest.mCallback = callback;
    gClockRequest.mCallbackArg = arg;
    return RTCi_ReadRawTimeAsync() != 0 ? RTC_RESULT_SUCCESS : RTC_RESULT_SEND_ERROR;
}

// Reads the time and waits for the reply.
RTCResult RTC_GetTime(RTCTime *time) {
    gClockRequest.mCommonResult = RTC_GetTimeAsync(time, RtcGetResultCallback, 0);
    if (gClockRequest.mCommonResult == RTC_RESULT_SUCCESS) {
        RtcWaitBusy();
    }
    return gClockRequest.mCommonResult;
}

// Receives the reply of the other processor: decodes the shared date and time words into the buffer by mSequence,
// then ends the request and calls its callback.
void RtcCommonCallback(u32 tag, u32 data, BOOL err) {
    u8 command;
    u32 status;
    RTCResult result;
    RTCDate *date;
    RTCTime *time;
    RTCAlarmParam *alarm;
    RTCAlarmStatus *alarmStatus;
    RTCCallback callback;

    if (err != 0) {
        if (gClockRequest.mIndex != 0) {
            gClockRequest.mIndex = 0;
        }
        if (gClockRequest.mLock != 0) {
            gClockRequest.mLock = 0;
        }
        callback = gClockRequest.mCallback;
        if (callback != 0) {
            gClockRequest.mCallback = 0;
            callback(RTC_RESULT_FATAL_ERROR, gClockRequest.mCallbackArg);
        }
        return;
    }
    command = (data & 0x7f00) >> 8;
    status = data & 0xff;
    if (command == 0x30) {
        if (gClockRequest.mInterrupt != 0) {
            gClockRequest.mInterrupt();
        }
        return;
    }
    if (status == 0) {
        result = RTC_RESULT_SUCCESS;
        switch (gClockRequest.mSequence) {
            case RTC_SEQ_GET_DATE:
                date = gClockRequest.mBuffer[0];
                date->mYear = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mYear);
                date->mMonth = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mMonth);
                date->mDay = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mDay);
                date->mWeek = SYSTEM_WORK->mRealTimeClock.mDate.mWeek;
                break;
            case RTC_SEQ_GET_TIME:
                time = gClockRequest.mBuffer[0];
                time->mHour = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mHour);
                time->mMinute = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mMinute);
                time->mSecond = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mTime.mValue.mSecond);
                break;
            case RTC_SEQ_GET_DATETIME:
                date = gClockRequest.mBuffer[0];
                date->mYear = RtcBCD2HEX(*(u32 *) HW_REAL_TIME_CLOCK_BUF & 0xff);
                date->mMonth = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mMonth);
                date->mDay = RtcBCD2HEX(SYSTEM_WORK->mRealTimeClock.mDate.mDay);
                date->mWeek = SYSTEM_WORK->mRealTimeClock.mDate.mWeek;
                time = gClockRequest.mBuffer[1];
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
                alarmStatus = gClockRequest.mBuffer[0];
                switch (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode) {
                    case 4:
                        alarmStatus[0] = RTC_ALARM_STATUS_ON;
                        break;
                    default:
                        alarmStatus[0] = RTC_ALARM_STATUS_OFF;
                        break;
                }
                break;
            case RTC_SEQ_GET_ALARM2_STATUS:
                alarmStatus = gClockRequest.mBuffer[0];
                if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode) {
                    alarmStatus[0] = RTC_ALARM_STATUS_ON;
                } else {
                    alarmStatus[0] = RTC_ALARM_STATUS_OFF;
                }
                break;
            case RTC_SEQ_GET_ALARM_PARAM:
                alarm = gClockRequest.mBuffer[0];
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
                if (gClockRequest.mIndex == 0) {
                    if (*(RTCAlarmStatus *) gClockRequest.mBuffer[0] == RTC_ALARM_STATUS_ON) {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode != 4) {
                            gClockRequest.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode = 4;
                            if (RTCi_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                gClockRequest.mIndex = 0;
                            }
                        }
                    } else {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode != 0) {
                            gClockRequest.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntrMode = 0;
                            if (RTCi_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                gClockRequest.mIndex = 0;
                            }
                        }
                    }
                } else {
                    gClockRequest.mIndex = 0;
                }
                break;
            case RTC_SEQ_SET_ALARM2_STATUS:
                if (gClockRequest.mIndex == 0) {
                    if (*(RTCAlarmStatus *) gClockRequest.mBuffer[0] == RTC_ALARM_STATUS_ON) {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode == 0) {
                            gClockRequest.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode = 1;
                            if (RTCi_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                gClockRequest.mIndex = 0;
                            }
                        }
                    } else {
                        if (SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode != 0) {
                            gClockRequest.mIndex++;
                            SYSTEM_WORK->mRealTimeClock.mStatus2.mValue.mIntr2Mode = 0;
                            if (RTCi_WriteRawStatus2Async() == 0) {
                                result = RTC_RESULT_SEND_ERROR;
                                gClockRequest.mIndex = 0;
                            }
                        }
                    }
                } else {
                    gClockRequest.mIndex = 0;
                }
                break;
            default:
                gClockRequest.mIndex = 0;
                result = RTC_RESULT_INVALID_COMMAND;
                break;
        }
    } else {
        gClockRequest.mIndex = 0;
        switch (status) {
            case 1:
                result = RTC_RESULT_INVALID_COMMAND;
                break;
            case 2:
                result = RTC_RESULT_ILLEGAL_STATUS;
                break;
            case 3:
                result = RTC_RESULT_BUSY;
                break;
            case 0:
            case 4:
            default:
                result = RTC_RESULT_FATAL_ERROR;
                break;
        }
    }
    if (gClockRequest.mIndex != 0) {
        return;
    }
    if (gClockRequest.mLock != 0) {
        gClockRequest.mLock = 0;
    }
    callback = gClockRequest.mCallback;
    if (callback != 0) {
        gClockRequest.mCallback = 0;
        callback(result, gClockRequest.mCallbackArg);
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
void RtcGetResultCallback(RTCResult result, void *arg) {
    gClockRequest.mCommonResult = result;
}

// clang-format off
// Waits while the lock word of gClockRequest is 1.
asm void RtcWaitBusy(void) {
    ldr ip, =gClockRequest
wait_loop:
    ldr r0, [ip]
    cmp r0, #0x1
    beq wait_loop
    bx lr
}
// clang-format on
