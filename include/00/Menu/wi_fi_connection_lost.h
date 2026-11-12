#pragma once

#include "types.h"
#include "00/code_02180608.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

// mState selects the handler run by AdvanceWiFiConnectionLost.
typedef struct WiFiConnectionLost {
    /* 0 */ s32 mState;
    /* 4 */ s32 mNextState;
} WiFiConnectionLost;

void RegisterWiFiConnectionLostCallbacks(void);
void WriteWiFiConnectionLostRegistersNop(void);
void AdvanceWiFiConnectionLost(void);
void AdvanceWiFiConnectionLostState1(void);
void AdvanceWiFiConnectionLostState0(void);
void ClearWiFiConnectionLostPointer(void);
void InitWiFiConnectionLost(void *heap);

extern WiFiStateCallbacks gWiFiConnectionLostCallbacks;
extern WiFiConnectionLost *gWiFiConnectionLost;
