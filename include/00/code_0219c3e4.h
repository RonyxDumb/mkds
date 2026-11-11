#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02193b88.h"

#include "00/code_02192d64.h"

#include "00/code_0219c000.h"

u32 DWCi_CheckLogin(void);
void DWCi_GPGetInfoCallback(GpConnection *connection, GetInfoReply *arg, u32 param);
void DWCi_RemoteLoginProcess(void);
void DWCi_RemoteLogin(void (*callback)(), void *param);
void DWCi_GPConnect(char *authToken, char *partnerChallenge, void (*callback)(), s32 targetState);
void DWCi_RemoteAuthCallback(char *authToken, char *partnerChallenge);
void DWCi_GPConnectCallback(GpConnection *connection, ConnectReply *arg, u32 param);
s32 ReportWiFiLoginGpResult(s32 result);
