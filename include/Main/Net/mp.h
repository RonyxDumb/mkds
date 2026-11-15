#pragma once

#include "types.h"

void UpdateMPWaitRequestDone(void *stateObject);
void EnterMPWaitRequestDone(void *stateObject);
void UpdateMPLoadCourseSound(void *stateObject);
void EnterMPLoadCourseSound(void *stateObject);
void LoadCourseSoundSetCallback(void);
void UpdateMPWaitRaceArchives(void *stateObject);
void EnterMPWaitRaceArchives(void *stateObject);
u32 AdvanceRaceArchives(void);
void RequestMPWaitMenuArchives(void);
void RequestMPWaitResultArchives(void);
void RequestMPWaitRaceArchives(void *courseId, void *mode);
u32 AdvanceMainAndMenuDLArchives(void);
s32 AdvanceChildArchiveSync(s32 archiveKind, void *courseId, void *mode);
s32 AdvanceParentSync(void);
s32 IsAllMPChildSharedDataCopied(void);
void StoreReceivedPlayerNameByState(const void *data, u8 aid, s32 playerIndex, s32 keepMask);
void InitMPChunkBuffers(void *heap);
