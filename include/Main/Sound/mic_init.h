#pragma once

#include "types.h"
#include "Main/Sound/mic_buffer_sleep.h" // MicBuffer
#include "player.h"
#include "code_0212c7a0.h" // NNSSndPlayer
#include "stream.h" // NNSSndStrmChannel
#include "code_0212c9d4.h" // CaptureParam, EffectInfo
#include "Main/Graphics/layout_rect_table.h" // LayoutEntryTable
#include "Main/Graphics/layout_entry_angle.h" // LayoutTableEntry
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h" // RaceHudOamBuffer
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h" // SoundHandlePool

// MICAutoParam.mRate of the microphone buffer: the ARM7 clock (33,513,982 Hz) divided by 8000 samples per second.
#define MIC_AUTO_SAMPLING_RATE 0x105d

void InitMicAndAmp(void);
void SetupMicAutoSampling(MicBuffer *micBuffer);

extern u32 gMicInitialized;
