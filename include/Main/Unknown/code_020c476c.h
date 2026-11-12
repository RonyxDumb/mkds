#pragma once

#include "types.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Unknown/code_020c06c4.h"

// Object behind gRaceStartGp, 0x41c bytes, allocated by InitRaceStartGp.
typedef struct RaceStartGp {
    /* 00 */ s32 mUpdateFrames;
    /* 04 */ Nclr *mRaceStartGpMONclr;
    /* 08 */ Ncgr *mRaceStartGpMONcgr;
    /* 0c */ NNSG2dCellDataWithBR *mRaceStartGpMNcerEntries[3];
    /* 18 */ RaceHudOamBuffer mMainOam;
} RaceStartGp;

void InitRaceStartGp(void);

extern const Vec3 gVec3Zero;

void ClearRaceTaPositionsPointer(void);
void InitRaceTaPositions(void);
void ResetRaceTaKartPositions(s32 kartIndex);
void HideRaceTaKartPositions(s32 kartIndex);
void DrawRaceStartGp(void);
u16 UpdateRaceStartGp(void);
void UploadRaceStartGpOam(void);
void DrawRaceLinkLevel(RaceHudOamBuffer *oamBuffer);
void UpdateRaceLinkLevel(void);
void ClearRaceLinkLevelPointer(void);
