#pragma once

#include "types.h"
#include "os_thread.h"

#include "00/Lib/DWC/code_02185954.h"

extern char gCaInfoTable[];
extern char gContentLengthHeaderText[];
extern char gConnectionHeaderName[];
extern char gConnectionCloseValue[];
extern const char gContentLengthFormat[];
extern char gContentLengthHeaderName[];
extern u32 DWChttpignoreca;

void ReleaseHttp(Http *a);
void DWCi_Http_Thread(void *argument);
u32 SleepUnlessHttpAborted(Http *http);
void DWC_Http_Abort(Http *http);
void DWC_Http_StartThread(Http *http);
u32 DWC_Http_FinishHeader(Http *http);
s32 DWC_Http_Create(Http *http, const DWCHttpParam *param);
