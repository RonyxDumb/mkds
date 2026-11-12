#pragma once

#include "types.h"

// Data whose layout isn't known yet.
extern u16 gLinkLevelPosition[];
extern u8 gLinkLevelImages[][4];
extern u8 gEditKeyboardKeyPalettes[];
extern u8 gEditKeyboardRow4HighlightValues[];
extern u8 gEditKeyboardRow4Inputs[];
extern u16 gEditKeyboardRow4KeySize[][2];
extern u16 gEditKeyboardKeySize[][2];
extern u8 gEditKeyboardExtraKeyInputs[];
extern u16 gEditKeyboardRow4KeyPositions[][2];
extern u16 gEditKeyboardExtraKeyPositions[][2];
extern u16 gEditKeyboardPage1KeyPosition[][2];
extern u16 gEditKeyboardLastExtraKeyPositions[][2];
extern u16 gEditKeyboardExtraKeySizes[][2];
extern u16 gEditKeyboardPage1KeySize[][2];
extern u16 gEditKeyboardLastExtraKeySizes[][2];
extern u16 gEditKeyboardKeyPositions[][2];
extern u16 gEditKeyboardKeyPositionsSecond[][2];
extern u16 gEditKeyboardKeyPositionsThird[][2];
extern u16 gEditKeyboardCursorPositions[53][2];
extern s8 gEditKeyboardCursorMoves[][4];
extern u8 gEditKeyboardRow4KeyCounts[5];
extern u8 gEditKeyboardKeyCounts[5];
extern u8 gEditKeyboardExtraKeyCounts[5];
extern u8 gEditKeyboardPage0Inputs[0x30];
extern u8 gEditKeyboardPage1Inputs[0x30];
extern u8 gEditKeyboardPage2Inputs[0x30];
extern u8 *gEditKeyboardPageInputs[3];
extern u32 gEditKeyboardExtraKeySoundSeqs[];
