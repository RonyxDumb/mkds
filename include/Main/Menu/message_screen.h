#pragma once

#include "types.h"
#include "Main/Menu/menu_screens_work.h"

void SetLinkLevelIconEnabled(u32 index, u32 enabled);
void CreateGlobalNN_from_thumb(void *heap, void *oamList);
void DisplayMultiplayError_from_thumb(s32 messageKind, s32 inputEnabled);
void MaybeFormatMultiplayNetErrorCode_from_thumb(void);
void DrawMultiplayError_from_thumb(void);
void *GetMultiplayerErrorString_from_thumb(void);
void CleanTemporaryMultiplayErrorBuffer_from_thumb(void);
void *GetSomeBgCanvasTileData_from_thumb(void);

void SetupLinkLevelIcons(void);
void UpdateLinkLevelIconTiles(void);
void AdvanceLinkLevelIcons(void);

void ResetGlobalNN_from_thumb(void);

void Clear1A44SomeTileData_from_thumb(void);

s32 UpdateMessageScreen(void);
void ResetMultiplayErrors_from_thumb(void);
void InitializeGlobal1A44_from_thumb(void *heap);

extern const u8 gLinkLevelIconSlotCellEntryIndices[4];
extern const u8 gLinkLevelIconCharCounts[8];
extern const u8 gLinkLevelIconCharCellEntryIndices[5][4];
extern struct LinkLevelIcons *g_GlobalNN;
extern struct MessageScreen *g_Global1A44;

extern char g_str_common_bmg_7[11];
