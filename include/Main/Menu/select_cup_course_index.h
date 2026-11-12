#pragma once

#include "types.h"

void AdvanceSelectCupCourseState2(void);

void AdvanceSelectCupCourseState1(void);

void AdvanceSelectCupCourseState0(void);

void RequestSelectCupCourseState7(void);
void RequestSelectCupCourseState8(void);
void InitSelectCupCourse(void *parentHeap, void *mainOam, void *subOam, s32 mode);
void ReleaseSelectCupCourse(void);

void RequestSelectCupCourseState6(void);

void AdvanceSelectCupCourseIndexChange(void);
void RequestSelectCupCourseState0(void);
void RequestSelectCupCourseState1(void);
void RequestSelectCupCourseState2(void);
void RequestSelectCupCourseState3(void);
void RequestSelectCupCourseState4(void);
void RequestSelectCupCourseState5(void);

u32 IsSelectCupCourseIndexChangeRunning(void);
