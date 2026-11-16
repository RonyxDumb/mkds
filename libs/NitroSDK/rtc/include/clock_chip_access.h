#pragma once

#include "types.h"

typedef enum RTCWeek {
    RTC_WEEK_SUNDAY = 0,
    RTC_WEEK_MONDAY,
    RTC_WEEK_TUESDAY,
    RTC_WEEK_WEDNESDAY,
    RTC_WEEK_THURSDAY,
    RTC_WEEK_FRIDAY,
    RTC_WEEK_SATURDAY,
    RTC_WEEK_MAX
} RTCWeek;

typedef enum RTCAlarmStatus { RTC_ALARM_STATUS_OFF = 0, RTC_ALARM_STATUS_ON, RTC_ALARM_STATUS_MAX } RTCAlarmStatus;

typedef enum RTCResult {
    RTC_RESULT_SUCCESS = 0,
    RTC_RESULT_BUSY,
    RTC_RESULT_ILLEGAL_PARAMETER,
    RTC_RESULT_SEND_ERROR,
    RTC_RESULT_INVALID_COMMAND,
    RTC_RESULT_ILLEGAL_STATUS,
    RTC_RESULT_FATAL_ERROR,
    RTC_RESULT_MAX
} RTCResult;

// Nonzero reply status codes the clock processor puts in the low byte of a reply.
enum {
    CLOCK_REPLY_STATUS_OK = 0,
    CLOCK_REPLY_STATUS_INVALID_COMMAND,
    CLOCK_REPLY_STATUS_ILLEGAL_STATUS,
    CLOCK_REPLY_STATUS_BUSY,
    CLOCK_REPLY_STATUS_FATAL_ERROR,
};

// Which request is in flight; Rtc_FifoHandler decodes the reply by it.
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

typedef void (*RTCCallback)(RTCResult result, void *arg);
typedef void (*RTCInterrupt)(void);

// The date as plain numbers: year since 2000 (0 to 99), month (1 to 12), day (1 to 31) and weekday.
typedef struct RTCDate {
    /* 00 */ u32 mYear;
    /* 04 */ u32 mMonth;
    /* 08 */ u32 mDay;
    /* 0c */ RTCWeek mWeek;
} RTCDate;

// The time of day as plain numbers.
typedef struct RTCTime {
    /* 00 */ u32 mHour;
    /* 04 */ u32 mMinute;
    /* 08 */ u32 mSecond;
} RTCTime;

// An alarm as plain numbers; mEnable has one bit each for week (1), hour (2) and minute (4).
typedef struct RTCAlarmParam {
    /* 00 */ RTCWeek mWeek;
    /* 04 */ u32 mHour;
    /* 08 */ u32 mMinute;
    /* 0c */ u32 mEnable;
} RTCAlarmParam;

// The clock chip's date: year, month, day and weekday.
typedef struct RTCRawDate {
    /* 00 */ u32 mYear : 8;
    /* 00 */ u32 mMonth : 5;
    /* 00 */ u32 : 3;
    /* 00 */ u32 mDay : 6;
    /* 00 */ u32 : 2;
    /* 00 */ u32 mWeek : 3;
    /* 00 */ u32 : 5;
} RTCRawDate;

// The clock chip's time: hour, afternoon flag, minute and second.
typedef struct RTCRawTime {
    /* 00 */ u32 mHour : 6;
    /* 00 */ u32 mAfternoon : 1;
    /* 00 */ u32 : 1;
    /* 00 */ u32 mMinute : 7;
    /* 00 */ u32 : 1;
    /* 00 */ u32 mSecond : 7;
    /* 00 */ u32 : 9;
} RTCRawTime;

// mIntrMode values this code uses: no alarm 1 interrupt, alarm 1 interrupt.
#define CLOCK_ALARM_INTR_MODE_NONE 0
#define CLOCK_ALARM_INTR_MODE_ALARM1 4

// The clock chip's status register 2: the interrupt modes.
typedef struct RTCRawStatus2 {
    /* 00 */ u16 mIntrMode : 4;
    /* 00 */ u16 : 2;
    /* 00 */ u16 mIntr2Mode : 1;
    /* 00 */ u16 : 9;
} RTCRawStatus2;

// A clock chip alarm register: mWeek, mHour and mMinute with the enable bits mWe, mHe and mMe.
typedef struct RTCRawAlarm {
    /* 00 */ u32 mWeek : 3;
    /* 00 */ u32 : 4;
    /* 00 */ u32 mWe : 1;
    /* 00 */ u32 mHour : 6;
    /* 00 */ u32 mAfternoon : 1;
    /* 00 */ u32 mHe : 1;
    /* 00 */ u32 mMinute : 7;
    /* 00 */ u32 mMe : 1;
    /* 00 */ u32 : 8;
} RTCRawAlarm;

// The 8 bytes the other processor writes into shared memory: the views overlap, and the alarm and time words share one.
typedef union RTCRawData {
    u32 mWords[2];
    RTCRawDate mDate;
    struct {
        /* 00 */ u8 mUnk_00[2];
        /* 02 */ RTCRawStatus2 mValue;
    } mStatus2;
    struct {
        /* 00 */ u8 mUnk_00[4];
        /* 04 */ RTCRawTime mValue;
    } mTime;
    struct {
        /* 00 */ u8 mUnk_00[4];
        /* 04 */ RTCRawAlarm mValue;
    } mAlarm;
} RTCRawData;

// The clock chip request in flight: its lock, callback, result buffers and which request it is.
typedef struct RTCWork {
    // Nonzero while a request is in flight.
    /* 00 */ vu32 mLock;
    // Called once with the result and mCallbackArg when the request finishes (cleared first).
    /* 04 */ RTCCallback mCallback;
    // Where Rtc_FifoHandler writes the decoded words; the second one is for the date and time request.
    /* 08 */ void *mBuffer[2];
    /* 10 */ void *mCallbackArg;
    // Which request is in flight.
    /* 14 */ u32 mSequence;
    // Nonzero between sending a status register write and its reply.
    /* 18 */ u32 mIndex;
    // Called without arguments when command 0x30 arrives.
    /* 1c */ RTCInterrupt mInterrupt;
    // Result of the last waiting call.
    /* 20 */ RTCResult mCommonResult;
} RTCWork;

// Set to 1 by Rtc_Initialize; a second call returns at once.
extern u16 g_Rtc_Initialized;
// The one request object.
extern RTCWork g_Rtc_Context;

// Spins while mLock of g_Rtc_Context is 1.
void Rtc_WaitBusy(void);
// Stores the result in mCommonResult of g_Rtc_Context; the callback of the waiting forms.
void Rtc_GetTimeAsync_ErrorFunction(RTCResult result, void *arg);
// Returns the value of x read as 8 decimal digits (4 bits each, least significant first), or 0 when a digit is above 9.
u32 RtcBCD2HEX(u32 bcd);
// Receive handler of the clock channel. Command 0x30 calls mInterrupt. Otherwise a zero status byte decodes the shared
// date and time words into the buffer by mSequence, and a nonzero byte maps 1, 2, 3 and anything else to 4, 5, 1 and 6.
// A transport error finishes the request with 6. Then clears mLock and calls mCallback once, unless a status register
// write is waiting for its reply.
void Rtc_FifoHandler(u32 tag, u32 data, BOOL err);
// Rtc_GetTimeAsync, then waits for the reply; returns the result.
RTCResult Rtc_GetTime(RTCTime *time);
// Starts a read of the time into time and returns at once; same arguments and return values as Rtc_GetDateAsync.
RTCResult Rtc_GetTimeAsync(RTCTime *time, RTCCallback callback, void *arg);
// Rtc_GetDateAsync, then waits for the reply; returns the result.
RTCResult Rtc_GetDate(RTCDate *date);
// Starts a read of the date into date and returns at once; callback is called with the result and arg when the reply
// is in. Returns RTC_RESULT_BUSY when a request is already in flight, RTC_RESULT_SEND_ERROR when the command could not
// be sent, otherwise RTC_RESULT_SUCCESS.
RTCResult Rtc_GetDateAsync(RTCDate *date, RTCCallback callback, void *arg);
// Runs once: clears the request object, opens the clock channel (PXI tag 5), waits for the other processor and installs
// Rtc_FifoHandler as its handler.
void Rtc_Initialize(void);
// Sends command number command on tag 5; returns 1 when the FIFO accepted the word, 0 when not.
BOOL Rtc_SendFifoWord(u32 command);
// Sends command 0x27.
BOOL Rtc_WriteRawStatus2Async(void);
// Sends command 0x12.
BOOL Rtc_ReadRawTimeAsync(void);
// Sends command 0x11.
BOOL Rtc_ReadRawDateAsync(void);
