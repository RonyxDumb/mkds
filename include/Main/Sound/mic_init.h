#pragma once

#include "types.h"
#include "Main/Sound/mic_buffer_sleep.h" // MicBuffer
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

#define MICROPHONE_AUTO_SAMPLING_RATE 0x105d

void InitMicAndAmp(void);
void SetupMicAutoSampling(MicBuffer *micBuffer);

extern u32 gMicInitialized;
