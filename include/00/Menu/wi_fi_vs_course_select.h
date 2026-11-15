#pragma once

#include "types.h"
#include "00/Menu/wi_fi_state_machine.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

// Object behind gWiFiVSCourseSelectState.
typedef struct WiFiVSCourseSelectHeapHolder {
    /* 0 */ u8 mUnk_00[4];
    /* 4 */ void *mHeap;
} WiFiVSCourseSelectHeapHolder;

void RegisterWiFiVSCourseSelectCallbacks(void);
void WriteWiFiVSCourseSelectRegistersWrapper(void);
void AdvanceWiFiVSCourseSelectState(void);
void InitWiFiVSCourseSelectNop(void);
void ReleaseWiFiVSCourseSelectState(void);
void InitWiFiVSCourseSelectState(void *heap);

extern WiFiStateCallbacks gWiFiVSCourseSelectCallbacks;
extern WiFiVSCourseSelectHeapHolder *gWiFiVSCourseSelectState;
