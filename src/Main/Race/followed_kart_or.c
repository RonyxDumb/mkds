#include "Main/Race/followed_kart_or.h"
#include "thread_scheduler.h"
#include "Main/Race/kart_highest_lap.h"
#include "arena_cache_init.h"
#include "graphic_resource_unpack.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "cell_data_unpack.h"
#include "fixed_vector_math.h"
#include "Main/Race/kart.h"

u16 GetFollowedKartOrEntryIndex(void) {
    RaceSetup *raceSetup = gRaceSetup;

    return raceSetup->mRaceKind == RACE_KIND_DEMO ? raceSetup->mFollowedKartIndex : raceSetup->mEntryIndex;
}

// Highest lap of the followed kart, one less while its race has not ended: the last lap that is over (0 = none).
u16 GetFollowedKartLastEndedLap(void) {
    u16 lap;

    lap = GetKartHighestLap(
        (u16) (gRaceSetup->mRaceKind == RACE_KIND_DEMO ? gRaceSetup->mFollowedKartIndex : gRaceSetup->mEntryIndex));
    if (IsKartEnded((u16) (gRaceSetup->mRaceKind == RACE_KIND_DEMO ? gRaceSetup->mFollowedKartIndex
                                                                   : gRaceSetup->mEntryIndex)) == 0) {
        lap = lap - 1;
    }
    return lap;
}

void Matrix2x2ReciprocalScale(MtxFx22 *matrix, s32 scale) {
    s32 reciprocal;

    if (scale != 0) {
        reciprocal = FX_Div(0x1000, scale);
    } else {
        reciprocal = 0x1000;
    }
    matrix->mElements[3] = reciprocal;
    matrix->mElements[0] = matrix->mElements[3];
    matrix->mElements[2] = 0;
    matrix->mElements[1] = matrix->mElements[2];
}

void Matrix2x2Rotation(MtxFx22 *matrix, u16 angle) {
    s32 anglePairFirst = FX_SinIdx(angle);
    s32 anglePairSecond = FX_CosIdx(angle);

    matrix->mElements[0] = anglePairSecond;
    matrix->mElements[1] = anglePairFirst;
    matrix->mElements[2] = -anglePairFirst;
    matrix->mElements[3] = anglePairSecond;
}

void Matrix2x2ReflectedRotation(MtxFx22 *matrix, u16 angle) {
    s32 anglePairSecond = FX_CosIdx(angle);
    s32 anglePairFirst;

    matrix->mElements[0] = -anglePairSecond;
    anglePairFirst = FX_SinIdx(angle);
    matrix->mElements[1] = anglePairFirst;
    matrix->mElements[2] = anglePairFirst;
    matrix->mElements[3] = anglePairSecond;
}

void Matrix2x2RotationReciprocalScale(MtxFx22 *matrix, s32 scale, u16 angle) {
    s32 anglePairFirst = SIN_OF_ANGLE(angle);
    s32 anglePairSecond = COS_OF_ANGLE(angle);
    s32 reciprocal;

    if (scale != 0) {
        reciprocal = FX_Div(0x1000, scale);
    } else {
        reciprocal = 0x1000;
    }
    matrix->mElements[0] = MUL_FIXED12_NO_ROUND(anglePairSecond, reciprocal);
    matrix->mElements[1] = MUL_FIXED12_NO_ROUND(anglePairFirst, reciprocal);
    matrix->mElements[2] = -matrix->mElements[1];
    matrix->mElements[3] = matrix->mElements[0];
}

// TRUE when the points word is plural for this number; one language counts 0 as singular.
BOOL IsPointsLabelPlural(s32 number) {
    switch (gStartupWork->mLanguageIndex) {
        case LANGUAGE_UNSUFFIXED:
        case LANGUAGE_ENGLISH:
        case LANGUAGE_GERMAN:
        case LANGUAGE_ITALIAN:
        case LANGUAGE_SPANISH:
        default:
            if (number != 1) {
                return TRUE;
            }
            return FALSE;
        case LANGUAGE_FRENCH:
            if (number != 1 && number != 0) {
                return TRUE;
            }
            return FALSE;
    }
}

BOOL RaceStartIsLanguageJa(void) {
    switch (gStartupWork->mLanguageIndex) {
        case LANGUAGE_UNSUFFIXED:
            return TRUE;
        case LANGUAGE_ENGLISH:
        case LANGUAGE_FRENCH:
        case LANGUAGE_GERMAN:
        case LANGUAGE_ITALIAN:
        case LANGUAGE_SPANISH:
            return FALSE;
    }
}

s32 GetLanguageCharSpacing(void) {
    switch (gStartupWork->mLanguageIndex) {
        case LANGUAGE_UNSUFFIXED:
            return 1;
        case LANGUAGE_ENGLISH:
        case LANGUAGE_FRENCH:
        case LANGUAGE_GERMAN:
        case LANGUAGE_ITALIAN:
        case LANGUAGE_SPANISH:
            return -1;
    }
}

BOOL IsLanguageJa(void) {
    switch (gStartupWork->mLanguageIndex) {
        case LANGUAGE_UNSUFFIXED:
            return TRUE;
        case LANGUAGE_ENGLISH:
        case LANGUAGE_FRENCH:
        case LANGUAGE_GERMAN:
        case LANGUAGE_ITALIAN:
        case LANGUAGE_SPANISH:
            return FALSE;
    }
}

void LoadNclrData(Nclr **outNclr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x504c5454);
        if (part != NULL) {
            *outNclr = (Nclr *) (part + 1);
            NNS_G2dUnpackNCL((NNSG2dPaletteData *) *outNclr);
        }
    }
    DC_FlushRange((*outNclr)->mData, (*outNclr)->mDataSize);
}

void LocateNclr(Nclr **outNclr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x504c5454);
    if (part != NULL) {
        *outNclr = (Nclr *) (part + 1);
    }
}

void LoadNcgrData2(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            NNS_G2dUnpackBGNCG((NNSG2dCharacterData *) *outNcgr);
        }
    }
    DC_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void LocateNcgr2(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void LoadNcgrData(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            NNS_G2dUnpackNCG((NNSG2dCharacterData *) *outNcgr);
        }
    }
    DC_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void LocateNcgr(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void LoadNcerData(NNSG2dCellDataBank **outNcer, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x4345424b);
    if (part == NULL) {
        return;
    }
    *outNcer = (NNSG2dCellDataBank *) (part + 1);
    NNS_G2dUnpackNCE(*outNcer);
}

void LocateNcer(NNSG2dCellDataBank **outNcer, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x4345424b);
    if (part != NULL) {
        *outNcer = (NNSG2dCellDataBank *) (part + 1);
    }
}

void LoadNanrData(AnimBank **outNanr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x41424e4b);
    if (part == NULL) {
        return;
    }
    *outNanr = (AnimBank *) (part + 1);
    NNS_G2dUnpackNAN(*outNanr);
}

void LoadNscrData(Nscr **outNscr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = FindPartByTag(file, 0x5343524e);
        if (part != NULL) {
            *outNscr = (Nscr *) (part + 1);
            NNS_G2dGetUnpackedScreenData(file, (NNSG2dBinaryBlockHeader **) outNscr);
        }
    }
    DC_FlushRange((*outNscr)->mData, (*outNscr)->mDataSize);
}

void LocateNscr(Nscr **outNscr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = FindPartByTag(file, 0x5343524e);
    if (part != NULL) {
        *outNscr = (Nscr *) (part + 1);
    }
}
