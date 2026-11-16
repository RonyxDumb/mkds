#pragma once

#include "types.h"
#include "code_0201c528.h"

typedef struct Vec3s16 Vec3s16;
typedef struct Kart Kart;

// 0x88 bytes. The per-Kart set of effect objects that play while the Kart holds a turn (Kart.mTurnDirection is not 0):
// a turn start group, a level 2 group and a level 3 group (started when Kart.field2FC becomes 2 and when it is 3) and a
// level 4 group (requested at the step from 3 to 4), their counters, ids and the functions that start, stop, hide, show
// and place them; two variants of the function set are installed by dptc_init.
typedef struct KartTurnEffects {
    // The two effect objects of the turn start group, one per side, started by dptc_startDustClouds and moved by
    // dptc_updateDustClouds (the level 2 advance also switches their emission); NULL when the group is not
    // present.
    /* 00 */ Unk0201ca6c *mTurnStartEffects[2];
    // The two effect objects, one per side, started when Kart.field2FC becomes 2 (id 0x7e); released when mLevel2Frames
    // passes 8; NULL when the group is not present.
    /* 08 */ Unk0201ca6c *mLevel2Effects[2];
    // First effect object per side of the level 4 group, started by the restart in dptc_updateContRedSparks after the
    // request made when Kart.field2FC is 3 (so Kart.field2FC is 4 from then on); NULL when the group is not present.
    /* 10 */ Unk0201ca6c *mLevel4FirstEffects[2];
    // Second effect object per side of the level 4 group; only started by dptc_startContRedSparksPlayer, NULL for
    // the other variant.
    /* 18 */ Unk0201ca6c *mLevel4SecondEffects[2];
    // First of the two effect objects per side started when Kart.field2FC is 3; released when mLevel3Frames passes 10.
    /* 20 */ Unk0201ca6c *mLevel3FirstEffects[2];
    // Second of the two effect objects per side of the level 3 group.
    /* 28 */ Unk0201ca6c *mLevel3SecondEffects[2];
    // Calls of dptc_updateContRedSparks since mLevel4StopRequested became TRUE; the group is reset when it passes 10.
    /* 30 */ s16 mLevel4StopFrames;
    // TRUE from dptc_208C534, when the level 4 group was present, until the next reset; dptc_updateContRedSparks
    // counts mLevel4StopFrames while it is TRUE and resets the group after 10.
    /* 34 */ BOOL mLevel4StopRequested;
    // 1 while the level 4 group exists (also while mLevel4StopRequested is TRUE).
    /* 38 */ s32 mLevel4Present;
    // 1 while the turn start group exists (mTurnStartEffects valid), else 0.
    /* 3c */ u32 mTurnStartPresent;
    // 1 while the level 3 group exists.
    /* 40 */ s32 mLevel3Present;
    // TRUE while the level 2 group exists.
    /* 44 */ BOOL mLevel2Present;
    // Calls of dptc_updateRedSparks since the level 3 group started; the group is released when it passes 10.
    /* 48 */ s16 mLevel3Frames;
    // Calls of dptc_updateBlueSparks since the level 2 group started; the group is released when it passes 8.
    /* 4a */ s16 mLevel2Frames;
    // Id of the effect started for each side of the turn start group: 0x14 for the Kart of the selected entry and for
    // every Kart in time trial or when RaceSetup.fieldC is 5, 0x15 for the others.
    /* 4c */ s32 mTurnStartEffectId;
    // Effect id of mLevel4FirstEffects: 0x11 for the Kart of the selected entry and for every Kart in time trial or
    // when RaceSetup.fieldC is 5, 0x13 for the others.
    /* 50 */ s32 mLevel4FirstEffectId;
    // Effect id of mLevel4SecondEffects: 0x12 for the Karts that use dptc_startContRedSparksPlayer, -1 for the
    // others, which never start it.
    /* 54 */ s32 mLevel4SecondEffectId;
    // Effect id of mLevel3FirstEffects (0x16 for every Kart).
    /* 58 */ s32 mLevel3FirstEffectId;
    // Effect id of mLevel3SecondEffects (0x17 for every Kart).
    /* 5c */ s32 mLevel3SecondEffectId;
    // Index of the Kart this record belongs to (the record number); written at init, never read.
    /* 60 */ u16 mIndex;
    // Calls of dptc_updateContRedSparks with Kart.field44 bit 8 set since the restart was requested; the group is
    // restarted when it passes 10.
    /* 62 */ u16 mLevel4RestartFrames;
    // 1 after dptc_208C520 (made when Kart.field2FC is 3), 0 after every reset;
    // dptc_updateContRedSparks then restarts the group once mLevel4RestartFrames passes 10.
    /* 64 */ s32 mLevel4RestartRequested;
    // The start function of the level 4 group; set per Kart by dptc_init (the variant with the second object
    // or the one with the first only).
    /* 68 */ void (*mStartLevel4Effects)(struct KartTurnEffects *);
    // Stops the level 4 objects emitting (sets the library's emit-stop bit of each); set per Kart by
    // dptc_init (the variant with the second object or the one with the first only).
    /* 6c */ void (*mStopLevel4Emission)(struct KartTurnEffects *);
    // Lets the level 4 objects emit again (clears the library's emit-stop bit of each); set per Kart by
    // dptc_init (the variant with the second object or the one with the first only).
    /* 70 */ void (*mStartLevel4Emission)(struct KartTurnEffects *);
    // Releases the level 4 objects at once and clears the pointers; set per Kart by dptc_init (the variant
    // with the second object or the one with the first only).
    /* 74 */ void (*mReleaseLevel4Effects)(struct KartTurnEffects *);
    // Begins ending the level 4 group when the turn ends: the variant with the second object only stops emission, the
    // other releases the group at once; set per Kart by dptc_init (the variant with the second object or the
    // one with the first only).
    /* 78 */ void (*mStopLevel4Effects)(struct KartTurnEffects *);
    // Hides every present effect object of the Kart set (sets the library's skip-drawing bit); set per Kart by
    // dptc_init (the variant with the second object or the one with the first only).
    /* 7c */ void (*mHideEffects)(struct KartTurnEffects *);
    // Shows every present effect object of the Kart set again (clears the library's skip-drawing bit); set per Kart by
    // dptc_init (the variant with the second object or the one with the first only).
    /* 80 */ void (*mShowEffects)(struct KartTurnEffects *);
    // Places the level 4 objects: sets their direction and position from the two side arrays of KartEffects; set per
    // Kart by dptc_init (the variant with the second object or the one with the first only).
    /* 84 */ void (*mPlaceLevel4Effects)(struct KartTurnEffects *, Vec3s16 *, Vec3 *);
} KartTurnEffects;

extern const Vec3 data_02155fcc;

// Ends the turn effects of this Kart: when the level 4 group is present calls mStopLevel4Effects and sets
// mLevel4StopRequested, otherwise clears it; clears both restart members; sets the remove bit of the turn start objects
// and forgets them. The level 2 and level 3 groups end by their own counters.
void dptc_208C534(KartTurnEffects *p);
// The KartTurnEffects record of the Kart with that index; changes nothing.
KartTurnEffects *dptc_getControllerForDriver(int v1);
// Releases every effect object of the Kart set at once (turn start, level 4, level 3 and level 2 groups) and clears the
// flags and counters.
void dptc_killAll(KartTurnEffects *p);
// Counts mLevel2Frames and releases the level 2 objects when it passes 8, otherwise places them from the side arrays;
// while the group is present it also stops the turn start objects emitting, and clears that again when it ends.
void dptc_updateBlueSparks(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
// Starts the two level 2 objects (id 0x7e), releasing earlier ones; does nothing when v1 is 0.
void dptc_emitBlueSparks(KartTurnEffects *p, int v1);
// Counts mLevel3Frames and releases both level 3 sets when it passes 10, otherwise places all objects from the side
// arrays; does nothing when the group is not present.
void dptc_updateRedSparks(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
// Starts the level 3 objects, two per side, releasing earlier ones; does nothing when v1 is 0.
void dptc_emitRedSparks(KartTurnEffects *p, int v1);
// Each call: counts mLevel4StopFrames while a stop is requested and resets the group when it passes 10; restarts the
// group after a restart request once Kart.field44 bit 8 has been set for more than 10 calls; while the group is
// present, places the objects from the side arrays and switches their emission with Kart.field44 bit 0x10.
void dptc_updateContRedSparks(KartTurnEffects *p, Kart *q);
// Releases the level 4 group through mReleaseLevel4Effects when present and clears mLevel4Present, mLevel4StopFrames,
// mLevel4StopRequested and both restart members.
void dptc_killContRedSparks(KartTurnEffects *p);
void dptc_showAllCpu(KartTurnEffects *p);
void dptc_showAllPlayer(KartTurnEffects *p);
void dptc_showDustRedBlueSparks(KartTurnEffects *p);
void dptc_hideAllCpu(KartTurnEffects *p);
void dptc_hideAllPlayer(KartTurnEffects *p);
void dptc_hideDustRedBlueSparks(KartTurnEffects *p);
// Sets the direction and the position of the first level 4 object of each side from the side arrays.
void dptc_updateContRedSparksCpu(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
// Sets the direction and the position of both level 4 objects of each side from the side arrays (the position is the
// side position plus the object origin).
void dptc_updateContRedSparksPlayer(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
void dptc_208D1EC(KartTurnEffects *p);
void dptc_208D234(KartTurnEffects *p);
// Releases the first level 4 object of each side and clears the pointers.
void dptc_killContRedSparksCpu(KartTurnEffects *p);
// Releases the first and second level 4 objects of each side and clears the pointers.
void dptc_killContRedSparksPlayer(KartTurnEffects *p);
void dptc_resumeContRedSparksCpu(KartTurnEffects *p);
void dptc_resumeContRedSparksPlayer(KartTurnEffects *p);
void dptc_suspendContRedSparksCpu(KartTurnEffects *p);
void dptc_suspendContRedSparksPlayer(KartTurnEffects *p);
// Starts only the first level 4 object on each side.
void dptc_startContRedSparksCpu(KartTurnEffects *p);
// Starts the first and the second level 4 object on each side.
void dptc_startContRedSparksPlayer(KartTurnEffects *p);
// Each call, for each side: sets the object velocity from Kart.mEffectVelocity, its position from mSidePositions minus
// that velocity, and its emit-stop bit from Kart.field44 bit 0x10; does nothing when the group is not present.
void dptc_updateDustClouds(KartTurnEffects *p, Kart *q);
// Sets the library's remove bit of both turn start objects and forgets them; does nothing when the group is not
// present.
void dptc_stopDustClouds(KartTurnEffects *p);
// Starts the two effect objects of the turn start group, replacing any earlier ones.
void dptc_startDustClouds(KartTurnEffects *p);
// Allocates one KartTurnEffects per counted Kart in the heap a, installs the function set with the second level 4
// object for the selected entry, in time trial and when RaceSetup.fieldC is 5 and the set with the first object
// only for the others, and clears every pointer and counter.
void dptc_init(void *a);
