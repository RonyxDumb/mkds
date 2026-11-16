#pragma once

#include "types.h"

enum {
    SELECT_CUP_COURSE_STATE_WAIT_FADE,
    SELECT_CUP_COURSE_STATE_SLIDE_IN,
    SELECT_CUP_COURSE_STATE_WAIT_RETURN,
    SELECT_CUP_COURSE_STATE_PICK_COURSE,
    SELECT_CUP_COURSE_STATE_CONFIRM_PICK,
    SELECT_CUP_COURSE_STATE_WAIT_CHOICES,
    SELECT_CUP_COURSE_STATE_CHOOSE,
    SELECT_CUP_COURSE_STATE_CLOSE_CHOICES,
    SELECT_CUP_COURSE_STATE_SLIDE_OUT,
};

void AdvanceSelectCupCourseWaitReturn(void);

void AdvanceSelectCupCourseSlideIn(void);

void AdvanceSelectCupCourseWaitFade(void);

void RequestSelectCupCourseCloseChoices(void);
void RequestSelectCupCourseSlideOut(void);
void InitSelectCupCourse(void *parentHeap, void *mainOam, void *subOam, s32 mode);
void ReleaseSelectCupCourse(void);

void RequestSelectCupCourseChoose(void);

void AdvanceSelectCupCourseIndexChange(void);
void RequestSelectCupCourseWaitFade(void);
void RequestSelectCupCourseSlideIn(void);
void RequestSelectCupCourseWaitReturn(void);
void RequestSelectCupCoursePickCourse(void);
void RequestSelectCupCourseWaitPicked(void);
void RequestSelectCupCourseWaitChoices(void);

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
