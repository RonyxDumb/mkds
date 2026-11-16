#pragma once

#include "types.h"
#include "Main/Sound/mic_buffer_sleep.h" // MicBuffer
#include "sound_player_control.h"
#include "sound_player_type.h" // NNSSndPlayer
#include "sound_stream_control.h" // NNSSndStrmChannel
#include "sound_capture_effect.h" // CaptureParam, EffectInfo
#include "Main/Graphics/layout_rect_table.h" // LayoutEntryTable
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h" // RaceHudOamBuffer
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h" // SoundHandlePool

// MICAutoParam.mRate of the microphone buffer: the ARM7 clock (33,513,982 Hz) divided by 8000 samples per second.
#define MICROPHONE_AUTO_SAMPLING_RATE 0x105d

void InitializeBalloonHardware(void);
void Struct59C4Sub_Initialize(MicBuffer *micBuffer);

extern u32 g_BalloonHardwareInit;
