#pragma once

#include "types.h"
#include "00/unk_021b5000.h"
#include "03/Net/essid_packet_steps.h"

void InitWiFiLogin(WiFiLogin *login, DWCAccUserData *userData, GpConnection *gpConnection, u32 productId, u32 gamecode,
                   void (*resultCallback)(), void *resultCallbackArg);
u32 DWCi_GetPersCallbackLevel(void);
