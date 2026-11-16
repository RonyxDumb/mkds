#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectKindData
#include "Main/Course/MapObjectModel.h"
#include "Main/Unknown/code_020a0028.h" // Airship

// Object of kind 0x157 (TownMonte) with the MapObject base: two halfwords at 0xa0 and 0xa2, then three words
// (tmon_update, tmon_globalInitLogic, tmon_render).
typedef struct TownMonte {
    /* 00 */ MapObject mUnk_00;
// Frame of the .nsbtp animation chosen at random by tmon_globalInitLogic; frames 0 and 1 also set mUnk_a2 to 0x1a7
// and 0x1a8.
    /* a0 */ u16 mNsbtpFrameIndex;
    /* a2 */ u16 mSoundId;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mMirror;
} TownMonte;

// Array of object pointers: pointer to the array and the number of entries (tmon_globalInitLogic).
typedef struct Unk0209f800 {
    /* 00 */ TownMonte **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209f800;

extern char aChandelier_nsb[];
extern char aChandelier_n_1[];
extern char aTownmonte_nsbm[];
extern char aTownmonte_nsbt[];
extern void *tmon_sModel;
extern MapObjectKindData *pole_sConfigs[19];

void chnd_loadModel(void *a);
void *tmon_setupLogicPart(void);
void *tmon_setupRenderPart(void);
void tmon_update(void *a, TownMonte *townMonte); /* skipped for objects with mFlags & 4 (parked pool objects) */
void tmon_globalInitLogic(Unk0209f800 *a);
void tmon_render(void *a, TownMonte *townMonte);
// The parameter is the draw group (typed MapObjectModel here); its +0x14 is the callback that runs after the group's
// draw.
void tmon_loadModel(MapObjectModel *mapObjectModel); /* also stores the hook tmon_globalPostRender in the record's +0x14 */
void tmon_globalPostRender(void);
void pole_setupConfig(void);
void pole_init(MapObject *mapObject);
void *aship_setupLogicPart(void);
void *aship_setupRenderPart(void);
void aship_update(void *a, Airship *airship); /* skipped for objects with mFlags & 4 (parked pool objects) */
