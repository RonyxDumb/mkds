#pragma once

#include "types.h"

void WiFiRaceSyncReceiveCallback(u32 fromIndex, void *message, u32 size);
void WriteChangedWiFiBuddies(void);
void RequestWiFiSessionLogin(void);
void ReleaseWiFiConnectionWrapper(void);
BOOL UpdateWiFiSessionRelease(void);
// Values GetWiFiSessionLoginResult returns: the login failed, is still in progress, or is done.
#define WIFI_LOGIN_RESULT_ERROR -1
#define WIFI_LOGIN_RESULT_PENDING 0
#define WIFI_LOGIN_RESULT_LOGGED_IN 1
s32 GetWiFiSessionLoginResult(void);
void ReleaseWiFiSession(void);
void SetupWiFiSessionLogin(void);
void AdvanceWiFiSessionLoginStep1(void);
u32 UpdateWiFiSessionLogin(void);
void WiFiSessionLoginCallback(s32 result, u32 profileId, u32 arg);
void WiFiSessionBuddySyncCallback(s32 result, s32 changed);
void WiFiSessionEntryMergedCallback(u32 mergedIndex, u32 keptIndex);
void SetBuddyStatus(u32 index, u8 status);
