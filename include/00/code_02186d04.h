#pragma once

#include "types.h"
#include "os_thread.h"

#include "00/Lib/DWC/code_02185954.h"
#include "00/Lib/DWC/ca_info_globalsign_root.h"
#include "00/Lib/DWC/ca_info_baltimore_root.h"
#include "00/Lib/DWC/ca_info_gte_global_root.h"
#include "00/Lib/DWC/ca_info_gte_root.h"
#include "00/Lib/DWC/ca_info_nintendo.h"
#include "00/Lib/DWC/ca_info_thawte_premium_server.h"
#include "00/Lib/DWC/ca_info_thawte_server.h"
#include "00/Lib/DWC/ca_info_verisign_class3_g2.h"
#include "00/Lib/DWC/ca_info_verisign_class3_g3.h"
#include "00/Lib/DWC/ca_info_verisign_class3.h"
#include "00/Lib/DWC/ca_info_rsa_secure_server.h"

extern CPSCaInfo *gCaInfoTable[11];
extern u32 DWChttpignoreca;

void ReleaseHttp(Http *a);
void DWCi_Http_Thread(void *argument);
u32 SleepUnlessHttpAborted(Http *http);
void DWC_Http_Abort(Http *http);
void DWC_Http_StartThread(Http *http);
u32 DWC_Http_FinishHeader(Http *http);
s32 DWC_Http_Create(Http *http, const DWCHttpParam *param);
