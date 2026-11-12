#pragma once

#include "types.h"

u8 *GetEmblemRecordBytes(void);
u16 *GetEmblemSBPalette(void);
void AdvanceEmblemDisplayWrapper(void);
BOOL AdvanceEmblemAndCheckDone(void);
void InitEmblemAndAdvanceKartList(void);

extern const s32 gEmblemLPressButtonCursorIndices[4];
extern const s32 gEmblemSubBg3AffineMatrix[4];
extern const s32 gEmblemButtonLldEntries[12];
extern const s32 gEmblemTemplateScreenColorEntries[16];
extern const s32 gEmblemRPressButtonCursorIndices[4];
// Objects whose layout isn't known yet.
extern const s32 gEmblemColorLldEntries[16];
extern const s32 gEmblemTemplateLldEntries[29];
extern const s32 gEmblemButtonCursorVerticalMoves[3][12];
extern const s32 gEmblemButtonCursorHorizontalMoves[3][12];
extern const s32 gEmblemColorCursorVerticalMoves[3][16];
extern const s32 gEmblemColorCursorHorizontalMoves[3][16];
extern const s32 gEmblemTemplateCursorVerticalMoves[3][29];
extern const s32 gEmblemTemplateCursorHorizontalMoves[3][29];
