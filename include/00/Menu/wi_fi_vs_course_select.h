#pragma once

#include "types.h"
#include "00/code_02180608.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

void RegisterWiFiVSCourseSelectCallbacks(void);
void WriteWiFiVSCourseSelectRegistersWrapper(void);
void AdvanceWiFiVSCourseSelectState(void);
void InitWiFiVSCourseSelectNop(void);
void ReleaseWiFiVSCourseSelectState(void);
void InitWiFiVSCourseSelectState(u32 heap);

extern WiFiStateCallbacks gWiFiVSCourseSelectCallbacks;
extern u8 gWiFiVSCourseSelectState[1];
