#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // DataSharing

void sub_2053E74(void);
void ResetConnectionData(void);
void ResetDataSharing(DataSharing *dataSharing);
void sub_2054330(void);
void InitConnectionBuffers(void *heap);
void InitConnection(void *heap);
s32 func_0205465c(void);
s32 StartDataSharingSync(void);
BOOL FinishDataSharingSync(void);
s32 AdvanceBlockReceive(void);
void func_02054aa0(void);
s32 AdvanceBlockCountRequest(void);
s32 AdvanceConnectionSetup(s32 isParent, void *b);
