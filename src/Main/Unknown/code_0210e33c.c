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

const SoundSet data_0215c38c = {0xff, 0xff, 0xff};
const SoundSet data_0215c380 = {0xff, 0xff, 0xff};
const SoundSet data_0215c398 = {0xff, 0xff, 0xff};

void ReleaseLoadedSoundSet(void) {
    ReleaseSoundSet(sound_getSeqHeapState());
}

// Loads wave archives 0 and 0x50 (taken from archives 0x61 and 0x62 when b is set), assigns bank 0's wave archives to
// it, then loads group a.
u32 PreLoadSounds(u32 groupId, u32 moveWaveArcs) {
    NNSSndArcBankInfo *bankInfo;
    NNSSndArcWaveArcInfo *waveArcInfo;
    Unk02021968 *r;
    u32 v;
    u32 fileId;
    Unk02021968 *bankFile;
    u32 loaded;
    u32 listCount;
    s32 i;

    if (moveWaveArcs != 0) {
        if (NNS_SndArcLoadWaveArc(0x61, gSndHeapHandle) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *r;
            u32 v;
            u32 fileId;

            waveArcInfo = NNS_SndArcGetWaveArcInfo(0x61);
            r = NNS_SndArcGetWaveArcInfo(0);
            fileId = (r)->mFileId;
            v = waveArcInfo->mFileId;
            NNS_SndArcSetFileAddress(fileId, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            loaded = 1;
            listCount = data_0217d178.mCount;
            data_0217d178.mCount = listCount + 1;
            data_0217d178.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x62, gSndHeapHandle) == 0) {
            loaded = 0;
        } else {
            NNSSndArcWaveArcInfo *waveArcInfo;
            NNSSndArcWaveArcInfo *r;
            u32 v;
            u32 fileId;

            waveArcInfo = NNS_SndArcGetWaveArcInfo(0x62);
            r = NNS_SndArcGetWaveArcInfo(0x50);
            fileId = (r)->mFileId;
            v = waveArcInfo->mFileId;
            NNS_SndArcSetFileAddress(fileId, NNS_SndArcGetFileAddress(v));
            NNS_SndArcSetFileAddress(v, NULL);
            loaded = 1;
            listCount = data_0217d178.mCount;
            data_0217d178.mCount = listCount + 1;
            data_0217d178.mFileIds[listCount] = fileId;
        }
        if (loaded == 0) {
            return 0;
        }
    } else {
        if (NNS_SndArcLoadWaveArc(0, gSndHeapHandle) == 0) {
            return 0;
        }
        if (NNS_SndArcLoadWaveArc(0x50, gSndHeapHandle) == 0) {
            return 0;
        }
    }
    bankInfo = NNS_SndArcGetBankInfo(0);
    bankFile = NNS_SndArcGetFileAddress(bankInfo->mFileId);
    for (i = 0; i < 4; i++) {
        v = bankInfo->mWaveArcNo[i];
        if (v == 0xffff) {
            continue;
        }
        waveArcInfo = NNS_SndArcGetWaveArcInfo(v);
        if (waveArcInfo == NULL) {
            break;
        }
        fileId = waveArcInfo->mFileId;
        r = NNS_SndArcGetFileAddress(fileId);
        if (bankFile == NULL) {
            continue;
        }
        if (r == NULL) {
            continue;
        }
        SND_AssignWaveArc(bankFile, i, r);
    }
    if (loadGroup(groupId) == 0) {
        return 0;
    }
    return 1;
}

// Releases the loaded set and loads v unless it is empty or already loaded; d adds extra wave archives for some sets.
u32 LoadSoundSetIfChanged(SoundSet soundSet, u32 loadExtras) {
    SndFileIdList *p;
    u32 loaded;
    u32 listCount;
    s32 i;
    SndFileIdList *list;

    if (soundSet.mSeqId == 0xff && soundSet.field4 == 0xff && soundSet.field8 == 0xff) {
        return 1;
    }
    if (IsSoundSetLoaded(sound_getSeqHeapState(), soundSet) != 0) {
        return 1;
    }
    ReleaseSoundSet(sound_getSeqHeapState());
    p = &data_0217d134;
    for (i = 0; i < p->mCount; i++) {
        NNS_SndArcSetFileAddress(p->mFileIds[i], NULL);
    }
    list = &data_0217d134;
    for (i = 0; i < 16; i++) {
        list->mFileIds[i] = 0;
    }
    list->mCount = 0;
    if (loadExtras != 0) {
        switch (soundSet.mSeqId) {
            case 0x4a:
                if (NNS_SndArcLoadWaveArc(0x63, gSndHeapHandle) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    p = NNS_SndArcGetWaveArcInfo(0x63);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x31);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = p->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
                    loaded = 1;
                    listCount = data_0217d134.mCount;
                    data_0217d134.mCount = listCount + 1;
                    data_0217d134.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
            case 0x2b:
                if (NNS_SndArcLoadWaveArc(0x64, gSndHeapHandle) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    p = NNS_SndArcGetWaveArcInfo(0x64);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x58);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = p->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
                    loaded = 1;
                    listCount = data_0217d134.mCount;
                    data_0217d134.mCount = listCount + 1;
                    data_0217d134.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
            case 0xf:
                if (NNS_SndArcLoadWaveArc(0x34, gSndHeapHandle) == 0) {
                    loaded = 0;
                } else {
                    NNSSndArcWaveArcInfo *p;
                    NNSSndArcWaveArcInfo *destWaveArc;
                    u32 sourceFileId;
                    u32 destFileId;

                    p = NNS_SndArcGetWaveArcInfo(0x34);
                    destWaveArc = NNS_SndArcGetWaveArcInfo(0x33);
                    destFileId = destWaveArc->mFileId;
                    sourceFileId = p->mFileId;
                    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                    NNS_SndArcSetFileAddress(sourceFileId, NULL);
                    loaded = 1;
                    listCount = data_0217d134.mCount;
                    data_0217d134.mCount = listCount + 1;
                    data_0217d134.mFileIds[listCount] = destFileId;
                }
                if (loaded == 0) {
                    return 0;
                }
                break;
        }
        if (soundSet.field4 == 0x10) {
            if (NNS_SndArcLoadWaveArc(0x13, gSndHeapHandle) == 0) {
                loaded = 0;
            } else {
                NNSSndArcWaveArcInfo *p;
                NNSSndArcWaveArcInfo *destWaveArc;
                u32 sourceFileId;
                u32 destFileId;

                p = NNS_SndArcGetWaveArcInfo(0x13);
                destWaveArc = NNS_SndArcGetWaveArcInfo(0x12);
                destFileId = destWaveArc->mFileId;
                sourceFileId = p->mFileId;
                NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
                NNS_SndArcSetFileAddress(sourceFileId, NULL);
                loaded = 1;
                listCount = data_0217d134.mCount;
                data_0217d134.mCount = listCount + 1;
                data_0217d134.mFileIds[listCount] = destFileId;
            }
            if (loaded == 0) {
                return 0;
            }
        }
    }
    return LoadSoundSet(sound_getSeqHeapState(), soundSet) != 0;
}

void LoadCertainSwarSbnkSarc(void) {
    if (NNS_SndArcLoadWaveArc(1, gSndHeapHandle) == 0) {
        return;
    }
    if (NNS_SndArcLoadBankEx(0, 2, gSndHeapHandle) == 0) {
        return;
    }
    NNS_SndArcLoadSeqArc(0, gSndHeapHandle);
}

void sub_210E8F8(u32 moveWaveArcs) {
    PreLoadSounds(0, moveWaveArcs);
    saveHeapState(sound_getSeqHeapState());
}

void LoadSceneSoundSet(SoundRow soundRow, u32 loadExtras) {
    SoundSet soundSet;

    soundSet.mSeqId = soundRow.field0[1];
    soundSet.field4 = soundRow.field0[2];
    soundSet.field8 = soundRow.field0[3];
    LoadSoundSetIfChanged(soundSet, loadExtras);
    if (IsInRaceSceneNormalOrReplay() == 0) {
        return;
    }
    LoadSeqRowIfChanged(gRaceMultiConfig->mMode);
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

    NNS_SndArcSetCurrent(&SDATFile);
    loadResult = SetupSndArcFromFile(&gSdatFileSndArc, aDataSoundSou_0, gSndHeapHandle, 0);
    sound_setIsSdatLoaded(1);
    if (loadResult == 0) {
        return 0;
    }
    if (NNS_SndArcLoadSeqArc(1, gSndHeapHandle) == 0) {
        return 0;
    }
    sourceSeqArc = NNS_SndArcGetSeqArcInfo(1);
    destSeqArc = NNS_SndArcGetSeqArcInfo(0);
    sourceFileId = sourceSeqArc->mFileId;
    destFileId = destSeqArc->mFileId;
    NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
    NNS_SndArcSetFileAddress(sourceFileId, NULL);
    listCount = data_0217d178.mCount;
    data_0217d178.mCount = listCount + 1;
    data_0217d178.mFileIds[listCount] = destFileId;
    if (NNS_SndArcLoadWaveArc(0x3e, gSndHeapHandle) != 0) {
        sourceWaveArc = NNS_SndArcGetWaveArcInfo(0x3e);
        destWaveArc = NNS_SndArcGetWaveArcInfo(0x3d);
        destFileId = destWaveArc->mFileId;
        sourceFileId = sourceWaveArc->mFileId;
        NNS_SndArcSetFileAddress(destFileId, NNS_SndArcGetFileAddress(sourceFileId));
        NNS_SndArcSetFileAddress(sourceFileId, NULL);
        loaded = 1;
        listCount = data_0217d178.mCount;
        data_0217d178.mCount = listCount + 1;
        data_0217d178.mFileIds[listCount] = destFileId;
    } else {
        loaded = 0;
    }
    if (loaded == 0) {
        return 0;
    }
    if (NNS_SndArcLoadWaveArc(1, gSndHeapHandle) == 0) {
        loaded = 0;
    } else if (NNS_SndArcLoadBankEx(0, 2, gSndHeapHandle) == 0) {
        loaded = 0;
    } else if (NNS_SndArcLoadSeqArc(0, gSndHeapHandle) == 0) {
        loaded = 0;
    } else {
        loaded = 1;
    }
    if (loaded == 0) {
        return 0;
    }
    if (PreLoadSounds(1, 1) == 0) {
        return 0;
    }
    saveHeapState(sound_getSeqHeapState());
    return 1;
}

u32 LoadCourseSoundSet(u32 a, u32 b) {
    SoundRow row, rowCopy;
    SoundSet soundSet;
    u32 loaded;

    GetSequenceTableIndexAndData(b, &row);
    rowCopy = row;
    soundSet.mSeqId = rowCopy.field0[1];
    soundSet.field4 = rowCopy.field0[2];
    soundSet.field8 = rowCopy.field0[3];
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
    loaded = LoadSoundSetIfChanged(soundSet, 1) != 0;
    if (loaded != 0) {
        loaded = LoadSeqRowIfChanged(a);
    }
    return loaded;
}

u32 sub_210E524(void) {
    SoundRow row, rowCopy;
    SoundSet soundSet;

    row = GetSoundRow(0x29);
    row.field0[1] = snd_getResultSceneSeqId();
    rowCopy = row;
    soundSet.mSeqId = rowCopy.field0[1];
    soundSet.field4 = rowCopy.field0[2];
    soundSet.field8 = rowCopy.field0[3];
    NNS_SndArcSetCurrent(&gSdatFileSndArc);
    return LoadSoundSetIfChanged(soundSet, 1) != 0;
}

u32 loadGroup(s32 groupId) {
    return NNS_SndArcLoadGroup(groupId, gSndHeapHandle);
}

void ResetLoadedSoundSet(LoadedSoundSet *loadedSet) {
    loadedSet->mSoundSet = data_0215c398;
    loadedSet->mHeapState = 0xff00;
}

void saveHeapState(LoadedSoundSet *loadedSet) {
    loadedSet->mHeapState = NNS_SndHeapSaveState(gSndHeapHandle);
}

// Restores the heap to the state saved before the set was loaded.
void ReleaseSoundSet(LoadedSoundSet *loadedSet) {
    SoundSet emptySet = data_0215c380;

    if (emptySet.mSeqId == loadedSet->mSoundSet.mSeqId && emptySet.field4 == loadedSet->mSoundSet.field4 &&
        emptySet.field8 == loadedSet->mSoundSet.field8) {
        return;
    }
    NNS_SndHeapLoadState(gSndHeapHandle, loadedSet->mHeapState);
    NNS_SndHeapGetCurrentLevel(gSndHeapHandle);
    loadedSet->mSoundSet = data_0215c38c;
}

u32 IsSoundSetLoaded(LoadedSoundSet *loadedSet, SoundSet soundSet) {
    if (soundSet.mSeqId == loadedSet->mSoundSet.mSeqId && soundSet.field4 == loadedSet->mSoundSet.field4 &&
        soundSet.field8 == loadedSet->mSoundSet.field8) {
        return 1;
    }
    return 0;
}

u32 LoadSoundSet(LoadedSoundSet *loadedSet, SoundSet soundSet) {
    if (soundSet.mSeqId != 0xff && NNS_SndArcLoadSeq(soundSet.mSeqId, gSndHeapHandle) == 0) {
        return 0;
    }
    if (soundSet.field4 != 0xff && NNS_SndArcLoadBank(soundSet.field4, gSndHeapHandle) == 0) {
        return 0;
    }
    if (soundSet.field8 != 0xff && NNS_SndArcLoadBank(soundSet.field8, gSndHeapHandle) == 0) {
        return 0;
    }
    loadedSet->mSoundSet = soundSet;
    return 1;
}
