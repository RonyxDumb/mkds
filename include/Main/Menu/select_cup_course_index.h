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

extern char *gSelectCupMNcgrName;
extern char *gSelectCupCourseMONclrName;
extern char *gSelectCupMBnllName;
extern char *gSelectCupCourseTaMBNcgrName;
extern const u16 gSelectCupCourseLabelCells[4];
extern const s16 gCupCourseIndicesByCourse[56];
extern char *gSelectCupMNcerName;
extern const s16 gSelectCupCourseRectCourseIndices[4];
extern char *gSelectCupCourseTaMBnllName2;
extern char *gSelectCupCourseVsMNscrName;
extern char *gSelectCupCourseVsMBnclName;
extern char *gSelectCupMBnclName;
extern char *gSelectCupCourseVsMBNclrName;
extern char *gSelectCupCourseCupMBnblName;
extern const u16 gSelectCupCourseRecordCells[8];
extern char *gSelectCupMBNcgrName;
extern const u16 gCupCourseNameMessageIndices[8][4];
extern char *gSelectCupCourseMNcgrName;
extern const u16 gSelectCupCourseTrophyCells[4];
extern char *gSelectCupCourseTaMBNclrName;
extern char *gSelectCupCourseTaMNscrName;
extern const u16 gSelectCupCourseLabelIndices[4];
extern char *gSelectCupCourseVsMBnllName;
extern char *gSelectCupMONclrName;
extern const u32 gCupRowsByCupIndex[8];
extern const u16 gSelectCupCourseLabelHeights[4];
extern char *gSelectCupMNscrName;
extern const u16 gSelectCupCourseLabelWidths[4];
extern char *gSelectCupCourseMNcerName2;
extern const u16 gCupCourseGhostMessageIndices[8][4];
extern char *gSelectCupMBNclrName;
extern char *gSelectCupCourseTaMBnclName2;
extern const u32 gCupRowCourseIds[8][4];
extern char *gSelectCupCourseVsMBNcgrName;
