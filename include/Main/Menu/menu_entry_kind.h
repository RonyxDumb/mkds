#pragma once

#include "types.h"

// Blend coefficients of the menu text: the weight of the first and of the second target, out of 16.
#define MENU_BLEND_FIRST_COEFFICIENT 6
#define MENU_BLEND_SECOND_COEFFICIENT 10

void MenuWriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient);
void WriteMainBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient);
void SetUnfilledNotEliminated(unsigned int value);
void SetMenuEntryKind(unsigned int entryKind);

// Values of MenuShared.mMenuEntryKind: which screen the menu opens on (InitMenu), set by the screens that leave the
// menu and by the race scene for the way back. The mode's screens are the ones InitMenu switches to.
typedef enum MenuEntryKind {
    MENU_ENTRY_FIRST_SCREEN = 0,
    // The select character screen of the race mode.
    MENU_ENTRY_CHARACTER_SELECT = 1,
    // The course picking screen of the race mode: cup grid (versus, time attack) or battle stage.
    MENU_ENTRY_COURSE_SELECT = 2,
    // The mission run level select, or the mission select when no level is pending.
    MENU_ENTRY_MISSION_SELECT = 3,
    MENU_ENTRY_SELECT_GAME = 4,
    MENU_ENTRY_TIME_ATTACK_TOP_MENU = 5,
} MenuEntryKind;
