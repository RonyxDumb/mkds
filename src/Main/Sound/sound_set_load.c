#include "Main/Sound/sound_set_load.h"
#include "Main/Sound/sound_row.h"
#include "Main/Item/pooled_item_box_init.h"

#include "Main/Sound/seq_row.h"
#include "Main/Menu/menu_label_cell_rows.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "snd_bank.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_system.h"
#include "Main/Sound/snd_arc_setup.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "code_021479b4.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Menu/menu_screens_work.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"

const SoundSet gEmptySoundSet = {SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE};
u8 gSoundSetSdatPath[28] = "/data/Sound/sound_data.sdat";
const SoundSet gResetEmptySoundSet = {SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE};
const SoundSet gReleaseEmptySoundSet = {SOUND_ID_NONE, SOUND_ID_NONE, SOUND_ID_NONE};
NNSSndHeap *gCurrentSndHeap;
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
        if (NNS_SndArcLoadWaveArc(0x61, gCurrentSndHeap) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *destWaveArc;
            u32 sourceFileId;
            u32 fileId;

            waveArcInfo = NNS_SndArcGetWaveArcInfo(0x61);
            destWaveArc = NNS_SndArcGetWaveArcInfo(0);
            fileId = (destWaveArc)->mFileId;
            sourceFileId = waveArcInfo->mFileId;
            NNS_SndArcSetFileAddress(fileId, NNS_SndArcGetFileAddress(sourceFileId));
            NNS_SndArcSetFileAddress(sourceFileId, NULL);
            loaded = 1;
            listCount = gSndDataFileIdList.mCount;
            gSndDataFileIdList.mCount = listCount + 1;
            gSndDataFileIdList.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x62, gCurrentSndHeap) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *destWaveArc;
            u32 sourceFileId;
            u32 fileId;

            waveArcInfo = NNS_SndArcGetWaveArcInfo(0x62);
            destWaveArc = NNS_SndArcGetWaveArcInfo(0x50);
            fileId = (destWaveArc)->mFileId;
            sourceFileId = waveArcInfo->mFileId;
            NNS_SndArcSetFileAddress(fileId, NNS_SndArcGetFileAddress(sourceFileId));
            NNS_SndArcSetFileAddress(sourceFileId, NULL);
            loaded = 1;
            listCount = gSndDataFileIdList.mCount;
            gSndDataFileIdList.mCount = listCount + 1;
            gSndDataFileIdList.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
    } else {
        if (NNS_SndArcLoadWaveArc(0, gCurrentSndHeap) == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x50, gCurrentSndHeap) == 0) {
            return 0;
        }
    }
    bankInfo = NNS_SndArcGetBankInfo(0);
    bankFile = NNS_SndArcGetFileAddress(bankInfo->mFileId);
    for (waveArcSlot = 0; waveArcSlot < 4; waveArcSlot++) {
        waveArcNo = bankInfo->mWaveArcNo[waveArcSlot];
        if (waveArcNo == 0xffff) {
            continue;
        }
        waveArcInfo = NNS_SndArcGetWaveArcInfo(waveArcNo);
        if (waveArcInfo == NULL) {
            break;
        }
        fileId = waveArcInfo->mFileId;
        waveArcFile = NNS_SndArcGetFileAddress(fileId);
        if (bankFile == NULL) {
            continue;
        }
        if (waveArcFile == NULL) {
            continue;
        }
        SND_AssignWaveArc(bankFile, waveArcSlot, waveArcFile);
    }
    if (LoadSndGroup(groupId) == 0) {
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
        NNS_SndArcSetFileAddress(fileIdList->mFileIds[fileIndex], NULL);
    }
    list = &gSoundSetFileIdList;
    for (fileIndex = 0; fileIndex < 16; fileIndex++) {
        list->mFileIds[fileIndex] = 0;
    }
    list->mCount = 0;
    if (loadExtras != 0) {
        switch (soundSet.mSeqId) {
            case SOUND_SET_FIRST_SEQ_SWAP:
                if (NNS_SndArcLoadWaveArc(WAVE_ARC_FIRST_SWAP_SOURCE, gCurrentSndHeap) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_FIRST_SWAP_SOURCE);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_FIRST_SWAP_DEST);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = sourceWaveArc->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
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
                if (NNS_SndArcLoadWaveArc(WAVE_ARC_SECOND_SWAP_SOURCE, gCurrentSndHeap) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_SECOND_SWAP_SOURCE);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_SECOND_SWAP_DEST);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = sourceWaveArc->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
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
                if (NNS_SndArcLoadWaveArc(WAVE_ARC_THIRD_SWAP_SOURCE, gCurrentSndHeap) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_THIRD_SWAP_SOURCE);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_THIRD_SWAP_DEST);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = sourceWaveArc->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
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
            if (NNS_SndArcLoadWaveArc(WAVE_ARC_FOURTH_SWAP_SOURCE, gCurrentSndHeap) == 0) {
                loaded = 0;
            } else {
                NNSSndArcWaveArcInfo *sourceWaveArc;
                NNSSndArcWaveArcInfo *destWaveArc;
                u32 sourceFileId;
                u32 destFileId;

                sourceWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_FOURTH_SWAP_SOURCE);
                destWaveArc = NNS_SndArcGetWaveArcInfo(WAVE_ARC_FOURTH_SWAP_DEST);
                destFileId = destWaveArc->mFileId;
                sourceFileId = sourceWaveArc->mFileId;
                NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                NNS_SndArcSetFileAddress(sourceFileId, NULL);
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

void LoadInitialSndArcs(void) {
    if (NNS_SndArcLoadWaveArc(1, gCurrentSndHeap) == 0) {
        return;
    }
    if (NNS_SndArcLoadBankEx(0, 2, gCurrentSndHeap) == 0) {
        return;
    }
    NNS_SndArcLoadSeqArc(0, gCurrentSndHeap);
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
    if (IsRaceSceneNormalOrReplay() == 0) {
        return;
    }
    LoadSeqRowIfChanged(gRaceSetup->mMode);
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

    NNS_SndArcSetCurrent(&gOnMemorySndArc);
    loadResult = SetupSndArcFromFile(&gFileSndArc, gSoundSetSdatPath, gCurrentSndHeap, 0);
    SetFileSndArcOpen(1);
    if (loadResult == 0) {
        return 0;
    }
    if (NNS_SndArcLoadSeqArc(1, gCurrentSndHeap) == 0) {
        return 0;
    }
    sourceSeqArc = NNS_SndArcGetSeqArcInfo(1);
    destSeqArc = NNS_SndArcGetSeqArcInfo(0);
    sourceFileId = sourceSeqArc->mFileId;
    destFileId = destSeqArc->mFileId;
    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
    NNS_SndArcSetFileAddress(sourceFileId, NULL);
    listCount = gSndDataFileIdList.mCount;
    gSndDataFileIdList.mCount = listCount + 1;
    gSndDataFileIdList.mFileIds[listCount] = destFileId;
    if (NNS_SndArcLoadWaveArc(0x3e, gCurrentSndHeap) != 0) {
        sourceWaveArc = NNS_SndArcGetWaveArcInfo(0x3e);
        destWaveArc = NNS_SndArcGetWaveArcInfo(0x3d);
        destFileId = destWaveArc->mFileId;
        sourceFileId = sourceWaveArc->mFileId;
        NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
        NNS_SndArcSetFileAddress(sourceFileId, NULL);
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
    if (NNS_SndArcLoadWaveArc(1, gCurrentSndHeap) == 0) {
        loaded = 0;
    } else if (NNS_SndArcLoadBankEx(0, 2, gCurrentSndHeap) == 0) {
        loaded = 0;
    } else if (NNS_SndArcLoadSeqArc(0, gCurrentSndHeap) == 0) {
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

    GetCourseSoundRowIndex(courseId, &row);
    rowCopy = row;
    soundSet.mSeqId = rowCopy.mSeqId;
    soundSet.mFirstBankId = rowCopy.mFirstBankId;
    soundSet.mSecondBankId = rowCopy.mSecondBankId;
    NNS_SndArcSetCurrent(&gFileSndArc);
    loaded = LoadSoundSetIfChanged(soundSet, 1) != 0;
    if (loaded != 0) {
        loaded = LoadSeqRowIfChanged(raceMode);
    }
    return loaded;
}

u32 LoadResultSceneSoundSet(void) {
    SoundRow row, rowCopy;
    SoundSet soundSet;

    row = GetSoundRow(0x29);
    row.mSeqId = GetResultSceneSeqId();
    rowCopy = row;
    soundSet.mSeqId = rowCopy.mSeqId;
    soundSet.mFirstBankId = rowCopy.mFirstBankId;
    soundSet.mSecondBankId = rowCopy.mSecondBankId;
    NNS_SndArcSetCurrent(&gFileSndArc);
    return LoadSoundSetIfChanged(soundSet, 1) != 0;
}

u32 LoadSndGroup(s32 groupId) {
    return NNS_SndArcLoadGroup(groupId, gCurrentSndHeap);
}

void ResetLoadedSoundSet(LoadedSoundSet *loadedSet) {
    loadedSet->mSoundSet = gResetEmptySoundSet;
    loadedSet->mHeapState = LOADED_SOUND_SET_NO_HEAP_STATE;
}

void SaveSndHeapState(LoadedSoundSet *loadedSet) {
    loadedSet->mHeapState = NNS_SndHeapSaveState(gCurrentSndHeap);
}

// Restores the heap to the state saved before the set was loaded.
void ReleaseSoundSet(LoadedSoundSet *loadedSet) {
    SoundSet emptySet = gEmptySoundSet;

    if (emptySet.mSeqId == loadedSet->mSoundSet.mSeqId && emptySet.mFirstBankId == loadedSet->mSoundSet.mFirstBankId &&
        emptySet.mSecondBankId == loadedSet->mSoundSet.mSecondBankId) {
        return;
    }
    NNS_SndHeapLoadState(gCurrentSndHeap, loadedSet->mHeapState);
    NNS_SndHeapGetCurrentLevel(gCurrentSndHeap);
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
    if (soundSet.mSeqId != SOUND_ID_NONE && NNS_SndArcLoadSeq(soundSet.mSeqId, gCurrentSndHeap) == 0) {
        return 0;
    }
    if (soundSet.mFirstBankId != SOUND_ID_NONE && NNS_SndArcLoadBank(soundSet.mFirstBankId, gCurrentSndHeap) == 0) {
        return 0;
    }
    if (soundSet.mSecondBankId != SOUND_ID_NONE && NNS_SndArcLoadBank(soundSet.mSecondBankId, gCurrentSndHeap) == 0) {
        return 0;
    }
    loadedSet->mSoundSet = soundSet;
    return 1;
}
