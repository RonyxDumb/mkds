#pragma once
#include "types.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h" // MapObjectList, MapObjectKindData

extern u8 data_02159578[];

extern u16 data_0215969c;

extern u8 data_02159764;

extern u16 data_02159834;

extern u16 data_02159b64;

extern u16 gSecondHandFlag;

extern MapObjectList gObPakkunSfUpdateListData;

extern MapObjectDrawList gObPakkunSfDrawListData;

extern MapObjectKindData gObPakkunSfKindData;

extern const u32 gAttractorDistanceFlag;

extern MapObjectList gAttractorUpdateListData;

extern MapObjectKindData gAttractorKindData;

extern u8 data_021594d4[];

extern Vec3 gJgMatrixRow1Source;

extern u16 gItemObjectFadeOutPendingBit;

extern u16 gItemObjectNoCallbackFadeOutPendingBit;

extern u16 gItemObjectReleasePendingBit;

extern u16 gItemObjectReleaseTimerPendingBit;

extern u16 gItemObjectOwnerExcludedBit;

extern const u16 gItemObjectNoOwnerBit;

extern Vec3 gKouraWState7StartScale;

extern u8 gItemBombVec3UnitY[];

extern u16 gItemBombExcludedUntilCourseHitBit;

