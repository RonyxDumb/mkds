#pragma once

#include "types.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"

typedef enum NNSSndArcLoadResult {
    NNS_SND_ARC_LOAD_SUCESS,
    NNS_SND_ARC_LOAD_ERROR_INVALID_GROUP_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_SEQ_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_SEQARC_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_BANK_NO,
    NNS_SND_ARC_LOAD_ERROR_INVALID_WAVEARC_NO,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQ,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_SEQARC,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_BANK,
    NNS_SND_ARC_LOAD_ERROR_FAILED_LOAD_WAVE
} NNSSndArcLoadResult;

extern SNDWaveArc g_SomeSwarHeader;

void Sound_DtorFn_SwarHeader(void *mem, u32 size, void *data1, u32 data2);
void AnotherSoundDtorFn(void *mem, u32 size, void *data1, u32 data2);
void SomeSoundDtorFn(void *mem, u32 size, void *data1, u32 data2);
void Sound_DtorFn_SomeSarcPointer(void *mem, u32 size, void *data1, u32 data2);
void Sound_DisposeFile(void *mem, NNSSndArc *arc, u32 fileId);
SNDWaveArc *Sound_PrepareSwarDataImpl(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
SNDWaveArc *Sound_PrepareSwarData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
SNDBankData *Sound_PrepareSbnkData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
NNSSndSeqArc *Sound_PrepareSarcData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
NNSSndSeqData *Sound_PrepareSseqData(u32 fileId, NNSSndHeap *heap, BOOL bSetAddr);
void *Sound_AllocateReadEntireFile(u32 fileId, NNSSndHeapDisposeCallback callback, void *data1, u32 data2, NNSSndHeap *heap);
NNSSndArcLoadResult Sound_GetSwarPointer(s32 waveArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                           SNDWaveArc **pData);
NNSSndArcLoadResult Sound_GetSbnkPointer(s32 bankNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr, SNDBankData **pData);
NNSSndArcLoadResult Sound_GetSarcPointer(s32 seqArcNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr,
                                          NNSSndSeqArc **pData);
NNSSndArcLoadResult Sound_GetSseqPointer(s32 seqNo, u32 loadFlag, NNSSndHeap *heap, BOOL bSetAddr, NNSSndSeqData **pData);
NNSSndArcLoadResult Sound_LoadGroupImpl(s32 groupNo, NNSSndHeap *heap);
BOOL Sound_LoadSbnkWithFlags(s32 bankNo, u32 loadFlag, NNSSndHeap *heap);
BOOL Sound_LoadSwar(s32 waveArcNo, NNSSndHeap *heap);
BOOL Sound_LoadSbnk(s32 bankNo, NNSSndHeap *heap);
BOOL Sound_LoadSarc(s32 seqArcNo, NNSSndHeap *heap);
BOOL CheckMaybeLoadSseqOk(s32 seqNo, NNSSndHeap *heap);
BOOL Sound_LoadGroup(s32 groupNo, NNSSndHeap *heap);
BOOL StartSeqArc(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndSeqArcSeqInfo *sound,
                 NNSSndSeqArc *seqArc, u32 seqArcNo, u32 index);
BOOL MaybeStartSeq(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, NNSSndArcSeqInfo *info, s32 seqNo);
BOOL NNS_SndArcPlayerStartSeqArcEx(NNSSndSeqPlayer **handle, s32 playerNo, s32 bankNo, s32 playerPrio, s32 seqArcNo,
                                   s32 index);
BOOL PlaySseqFromSarc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index);
BOOL NNS_SndArcPlayerStartSeq(NNSSndSeqPlayer **handle, s32 seqNo);
BOOL NNS_SndArcPlayerSetup(NNSSndHeap *heap);
