#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject

// Object of the list FindMapObjectKindUpdateList(0x70): the shared MapObject part, then the words and the pointer
// StartShineBalloon sets.
typedef struct ShineBalloonObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mTimer;
    /* ac */ Kart *mUnk_ac;
    /* b0 */ s32 mState;
} ShineBalloonObject;

void *FindParkedMapObject(s32 kind);
void CreateParkedMapObjects(u32 kind, s32 count, void *object);
void StartShineBalloon(Kart *kart);
void *CreateShineBalloonUpdateList(void);
void *CreateShineBalloonDrawList(void);

void CreateShineBalloonKindData(void);

/* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject);
void DrawShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject);
void SetupDrawShineBalloon(void *mapObjectList);
void CreateShineBalloon(void *mapObjectList);

/* creates the pooled object hidden (parks it with ParkMapObject); the spawner later takes it with
 * UnparkFirstParkedMapObject */
void InitShineBalloon(u32 mapObjectArg);
