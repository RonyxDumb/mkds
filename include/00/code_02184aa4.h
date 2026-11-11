#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

extern WiFiStateCallbacks gWiFiVSCourseSelectCallbacks;

void RegisterWiFiVSCourseSelectCallbacks(void);
void WriteWiFiVSCourseSelectRegistersWrapper(void);
void AdvanceWiFiVSCourseSelectState(void);
void InitWiFiVSCourseSelectNop(void);
void ReleaseWiFiVSCourseSelectState(void);
void InitWiFiVSCourseSelectState(u32 heap);
