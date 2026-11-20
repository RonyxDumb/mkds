#pragma once

#include "types.h"

// Blend coefficients of the menu: the weight of the first plane and of the second plane, out of 16 (6 and 10); the menu
// setup and release write them to the blend registers and the text system starts mBlendEv1 and mBlendEv2 with them.
#define MENU_BLEND_FIRST_COEFFICIENT 6
#define MENU_BLEND_SECOND_COEFFICIENT 10

void MenuWriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient);
void WriteMainBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient);
void SetUnfilledNotEliminated(unsigned int value);
void SetMenuEntryKind(unsigned int entryKind);

// Values of MenuShared.mMenuEntryKind: InitMenu switches on it to pick the screen the menu opens on. The race scene
// sets it for the way back from a race and some screens set it before they leave the menu; screens clear it to 0 once
// it is used, and the cup grid, the battle stage screen and SetNextRaceSetupFromCopy test it.
typedef enum MenuEntryKind {
    MENU_ENTRY_SINGLE_PLAY_SELECT = 0,
    // The select character screen of the race mode.
    MENU_ENTRY_CHARACTER_SELECT = 1,
    // The course picking screen of the race mode: cup grid (versus, time attack) or battle stage.
    MENU_ENTRY_COURSE_SELECT = 2,
    // The mission run level select when GetUnfilledNotEliminated or GetLVselIndex6Requested is non-zero, else the
    // mission select.
    MENU_ENTRY_MISSION_SELECT = 3,
    MENU_ENTRY_SELECT_GAME = 4,
    MENU_ENTRY_TIME_ATTACK_TOP_MENU = 5,
} MenuEntryKind;
