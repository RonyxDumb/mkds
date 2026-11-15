#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/GameSpy/peer_connection.h"

#include "00/Lib/GameSpy/profile_info.h"

#include "00/Lib/DWC/login_state.h"

u32 DWCi_CheckLogin(void);
void DWCi_GPGetInfoCallback(GpConnection *connection, GetInfoReply *arg, u32 param);
void DWCi_RemoteLoginProcess(void);
void DWCi_RemoteLogin(void (*callback)(), void *param);
void DWCi_GPConnect(char *authToken, char *partnerChallenge, void (*callback)(), s32 targetState);
void DWCi_RemoteAuthCallback(char *authToken, char *partnerChallenge);
void DWCi_GPConnectCallback(GpConnection *connection, ConnectReply *arg, u32 param);
s32 ReportWiFiLoginGpResult(s32 result);

extern void (*stRemoteAuthCallback)();
// Points at WiFiConnection.mLogin: set by InitWiFiLogin (once per login), set to 0 by DWCi_ShutdownLogin.
extern struct WiFiLogin *gWiFiLogin;
extern void *pStRemoteAuthParam;
