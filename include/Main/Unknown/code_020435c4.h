#pragma once

#include "types.h"

// The pair of input bits the item code tests to use the held item.
#define ITEM_BITS 0x600
// Item input bit held while the item is used: the held item is thrown in front of the kart.
#define ITEM_THROW_FORWARD_BIT 0x40

typedef struct MissionFileRow MissionFileRow;

u32 input_getIsResetInvoked(void);
void input_setFlagsBit0(u32 openDuringRace);
void input_pressVirtualPadKeys(s32 slotIndex, u32 bits);
void input_update(void);
unsigned int input_getPressedKeys(void);
void input_sample(void);
void input_setMirrorMode(u32 mirrorMode);
void input_finalize(void);
void input_2043AE0(void);
void input_clearPads(void);
void input_stopTouchAutoSampling(void);
void input_2043B48(void);
void input_initUnits(void);
void input_init(void *heap);
void rconf_loadCharacterSounds(u32 a);
void sub_2043FB0(u32 courseId);
void LoadStaffGhost(u32 courseId);
void func_0204419c(u32 courseId, u32 b);
void func_020442d0(u32 courseId);
void rconf_setupMissionRace(MissionFileRow *missionFileRow, u32 tableRow, u32 tableColumn);
void sub_204451C(u32 entryIndex);
