#pragma once

#include "types.h"
#include "os_thread.h"

#include "00/Lib/DWC/code_02185954.h"
#include "00/Lib/DWC/ca_info_021b1490.h"
#include "00/Lib/DWC/ca_info_021b15dc.h"
#include "00/Lib/DWC/ca_info_021b172c.h"
#include "00/Lib/DWC/ca_info_021b1814.h"
#include "00/Lib/DWC/ca_info_021b18d8.h"
#include "00/Lib/DWC/ca_info_021b19c0.h"
#include "00/Lib/DWC/ca_info_021b1ae0.h"
#include "00/Lib/DWC/ca_info_021b1bf8.h"
#include "00/Lib/DWC/ca_info_021b1d24.h"
#include "00/Lib/DWC/ca_info_021b1ed8.h"
#include "00/Lib/DWC/ca_info_021b1fb4.h"

extern CPSCaInfo *gCaInfoTable[11];
extern u32 DWChttpignoreca;

void ReleaseHttp(Http *a);
void DWCi_Http_Thread(void *argument);
u32 SleepUnlessHttpAborted(Http *http);
void DWC_Http_Abort(Http *http);
void DWC_Http_StartThread(Http *http);
u32 DWC_Http_FinishHeader(Http *http);
s32 DWC_Http_Create(Http *http, const DWCHttpParam *param);
