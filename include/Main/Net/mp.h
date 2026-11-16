#pragma once

#include "types.h"

void StructZE_E7Fn_20_2_from_thumb(void *stateObject);
void StructZE_E7Fn_20_1_from_thumb(void *stateObject);
void StructZE_E7Fn_17_2_from_thumb(void *stateObject);
void StructZE_E7Fn_17_1_from_thumb(void *stateObject);
void LoadCourseSoundSetCallback(void);
void StructZE_E7Fn_16_2_from_thumb(void *stateObject);
void StructZE_E7Fn_16_1_from_thumb(void *stateObject);
u32 AdvanceRaceArchives(void);
void RequestMPWaitMenuArchives(void);
void RequestMPWaitResultArchives(void);
void RequestMPWaitRaceArchives(void *courseId, void *mode);
u32 AdvanceMainAndMenuDLArchives(void);
// First argument of AdvanceChildArchiveSync: which archive set the child requests and waits for.
enum {
    MP_ARCHIVE_KIND_MAIN_AND_MENU = 0,
    MP_ARCHIVE_KIND_RACE = 1,
    MP_ARCHIVE_KIND_RESULT = 2,
    MP_ARCHIVE_KIND_MENU = 3,
};
s32 AdvanceChildArchiveSync(s32 archiveKind, void *courseId, void *mode);
s32 AdvanceParentSync(void);
s32 IsAllMPChildSharedDataCopied(void);
void StoreReceivedPlayerNameByState(const void *data, u8 aid, s32 playerIndex, s32 keepMask);
void AllocateSomeZEStuff_from_thumb(void *heap);
