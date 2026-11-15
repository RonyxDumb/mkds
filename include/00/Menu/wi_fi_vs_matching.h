#pragma once

#include "types.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Save/emblem_block.h"

#include "Main/Graphics/nibble_tiles.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Net/player_record.h"
#include "Main/Net/wifi_session.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/text_draw.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/palette_blend.h"

#include "Main/Menu/player_entry_list.h"
#include "Main/Menu/message_screen.h"
#include "code_0212df7c.h"
#include "Main/Scene/display_settings.h"

void InitWiFiVSMatching(void *heap);

#include "00/Scene/wi_fi_menu_scene.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/DWC/code_0219b1f8.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Kart/karts.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "code_0214cfe4.h"
#include "player.h"
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry
#include "gfd_VramTransferManager.h"

extern MenuShared *gMenuShared;
extern u8 gWiFiVSMatchingTotalScalePercents[30];
extern u8 gWiFiVSMatchingEmblemScalePercents[40];

void WriteWiFiVSMatchingRegisters(void);
void UpdateWiFiVSMatchingPaletteBlend(void);
void SetWiFiVSMatchingBlendedColors(s32 weight);
void UpdateWiFiVSMatchingOffsets(void);
void AdvanceWiFiVSMatchingWaitFadeOut(void);
void AdvanceWiFiVSMatchingSlideOut(void);
void AdvanceWiFiVSMatchingWaitNoOpponentsBack(void);
void AdvanceWiFiVSMatchingWaitResultShown(void);
void AdvanceWiFiVSMatchingPauseBetweenOthers(void);
void AdvanceWiFiVSMatchingScaleInOther(void);
void AdvanceWiFiVSMatchingWaitPlayerListText(void);
void AdvanceWiFiVSMatchingEmblemScaleIn(void);
void AdvanceWiFiVSMatchingWaitMatching(void);
void AdvanceWiFiVSMatchingSlideIn(void);
void PrintWiFiVSMatchingNoOpponents(void);
void LocateAndQueueWiFiVSMatching(void);
void ReleaseWiFiVSMatching(void);
void InitWiFiVSMatchingEntryMatrices(void);
void InitWiFiVSMatchingLabels(void);

extern const s8 gWiFiVSMatchingNameSlideOffsets[30];
extern const u8 gWiFiVSMatchingOffsetTableIndices[3][5];
extern const u8 gWiFiVSMatchingTotalCellIndices[3][2];
extern const u8 gWiFiVSMatchingNameLabelIndices[3];
extern const u8 gWiFiVSMatchingOtherCellIndices[3];
extern const u8 gWiFiVSMatchingNameCellIndices[3];
extern const u8 gWiFiVSMatchingSearchLabelIndices[3];
extern const u8 gWiFiVSMatchingTotalLabelIndices[3][2];
extern const u8 gWiFiVSMatchingBlendColorOffsets[2];
extern const u8 gWiFiVSMatchingEmblemCellIndices[3];
extern const s32 gWiFiVSMatchingResultWaitFrames[3];

extern struct WiFiVSMatching *gWiFiVSMatching;
