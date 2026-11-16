#include "sound_archive_load.h"

#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "file_archive_access.h"
#include "sound_fader.h"
#include "file_handle_setup.h"
#include "sound_heap_sections.h"
#include "sound_command_queue.h"
#include "linked_list_init.h"
#include "linked_list_ops.h"
#include "heap_frame_allocator.h"
#include "cpu_copy_fill.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "sound_command_requests.h"
#include "thread_scheduler.h"
#include "sound_bank_wave_archive.h"
#include "sound_archive_load_result.h"
#include "sound_wave_channel_volume.h"

NNSSndArc *g_ActiveSdat;
SNDWaveArc g_SomeSwarHeader;

// Sets each player's sequence count and channels and creates its heaps.
BOOL NNS_SndArcPlayerSetup(NNSSndHeap *heap) {
    s32 playerIndex;
    NNSSndArcPlayerInfo *playerEntry;
    s32 seqIndex;

    Sound_GetActiveSdat();
    for (playerIndex = 0; playerIndex < 32; playerIndex++) {
        playerEntry = Sound_GetPlayerInfoEntry(playerIndex);
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

    info = Sound_GetSseqInfoEntry(seqNo);
    if (info == 0) {
        return 0;
    }
    return MaybeStartSeq(handle, info->mParam.mPlayerNo, info->mParam.mBankNo, info->mParam.mPlayerPrio, info, seqNo);
}

BOOL PlaySseqFromSarc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index) {
    NNSSndSeqArc *seqArcData;
    NNSSndSeqArcSeqInfo *seqEntry;
    NNSSndArcSeqArcInfo *info;

    info = Sound_GetSarcInfoEntry(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArcData = Sound_MaybeGetRawFilePointer(info->mFileId);
    if (seqArcData == 0) {
        return 0;
    }
    seqEntry = NNSi_SndSeqArcGetSeqInfo(seqArcData, index);
    if (seqEntry == 0) {
        return 0;
    }
    return StartSeqArc(handle, seqEntry->mParam.mPlayerNo, seqEntry->mParam.mBankNo, seqEntry->mParam.mPlayerPrio,
                       seqEntry, seqArcData, seqArcNo, index);
}

// A negative player, bank or priority takes the value from the entry.
BOOL NNS_SndArcPlayerStartSeqArcEx(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, s32 seqArcNo,
                                   s32 index) {
    NNSSndSeqArc *seqArcData;
    NNSSndSeqArcSeqInfo *seqEntry;
    NNSSndArcSeqArcInfo *info;

    info = Sound_GetSarcInfoEntry(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArcData = Sound_MaybeGetRawFilePointer(info->mFileId);
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

BOOL MaybeStartSeq(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndArcSeqInfo *info, s32 seqNo) {
    NNSSndSeqPlayer *seqPlayer;
    NNSSndSeqData *seq;
    SNDBankData *bank;
    NNSSndHeap *heap;

    seqPlayer = NNSi_SndPlayerAllocSeqPlayer(handle, playerNo, playerPrio);
    if (seqPlayer == 0) {
        return 0;
    }
    heap = NNSi_SndPlayerAllocHeap(playerNo, seqPlayer);
    if (Sound_GetSbnkPointer(bankNo, 6, heap, 0, &bank) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }
    if (Sound_GetSseqPointer(seqNo, 1, heap, 0, &seq) != 0) {
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
    if (Sound_GetSbnkPointer(bankNo, 6, heap, 0, &bank) != 0) {
        NNSi_SndPlayerFreeSeqPlayer(seqPlayer);
        return 0;
    }
    NNSi_SndPlayerStartSeq(seqPlayer, (u8 *) seqArc + seqArc->mBaseOffset, sound->mOffset, bank);
    NNS_SndPlayerSetInitialVolume(handle, sound->mParam.mVolume);
    NNS_SndPlayerSetChannelPriority(handle, sound->mParam.mChannelPrio);
    NNS_SndPlayerSetSeqArcNo(handle, seqArcNo, index);
    return 1;
}

BOOL Sound_LoadGroup(s32 groupNo, NNSSndHeap *heap) {
    return Sound_LoadGroupImpl(groupNo, heap) == 0;
}

BOOL CheckMaybeLoadSseqOk(s32 seqNo, NNSSndHeap *heap) {
    return Sound_GetSseqPointer(seqNo, 0xff, heap, 1, 0) == 0;
}

BOOL Sound_LoadSarc(s32 seqArcNo, NNSSndHeap *heap) {
    return Sound_GetSarcPointer(seqArcNo, 0xff, heap, 1, 0) == 0;
}

BOOL Sound_LoadSbnk(s32 bankNo, NNSSndHeap *heap) {
    return Sound_GetSbnkPointer(bankNo, 0xff, heap, 1, 0) == 0;
}

BOOL Sound_LoadSwar(s32 waveArcNo, NNSSndHeap *heap) {
    return Sound_GetSwarPointer(waveArcNo, 0xff, heap, 1, 0) == 0;
}

BOOL Sound_LoadSbnkWithFlags(s32 bankNo, u32 loadFlag, NNSSndHeap *heap) {
    return Sound_GetSbnkPointer(bankNo, loadFlag, heap, 1, 0) == 0;
}

NNSSndArcLoadResult Sound_LoadGroupImpl(s32 groupNo, NNSSndHeap *heap) {
    NNSSndArcGroupInfo *info;
    u32 itemIndex;
    NNSSndArcGroupItem *item;
    NNSSndArcLoadResult result;

    info = Sound_GetGroupInfoEntry(groupNo);
    if (info == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_GROUP_NO;
    }
    for (itemIndex = 0; itemIndex < info->mCount; itemIndex++) {
        item = &info->mItem[itemIndex];
        switch (item->mType) {
            case GROUP_ITEM_SEQUENCE:
                result = Sound_GetSseqPointer(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case GROUP_ITEM_SEQUENCE_SET:
                result = Sound_GetSarcPointer(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case GROUP_ITEM_SOUND_BANK:
                result = Sound_GetSbnkPointer(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
            case GROUP_ITEM_WAVE_SET:
                result = Sound_GetSwarPointer(item->mIndex, item->mLoadFlag, heap, 1, 0);
                if (result != NNS_SND_ARC_LOAD_SUCESS) {
                    return result;
                }
                break;
        }
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult Sound_GetSseqPointer(s32 seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                       NNSSndSeqData **pData) {
    NNSSndArcSeqInfo *seqEntry;
    NNSSndSeqData *loadedSeq;
    NNSSndArcLoadResult result;

    seqEntry = Sound_GetSseqInfoEntry(seqNo);
    if (seqEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQ_NO;
    }
    result = Sound_GetSbnkPointer(seqEntry->mParam.mBankNo, loadFlag, heap, bSetAddr, 0);
    if (result != NNS_SND_ARC_LOAD_SUCESS) {
        return result;
    }
    if (loadFlag & 1) {
        loadedSeq = Sound_PrepareSseqData(seqEntry->mFileId, heap, bSetAddr);
        if (loadedSeq == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQ;
        }
    } else {
        loadedSeq = Sound_MaybeGetRawFilePointer(seqEntry->mFileId);
    }
    if (pData != 0) {
        *pData = loadedSeq;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

NNSSndArcLoadResult Sound_GetSarcPointer(s32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                          NNSSndSeqArc **pData) {
    NNSSndArcSeqArcInfo *arcEntry;
    NNSSndSeqArc *loadedArc;

    arcEntry = Sound_GetSarcInfoEntry(seqArcNo);
    if (arcEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_SEQARC_NO;
    }
    if (loadFlag & 8) {
        loadedArc = Sound_PrepareSarcData(arcEntry->mFileId, heap, bSetAddr);
        if (loadedArc == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQARC;
        }
    } else {
        loadedArc = Sound_MaybeGetRawFilePointer(arcEntry->mFileId);
    }
    if (pData != 0) {
        *pData = loadedArc;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

// Loads the bank and its wave archives, and assigns them to the bank.
NNSSndArcLoadResult Sound_GetSbnkPointer(s32 bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                        SNDBankData **pData) {
    NNSSndArcBankInfo *bankEntry;
    NNSSndArcWaveArcInfo *waveEntry;
    SNDWaveArc *loadedWaveArc;
    SNDBankData *bank;
    s32 waveArcIndex;
    u32 loadWave;
    NNSSndArcLoadResult result;

    bankEntry = Sound_GetSbnkInfoEntry(bankNo);
    if (bankEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_BANK_NO;
    }
    if (loadFlag & 2) {
        bank = Sound_PrepareSbnkData(bankEntry->mFileId, heap, bSetAddr);
        if (bank == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_BANK;
        }
    } else {
        bank = Sound_MaybeGetRawFilePointer(bankEntry->mFileId);
    }
    loadWave = loadFlag & 4;
    for (waveArcIndex = 0; waveArcIndex < 4; waveArcIndex++) {
        if (bankEntry->mWaveArcNo[waveArcIndex] != 0xffff) {
            waveEntry = Sound_GetSwarInfoEntry(bankEntry->mWaveArcNo[waveArcIndex]);
            if (waveEntry == 0) {
                return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;
            }
            result =
                Sound_GetSwarPointer(bankEntry->mWaveArcNo[waveArcIndex], loadFlag, heap, bSetAddr, &loadedWaveArc);
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

NNSSndArcLoadResult Sound_GetSwarPointer(s32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                           SNDWaveArc **pData) {
    NNSSndArcWaveArcInfo *waveEntry;
    SNDWaveArc *loadedWaveArc;

    waveEntry = Sound_GetSwarInfoEntry(waveArcNo);
    if (waveEntry == 0) {
        return NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO;
    }
    if (loadFlag & 4) {
        if (waveEntry->mFlags & 1) {
            loadedWaveArc = Sound_PrepareSwarDataImpl(waveEntry->mFileId, heap, bSetAddr);
        } else {
            loadedWaveArc = Sound_PrepareSwarData(waveEntry->mFileId, heap, bSetAddr);
        }
        if (loadedWaveArc == 0) {
            return NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE;
        }
    } else {
        loadedWaveArc = Sound_MaybeGetRawFilePointer(waveEntry->mFileId);
    }
    if (pData != 0) {
        *pData = loadedWaveArc;
    }
    return NNS_SND_ARC_LOAD_SUCESS;
}

void *Sound_AllocateReadEntireFile(u32 fileId, NNSSndHeapDisposeCallback callback, void *data1, u32 data2, NNSSndHeap *heap) {
    u32 size;
    u8 *buffer;

    size = Sound_GetFileSize(fileId);
    if (size == 0) {
        return 0;
    }
    if (heap == 0) {
        return 0;
    }
    buffer = Sound_Context_Allocate(heap, size + 0x20, callback, data1, data2);
    if (buffer == 0) {
        return 0;
    }
    if (Sound_ReadFile(fileId, buffer, size, 0) != size) {
        return 0;
    }
    DC_SomeClean(buffer, size);
    return buffer;
}

NNSSndSeqData *Sound_PrepareSseqData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = Sound_MaybeGetRawFilePointer(fileId);
    if (buffer == 0) {
        buffer = Sound_AllocateReadEntireFile(fileId, Sound_DtorFn_SomeSarcPointer, bSetAddr ? Sound_GetActiveSdat() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            Sound_SetFileFatDynamicOffsetField(fileId, buffer);
        }
    }
    return buffer;
}

NNSSndSeqArc *Sound_PrepareSarcData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = Sound_MaybeGetRawFilePointer(fileId);
    if (buffer == 0) {
        buffer = Sound_AllocateReadEntireFile(fileId, Sound_DtorFn_SomeSarcPointer, bSetAddr ? Sound_GetActiveSdat() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            Sound_SetFileFatDynamicOffsetField(fileId, buffer);
        }
    }
    return buffer;
}

SNDBankData *Sound_PrepareSbnkData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    void *buffer;

    buffer = Sound_MaybeGetRawFilePointer(fileId);
    if (buffer == 0) {
        buffer = Sound_AllocateReadEntireFile(fileId, SomeSoundDtorFn, bSetAddr ? Sound_GetActiveSdat() : 0, fileId, heap);
        if (bSetAddr != 0 && buffer != 0) {
            Sound_SetFileFatDynamicOffsetField(fileId, buffer);
        }
    }
    return buffer;
}

SNDWaveArc *Sound_PrepareSwarData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    SNDWaveArc *waveArc;

    waveArc = Sound_MaybeGetRawFilePointer(fileId);
    if (waveArc == 0) {
        waveArc =
            Sound_AllocateReadEntireFile(fileId, AnotherSoundDtorFn, bSetAddr ? Sound_GetActiveSdat() : 0, fileId, heap);
        if (bSetAddr != 0 && waveArc != 0) {
            Sound_SetFileFatDynamicOffsetField(fileId, waveArc);
        }
    }
    return waveArc;
}

// Loads the wave archive header and tables; the waves load one by one.
SNDWaveArc *Sound_PrepareSwarDataImpl(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr) {
    SNDWaveArc *tableArc;
    u32 len;
    u32 offsetBytes;
    s32 bytesRead;

    tableArc = Sound_MaybeGetRawFilePointer(fileId);
    if (tableArc == 0) {
        if (Sound_ReadFile(fileId, &g_SomeSwarHeader, 0x3c, 0) != 0x3c) {
            return 0;
        }
        offsetBytes = g_SomeSwarHeader.mWaveCount * 4;
        len = offsetBytes * 2 + 0x3c;
        if (heap == 0) {
            return 0;
        }
        tableArc = Sound_Context_Allocate(heap, len + 0x20, Sound_DtorFn_SwarHeader,
                                    bSetAddr ? Sound_GetActiveSdat() : 0, fileId);
        if (tableArc == 0) {
            return 0;
        }
        bytesRead = Sound_ReadFile(fileId, tableArc, offsetBytes + 0x3c, 0);
        if (bytesRead != offsetBytes + 0x3c) {
            return 0;
        }
        Mem_CpuCopy8(tableArc->mWaveOffset, tableArc->mWaveOffset + tableArc->mWaveCount, offsetBytes);
        Mem_CpuFill8(tableArc->mWaveOffset, 0, offsetBytes);
        DC_SomeClean(tableArc, len);
        if (bSetAddr != 0) {
            Sound_SetFileFatDynamicOffsetField(fileId, tableArc);
        }
    }
    return tableArc;
}

// Clears the file address when mem is still the loaded copy.
void Sound_DisposeFile(void *mem, NNSSndArc *arc, u32 fileId) {
    NNSSndArc *previousArc;
    u32 enabled;

    if (arc == 0) {
        return;
    }
    enabled = Os_DisableIrq();
    previousArc = Sound_MaybeSetActiveSdat(arc);
    if (mem == Sound_MaybeGetRawFilePointer(fileId)) {
        Sound_SetFileFatDynamicOffsetField(fileId, 0);
    }
    Sound_MaybeSetActiveSdat(previousArc);
    Os_RestoreIrq(enabled);
}

void Sound_DtorFn_SomeSarcPointer(void *mem, u32 size, void *data1, u32 data2) {
    Sound_DisposeFile(mem, data1, data2);
    SND_InvalidateSeqData(mem, (u8 *) mem + size);
}

void SomeSoundDtorFn(void *mem, u32 size, void *data1, u32 data2) {
    Sound_DisposeFile(mem, data1, data2);
    SND_InvalidateBankData(mem, (u8 *) mem + size);
    SND_DestroyBank(mem);
}

void AnotherSoundDtorFn(void *mem, u32 size, void *data1, u32 data2) {
    Sound_DisposeFile(mem, data1, data2);
    SND_InvalidateWaveData(mem, (u8 *) mem + size);
    SND_DestroyWaveArc(mem);
}

void Sound_DtorFn_SwarHeader(void *mem, u32 size, void *data1, u32 data2) {
    Sound_DisposeFile(mem, data1, data2);
    SND_DestroyWaveArc(mem);
}

void AndAndAnotherSoundDtorFn(void *mem, u32 size, void *data1, u32 data2) {
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
    end = waveNo < waveTotal - 1 ? entry[16] : waveArc->mFileSize;
    len = end - startOffset;
    if (heap == 0) {
        return 0;
    }
    buffer = Sound_Context_Allocate(heap, len + 32, AndAndAnotherSoundDtorFn, waveArc, waveNo);
    if (buffer == 0) {
        return 0;
    }
    if (Sound_ReadFile(fileId, buffer, len, startOffset) != len) {
        return 0;
    }
    DC_SomeClean(buffer, len);
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
            if (inst.mType == 1 && waveArcNo == inst.mWave.mSecond) {
                if (LoadSingleWave(waveArc, inst.mWave.mFirst, fileId, heap) == 0) {
                    return 0;
                }
            }
        } while (SND_GetNextInstData(bank, &inst, &pos) != 0);
    }
    return 1;
}

NNSSndHeap *Sound_InitializeContext(void *startAddress, u32 size) {
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
    handle = Mem_Frame_Create(heap + 1, remaining - 16, 0);
    if (handle == 0) {
        return 0;
    }
    if (Sound_Context_SetHeap(heap, handle) != 0) {
        return heap;
    }
    Mem_Frame_Finalize(handle);
    return 0;
}

void Sound_Context_Dispose(NNSSndHeap *heap) {
    Sound_Context_DisposeLoadedStuff(heap);
    Mem_Frame_Finalize(heap->mHandle);
}

void Sound_Context_DisposeLoadedStuff(NNSSndHeap *heap) {
    NNSSndHeapSection *heapSection;
    void *listItem;
    u32 calledBack = 0;

    for (heapSection = IntrusiveListWrapper_GetPrevItem(&heap->mSectionList, 0); heapSection != 0;
         heapSection = IntrusiveListWrapper_GetPrevItem(&heap->mSectionList, 0)) {
        for (listItem = IntrusiveListWrapper_GetPrevItem(&heapSection->mBlockList, 0); listItem != 0;
             listItem = IntrusiveListWrapper_GetPrevItem(&heapSection->mBlockList, listItem)) {
            NNSSndHeapBlock *heapBlock = listItem;

            if (heapBlock->mCallback != 0) {
                heapBlock->mCallback(heapBlock + 1, heapBlock->mSize, heapBlock->mData1, heapBlock->mData2);
                calledBack = 1;
            }
        }
        IntrusiveListWrapper_RemoveItem(&heap->mSectionList, heapSection);
    }
    Mem_ResetFrameHeap(heap->mHandle, 3);
    if (calledBack != 0) {
        EraseSync();
    }
    Sound_Context_MaybeReset(heap);
}

// Allocates behind a 32-byte block header holding the dispose callback.
void *Sound_Context_Allocate(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, void *data1, u32 data2) {
    NNSSndHeapBlock *heapBlock;
    NNSSndHeapSection *heapSection;

    heapBlock = Mem_Frame_Allocate(heap->mHandle, ((size + 31) & ~31) + 32, 32);
    if (heapBlock == 0) {
        return 0;
    }
    heapSection = IntrusiveListWrapper_GetPrevItem(&heap->mSectionList, 0);
    heapBlock->mSize = size;
    heapBlock->mCallback = callback;
    heapBlock->mData1 = data1;
    heapBlock->mData2 = data2;
    IntrusiveListWrapper_InsertLast(&heapSection->mBlockList, heapBlock);
    return heapBlock + 1;
}

// Returns the level for Sound_MaybeRestoreHeapState, or -1.
s32 Sound_Context_BackupFrameState(NNSSndHeap *heap) {
    if (Mem_CreateFrameHeapState(heap->mHandle, heap->mSectionList.mCount) == 0) {
        return -1;
    }
    if (Sound_Context_MaybeReset(heap) != 0) {
        return heap->mSectionList.mCount - 1;
    }
    Mem_RestoreFrameHeapState(heap->mHandle, 0);
    return -1;
}

// Frees the sections above level; level 0 clears the heap.
void Sound_MaybeRestoreHeapState(NNSSndHeap *heap, s32 level) {
    NNSSndHeapSection *heapSection;
    void *listItem = 0;
    u32 calledBack = 0;

    if (level == 0) {
        Sound_Context_DisposeLoadedStuff(heap);
        return;
    }
    if (level < heap->mSectionList.mCount) {
        do {
            heapSection = IntrusiveListWrapper_GetPrevItem(&heap->mSectionList, 0);
            for (listItem = IntrusiveListWrapper_GetPrevItem(&heapSection->mBlockList, listItem); listItem != 0;
                 listItem = IntrusiveListWrapper_GetPrevItem(&heapSection->mBlockList, listItem)) {
                NNSSndHeapBlock *heapBlock = listItem;

                if (heapBlock->mCallback != 0) {
                    heapBlock->mCallback(heapBlock + 1, heapBlock->mSize, heapBlock->mData1, heapBlock->mData2);
                    calledBack = 1;
                }
            }
            IntrusiveListWrapper_RemoveItem(&heap->mSectionList, heapSection);
        } while (level < heap->mSectionList.mCount);
    }
    Mem_RestoreFrameHeapState(heap->mHandle, level);
    if (calledBack != 0) {
        EraseSync();
    }
    Mem_CreateFrameHeapState(heap->mHandle, heap->mSectionList.mCount);
    Sound_Context_MaybeReset(heap);
}

s32 Sound_Context_GetMaybeSavedFrameHeapStateId(NNSSndHeap *heap) {
    return heap->mSectionList.mCount - 1;
}

void InitHeapSection(NNSSndHeapSection *section) {
    IntrusiveListWrapper_InitializeEmpty(&section->mBlockList, 0);
}

BOOL Sound_Context_SetHeap(NNSSndHeap *heap, void *handle) {
    IntrusiveListWrapper_InitializeEmpty(&heap->mSectionList, 12);
    heap->mHandle = handle;
    return Sound_Context_MaybeReset(heap) != 0;
}

BOOL Sound_Context_MaybeReset(NNSSndHeap *heap) {
    NNSSndHeapSection *newSection;

    newSection = Mem_Frame_Allocate(heap->mHandle, 0x14, 4);
    if (newSection == 0) {
        return 0;
    }
    InitHeapSection(newSection);
    IntrusiveListWrapper_InsertLast(&heap->mSectionList, newSection);
    return 1;
}

void EraseSync(void) {
    u32 pendingTag;

    pendingTag = SND_GetCurrentCommandTag();
    Sound_FlushCommand(1);
    SND_WaitForCommandProc(pendingTag);
}

void Sound_ReadSdatFromPathImpl(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    arc->mInfo = 0;
    arc->mFat = 0;
    arc->mSymbol = 0;
    if (Fs_FileId_LoadFromPath(&arc->mFileId, filePath) == 0) {
        return;
    }
    Fs_File_Initialize(&arc->mFile);
    if (Fs_File_OpenById(&arc->mFile, arc->mFileId) == 0) {
        return;
    }
    arc->mFileOpen = 1;
    if (Sound_ReadSdatFromOpenedFile(arc, heap, symbolLoadFlag) != 0) {
        g_ActiveSdat = arc;
    }
}

BOOL Sound_ReadSdatFromOpenedFile(NNSSndArc *arc, NNSSndHeap *heap, BOOL symbolLoadFlag) {
    s32 bytesRead;

    if (Fs_File_Seek(&arc->mFile, 0, 0) == 0) {
        return 0;
    }
    if (Fs_File_Read(&arc->mFile, &arc->mHeader, 0x30) != 0x30) {
        return 0;
    }
    if (heap != 0) {
        arc->mInfo = Sound_Context_Allocate(heap, arc->mHeader.mInfoSize, InfoDisposeCallback, arc, 0);
        if (arc->mInfo == 0) {
            return 0;
        }
        if (Fs_File_Seek(&arc->mFile, arc->mHeader.mInfoOffset, 0) == 0) {
            return 0;
        }
        bytesRead = Fs_File_Read(&arc->mFile, arc->mInfo, arc->mHeader.mInfoSize);
        if (bytesRead != arc->mHeader.mInfoSize) {
            return 0;
        }
        arc->mFat = Sound_Context_Allocate(heap, arc->mHeader.mFatSize, FatDisposeCallback, arc, 0);
        if (arc->mFat == 0) {
            return 0;
        }
        if (Fs_File_Seek(&arc->mFile, arc->mHeader.mFatOffset, 0) == 0) {
            return 0;
        }
        bytesRead = Fs_File_Read(&arc->mFile, arc->mFat, arc->mHeader.mFatSize);
        if (bytesRead != arc->mHeader.mFatSize) {
            return 0;
        }
        if (symbolLoadFlag != 0 && arc->mHeader.mSymbolDataSize != 0) {
            arc->mSymbol = Sound_Context_Allocate(heap, arc->mHeader.mSymbolDataSize, SymbolDisposeCallback, arc, 0);
            if (arc->mSymbol == 0) {
                return 0;
            }
            if (Fs_File_Seek(&arc->mFile, arc->mHeader.mSymbolDataOffset, 0) == 0) {
                return 0;
            }
            bytesRead = Fs_File_Read(&arc->mFile, arc->mSymbol, arc->mHeader.mSymbolDataSize);
            if (bytesRead != arc->mHeader.mSymbolDataSize) {
                return 0;
            }
        }
    }
    return 1;
}

// Points the blocks and files into an archive already in memory.
void Sound_ReadSdatFromMemory(NNSSndArc *arc, void *data) {
    u32 fileIndex;

    Mem_CpuCopy32(data, &arc->mHeader, 0x30);
    arc->mInfo = arc->mHeader.mInfoOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcInfo, data, arc->mHeader.mInfoOffset);
    arc->mFat = arc->mHeader.mFatOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcFat, data, arc->mHeader.mFatOffset);
    arc->mSymbol =
        arc->mHeader.mSymbolDataOffset == 0 ? 0 : OFFSET_PTR(NNSSndArcSymbol, data, arc->mHeader.mSymbolDataOffset);
    for (fileIndex = 0; fileIndex < arc->mFat->mCount; fileIndex++) {
        NNSSndArcFileInfo *file = &arc->mFat->mFiles[fileIndex];

        file->mMem = file->mOffset == 0 ? 0 : (u8 *) data + file->mOffset;
    }
    arc->mFileOpen = 0;
    g_ActiveSdat = arc;
}

NNSSndArc *Sound_MaybeSetActiveSdat(NNSSndArc *arc) {
    NNSSndArc *previousArc = g_ActiveSdat;

    g_ActiveSdat = arc;
    return previousArc;
}

NNSSndArc *Sound_GetActiveSdat(void) {
    return g_ActiveSdat;
}

NNSSndSeqParam *NNS_SndArcGetSeqArcParam(s32 seqArcNo, s32 index) {
    NNSSndArcSeqArcInfo *info;
    NNSSndSeqArc *seqArcData;
    NNSSndSeqArcSeqInfo *seqEntry;

    info = Sound_GetSarcInfoEntry(seqArcNo);
    if (info == 0) {
        return 0;
    }
    seqArcData = Sound_MaybeGetRawFilePointer(info->mFileId);
    if (seqArcData == 0) {
        return 0;
    }
    seqEntry = NNSi_SndSeqArcGetSeqInfo(seqArcData, index);
    if (seqEntry == 0) {
        return 0;
    }
    return &seqEntry->mParam;
}

NNSSndArcSeqInfo *Sound_GetSseqInfoEntry(s32 seqNo) {
    NNSSndArc *arc = g_ActiveSdat;
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

NNSSndArcSeqArcInfo *Sound_GetSarcInfoEntry(s32 seqArcNo) {
    NNSSndArc *arc = g_ActiveSdat;
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

NNSSndArcBankInfo *Sound_GetSbnkInfoEntry(s32 bankNo) {
    NNSSndArc *arc = g_ActiveSdat;
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

NNSSndArcWaveArcInfo *Sound_GetSwarInfoEntry(s32 waveArcNo) {
    NNSSndArc *arc = g_ActiveSdat;
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

NNSSndArcPlayerInfo *Sound_GetPlayerInfoEntry(s32 playerNo) {
    NNSSndArc *arc = g_ActiveSdat;
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

NNSSndArcGroupInfo *Sound_GetGroupInfoEntry(s32 groupNo) {
    NNSSndArc *arc = g_ActiveSdat;
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

u32 Sound_GetFileSize(u32 fileId) {
    NNSSndArcFat *fat = g_ActiveSdat->mFat;

    if (fileId >= fat->mCount) {
        return 0;
    }
    return fat->mFiles[fileId].mSize;
}

// Returns the number of bytes read, or -1.
s32 Sound_ReadFile(u32 fileId, void *buffer, u32 size, u32 offset) {
    NNSSndArc *arc = g_ActiveSdat;
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
    if (Fs_File_Seek(&arc->mFile, file->mOffset + offset, 0) == 0) {
        return -1;
    }
    return Fs_File_Read(&arc->mFile, buffer, size);
}

void *Sound_MaybeGetRawFilePointer(u32 fileId) {
    NNSSndArcFat *fat = g_ActiveSdat->mFat;

    if (fileId >= fat->mCount) {
        return 0;
    }
    return fat->mFiles[fileId].mMem;
}

void Sound_SetFileFatDynamicOffsetField(u32 fileId, void *address) {
    g_ActiveSdat->mFat->mFiles[fileId].mMem = address;
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
