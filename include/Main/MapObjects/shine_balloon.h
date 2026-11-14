#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h" // Kart
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h" // MapObject
#include "01/MapObjects/data_0209bc74.h"

// ShineBalloonObject.mState values: HIDDEN waits until the kart has a balloon, APPEAR and DISAPPEAR pulse the scale,
// SHOWN follows the kart until its balloons are gone.
enum {
    SHINE_BALLOON_STATE_HIDDEN,
    SHINE_BALLOON_STATE_APPEAR,
    SHINE_BALLOON_STATE_SHOWN,
    SHINE_BALLOON_STATE_DISAPPEAR,
};

// Object of the list FindMapObjectKindUpdateList(0x70): the shared MapObject part, then the words and the pointer
// StartShineBalloon sets.
typedef struct ShineBalloonObject {
    /* 00 */ MapObject mMapObject;
    /* a0 */ s32 mPulseScale;
    /* a4 */ s32 mPulseScaleSpeed;
    /* a8 */ s32 mTimer;
    /* ac */ Kart *mKart;
    /* b0 */ s32 mState;
} ShineBalloonObject;

void *FindParkedMapObject(s32 kind);
void CreateParkedMapObjects(u32 kind, s32 count, void *object);
void StartShineBalloon(Kart *kart);
MapObjectList *CreateShineBalloonUpdateList(void);
MapObjectList *CreateShineBalloonDrawList(void);

MapObjectKindData *CreateShineBalloonKindData(void);

/* skipped for objects with mFlags & 4 (parked pool objects) */
void UpdateShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject);
void DrawShineBalloon(void *mapObjectList, ShineBalloonObject *shineBalloonObject);
void SetupDrawShineBalloon(void *mapObjectList);
void CreateShineBalloon(void *mapObjectList);

/* creates the pooled object hidden (parks it with ParkMapObject); the spawner later takes it with
 * UnparkFirstParkedMapObject */
void InitShineBalloon(u32 mapObjectArg);

extern const u16 gShineBalloonEndSecondFlag;
extern const u16 gShineBalloonEndFlag;
extern struct MapObjectModel *gShineBalloon;
