#include "Main/Sound/sound_set_load.h"
#include "Main/Sound/sound_row.h"
#include "Main/Item/pooled_item_box_init.h"

#include "Main/Sound/seq_row.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "sound_bank_wave_archive.h"
#include "sound_archive_load.h"
#include "sound_archive_load_result.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/sound_archive_setup.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "sound_player_control.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

const SoundSet gEmptySoundSet = {SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE};
u8 g_str_data_Sound_sound_data_sdat_0[28] = "/data/Sound/sound_data.sdat";
const SoundSet gResetEmptySoundSet = {SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE};
const SoundSet gReleaseEmptySoundSet = {SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE};
NNSSndHeap *g_SoundContext;
SndFileIdList gSndDataFileIdList;
SndFileIdList gSoundSetFileIdList;

void ReleaseLoadedSoundSet(void) {
    ReleaseSoundSet(GetLoadedSoundSet());
}

// Loads wave archives 0 and 0x50 (taken from archives 0x61 and 0x62 when moveWaveArcs is set), assigns bank 0's wave
// archives to it, then loads group groupId.
u32 LoadSndGroupWithWaveArcs(u32 groupId, u32 moveWaveArcs) {
    NNSSndArcBankInfo *bankInfo;
    NNSSndArcWaveArcInfo *waveArcInfo;
    SNDWaveArc *waveArcFile;
    u32 waveArcNo;
    u32 fileId;
    SNDBankData *bankFile;
    u32 loaded;
    u32 listCount;
    s32 waveArcSlot;

    if (moveWaveArcs != 0) {
        if (Sound_LoadSwar(0x61, g_SoundContext) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *destWaveArc;
            u32 sourceFileId;
            u32 fileId;

            waveArcInfo = Sound_GetSwarInfoEntry(0x61);
            destWaveArc = Sound_GetSwarInfoEntry(0);
            fileId = (destWaveArc)->mFileId;
            sourceFileId = waveArcInfo->mFileId;
            Sound_SetFileFatDynamicOffsetField(fileId, Sound_MaybeGetRawFilePointer(sourceFileId));
            Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
            loaded = 1;
            listCount = gSndDataFileIdList.mCount;
            gSndDataFileIdList.mCount = listCount + 1;
            gSndDataFileIdList.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
        if (Sound_LoadSwar(0x62, g_SoundContext) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *destWaveArc;
            u32 sourceFileId;
            u32 fileId;

            waveArcInfo = Sound_GetSwarInfoEntry(0x62);
            destWaveArc = Sound_GetSwarInfoEntry(0x50);
            fileId = (destWaveArc)->mFileId;
            sourceFileId = waveArcInfo->mFileId;
            Sound_SetFileFatDynamicOffsetField(fileId, Sound_MaybeGetRawFilePointer(sourceFileId));
            Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
            loaded = 1;
            listCount = gSndDataFileIdList.mCount;
            gSndDataFileIdList.mCount = listCount + 1;
            gSndDataFileIdList.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
    } else {
        if (Sound_LoadSwar(0, g_SoundContext) == 0) {
            return 0;
        }
        if (Sound_LoadSwar(0x50, g_SoundContext) == 0) {
            return 0;
        }
    }
    bankInfo = Sound_GetSbnkInfoEntry(0);
    bankFile = Sound_MaybeGetRawFilePointer(bankInfo->mFileId);
    for (waveArcSlot = 0; waveArcSlot < 4; waveArcSlot++) {
        waveArcNo = bankInfo->mWaveArcNo[waveArcSlot];
        if (waveArcNo == 0xffff) {
            continue;
        }
        waveArcInfo = Sound_GetSwarInfoEntry(waveArcNo);
        if (waveArcInfo == NULL) {
            break;
        }
        fileId = waveArcInfo->mFileId;
        waveArcFile = Sound_MaybeGetRawFilePointer(fileId);
        if (bankFile == NULL) {
            continue;
        }
        if (waveArcFile == NULL) {
            continue;
        }
        SND_AssignWaveArc(bankFile, waveArcSlot, waveArcFile);
    }
    if (LoadGroupById(groupId) == 0) {
        return 0;
    }
    return 1;
}

// Releases the loaded set and loads soundSet unless it is empty or already loaded; loadExtras adds extra wave archives
// for some sets.
u32 LoadSoundSetIfChanged(SoundSet soundSet, u32 loadExtras) {
    SndFileIdList *fileIdList;
    u32 loaded;
    u32 listCount;
    s32 fileIndex;
    SndFileIdList *list;

    if (soundSet.mSeqId == SOUND_ID_NONE && soundSet.mFirstBankId == SOUND_ID_NONE &&
        soundSet.mSecondBankId == SOUND_ID_NONE) {
        return 1;
    }
    if (IsSoundSetLoaded(GetLoadedSoundSet(), soundSet) != 0) {
        return 1;
    }
    ReleaseSoundSet(GetLoadedSoundSet());
    fileIdList = &gSoundSetFileIdList;
    for (fileIndex = 0; fileIndex < fileIdList->mCount; fileIndex++) {
        Sound_SetFileFatDynamicOffsetField(fileIdList->mFileIds[fileIndex], NULL);
    }
    list = &gSoundSetFileIdList;
    for (fileIndex = 0; fileIndex < 16; fileIndex++) {
        list->mFileIds[fileIndex] = 0;
    }
    list->mCount = 0;
    if (loadExtras != 0) {
        switch (soundSet.mSeqId) {
            case SOUND_SET_FIRST_SEQ_SWAP:
                if (Sound_LoadSwar(WAVE_ARC_FIRST_SWAP_SOURCE, g_SoundContext) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_FIRST_SWAP_SOURCE);
                    destWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_FIRST_SWAP_DEST);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = sourceWaveArc->mFileId;
                    Sound_SetFileFatDynamicOffsetField(destFileId, Sound_MaybeGetRawFilePointer(sourceFileId));
                    Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
                    loaded = 1;
                    listCount = gSoundSetFileIdList.mCount;
                    gSoundSetFileIdList.mCount = listCount + 1;
                    gSoundSetFileIdList.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
            case SOUND_SET_SECOND_SEQ_SWAP:
                if (Sound_LoadSwar(WAVE_ARC_SECOND_SWAP_SOURCE, g_SoundContext) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_SECOND_SWAP_SOURCE);
                    destWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_SECOND_SWAP_DEST);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = sourceWaveArc->mFileId;
                    Sound_SetFileFatDynamicOffsetField(destFileId, Sound_MaybeGetRawFilePointer(sourceFileId));
                    Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
                    loaded = 1;
                    listCount = gSoundSetFileIdList.mCount;
                    gSoundSetFileIdList.mCount = listCount + 1;
                    gSoundSetFileIdList.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
            case SOUND_SET_THIRD_SEQ_SWAP:
                if (Sound_LoadSwar(WAVE_ARC_THIRD_SWAP_SOURCE, g_SoundContext) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_THIRD_SWAP_SOURCE);
                    destWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_THIRD_SWAP_DEST);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = sourceWaveArc->mFileId;
                    Sound_SetFileFatDynamicOffsetField(destFileId, Sound_MaybeGetRawFilePointer(sourceFileId));
                    Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
                    loaded = 1;
                    listCount = gSoundSetFileIdList.mCount;
                    gSoundSetFileIdList.mCount = listCount + 1;
                    gSoundSetFileIdList.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
        }
        if (soundSet.mFirstBankId == SOUND_SET_FOURTH_BANK_SWAP) {
            if (Sound_LoadSwar(WAVE_ARC_FOURTH_SWAP_SOURCE, g_SoundContext) == 0) {
                loaded = 0;
            } else {
                NNSSndArcWaveArcInfo *sourceWaveArc;
                NNSSndArcWaveArcInfo *destWaveArc;
                u32 sourceFileId;
                u32 destFileId;

                sourceWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_FOURTH_SWAP_SOURCE);
                destWaveArc = Sound_GetSwarInfoEntry(WAVE_ARC_FOURTH_SWAP_DEST);
                destFileId = destWaveArc->mFileId;
                sourceFileId = sourceWaveArc->mFileId;
                Sound_SetFileFatDynamicOffsetField(destFileId, Sound_MaybeGetRawFilePointer(sourceFileId));
                Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
                loaded = 1;
                listCount = gSoundSetFileIdList.mCount;
                gSoundSetFileIdList.mCount = listCount + 1;
                gSoundSetFileIdList.mFileIds[listCount] = destFileId;
            }
            if (loaded == 0) {
                return 0;
            }
        }
    }
    return LoadSoundSet(GetLoadedSoundSet(), soundSet) != 0;
}

void LoadCertainSwarSbnkSarc(void) {
    if (Sound_LoadSwar(1, g_SoundContext) == 0) {
        return;
    }
    if (Sound_LoadSbnkWithFlags(0, 2, g_SoundContext) == 0) {
        return;
    }
    Sound_LoadSarc(0, g_SoundContext);
}

void LoadInitialSndGroup(u32 moveWaveArcs) {
    LoadSndGroupWithWaveArcs(0, moveWaveArcs);
    SaveSndHeapState(GetLoadedSoundSet());
}

void LoadSceneSoundSet(SoundRow soundRow, u32 loadExtras) {
    SoundSet soundSet;

    soundSet.mSeqId = soundRow.mSeqId;
    soundSet.mFirstBankId = soundRow.mFirstBankId;
    soundSet.mSecondBankId = soundRow.mSecondBankId;
    LoadSoundSetIfChanged(soundSet, loadExtras);
    if (IsInRaceSceneNormalOrReplay() == 0) {
        return;
    }
    LoadPerRaceModeResultSseqs(g_GlobalCO->mMode);
}

u32 LoadSndDataFromFile(void) {
    NNSSndArcSeqArcInfo *sourceSeqArc;
    NNSSndArcSeqArcInfo *destSeqArc;
    NNSSndArcWaveArcInfo *sourceWaveArc;
    NNSSndArcWaveArcInfo *destWaveArc;
    u32 loadResult;
    u32 sourceFileId;
    u32 destFileId;
    u32 loaded;
    u32 listCount;

    Sound_MaybeSetActiveSdat(&g_MainSdat);
    loadResult = Sound_ReadSdatFromPathImplV2(&g_GlobalSdat, g_str_data_Sound_sound_data_sdat_0, g_SoundContext, 0);
    SetGlobalSdatUsed(1);
    if (loadResult == 0) {
        return 0;
    }
    if (Sound_LoadSarc(1, g_SoundContext) == 0) {
        return 0;
    }
    sourceSeqArc = Sound_GetSarcInfoEntry(1);
    destSeqArc = Sound_GetSarcInfoEntry(0);
    sourceFileId = sourceSeqArc->mFileId;
    destFileId = destSeqArc->mFileId;
    Sound_SetFileFatDynamicOffsetField(destFileId, Sound_MaybeGetRawFilePointer(sourceFileId));
    Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
    listCount = gSndDataFileIdList.mCount;
    gSndDataFileIdList.mCount = listCount + 1;
    gSndDataFileIdList.mFileIds[listCount] = destFileId;
    if (Sound_LoadSwar(0x3e, g_SoundContext) != 0) {
        sourceWaveArc = Sound_GetSwarInfoEntry(0x3e);
        destWaveArc = Sound_GetSwarInfoEntry(0x3d);
        destFileId = destWaveArc->mFileId;
        sourceFileId = sourceWaveArc->mFileId;
        Sound_SetFileFatDynamicOffsetField(destFileId, Sound_MaybeGetRawFilePointer(sourceFileId));
        Sound_SetFileFatDynamicOffsetField(sourceFileId, NULL);
        loaded = 1;
        listCount = gSndDataFileIdList.mCount;
        gSndDataFileIdList.mCount = listCount + 1;
        gSndDataFileIdList.mFileIds[listCount] = destFileId;
    } else {
        loaded = 0;
    }
    if (loaded == 0) {
        return 0;
    }
    if (Sound_LoadSwar(1, g_SoundContext) == 0) {
        loaded = 0;
    } else if (Sound_LoadSbnkWithFlags(0, 2, g_SoundContext) == 0) {
        loaded = 0;
    } else if (Sound_LoadSarc(0, g_SoundContext) == 0) {
        loaded = 0;
    } else {
        loaded = 1;
    }
    if (loaded == 0) {
        return 0;
    }
    if (LoadSndGroupWithWaveArcs(1, 1) == 0) {
        return 0;
    }
    SaveSndHeapState(GetLoadedSoundSet());
    return 1;
}

u32 LoadCourseSoundSet(u32 raceMode, u32 courseId) {
    SoundRow row, rowCopy;
    SoundSet soundSet;
    u32 loaded;

    GetCourseBgmInfo(courseId, &row);
    rowCopy = row;
    soundSet.mSeqId = rowCopy.mSeqId;
    soundSet.mFirstBankId = rowCopy.mFirstBankId;
    soundSet.mSecondBankId = rowCopy.mSecondBankId;
    Sound_MaybeSetActiveSdat(&g_GlobalSdat);
    loaded = LoadSoundSetIfChanged(soundSet, 1) != 0;
    if (loaded != 0) {
        loaded = LoadPerRaceModeResultSseqs(raceMode);
    }
    return loaded;
}

u32 LoadResultSceneSoundSet(void) {
    SoundRow row, rowCopy;
    SoundSet soundSet;

    row = GetCourseBgmEntry(0x29);
    row.mSeqId = GetResultSceneSeqId();
    rowCopy = row;
    soundSet.mSeqId = rowCopy.mSeqId;
    soundSet.mFirstBankId = rowCopy.mFirstBankId;
    soundSet.mSecondBankId = rowCopy.mSecondBankId;
    Sound_MaybeSetActiveSdat(&g_GlobalSdat);
    return LoadSoundSetIfChanged(soundSet, 1) != 0;
}

u32 LoadGroupById(s32 groupId) {
    return Sound_LoadGroup(groupId, g_SoundContext);
}

void ResetLoadedSoundSet(LoadedSoundSet *loadedSet) {
    loadedSet->mSoundSet = gResetEmptySoundSet;
    loadedSet->mHeapState = LOADED_SOUND_SET_NO_HEAP_STATE;
}

void SaveSndHeapState(LoadedSoundSet *loadedSet) {
    loadedSet->mHeapState = Sound_Context_BackupFrameState(g_SoundContext);
}

// Restores the heap to the state saved before the set was loaded.
void ReleaseSoundSet(LoadedSoundSet *loadedSet) {
    SoundSet emptySet = gEmptySoundSet;

    if (emptySet.mSeqId == loadedSet->mSoundSet.mSeqId && emptySet.mFirstBankId == loadedSet->mSoundSet.mFirstBankId &&
        emptySet.mSecondBankId == loadedSet->mSoundSet.mSecondBankId) {
        return;
    }
    Sound_MaybeRestoreHeapState(g_SoundContext, loadedSet->mHeapState);
    Sound_Context_GetMaybeSavedFrameHeapStateId(g_SoundContext);
    loadedSet->mSoundSet = gReleaseEmptySoundSet;
}

u32 IsSoundSetLoaded(LoadedSoundSet *loadedSet, SoundSet soundSet) {
    if (soundSet.mSeqId == loadedSet->mSoundSet.mSeqId && soundSet.mFirstBankId == loadedSet->mSoundSet.mFirstBankId &&
        soundSet.mSecondBankId == loadedSet->mSoundSet.mSecondBankId) {
        return 1;
    }
    return 0;
}

u32 LoadSoundSet(LoadedSoundSet *loadedSet, SoundSet soundSet) {
    if (soundSet.mSeqId != SOUND_ID_NONE && CheckMaybeLoadSseqOk(soundSet.mSeqId, g_SoundContext) == 0) {
        return 0;
    }
    if (soundSet.mFirstBankId != SOUND_ID_NONE && Sound_LoadSbnk(soundSet.mFirstBankId, g_SoundContext) == 0) {
        return 0;
    }
    if (soundSet.mSecondBankId != SOUND_ID_NONE && Sound_LoadSbnk(soundSet.mSecondBankId, g_SoundContext) == 0) {
        return 0;
    }
    loadedSet->mSoundSet = soundSet;
    return 1;
}
