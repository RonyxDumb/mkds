#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h" // Unk020e0764
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8

extern Unk020e0764 data_0216b8c4;
extern Unk020e0764 data_0216b8ec;
extern UnkFunc *kuribo_sStates[];
extern UnkFunc *efbub_sStates[];
extern UnkFunc *kblock_sStates[];

// Objects whose layout isn't known yet.
extern const char aKuribo_nsbmd[];
extern const char aKuribo_nsbtp[];
extern const char aEarthen_pipe1_[];
extern const char aEarthen_pipe2_[];

extern u8 *mobj_sDriverHitResponseTable[][4];
extern u8 *mobj_sDriverHitObjResponseTable[][4];
extern u8 *mobj_sItemHitResponseTable[][14];
extern u8 *mobj_sItemHitObjResponseTable[][14];
