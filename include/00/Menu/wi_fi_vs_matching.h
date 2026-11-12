#pragma once

#include "types.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Save/emblem_block.h"

#include "Main/Graphics/nibble_tiles.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_02108a40.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"

#include "Main/Menu/player_entry_list.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/message_screen.h"
#include "code_0212df7c.h"
#include "Main/Scene/display_settings.h"

void InitWiFiVSMatching(void *heap);

#include "00/Scene/wi_fi_menu_scene.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "00/Lib/DWC/code_0219b580.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Kart/karts.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry
#include "gfd_VramTransferManager.h"

extern MenuShared *gMenuShared;
extern WiFiSession *gWiFiSession;
extern u8 gWiFiVSMatchingBlendColorOffsets[2];
extern u8 gWiFiVSMatchingOtherCellIndices[3];
extern u8 gWiFiVSMatchingSearchLabelIndices[3];
extern u8 gWiFiVSMatchingNameLabelIndices[3];
extern u8 gWiFiVSMatchingEmblemCellIndices[3];
extern s32 gWiFiVSMatchingResultWaitFrames[3];
extern s8 gWiFiVSMatchingNameSlideOffsets[30];
extern u8 gWiFiVSMatchingTotalScalePercents[30];
extern u8 gWiFiVSMatchingEmblemScalePercents[40];
extern char gWiFiBmgName2[];
extern char gCommonBmgName4[];

void WriteWiFiVSMatchingRegisters(void);
void UpdateWiFiVSMatchingPaletteBlend(void);
void SetWiFiVSMatchingBlendedColors(s32 weight);
void UpdateWiFiVSMatchingOffsets(void);
void AdvanceWiFiVSMatchingState11(void);
void AdvanceWiFiVSMatchingState10(void);
void AdvanceWiFiVSMatchingState9(void);
void AdvanceWiFiVSMatchingState8(void);
void AdvanceWiFiVSMatchingState5(void);
void AdvanceWiFiVSMatchingState4(void);
void AdvanceWiFiVSMatchingState3(void);
void AdvanceWiFiVSMatchingState2(void);
void AdvanceWiFiVSMatchingState1(void);
void AdvanceWiFiVSMatchingState0(void);
void PrintWiFiVSMatchingNoOpponents(void);
void LocateAndQueueWiFiVSMatching(void);
void ReleaseWiFiVSMatching(void);
void InitWiFiVSMatchingEntryMatrices(void);
void InitWiFiVSMatchingLabels(void);
