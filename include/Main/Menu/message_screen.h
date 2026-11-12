#pragma once

#include "types.h"
#include "Main/Menu/data_0217d000.h"

void SetLinkLevelIconEnabled(u32 index, u32 enabled);
void InitLinkLevelIcons(void *heap, void *oamList);
void OpenMessageScreen(s32 messageKind, s32 inputEnabled);
void FormatMessageScreenErrorCode(void);
void PrintMessageScreenText(void);
void *GetMessageScreenText(void);
void ClearMessageScreenMap(void);
void *GetMessageScreenCharBuffer(void);

void SetupLinkLevelIcons(void);
void UpdateLinkLevelIconTiles(void);
void AdvanceLinkLevelIcons(void);

void ClearLinkLevelIconsPointer(void);

void ClearMessageScreenChars(void);

s32 UpdateMessageScreen(void);
void ResetMessageScreen(void);
void InitMessageScreen(void *heap);

extern const u8 gLinkLevelIconSlotCellEntryIndices[4];
extern const u8 gLinkLevelIconCharCounts[8];
extern const u8 gLinkLevelIconCharCellEntryIndices[5][4];
extern struct LinkLevelIcons *gLinkLevelIcons;
extern struct MessageScreen *gMessageScreen;
