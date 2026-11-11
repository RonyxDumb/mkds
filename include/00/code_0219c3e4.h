#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"

// Argument of the callbacks DWCi_GPGetInfoCallback, WiFiLoginGpConnectCallback, DWCi_GPGetInfoCallback_RecvAuthMessage
// and DWCi_GPGetInfoCallback_RecvBuddyRequest.
typedef Unk0218eff8Arg Unk0219c400;


#include "00/code_0219c000.h"

u32 IsWiFiLoginDone(void);
void DWCi_GPGetInfoCallback(GpConnection *connection, Unk0219c400 *arg, u32 param);
void UpdateWiFiLoginRequest(void);
void StartWiFiLoginRequest(void (*callback)(), void *param);
void StartWiFiLoginGpConnect(char *authToken, char *partnerChallenge, void (*callback)(), s32 nextState);
void WiFiLoginRequestCallback(char *authToken, char *partnerChallenge);
void WiFiLoginGpConnectCallback(GpConnection *connection, Unk0219c400 *arg, u32 param);
s32 ReportWiFiLoginGpResult(s32 result);
