#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "code_0200eddc.h"
#include "code_02021f6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "g2d_NOB_load.h"
#include "code_02147cd8.h"
#include "Main/Kart/KartTimes.h"

u16 Race_GetPlayerId(void) {
    RaceSetup *raceSetup = gRaceMultiConfig;

    return raceSetup->mRaceKind == RACE_KIND_DEMO ? raceSetup->mFollowedKartIndex : raceSetup->mEntryIndex;
}

// Highest lap of the followed kart, one less while its race has not ended: the last lap that is over (0 = none).
u16 GetFollowedKartLastEndedLap(void) {
    u16 lap;

    lap = rstat_getDriverHighestReachedLap(
        (u16) (gRaceMultiConfig->mRaceKind == RACE_KIND_DEMO ? gRaceMultiConfig->mFollowedKartIndex : gRaceMultiConfig->mEntryIndex));
    if (rstat_hasDriverFinished((u16) (gRaceMultiConfig->mRaceKind == RACE_KIND_DEMO ? gRaceMultiConfig->mFollowedKartIndex
                                                                   : gRaceMultiConfig->mEntryIndex)) == 0) {
        lap = lap - 1;
    }
    return lap;
}

void lmap_scaleMtx22(s32 *matrix, s32 scale) {
    s32 reciprocal;

    if (scale != 0) {
        reciprocal = FX_Div(0x1000, scale);
    } else {
        reciprocal = 0x1000;
    }
    matrix[3] = reciprocal;
    matrix[0] = matrix[3];
    matrix[2] = 0;
    matrix[1] = matrix[2];
}

void lmap_rotMtx22(s32 *matrix, s32 angle) {
    s32 anglePairFirst = FX_SinCosTable_[(angle >> 4) * 2];
    s32 anglePairSecond = FX_SinCosTable_[(angle >> 4) * 2 + 1];

    matrix[0] = anglePairSecond;
    matrix[1] = anglePairFirst;
    matrix[2] = -anglePairFirst;
    matrix[3] = anglePairSecond;
}

void lmap_rotMtx22FlipX(s32 *matrix, s32 angle) {
    s32 anglePairSecond = FX_SinCosTable_[(angle >> 4) * 2 + 1];
    s32 anglePairFirst;

    matrix[0] = -anglePairSecond;
    anglePairFirst = FX_SinCosTable_[(angle >> 4) * 2];
    matrix[1] = anglePairFirst;
    matrix[2] = anglePairFirst;
    matrix[3] = anglePairSecond;
}

void lmap_rotScaleMtx22(s32 *matrix, s32 scale, s32 angle) {
    s32 angleIndex = angle >> 4;
    s32 anglePairFirst = FX_SinCosTable_[angleIndex * 2];
    s32 anglePairSecond = FX_SinCosTable_[angleIndex * 2 + 1];
    s32 reciprocal;

    if (scale != 0) {
        reciprocal = FX_Div(0x1000, scale);
    } else {
        reciprocal = 0x1000;
    }
    matrix[0] = ((s64) anglePairSecond * reciprocal) >> 12;
    matrix[1] = ((s64) anglePairFirst * reciprocal) >> 12;
    matrix[2] = -matrix[1];
    matrix[3] = matrix[0];
}

BOOL r2d_shouldUsePointsPlural(s32 number) {
    switch (gSystemData->mLanguageIndex) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        default:
            if (number != 1) {
                return TRUE;
            }
            return FALSE;
        case 2:
            if (number != 1 && number != 0) {
                return TRUE;
            }
            return FALSE;
    }
}

BOOL RaceStartIsLanguageJa(void) {
    switch (gSystemData->mLanguageIndex) {
        case 0:
            return TRUE;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return FALSE;
    }
}

s32 GetLanguageCharSpacing(void) {
    switch (gSystemData->mLanguageIndex) {
        case 0:
            return 1;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return -1;
    }
}

BOOL g2du_getTextHSpace(void) {
    switch (gSystemData->mLanguageIndex) {
        case 0:
            return TRUE;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return FALSE;
    }
}

void g2du_unpackPaletteData(Nclr **outNclr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = NNS_G2dFindBinaryBlock(file, 0x504c5454);
        if (part != NULL) {
            *outNclr = (Nclr *) (part + 1);
            NNS_G2dUnpackNCL((NNSG2dPaletteData *) *outNclr);
        }
    }
    DC_FlushRange((*outNclr)->mData, (*outNclr)->mDataSize);
}

void g2du_getPaletteData(Nclr **outNclr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = NNS_G2dFindBinaryBlock(file, 0x504c5454);
    if (part != NULL) {
        *outNclr = (Nclr *) (part + 1);
    }
}

void g2du_unpackCharacterData(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = NNS_G2dFindBinaryBlock(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            NNS_G2dUnpackNCG((NNSG2dCharacterData *) *outNcgr);
        }
    }
    DC_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void g2du_getCharacterData(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = NNS_G2dFindBinaryBlock(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void g2du_unpackCharacterDataBG(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = NNS_G2dFindBinaryBlock(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            NNS_G2dUnpackBGNCG((NNSG2dCharacterData *) *outNcgr);
        }
    }
    DC_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void g2du_getCharacterDataBG(Ncgr **outNcgr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = NNS_G2dFindBinaryBlock(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void g2du_unpackCellBankData(Unk02021dc8 **outNcer, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = NNS_G2dFindBinaryBlock(file, 0x4345424b);
    if (part == NULL) {
        return;
    }
    *outNcer = (Unk02021dc8 *) (part + 1);
    NNS_G2dUnpackNCE(*outNcer);
}

void g2du_getCellBankData(Unk02021dc8 **outNcer, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = NNS_G2dFindBinaryBlock(file, 0x4345424b);
    if (part != NULL) {
        *outNcer = (Unk02021dc8 *) (part + 1);
    }
}

void g2du_unpackAnimBank(Unk02021dc8 **outNanr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = NNS_G2dFindBinaryBlock(file, 0x41424e4b);
    if (part == NULL) {
        return;
    }
    *outNanr = (Unk02021dc8 *) (part + 1);
    NNS_G2dUnpackNAN(*outNanr);
}

void g2du_unpackScreenData(Nscr **outNscr, void *file) {
    Unk02021fd0 *part;

    if (file != NULL) {
        part = NNS_G2dFindBinaryBlock(file, 0x5343524e);
        if (part != NULL) {
            *outNscr = (Nscr *) (part + 1);
            NNS_G2dUnpackNSC(file, (Unk02021fd0 **) outNscr);
        }
    }
    DC_FlushRange((*outNscr)->mData, (*outNscr)->mDataSize);
}

void g2du_getScreenData(Nscr **outNscr, void *file) {
    Unk02021fd0 *part;

    if (file == NULL) {
        return;
    }
    part = NNS_G2dFindBinaryBlock(file, 0x5343524e);
    if (part != NULL) {
        *outNscr = (Nscr *) (part + 1);
    }
}
