#pragma once

#include "types.h"

// Object sfx_sSoundTriggerSfxIds: five 16-byte rows of eight halfwords; sfx_handleSoundTrigger reads one halfword of a row and
// sfx_initSoundTriggers walks a row.
typedef struct Unk0216cb50 {
    /* 00 */ u16 field0[8];
} Unk0216cb50;

// Object sfx_sSoundTriggerVolumeStates: a word at 0, a word at 4 and eight bytes at 8; sfx_updateSoundTriggerVolumeContinuous, sfx_updateSoundTriggerVolumeAtStart, sfx_handleSoundTrigger
// and sfx_initSoundTriggers read the word at 0, and sfx_initSoundTriggers writes the two words.
typedef struct Unk0217d1c0 {
    /* 00 */ u32 field0;
    /* 04 */ u32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u8 fieldC;
    /* 0d */ u8 fieldD;
    /* 0e */ u8 fieldE;
    /* 0f */ u8 fieldF;
} Unk0217d1c0;

// Object data_0217d1c4: a word at 0 and twelve bytes at 4; sfx_handleSoundTrigger writes the word at 0 and sfx_updateSoundTriggerVolumeContinuous
// reads it.
typedef struct Unk0217d1c4 {
    /* 00 */ u32 field0;
    /* 04 */ u8 field4[0xc];
} Unk0217d1c4;

// Object data_0217d1c8: a word at 0 and twelve bytes at 4; sfx_handleSoundTrigger reads the word at 0.
typedef struct Unk0217d1c8 {
    /* 00 */ u32 field0;
    /* 04 */ u8 field4[0xc];
} Unk0217d1c8;

// Object data_0217d1cc: sixteen bytes; sfx_updateSoundTriggerVolumeContinuous and sfx_updateSoundTriggerVolumeAtStart read one byte of the row that the first
// word of the sfx_sSoundTriggerVolumeStates element selects.
typedef struct Unk0217d1cc {
    /* 00 */ u8 field0[0x10];
} Unk0217d1cc;

extern Unk0217d1c0 sfx_sSoundTriggerVolumeStates[];
extern Unk0217d1c4 data_0217d1c4[];
extern Unk0217d1c8 data_0217d1c8[];
extern Unk0217d1cc data_0217d1cc[];
extern Unk0217d1c0 data_0217d1d0[];
extern u32 sfx_sSoundTriggerSetId;
extern Unk0216cb50 sfx_sSoundTriggerSfxIds[5];

void sfx_initSoundTriggers(u32 a);
void sfx_handleSoundTrigger(s32 a);
u32 sfx_updateSoundTriggerVolumeAtStart(s32 a, u32 soundId);
u32 sfx_updateSoundTriggerVolumeContinuous(u32 a, u32 soundId);
