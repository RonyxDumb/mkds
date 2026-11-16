#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void WriteSelectCupGridRegisters(void);
void SetCupFromSelectCupGrid(void);
// Sets up the screen for the cup at mIndex: draws the cup, writes the four messages of the cup
// (gSelectCupGridCupMessageIndices[mIndex]) into the cells, shows the record cells of mode 0 and asks for the cup
// picture; called at InitSelectCupGrid and again by AdvanceSelectCupGridIndexChange.
void SetupSelectCupGridIndex(void);
// Asks for the cup picture of the course that mShownCourseIndex selects and sets mCupPicturePending;
// AdvanceSelectCupGrid queues the picture data when it is ready.
void RequestSelectCupGridCupPicture(void);
void UpdateSelectCupGridCupCells(void);
void InitSelectCupGridCells(void);
void RefreshSelectCupGridCupsEnabled(void);

// Advances the cup chooser by one step: takes mNextState as mState, runs the handler of that state
// (AdvanceSelectCupGridWaitFade to AdvanceSelectCupGridSlideOut), then updates the cells and the draw lists; returns
// mResult once SlideOut has run for 10 steps, else 0.
s32 AdvanceSelectCupGrid(void);
// Slides the cups out over 10 steps (mStateFrames counts the calls); AdvanceSelectCupGrid returns mResult after the
// tenth.
void AdvanceSelectCupGridSlideOut(void);
// Waits for the answer to the CheckZetaInvokeBeta message: answers -1 and 0 go back to Choose, answer 1 sets mResult to 3 and
// requests SlideOut.
void AdvanceSelectCupGridWaitExitAnswer(void);
// Runs AdvanceSelectCupGridShownCourse; when GetSelectChoisesDone returns non-zero it requests WaitExitAnswer (and
// plays sound 0xf for answer 1 when the flag at 0x027ffc40 is 2).
void AdvanceSelectCupGridWaitExitChoices(void);

// Runs AdvanceSelectCupGridShownCourse and waits until IsSelectChoisesChooseNoRequest returns non-zero (after the
// request of WaitExitOpen, RequestSelectCupGridWaitExitOpen, opened a message with StartSelectChoises), then requests
// WaitExitChoices.
void AdvanceSelectCupGridWaitExitOpen(void);

// Waits for the answer to the confirmation message: answer 0 stores the choice, sets mResult to 1 and requests
// SlideOut; answers -1 and 1 go back to Choose.
void AdvanceSelectCupGridWaitConfirmAnswer(void);

// Runs AdvanceSelectCupGridShownCourse and waits until GetSelectChoisesDone returns non-zero, then requests
// WaitConfirmAnswer.
void AdvanceSelectCupGridWaitConfirmChoices(void);
// Runs AdvanceSelectCupGridShownCourse and waits until IsSelectChoisesChooseNoRequest returns non-zero (after the
// request of WaitConfirmOpen, RequestSelectCupGridWaitConfirmOpen, opened a message with StartSelectChoises), then
// requests WaitConfirmChoices.
void AdvanceSelectCupGridWaitConfirmOpen(void);

// Waits 10 steps after the cup was chosen; in mode 0 it then requests WaitConfirmOpen, otherwise it stores the
// choice, sets mResult to 1 and requests SlideOut.
void AdvanceSelectCupGridWaitChosen(void);
// Reads the touch rectangles and the keys: the CheckZetaInvokeBeta input ends the screen with mResult 2 (in modes 2 to 4 it first
// opens the message of WaitExitOpen when g_GlobalB488.mMenuEntryKind is 2 or 3), choosing an enabled cup requests
// WaitChosen, touching a disabled cup plays the error sound, and a direction key moves mIndex to the neighbour cup
// when that cup is enabled.
void AdvanceSelectCupGridChoose(void);

// Waits until IsSelectReturnShownNoRequest returns non-zero, then requests Choose.
void AdvanceSelectCupGridWaitReturn(void);

// Slides the cups in over 10 steps (mStateFrames counts the calls), then requests WaitReturn.
void AdvanceSelectCupGridSlideIn(void);

// Waits until Bright_IsBothScreensFadedIn returns non-zero, then requests SlideIn (the first state after InitSelectCupGrid:
// mState is 0 from the allocation).
void AdvanceSelectCupGridWaitFade(void);

void RequestSelectCupGridWaitExitAnswer(void);
// Requests SlideOut: stores mNextState = SELECT_CUP_GRID_STATE_SLIDE_OUT and zeroes mStateFrames; the next
// AdvanceSelectCupGrid call copies it to mState and runs AdvanceSelectCupGridSlideOut.
void RequestSelectCupGridSlideOut(void);
// Builds the cup chooser: makes its heap and object, loads the cup files, builds the cells and sets the first state. a
// is the parent heap, d the mode (0, 1 or 2 to 4 by the screen that opened it).
void InitSelectCupGrid(void *heap, void *mainOam, void *subOam, s32 mode);
// Releases the cup chooser: writes the layer enable bits 0x1800 of the display control register when mResult is 2 (or 1
// in mode 0), releases the file helpers, destroys the heap and clears gSelectCupGrid.
void ReleaseSelectCupGrid(void);

void RequestSelectCupGridWaitExitChoices(void);

void RequestSelectCupGridWaitExitOpen(void);
void RequestSelectCupGridWaitConfirmAnswer(void);

void RequestSelectCupGridWaitConfirmChoices(void);

// Advances the cell slide that follows a change of mIndex: restarts mIndexChangeTimer at 7 when mIndex differs from
// mShownIndex, rebuilds the cells at 7 (SetupSelectCupGridIndex) and moves them while it counts down to 0.
void AdvanceSelectCupGridIndexChange(void);
void UpdateSelectCupGridCourseCells(void);
// Counts the calls of the handlers; every 0x4b calls it shows the next of the four courses of the cup: steps
// mShownCourseIndex (wrapping at 4), zeroes mShownCourseFrames and requests the cup picture.
void AdvanceSelectCupGridShownCourse(void);
// Starts the course cycle of the shown cup again: mShownCourseIndex and mShownCourseFrames back to 0.
void ResetSelectCupGridShownCourse(void);
void RequestSelectCupGridWaitFade(void);
// Requests SlideIn: stores mNextState = SELECT_CUP_GRID_STATE_SLIDE_IN and zeroes mStateFrames; the next
// AdvanceSelectCupGrid call copies it to mState and runs AdvanceSelectCupGridSlideIn.
void RequestSelectCupGridSlideIn(void);
void RequestSelectCupGridWaitReturn(void);
// Requests Choose: stores mNextState = SELECT_CUP_GRID_STATE_CHOOSE and zeroes mStateFrames; the next
// AdvanceSelectCupGrid call copies it to mState and runs AdvanceSelectCupGridChoose.
void RequestSelectCupGridChoose(void);
void RequestSelectCupGridWaitChosen(void);
void RequestSelectCupGridWaitConfirmOpen(void);

// Returns 1 while the cell slide that follows a change of mIndex is running (mIndexChangeTimer is non-zero), else 0;
// changes nothing.
u32 IsSelectCupGridIndexChangeRunning(void);

extern char *gSelectCupGridMBNclrName;
extern const u16 gSelectCupGridCupMessageIndices[8][4];
extern const s32 gSelectCupGridRecordEngineClasses[4];
extern const s16 gSelectCupGridRightOffsets[8];
extern const s16 gSelectCupGridLeftOffsets[8];
extern const u32 gSelectCupGridFirstCourseIds[8];
extern const u32 gSelectCupGridMirrorFlagIndices[8];
extern const u16 gSelectCupGridCourseLabelHeights[4];
extern const u32 gSelectCupGridRectCupIndices[8];
extern const u16 gSelectCupGridCourseLabelCells[4];
extern char *gSelectCupGridSNcerName;
extern const u16 gSelectCupGridRecordCells[8];
extern const u16 gSelectCupGridCourseLabelWidths[4];
extern const s16 gSelectCupGridDownOffsets[8];
extern char *gSelectCupGridMNcgrName;
extern const u16 gSelectCupGridTrophyCells[4];
extern const u32 gSelectCupGridEngineSlots[3];
extern char *gSelectCupGridSBnclName;
extern char *gSelectCupGridMBNcgrName;
extern char *gSelectCupGridMBnllName;
extern char *gSelectCupGridMNscrName;
extern char *gSelectCupGridMONclrName;
extern const s16 gSelectCupGridUpOffsets[8];
extern char *gSelectCupGridSONclrName;
extern const u32 gSelectCupGridEngineFlagIndices[8][3];
extern const u32 gSelectCupGridCupIndices[8];
extern char *gSelectCupGridSBnblName;
extern const u32 gSelectCupGridIndicesByCup[8];
extern const u16 gSelectCupGridCourseLabelIndices[4];
extern char *gSelectCupGridMNcerName;
extern char *gSelectCupGridSNcgrName;
extern const u32 gSelectCupGridRecordCellSlots[8];
extern char *gSelectCupGridMBnclName;

// Pointer to the cup chooser object: set by InitSelectCupGrid, cleared by ReleaseSelectCupGrid.
extern struct SelectCupGrid *gSelectCupGrid;

extern const u16 gSelectCupGridCupCellIndices[8][6];
extern const u32 gSelectCupGridCourseIds[8][4];
