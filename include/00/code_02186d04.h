#pragma once

#include "types.h"
#include "os_thread.h"

#include "00/code_02185954.h"

extern char data_ov000_021b1204[];
extern char gContentLengthHeaderText[];
extern char data_ov000_021b135c[];
extern char data_ov000_021b1368[];
extern const char data_ov000_021b1370[];
extern char data_ov000_021b1374[];
extern u32 DWChttpignoreca;

void ReleaseHttp(Http *a);
void DWCi_Http_Thread(void *argument);
u32 SleepUnlessHttpAborted(Http *http);
void DWC_Http_Abort(Http *http);
void DWC_Http_StartThread(Http *http);
u32 DWC_Http_FinishHeader(Http *http);
s32 DWC_Http_Create(Http *http, const DWCHttpParam *param);
