#pragma once

#include "types.h"
#include "00/Lib/DWC/code_0218a064.h"

// Values of ACHOLD.mPhase, the steps of the automatic connect: start up the wireless layer, scan around, scan the channels
// of the listed access points, scan for hidden ones, connect to an access point, retry the connect, test the
// connection (get an address, open a socket, run the test), then finish or fail.
enum {
    AC_PHASE_START = 1,
    AC_PHASE_STARTING_UP = 2,
    AC_PHASE_SEARCH_AROUND = 3,
    AC_PHASE_SEARCH_LISTED_CHANNELS = 4,
    AC_PHASE_SEARCH_HIDDEN = 5,
    AC_PHASE_SEARCH_DONE = 6,
    AC_PHASE_CONNECT_START = 7,
    AC_PHASE_CONNECT_AP = 8,
    AC_PHASE_CONNECT_RETRY = 9,
    AC_PHASE_TEST_START = 10,
    AC_PHASE_TEST_RETRY = 11,
    AC_PHASE_TEST_GET_IP = 12,
    AC_PHASE_TEST_CREATE = 13,
    AC_PHASE_TEST_PROCESS = 14,
    AC_PHASE_TEST_END = 15,
    AC_PHASE_COMPLETE = 16,
    AC_PHASE_ERROR = 17,
    AC_PHASE_END = 18,
};

// Values of the type argument of DWCi_AC_MakeSearchList: which access points the scan list is made from.
enum {
    AC_SEARCH_LIST_AROUND,
    AC_SEARCH_LIST_OTHER_CHANNELS,
    AC_SEARCH_LIST_HIDDEN,
};

// Object behind gAcHold.
typedef struct ACHOLD {
    /* 00 */ SocketAllocFn mAlloc;
    /* 04 */ SocketFreeFn mFree;
    /* 08 */ u8 mAllocState;
    /* 09 */ u8 mPhase;
    /* 0a */ u8 mErrorPhase;
    /* 0b */ u8 mBeaconReceived;
    /* 0c */ u32 mError;
    /* 10 */ s32 mErrorTest;
    /* 14 */ u8 mEndState;
    /* 15 */ u8 mEndType;
    /* 16 */ u8 mEndSequence;
    /* 17 */ u8 mApType;
} ACHOLD;

u8 DWCi_ConvConnectAPType(u8 apType);
void SetAcHoldApType(u8 apType);
u32 DWCi_AC_GetError(void);
void DWCi_AC_SetError(u32 error);
u8 DWCi_AC_GetPhase(void);
void DWCi_AC_SetPhase(u8 phase);
void *DWCi_AC_GetMemPtr(u32 name);
void DWCi_AC_FreeAll(void);
