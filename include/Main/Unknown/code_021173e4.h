#pragma once

#include "types.h"

void WriteSelectCupGridRegisters(void);
void func_021185ec(void);
// Sets up the screen for the cup at mIndex: draws the cup, writes the four messages of the cup
// (a_0123456789Abcdefghijkl[mIndex]) into the cells, shows the record cells of mode 0 and asks for the cup
// picture; called at SPM_LoadCupSelectionMenu and again by AdvanceSelectCupGridIndexChange.
void UpdateCourseNames(void);
// Asks for the cup picture of the course that mShownCourseIndex selects and sets mCupPicturePending;
// AdvanceSelectCupGrid queues the picture data when it is ready.
void UpdateCoursePicture(void);
void UpdateSelectCupGridCupCells(void);
void LoadCupSelectionMenuOAM(void);
void RefreshSelectCupGridCupsEnabled(void);
