#pragma once

#include "types.h"
#include "00/Menu/wi_fi_state_machine.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

// Values of WiFiConnectionLost.mState and mNextState.
enum {
    WIFI_CONNECTION_LOST_STATE_WAIT_FADE_OUT,
    WIFI_CONNECTION_LOST_STATE_WAIT_FADE_IN,
};

// The Wi-Fi connection lost state: mState and mNextState pick the fade handler AdvanceWiFiConnectionLost runs.
typedef struct WiFiConnectionLost {
    /* 0 */ s32 mState;
    /* 4 */ s32 mNextState;
} WiFiConnectionLost;

void RegisterWiFiConnectionLostCallbacks(void);
void WriteWiFiConnectionLostRegistersNop(void);
void AdvanceWiFiConnectionLost(void);
void AdvanceWiFiConnectionLostWaitFadeIn(void);
void AdvanceWiFiConnectionLostWaitFadeOut(void);
void ClearWiFiConnectionLostPointer(void);
void InitWiFiConnectionLost(void *heap);

extern WiFiStateCallbacks gWiFiConnectionLostCallbacks;
extern WiFiConnectionLost *gWiFiConnectionLost;
