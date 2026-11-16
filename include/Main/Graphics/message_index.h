#pragma once

#include "types.h"
#include "Main/Save/buddy_record_time.h"

int GetWiFiCourseMessageIndex(int courseId);
int GetGhostCourseMessageIndex(int courseId);
u32 GetCourseMessageIndex(u32 courseId);
u32 GetKartMessageIndex(u32 kartIndex);

typedef struct KartAppear KartAppear;

s32 GetKartPositionWithinAppearLimit(KartAppear *appear, u32 characterIndex, s32 kartIndex);

int CountKartsWithinAppearLimit(KartAppear *appear, u32 characterIndex);

u32 GetKartIndexAtTableIndex(u32 tableIndex);
s32 FindKartTableIndex(u32 kartIndex);
s32 GetCharacterKartIndexByMode(s32 characterIndex);

u32 GetCharacterSeqPairNo(u32 characterIndex);

extern const s32 gCharacterKartIndexTableBattle[13];
extern const s32 gCharacterKartIndexTable[13];
extern const u32 gCharacterSeqPairNoTable[13];
extern const u32 gKartMessageIndexTable[36];
extern const u32 gKartIndexTable[36];

extern const s32 gCourseMessageIndexTable[48];
