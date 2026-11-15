#include "Main/Race/followed_kart_or.h"
#include "os_thread.h"
#include "Main/Race/kart_highest_lap.h"
#include "code_0200eddc.h"
#include "code_02021f6c.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "g2d_NOB_load.h"
#include "code_02147cd8.h"
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
    matrix->a[3] = reciprocal;
    matrix->a[0] = matrix->a[3];
    matrix->a[2] = 0;
    matrix->a[1] = matrix->a[2];
}

void Matrix2x2Rotation(MtxFx22 *matrix, u16 angle) {
    s32 anglePairFirst = FX_SinIdx(angle);
    s32 anglePairSecond = FX_CosIdx(angle);

    matrix->a[0] = anglePairSecond;
    matrix->a[1] = anglePairFirst;
    matrix->a[2] = -anglePairFirst;
    matrix->a[3] = anglePairSecond;
}

void Matrix2x2ReflectedRotation(MtxFx22 *matrix, s32 angle) {
    s32 anglePairSecond = FX_CosIdx(angle);
    s32 anglePairFirst;

    matrix->a[0] = -anglePairSecond;
    anglePairFirst = FX_SinIdx(angle);
    matrix->a[1] = anglePairFirst;
    matrix->a[2] = anglePairFirst;
    matrix->a[3] = anglePairSecond;
}

void Matrix2x2RotationReciprocalScale(MtxFx22 *matrix, s32 scale, s32 angle) {
    s32 anglePairFirst = SIN_OF_ANGLE(angle);
    s32 anglePairSecond = COS_OF_ANGLE(angle);
    s32 reciprocal;

    if (scale != 0) {
        reciprocal = FX_Div(0x1000, scale);
    } else {
        reciprocal = 0x1000;
    }
    matrix->a[0] = MUL_FIXED12_NO_ROUND(anglePairSecond, reciprocal);
    matrix->a[1] = MUL_FIXED12_NO_ROUND(anglePairFirst, reciprocal);
    matrix->a[2] = -matrix->a[1];
    matrix->a[3] = matrix->a[0];
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
