#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
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

u16 GetCurrentPlayerRacerId(void) {
    RaceSetup *raceSetup = g_GlobalCO;

    return raceSetup->mRaceKind == RACE_KIND_DEMO ? raceSetup->mFollowedKartIndex : raceSetup->mEntryIndex;
}

// Highest lap of the followed kart, one less while its race has not ended: the last lap that is over (0 = none).
u16 GetSomeLapCount(void) {
    u16 lap;

    lap = GetKartHighestLap(
        (u16) (g_GlobalCO->mRaceKind == RACE_KIND_DEMO ? g_GlobalCO->mFollowedKartIndex : g_GlobalCO->mEntryIndex));
    if (IsRacerFinishedRace((u16) (g_GlobalCO->mRaceKind == RACE_KIND_DEMO ? g_GlobalCO->mFollowedKartIndex
                                                                   : g_GlobalCO->mEntryIndex)) == 0) {
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

void MaybeCreateRotationMatrix(MtxFx22 *matrix, u16 angle) {
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
BOOL SomeCheckLangFrench(s32 number) {
    switch (g_GlobalP->mLanguageIndex) {
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

BOOL GetSomeInterCharacterWidth(void) {
    switch (g_GlobalP->mLanguageIndex) {
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

s32 GetSomeInterCharacterWidth2(void) {
    switch (g_GlobalP->mLanguageIndex) {
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

BOOL ComputeSomeInterCharacterWidth(void) {
    switch (g_GlobalP->mLanguageIndex) {
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

void Gfx_ReadPalette(Nclr **outNclr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = Common_FindBlockByMagic(file, 0x504c5454);
        if (part != NULL) {
            *outNclr = (Nclr *) (part + 1);
            Gfx_MakePaletteOffsetsAbsolute((NNSG2dPaletteData *) *outNclr);
        }
    }
    Arm_FlushRange((*outNclr)->mData, (*outNclr)->mDataSize);
}

void Gfx_ReadPaletteRelative(Nclr **outNclr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = Common_FindBlockByMagic(file, 0x504c5454);
    if (part != NULL) {
        *outNclr = (Nclr *) (part + 1);
    }
}

void Gfx_ReadCharGraphics(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = Common_FindBlockByMagic(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            Gfx_MakeCharGraphicsOffsetsAbsolute((NNSG2dCharacterData *) *outNcgr);
        }
    }
    Arm_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void Gfx_ReadCharGraphicsRelative(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = Common_FindBlockByMagic(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void Gfx_ReadCharGraphicsV2(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = Common_FindBlockByMagic(file, 0x43484152);
        if (part != NULL) {
            *outNcgr = (Ncgr *) (part + 1);
            Gfx_MakeCharGraphicsOffsetsAbsoluteV2((NNSG2dCharacterData *) *outNcgr);
        }
    }
    Arm_FlushRange((*outNcgr)->mData, (*outNcgr)->mDataSize);
}

void MaybeReadCharBlock_1(Ncgr **outNcgr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = Common_FindBlockByMagic(file, 0x43484152);
    if (part != NULL) {
        *outNcgr = (Ncgr *) (part + 1);
    }
}

void LoadCellBankFrom(NNSG2dCellDataBank **outNcer, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = Common_FindBlockByMagic(file, 0x4345424b);
    if (part == NULL) {
        return;
    }
    *outNcer = (NNSG2dCellDataBank *) (part + 1);
    CellBank_InitializeLoad(*outNcer);
}

void LocateNcer(NNSG2dCellDataBank **outNcer, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = Common_FindBlockByMagic(file, 0x4345424b);
    if (part != NULL) {
        *outNcer = (NNSG2dCellDataBank *) (part + 1);
    }
}

void LoadNanrData(AnimBank **outNanr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = Common_FindBlockByMagic(file, 0x41424e4b);
    if (part == NULL) {
        return;
    }
    *outNanr = (AnimBank *) (part + 1);
    NNS_G2dUnpackNAN(*outNanr);
}

void MaybeReadScreenBlock_0(Nscr **outNscr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file != NULL) {
        part = Common_FindBlockByMagic(file, 0x5343524e);
        if (part != NULL) {
            *outNscr = (Nscr *) (part + 1);
            Screen_ReadBlock(file, (NNSG2dBinaryBlockHeader **) outNscr);
        }
    }
    Arm_FlushRange((*outNscr)->mData, (*outNscr)->mDataSize);
}

void MaybeReadScreenBlock(Nscr **outNscr, void *file) {
    NNSG2dBinaryBlockHeader *part;

    if (file == NULL) {
        return;
    }
    part = Common_FindBlockByMagic(file, 0x5343524e);
    if (part != NULL) {
        *outNscr = (Nscr *) (part + 1);
    }
}
