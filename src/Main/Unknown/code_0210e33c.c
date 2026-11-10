#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_0202511c.h"
#include "Main/Unknown/code_021053e4.h"

#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02111000.h"
#include "code_020219e8.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02108950.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210ef68.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/code_0212da2c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

const SoundSet gReleaseEmptySoundSet = {0xff, 0xff, 0xff};
const SoundSet gEmptySoundSet = {0xff, 0xff, 0xff};
const SoundSet gResetEmptySoundSet = {0xff, 0xff, 0xff};

void ReleaseLoadedSoundSet(void) {
    ReleaseSoundSet(GetLoadedSoundSet());
}

// Loads wave archives 0 and 0x50 (taken from archives 0x61 and 0x62 when b is set), assigns bank 0's wave archives to
// it, then loads group a.
u32 LoadSndGroupWithWaveArcs(u32 groupId, u32 moveWaveArcs) {
    NNSSndArcBankInfo *bankInfo;
    NNSSndArcWaveArcInfo *waveArcInfo;
    Unk02021968 *waveArcFile;
    u32 waveArcNo;
    u32 fileId;
    Unk02021968 *bankFile;
    u32 loaded;
    u32 listCount;
    s32 i;

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
    for (i = 0; i < 4; i++) {
        waveArcNo = bankInfo->mWaveArcNo[i];
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
        SND_AssignWaveArc(bankFile, i, waveArcFile);
    }
    if (LoadSndGroup(groupId) == 0) {
        return 0;
    }
    return 1;
}

// Releases the loaded set and loads v unless it is empty or already loaded; d adds extra wave archives for some sets.
u32 LoadSoundSetIfChanged(SoundSet soundSet, u32 loadExtras) {
    SndFileIdList *fileIdList;
    u32 loaded;
    u32 listCount;
    s32 i;
    SndFileIdList *list;

    if (soundSet.mSeqId == 0xff && soundSet.mFirstBankId == 0xff && soundSet.mSecondBankId == 0xff) {
        return 1;
    }
    if (IsSoundSetLoaded(GetLoadedSoundSet(), soundSet) != 0) {
        return 1;
    }
    ReleaseSoundSet(GetLoadedSoundSet());
    fileIdList = &gSoundSetFileIdList;
    for (i = 0; i < fileIdList->mCount; i++) {
        NNS_SndArcSetFileAddress(fileIdList->mFileIds[i], NULL);
    }
    list = &gSoundSetFileIdList;
    for (i = 0; i < 16; i++) {
        list->mFileIds[i] = 0;
    }
    list->mCount = 0;
    if (loadExtras != 0) {
        switch (soundSet.mSeqId) {
            case 0x4a:
                if (NNS_SndArcLoadWaveArc(0x63, gCurrentSndHeap) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = NNS_SndArcGetWaveArcInfo(0x63);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x31);
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
            case 0x2b:
                if (NNS_SndArcLoadWaveArc(0x64, gCurrentSndHeap) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = NNS_SndArcGetWaveArcInfo(0x64);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x58);
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
            case 0xf:
                if (NNS_SndArcLoadWaveArc(0x34, gCurrentSndHeap) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *sourceWaveArc;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    sourceWaveArc = NNS_SndArcGetWaveArcInfo(0x34);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x33);
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
        if (soundSet.mFirstBankId == 0x10) {
            if (NNS_SndArcLoadWaveArc(0x13, gCurrentSndHeap) == 0) {
                loaded = 0;
            } else {
                NNSSndArcWaveArcInfo *sourceWaveArc;
                NNSSndArcWaveArcInfo *destWaveArc;
                u32 sourceFileId;
                u32 destFileId;

                sourceWaveArc = NNS_SndArcGetWaveArcInfo(0x13);
                destWaveArc = NNS_SndArcGetWaveArcInfo(0x12);
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

    soundSet.mSeqId = soundRow.mUnk_00[1];
    soundSet.mFirstBankId = soundRow.mUnk_00[2];
    soundSet.mSecondBankId = soundRow.mUnk_00[3];
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
    loadResult = SetupSndArcFromFile(&gFileSndArc, data_0216cb30, gCurrentSndHeap, 0);
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
    soundSet.mSeqId = rowCopy.mUnk_00[1];
    soundSet.mFirstBankId = rowCopy.mUnk_00[2];
    soundSet.mSecondBankId = rowCopy.mUnk_00[3];
    NNS_SndArcSetCurrent(&gFileSndArc);
    loaded = LoadSoundSetIfChanged(soundSet, 1) != 0;
    if (loaded != 0) {
        loaded = LoadSeqRowIfChanged(raceMode);
    }
    return loaded;
}

u32 func_0210e524(void) {
    SoundRow row, rowCopy;
    SoundSet soundSet;

    row = GetSoundRow(0x29);
    row.mUnk_00[1] = GetResultSceneSeqId();
    rowCopy = row;
    soundSet.mSeqId = rowCopy.mUnk_00[1];
    soundSet.mFirstBankId = rowCopy.mUnk_00[2];
    soundSet.mSecondBankId = rowCopy.mUnk_00[3];
    NNS_SndArcSetCurrent(&gFileSndArc);
    return LoadSoundSetIfChanged(soundSet, 1) != 0;
}

u32 LoadSndGroup(s32 groupId) {
    return NNS_SndArcLoadGroup(groupId, gCurrentSndHeap);
}

void ResetLoadedSoundSet(LoadedSoundSet *loadedSet) {
    loadedSet->mSoundSet = gResetEmptySoundSet;
    loadedSet->mHeapState = 0xff00;
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
    if (soundSet.mSeqId != 0xff && NNS_SndArcLoadSeq(soundSet.mSeqId, gCurrentSndHeap) == 0) {
        return 0;
    }
    if (soundSet.mFirstBankId != 0xff && NNS_SndArcLoadBank(soundSet.mFirstBankId, gCurrentSndHeap) == 0) {
        return 0;
    }
    if (soundSet.mSecondBankId != 0xff && NNS_SndArcLoadBank(soundSet.mSecondBankId, gCurrentSndHeap) == 0) {
        return 0;
    }
    loadedSet->mSoundSet = soundSet;
    return 1;
}
