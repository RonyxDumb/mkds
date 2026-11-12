#include "code_0212d214.h"

#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_02003be0.h"
#include "code_0212f788.h"
#include "fs_file.h"
#include "code_0212d968.h"
#include "snd_command.h"
#include "code_0201750c.h"
#include "code_020172d0.h"
#include "frameheap.h"
#include "code_0214d018.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "snd_interface.h"
#include "os_thread.h"
#include "snd_bank.h"
#include "code_0212df7c.h"
#include "code_020218f4.h"

NNSSndArc *sCurrent;
SNDWaveArc sWaveArcHeader;

// Sets each player's sequence count and channels and creates its heaps.
BOOL NNS_SndArcPlayerSetup(NNSSndHeap *heap) {
    s32 playerIndex;
    NNSSndArcPlayerInfo *playerEntry;
    s32 seqIndex;

    NNS_SndArcGetCurrent();
    for (playerIndex = 0; playerIndex < 32; playerIndex++) {
        playerEntry = NNS_SndArcGetPlayerInfo(playerIndex);
        if (playerEntry == 0) {
            continue;
        }
        NNS_SndPlayerSetPlayableSeqCount(playerIndex, playerEntry->mSeqMax);
        NNS_SndPlayerSetAllocatableChannel(playerIndex, playerEntry->mAllocChBitFlag);
        if (playerEntry->mHeapSize == 0 || heap == 0) {
            continue;
        }
        for (seqIndex = 0; seqIndex < playerEntry->mSeqMax; seqIndex++) {
            if (NNS_SndPlayerCreateHeap(playerIndex, heap, playerEntry->mHeapSize) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

BOOL NNS_SndArcPlayerStartSeq(NNSSndSeqPlayer **handle, s32 seqNo) {
    NNSSndArcSeqInfo *info;

    info = NNS_SndArcGetSeqInfo(seqNo);
    if (info == 0) {
        return 0;
    }
    return StartSeq(handle, info->mParam.mPlayerNo, info->mParam.mBankNo, info->mParam.mPlayerPrio, info, seqNo);
}

BOOL NNS_SndArcPlayerStartSeqArc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index) {
    NNSSndSeqArc *seqArcData;
    NNSSndSeqArcSeqInfo *seqEntry;
    NNSSndArcSeqArcInfo *info;

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArcData = NNS_SndArcGetFileAddress(info->mFileId);
    if (seqArcData == 0) {
        return 0;
    }
    seqEntry = NNSi_SndSeqArcGetSeqInfo(seqArcData, index);
    if (seqEntry == 0) {
        return 0;
    }
    return StartSeqArc(handle, seqEntry->mParam.mPlayerNo, seqEntry->mParam.mBankNo, seqEntry->mParam.mPlayerPrio, seqEntry, seqArcData,
                       seqArcNo, index);
}

// A negative player, bank or priority takes the value from the entry.
BOOL NNS_SndArcPlayerStartSeqArcEx(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, s32 seqArcNo,
                                   s32 index) {
    NNSSndSeqArc *seqArcData;
    NNSSndSeqArcSeqInfo *seqEntry;
    NNSSndArcSeqArcInfo *info;

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArcData = NNS_SndArcGetFileAddress(info->mFileId);
    if (seqArcData == 0) {
        return 0;
    }
    seqEntry = NNSi_SndSeqArcGetSeqInfo(seqArcData, index);
    if (seqEntry == 0) {
        return 0;
    }
    if (playerPrio < 0) {
        playerPrio = seqEntry->mParam.mPlayerPrio;
    }
    if (bankNo < 0) {
        bankNo = seqEntry->mParam.mBankNo;
    }
    if (playerNo < 0) {
        playerNo = seqEntry->mParam.mPlayerNo;
    }
    return StartSeqArc(handle, playerNo, bankNo, playerPrio, seqEntry, seqArcData, seqArcNo, index);
}

BOOL StartSeq(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndArcSeqInfo *info, s32 seqNo) {
    NNSSndSeqPlayer *seqPlayer;
    NNSSndSeqData *seq;
    SNDBankData *bank;
    NNSSndHeap *heap;

    seqPlayer = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    if (seqPlayer == 0) {
        return 0;
    }
    heap = NNSi_SndPlayerAllocHeap(playerNo, seqPlayer);
    if (NNSi_SndArcLoadBank(bankNo, 6, heap, 0, &bank) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }
    if (NNSi_SndArcLoadSeq(seqNo, 1, heap, 0, &seq) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }
    NNSi_SndPlayerStartSeq(seqPlayer, (u8 *) seq + seq->mBaseOffset, 0, bank);
    NNS_SndPlayerSetInitialVolume(handle, info->mParam.mVolume);
    NNS_SndPlayerSetChannelPriority(handle, info->mParam.mChannelPrio);
    NNS_SndPlayerSetSeqNo(handle, seqNo);
    return 1;
}

BOOL StartSeqArc(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndSeqArcSeqInfo *sound,
                 NNSSndSeqArc *seqArc, u32 seqArcNo, u32 index) {
    void *seqPlayer;
    SNDBankData *bank;
    NNSSndHeap *heap;

    seqPlayer = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    if (seqPlayer == 0) {
        return 0;
    }
    heap = NNSi_SndPlayerAllocHeap(playerNo, seqPlayer);
    if (NNSi_SndArcLoadBank(bankNo, 6, heap, 0, &bank) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }
    NNSi_SndPlayerStartSeq(seqPlayer, (u8 *) seqArc + seqArc->mBaseOffset, sound->mOffset, bank);
    NNS_SndPlayerSetInitialVolume(handle, sound->mParam.mVolume);
    NNS_SndPlayerSetChannelPriority(handle, sound->mParam.mChannelPrio);
    NNS_SndPlayerSetSeqArcNo(handle, seqArcNo, index);
    return 1;
}

BOOL NNS_SndArcLoadGroup(s32 groupNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadGroup(groupNo, heap) == 0;
}

BOOL NNS_SndArcLoadSeq(s32 seqNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadSeq(seqNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadSeqArc(s32 seqArcNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadSeqArc(seqArcNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadBank(s32 bankNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadBank(bankNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadWaveArc(s32 waveArcNo, NNSSndHeap *heap) {
    return NNSi_SndArcLoadWaveArc(waveArcNo, 0xff, heap, 1, 0) == 0;
}

BOOL NNS_SndArcLoadBankEx(s32 bankNo, u32 loadFlag, NNSSndHeap *heap) {
    return NNSi_SndArcLoadBank(bankNo, loadFlag, heap, 1, 0) == 0;
}

NNSSndArcLoadResult NNSi_SndArcLoadGroup(s32 groupNo, NNSSndHeap *heap) {
    NNSSndArcGroupInfo *info;
    u32 itemIndex;
    NNSSndArcGroupItem *item;
    NNSSndArcLoadResult result;

    info = NNS_SndArcGetGroupInfo(groupNo);
    if (info == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_GROUP_NO;
    }
    for (itemIndex = 0; itemIndex < info->mCount; itemIndex++) {
        item = &info->mItem[itemIndex];
        switch (item->mType) {
            case 0:
                result = NNSi_SndArcLoadSeq(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case 3:
                result = NNSi_SndArcLoadSeqArc(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case 1:
                result = NNSi_SndArcLoadBank(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case 2:
                result = NNSi_SndArcLoadWaveArc(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
        }
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult NNSi_SndArcLoadSeq(s32 seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                       NNSSndSeqData **pData) {
    NNSSndArcSeqInfo *seqEntry;
    NNSSndSeqData *loadedSeq;
    NNSSndArcLoadResult result;

    seqEntry = NNS_SndArcGetSeqInfo(seqNo);
    if (seqEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQ_NO;
    }
    result = NNSi_SndArcLoadBank(seqEntry->mParam.mBankNo, loadFlag, heap, bSetAddr, 0);
    if (result != NNS_SND_ARC_LOAD_SUCESS) {
        return result;
    }
    if (loadFlag & 1) {
        loadedSeq = LoadSeq(seqEntry->mFileId, heap, bSetAddr);
        if (loadedSeq == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQ;
        }
    } else {
        loadedSeq = NNS_SndArcGetFileAddress(seqEntry->mFileId);
    }
    if (pData != 0) {
        *pData = loadedSeq;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult NNSi_SndArcLoadSeqArc(s32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                          NNSSndSeqArc **pData) {
    NNSSndArcSeqArcInfo *arcEntry;
    NNSSndSeqArc *loadedArc;

    arcEntry = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (arcEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQARC_NO;
    }
    if (loadFlag & 8) {
        loadedArc = LoadSeqArc(arcEntry->mFileId, heap, bSetAddr);
        if (loadedArc == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQARC;
        }
    } else {
        loadedArc = NNS_SndArcGetFileAddress(arcEntry->mFileId);
    }
    if (pData != 0) {
        *pData = loadedArc;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

// Loads the bank and its wave archives, and assigns them to the bank.
NNSSndArcLoadResult NNSi_SndArcLoadBank(s32 bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                        SNDBankData **pData) {
    NNSSndArcBankInfo *bankEntry;
    NNSSndArcWaveArcInfo *waveEntry;
    SNDWaveArc *loadedWaveArc;
    SNDBankData *bank;
    s32 waveArcIndex;
    u32 loadWave;
    NNSSndArcLoadResult result;

    bankEntry = NNS_SndArcGetBankInfo(bankNo);
    if (bankEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_BANK_NO;
    }
    if (loadFlag & 2) {
        bank = LoadBank(bankEntry->mFileId, heap, bSetAddr);
        if (bank == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_BANK;
        }
    } else {
        bank = NNS_SndArcGetFileAddress(bankEntry->mFileId);
    }
    loadWave = loadFlag & 4;
    for (waveArcIndex = 0; waveArcIndex < 4; waveArcIndex++) {
        if (bankEntry->mWaveArcNo[waveArcIndex] != 0xffff) {
            waveEntry = NNS_SndArcGetWaveArcInfo(bankEntry->mWaveArcNo[waveArcIndex]);
            if (waveEntry == 0) {
                return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;
            }
            result = NNSi_SndArcLoadWaveArc(bankEntry->mWaveArcNo[waveArcIndex], loadFlag, heap, bSetAddr, &loadedWaveArc);
            if (result != NNS_SND_ARC_LOAD_SUCESS) {
                return result;
            }
            if ((waveEntry->mFlags & 1) && loadWave) {
                if (LoadSingleWaves(loadedWaveArc, bank, waveArcIndex, waveEntry->mFileId, heap) == 0) {
                    return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE;
                }
            }
            if (bank != 0 && loadedWaveArc != 0) {
                SND_AssignWaveArc(bank, waveArcIndex, loadedWaveArc);
            }
        }
    }
    if (pData != 0) {
        *pData = bank;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult NNSi_SndArcLoadWaveArc(s32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                           SNDWaveArc **pData) {
    NNSSndArcWaveArcInfo *waveEntry;
    SNDWaveArc *loadedWaveArc;

    waveEntry = NNS_SndArcGetWaveArcInfo(waveArcNo);
    if (waveEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;
    }
    if (loadFlag & 4) {
        if (waveEntry->mFlags & 1) {
            loadedWaveArc = LoadWaveArcTable(waveEntry->mFileId, heap, bSetAddr);
        } else {
            loadedWaveArc = LoadWaveArc(waveEntry->mFileId, heap, bSetAddr);
        }
        if (loadedWaveArc == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE;
        }
    } else {
        loadedWaveArc = NNS_SndArcGetFileAddress(waveEntry->mFileId);
    }
    if (pData != 0) {
        *pData = loadedWaveArc;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

void *NNSi_SndArcLoadFile(u32 fileId, NNSSndHeapDisposeCallback callback, void *data1, u32 data2, NNSSndHeap *heap) {
    u32 size;
    u8 *buffer;

    size = NNS_SndArcGetFileSize(fileId);
    if (size == 0) {
        return 0;
    }
    if (heap == 0) {
        return 0;
    }
    buffer = NNS_SndHeapAlloc(heap, size + 0x20, callback, data1, data2);
    if (buffer == 0) {
        return 0;
    }
    if (NNS_SndArcReadFile(fileId, buffer, size, 0) != size) {
        return 0;
    }
    DC_StoreRange(buffer, size);
    return buffer;
}

NNSSndSeqData *LoadSeq(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = NNS_SndArcGetFileAddress(fileId);
    if (buffer == 0) {
        buffer = NNSi_SndArcLoadFile(fileId, SeqDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            NNS_SndArcSetFileAddress(fileId, buffer);
        }
    }
    return buffer;
}

NNSSndSeqArc *LoadSeqArc(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = NNS_SndArcGetFileAddress(fileId);
    if (buffer == 0) {
        buffer = NNSi_SndArcLoadFile(fileId, SeqDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            NNS_SndArcSetFileAddress(fileId, buffer);
        }
    }
    return buffer;
}

SNDBankData *LoadBank(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = NNS_SndArcGetFileAddress(fileId);
    if (buffer == 0) {
        buffer = NNSi_SndArcLoadFile(fileId, BankDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            NNS_SndArcSetFileAddress(fileId, buffer);
        }
    }
    return buffer;
}

SNDWaveArc *LoadWaveArc(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    SNDWaveArc *waveArc;

    waveArc = NNS_SndArcGetFileAddress(fileId);
    if (waveArc == 0) {
        waveArc =
            NNSi_SndArcLoadFile(fileId, WaveArcDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0, fileId, heap);
        if (bSetAddr != 0 && waveArc != 0) {
            NNS_SndArcSetFileAddress(fileId, waveArc);
        }
    }
    return waveArc;
}

// Loads the wave archive header and tables; the waves load one by one.
SNDWaveArc *LoadWaveArcTable(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    SNDWaveArc *tableArc;
    u32 len;
    u32 offsetBytes;
    s32 bytesRead;

    tableArc = NNS_SndArcGetFileAddress(fileId);
    if (tableArc == 0) {
        if (NNS_SndArcReadFile(fileId, &sWaveArcHeader, 0x3c, 0) != 0x3c) {
            return 0;
        }
        offsetBytes = sWaveArcHeader.mWaveCount * 4;
        len = offsetBytes * 2 + 0x3c;
        if (heap == 0) {
            return 0;
        }
        tableArc = NNS_SndHeapAlloc(heap, len + 0x20, WaveArcTableDisposeCallback, bSetAddr ? NNS_SndArcGetCurrent() : 0,
                                   fileId);
        if (tableArc == 0) {
            return 0;
        }
        bytesRead = NNS_SndArcReadFile(fileId, tableArc, offsetBytes + 0x3c, 0);
        if (bytesRead != offsetBytes + 0x3c) {
            return 0;
        }
        MI_CpuCopy8(tableArc->mWaveOffset, tableArc->mWaveOffset + tableArc->mWaveCount, offsetBytes);
        MI_CpuFill8(tableArc->mWaveOffset, 0, offsetBytes);
        DC_StoreRange(tableArc, len);
        if (bSetAddr != 0) {
            NNS_SndArcSetFileAddress(fileId, tableArc);
        }
    }
    return tableArc;
}

// Clears the file address when mem is still the loaded copy.
void DisposeCallback(void *mem, NNSSndArc *arc, u32 fileId) {
    NNSSndArc *previousArc;
    u32 enabled;

    if (arc == 0) {
        return;
    }
    enabled = OS_DisableInterrupts();
    previousArc = NNS_SndArcSetCurrent(arc);
    if (mem == NNS_SndArcGetFileAddress(fileId)) {
        NNS_SndArcSetFileAddress(fileId, 0);
    }
    NNS_SndArcSetCurrent(previousArc);
    OS_RestoreInterrupts(enabled);
}

void SeqDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_InvalidateSeqData(mem, (u8 *) mem + size);
}

void BankDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_InvalidateBankData(mem, (u8 *) mem + size);
    SND_DestroyBank(mem);
}

void WaveArcDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_InvalidateWaveData(mem, (u8 *) mem + size);
    SND_DestroyWaveArc(mem);
}

void WaveArcTableDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    DisposeCallback(mem, data1, data2);
    SND_DestroyWaveArc(mem);
}

void SingleWaveDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    u8 *wave = mem;

    if (wave == SND_GetWaveDataAddress(data1, data2)) {
        SND_SetWaveDataAddress(data1, data2, 0);
    }
    SND_InvalidateWaveData(wave, wave + size);
}

BOOL LoadSingleWave(SNDWaveArc *waveArc, s32 waveNo, u32 fileId, NNSSndHeap *heap) {
    u32 *entry;
    u32 waveTotal;
    u32 end;
    u32 len;
    u32 startOffset;
    void *buffer;

    if (SND_GetWaveDataAddress(waveArc, waveNo) != 0) {
        return 1;
    }
    waveTotal = SND_GetWaveDataCount(waveArc);
    entry = (u32 *) waveArc + (waveArc->mWaveCount + waveNo);
    startOffset = entry[15];
    end = waveNo < waveTotal - 1 ? entry[16] : waveArc->mUnk_08;
    len = end - startOffset;
    if (heap == 0) {
        return 0;
    }
    buffer = NNS_SndHeapAlloc(heap, len + 32, SingleWaveDisposeCallback, waveArc, waveNo);
    if (buffer == 0) {
        return 0;
    }
    if (NNS_SndArcReadFile(fileId, buffer, len, startOffset) != len) {
        return 0;
    }
    DC_StoreRange(buffer, len);
    SND_SetWaveDataAddress(waveArc, waveNo, buffer);
    return 1;
}

BOOL LoadSingleWaves(SNDWaveArc *waveArc, SNDBankData *bank, s32 waveArcNo, u32 fileId, NNSSndHeap *heap) {
    SNDInstPos pos;
    SNDInstPos firstPos;
    SNDInstData inst;

    SND_GetFirstInstDataPos(&firstPos);
    pos = firstPos;
    if (bank == 0) {
        return 0;
    }
    if (SND_GetNextInstData(bank, &inst, &pos) != 0) {
        do {
            if (inst.mType == 1 && waveArcNo == inst.mWave.mUnk_02) {
                if (LoadSingleWave(waveArc, inst.mWave.mUnk_00, fileId, heap) == 0) {
                    return 0;
                }
            }
        } while (SND_GetNextInstData(bank, &inst, &pos) != 0);
    }
    return 1;
}

NNSSndHeap *NNS_SndHeapCreate(void *startAddress, u32 size) {
    NNSSndHeap *heap;
    void *handle;
    u32 end;
    u32 remaining;

    end = (u32) startAddress + size;
    heap = (NNSSndHeap *) (((u32) startAddress + 3) & ~3);
    if ((u32) heap > end) {
        return 0;
    }
    remaining = end - (u32) heap;
    if (remaining < 16) {
        return 0;
    }
    handle = NNS_FndCreateFrmHeapEx(heap + 1, remaining - 16, 0);
    if (handle == 0) {
        return 0;
    }
    if (InitHeap(heap, handle) != 0) {
        return heap;
    }
    NNS_FndDestroyFrmHeap(handle);
    return 0;
}

void NNS_SndHeapDestroy(NNSSndHeap *heap) {
    NNS_SndHeapClear(heap);
    NNS_FndDestroyFrmHeap(heap->mHandle);
}

void NNS_SndHeapClear(NNSSndHeap *heap) {
    NNSSndHeapSection *heapSection;
    void *listItem;
    u32 calledBack = 0;

    for (heapSection = NNS_FndGetPrevListObject(&heap->mSectionList, 0); heapSection != 0;
         heapSection = NNS_FndGetPrevListObject(&heap->mSectionList, 0)) {
        for (listItem = NNS_FndGetPrevListObject(&heapSection->mBlockList, 0); listItem != 0;
             listItem = NNS_FndGetPrevListObject(&heapSection->mBlockList, listItem)) {
            NNSSndHeapBlock *heapBlock = listItem;

            if (heapBlock->mCallback != 0) {
                heapBlock->mCallback(heapBlock + 1, heapBlock->mSize, heapBlock->mData1, heapBlock->mData2);
                calledBack = 1;
            }
        }
        NNS_FndRemoveListObject(&heap->mSectionList, heapSection);
    }
    NNS_FndFreeToFrmHeap(heap->mHandle, 3);
    if (calledBack != 0) {
        EraseSync();
    }
    NewSection(heap);
}

// Allocates behind a 32-byte block header holding the dispose callback.
void *NNS_SndHeapAlloc(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, void *data1, u32 data2) {
    NNSSndHeapBlock *heapBlock;
    NNSSndHeapSection *heapSection;

    heapBlock = NNS_FndAllocFromFrmHeapEx(heap->mHandle, ((size + 31) & ~31) + 32, 32);
    if (heapBlock == 0) {
        return 0;
    }
    heapSection = NNS_FndGetPrevListObject(&heap->mSectionList, 0);
    heapBlock->mSize = size;
    heapBlock->mCallback = callback;
    heapBlock->mData1 = data1;
    heapBlock->mData2 = data2;
    NNS_FndAppendListObject(&heapSection->mBlockList, heapBlock);
    return heapBlock + 1;
}

// Returns the level for NNS_SndHeapLoadState, or -1.
s32 NNS_SndHeapSaveState(NNSSndHeap *heap) {
    if (NNS_FndRecordStateForFrmHeap(heap->mHandle, heap->mSectionList.mCount) == 0) {
        return -1;
    }
    if (NewSection(heap) != 0) {
        return heap->mSectionList.mCount - 1;
    }
    NNS_FndFreeByStateToFrmHeap(heap->mHandle, 0);
    return -1;
}

// Frees the sections above level; level 0 clears the heap.
void NNS_SndHeapLoadState(NNSSndHeap *heap, s32 level) {
    NNSSndHeapSection *heapSection;
    void *listItem = 0;
    u32 calledBack = 0;

    if (level == 0) {
        NNS_SndHeapClear(heap);
        return;
    }
    if (level < heap->mSectionList.mCount) {
        do {
            heapSection = NNS_FndGetPrevListObject(&heap->mSectionList, 0);
            for (listItem = NNS_FndGetPrevListObject(&heapSection->mBlockList, listItem); listItem != 0;
                 listItem = NNS_FndGetPrevListObject(&heapSection->mBlockList, listItem)) {
                NNSSndHeapBlock *heapBlock = listItem;

                if (heapBlock->mCallback != 0) {
                    heapBlock->mCallback(heapBlock + 1, heapBlock->mSize, heapBlock->mData1, heapBlock->mData2);
                    calledBack = 1;
                }
            }
            NNS_FndRemoveListObject(&heap->mSectionList, heapSection);
        } while (level < heap->mSectionList.mCount);
    }
    NNS_FndFreeByStateToFrmHeap(heap->mHandle, level);
    if (calledBack != 0) {
        EraseSync();
    }
    NNS_FndRecordStateForFrmHeap(heap->mHandle, heap->mSectionList.mCount);
    NewSection(heap);
}

s32 NNS_SndHeapGetCurrentLevel(NNSSndHeap *heap) {
    return heap->mSectionList.mCount - 1;
}

void InitHeapSection(NNSSndHeapSection *section) {
    NNS_FndInitList(&section->mBlockList, 0);
}

BOOL InitHeap(NNSSndHeap *heap, void *handle) {
    NNS_FndInitList(&heap->mSectionList, 12);
    heap->mHandle = handle;
    return NewSection(heap) != 0;
}

BOOL NewSection(NNSSndHeap *heap) {
    NNSSndHeapSection *newSection;

    newSection = NNS_FndAllocFromFrmHeapEx(heap->mHandle, 0x14, 4);
    if (newSection == 0) {
        return 0;
    }
    InitHeapSection(newSection);
    NNS_FndAppendListObject(&heap->mSectionList, newSection);
    return 1;
}

void EraseSync(void) {
    u32 pendingTag;

    pendingTag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(pendingTag);
}

void NNS_SndArcInit(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    arc->mInfo = 0;
    arc->mFat = 0;
    arc->mSymbol = 0;
    if (FS_ConvertPathToFileID(&arc->mFileId, filePath) == 0) {
        return;
    }
    FS_InitFile(&arc->mFile);
    if (FS_OpenFileFast(&arc->mFile, arc->mFileId) == 0) {
        return;
    }
    arc->mFileOpen = 1;
    if (NNS_SndArcSetup(arc, heap, symbolLoadFlag) != 0) {
        sCurrent = arc;
    }
}

BOOL NNS_SndArcSetup(NNSSndArc *arc, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    s32 bytesRead;

    if (FS_SeekFile(&arc->mFile, 0, 0) == 0) {
        return 0;
    }
    if (FS_ReadFile(&arc->mFile, &arc->mHeader, 0x30) != 0x30) {
        return 0;
    }
    if (heap != 0) {
        arc->mInfo = NNS_SndHeapAlloc(heap, arc->mHeader.mInfoSize, InfoDisposeCallback, arc, 0);
        if (arc->mInfo == 0) {
            return 0;
        }
        if (FS_SeekFile(&arc->mFile, arc->mHeader.mInfoOffset, 0) == 0) {
            return 0;
        }
        bytesRead = FS_ReadFile(&arc->mFile, arc->mInfo, arc->mHeader.mInfoSize);
        if (bytesRead != arc->mHeader.mInfoSize) {
            return 0;
        }
        arc->mFat = NNS_SndHeapAlloc(heap, arc->mHeader.mFatSize, FatDisposeCallback, arc, 0);
        if (arc->mFat == 0) {
            return 0;
        }
        if (FS_SeekFile(&arc->mFile, arc->mHeader.mFatOffset, 0) == 0) {
            return 0;
        }
        bytesRead = FS_ReadFile(&arc->mFile, arc->mFat, arc->mHeader.mFatSize);
        if (bytesRead != arc->mHeader.mFatSize) {
            return 0;
        }
        if (symbolLoadFlag != 0 && arc->mHeader.mSymbolDataSize != 0) {
            arc->mSymbol = NNS_SndHeapAlloc(heap, arc->mHeader.mSymbolDataSize, SymbolDisposeCallback, arc, 0);
            if (arc->mSymbol == 0) {
                return 0;
            }
            if (FS_SeekFile(&arc->mFile, arc->mHeader.mSymbolDataOffset, 0) == 0) {
                return 0;
            }
            bytesRead = FS_ReadFile(&arc->mFile, arc->mSymbol, arc->mHeader.mSymbolDataSize);
            if (bytesRead != arc->mHeader.mSymbolDataSize) {
                return 0;
            }
        }
    }
    return 1;
}

// Points the blocks and files into an archive already in memory.
void NNS_SndArcInitOnMemory(NNSSndArc *arc, void *data) {
    u32 fileIndex;

    MIi_CpuCopy32(data, &arc->mHeader, 0x30);
    arc->mInfo = arc->mHeader.mInfoOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcInfo, data, arc->mHeader.mInfoOffset);
    arc->mFat = arc->mHeader.mFatOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcFat, data, arc->mHeader.mFatOffset);
    arc->mSymbol =
        arc->mHeader.mSymbolDataOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcSymbol, data, arc->mHeader.mSymbolDataOffset);
    for (fileIndex = 0; fileIndex < arc->mFat->mCount; fileIndex++) {
        NNSSndArcFileInfo *file = &arc->mFat->mFiles[fileIndex];

        file->mMem = file->mOffset == 0 ? 0 : (u8 *) data + file->mOffset;
    }
    arc->mFileOpen = 0;
    sCurrent = arc;
}

NNSSndArc *NNS_SndArcSetCurrent(NNSSndArc *arc) {
    NNSSndArc *previousArc = sCurrent;

    sCurrent = arc;
    return previousArc;
}

NNSSndArc *NNS_SndArcGetCurrent(void) {
    return sCurrent;
}

NNSSndSeqParam *NNS_SndArcGetSeqArcParam(s32 seqArcNo, s32 index) {
    NNSSndArcSeqArcInfo *info;
    NNSSndSeqArc *seqArcData;
    NNSSndSeqArcSeqInfo *seqEntry;

    info = NNS_SndArcGetSeqArcInfo(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArcData = NNS_SndArcGetFileAddress(info->mFileId);
    if (seqArcData == 0) {
        return 0;
    }
    seqEntry = NNSi_SndSeqArcGetSeqInfo(seqArcData, index);
    if (seqEntry == 0) {
        return 0;
    }
    return &seqEntry->mParam;
}

NNSSndArcSeqInfo *NNS_SndArcGetSeqInfo(s32 seqNo) {
    NNSSndArc *arc = sCurrent;
    NNSSndArcOffsetTable *offsetTable;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mSeqOffset;
    offsetTable = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (offsetTable == 0) {
        return 0;
    }
    if (seqNo < 0) {
        return 0;
    }
    if (seqNo >= offsetTable->mCount) {
        return 0;
    }
    offset = offsetTable->mOffset[seqNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcSeqInfo *) (base + offset);
}

NNSSndArcSeqArcInfo *NNS_SndArcGetSeqArcInfo(s32 seqArcNo) {
    NNSSndArc *arc = sCurrent;
    NNSSndArcOffsetTable *offsetTable;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mSeqArcOffset;
    offsetTable = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (offsetTable == 0) {
        return 0;
    }
    if (seqArcNo < 0) {
        return 0;
    }
    if (seqArcNo >= offsetTable->mCount) {
        return 0;
    }
    offset = offsetTable->mOffset[seqArcNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcSeqArcInfo *) (base + offset);
}

NNSSndArcBankInfo *NNS_SndArcGetBankInfo(s32 bankNo) {
    NNSSndArc *arc = sCurrent;
    NNSSndArcOffsetTable *offsetTable;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mBankOffset;
    offsetTable = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (offsetTable == 0) {
        return 0;
    }
    if (bankNo < 0) {
        return 0;
    }
    if (bankNo >= offsetTable->mCount) {
        return 0;
    }
    offset = offsetTable->mOffset[bankNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcBankInfo *) (base + offset);
}

NNSSndArcWaveArcInfo *NNS_SndArcGetWaveArcInfo(s32 waveArcNo) {
    NNSSndArc *arc = sCurrent;
    NNSSndArcOffsetTable *offsetTable;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mWaveArcOffset;
    offsetTable = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (offsetTable == 0) {
        return 0;
    }
    if (waveArcNo < 0) {
        return 0;
    }
    if (waveArcNo >= offsetTable->mCount) {
        return 0;
    }
    offset = offsetTable->mOffset[waveArcNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcWaveArcInfo *) (base + offset);
}

NNSSndArcPlayerInfo *NNS_SndArcGetPlayerInfo(s32 playerNo) {
    NNSSndArc *arc = sCurrent;
    NNSSndArcOffsetTable *offsetTable;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mPlayerInfoOffset;
    offsetTable = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (offsetTable == 0) {
        return 0;
    }
    if (playerNo < 0) {
        return 0;
    }
    if (playerNo >= offsetTable->mCount) {
        return 0;
    }
    offset = offsetTable->mOffset[playerNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcPlayerInfo *) (base + offset);
}

NNSSndArcGroupInfo *NNS_SndArcGetGroupInfo(s32 groupNo) {
    NNSSndArc *arc = sCurrent;
    NNSSndArcOffsetTable *offsetTable;
    u32 offset;
    u8 *base;

    offset = arc->mInfo->mGroupInfoOffset;
    offsetTable = offset == 0 ? 0 : OFFSET_PTR(NNSSndArcOffsetTable, arc->mInfo, offset);
    if (offsetTable == 0) {
        return 0;
    }
    if (groupNo < 0) {
        return 0;
    }
    if (groupNo >= offsetTable->mCount) {
        return 0;
    }
    offset = offsetTable->mOffset[groupNo];
    base = (u8 *) arc->mInfo;
    return offset == 0 ? 0 : (NNSSndArcGroupInfo *) (base + offset);
}

u32 NNS_SndArcGetFileSize(u32 fileId) {
    NNSSndArcFat *fat = sCurrent->mFat;

    if (fileId >= fat->mCount) {
        return 0;
    }
    return fat->mFiles[fileId].mSize;
}

// Returns the number of bytes read, or -1.
s32 NNS_SndArcReadFile(u32 fileId, void *buffer, u32 size, u32 offset) {
    NNSSndArc *arc = sCurrent;
    NNSSndArcFat *fat;
    NNSSndArcFileInfo *file;
    u32 left;

    fat = arc->mFat;
    if (fileId >= fat->mCount) {
        return -1;
    }
    file = &fat->mFiles[fileId];
    left = file->mSize - offset;
    if (size > left) {
        size = left;
    }
    if (FS_SeekFile(&arc->mFile, file->mOffset + offset, 0) == 0) {
        return -1;
    }
    return FS_ReadFile(&arc->mFile, buffer, size);
}

void *NNS_SndArcGetFileAddress(u32 fileId) {
    NNSSndArcFat *fat = sCurrent->mFat;

    if (fileId >= fat->mCount) {
        return 0;
    }
    return fat->mFiles[fileId].mMem;
}

void NNS_SndArcSetFileAddress(u32 fileId, void *address) {
    sCurrent->mFat->mFiles[fileId].mMem = address;
}

void InfoDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    NNSSndArc *arc = data1;

    arc->mInfo = 0;
}

void FatDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    NNSSndArc *arc = data1;

    arc->mFat = 0;
}

void SymbolDisposeCallback(void *mem, u32 size, void *data1, u32 data2) {
    NNSSndArc *arc = data1;

    arc->mSymbol = 0;
}
