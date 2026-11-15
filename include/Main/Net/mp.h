#pragma once

#include "types.h"

void UpdateMPState20(void *stateObject);
void EnterMPState20(void *stateObject);
void UpdateMPState17(void *stateObject);
void EnterMPState17(void *stateObject);
void LoadCourseSoundSetCallback(void);
void UpdateMPState16(void *stateObject);
void EnterMPState16(void *stateObject);
u32 AdvanceRaceArchives(void);
void RequestMPState21(void);
void RequestMPState18(void);
void RequestMPState16(void *courseId, void *mode);
u32 AdvanceMainAndMenuDLArchives(void);
s32 AdvanceChildArchiveSync(s32 archiveKind, void *courseId, void *mode);
s32 AdvanceParentSync(void);
s32 IsAllMPChildSharedDataCopied(void);
void StoreReceivedPlayerNameByState(const void *data, u8 aid, s32 playerIndex, s32 keepMask);
void InitMPChunkBuffers(void *heap);
