#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void AdvanceSelectCupCoursePickCourse(void);
void AdvanceSelectCupCourseConfirmPick(void);
void AdvanceSelectCupCourseWaitChoices(void);
void AdvanceSelectCupCourseChoose(void);
void AdvanceSelectCupCourseCloseChoices(void);
void AdvanceSelectCupCourseSlideOut(void);
s32 AdvanceSelectCupCourse(void);
void WriteSelectCupCourseBgOffsets(void);
void VerifySelectCupFiles_from_thumb(void);
void LocateAndQueueSelectCupGrid(void);
// Returns whether cup a can be chosen in the current mode: the cups 0, 1, 4 and 5 always (mode 3 only 0 and 4), the
// others by the result of CheckSavedSecretFlag_from_thumb (CheckSecretFlag in mode 4) for the flag of that cup; changes
// nothing.
u32 GetSelectCupGridCupEnabled(u32 cupIndex);

extern struct SelectCupCourse *gSelectCupCourse;
