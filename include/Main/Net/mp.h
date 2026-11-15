#pragma once

#include "types.h"

void UpdateMPState20(void);
void EnterMPState20(void);
void UpdateMPState17(void);
void EnterMPState17(void);
void LoadCourseSoundSetCallback(void);
void UpdateMPState16(void);
void EnterMPState16(void);
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
