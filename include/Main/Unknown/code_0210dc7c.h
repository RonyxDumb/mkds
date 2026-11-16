#pragma once

#include "types.h"

typedef struct Unk0217c7c4 Unk0217c7c4;
typedef struct SoundSetPlayer SoundSetPlayer;
typedef struct LoadedSoundSet LoadedSoundSet;
typedef struct SoundRequestQueue SoundRequestQueue;
typedef struct NNSSndHeap NNSSndHeap;

void *sp_acquireElement(Unk0217c7c4 *pool);
void sp_updateAges(Unk0217c7c4 *pool);
void sp_init(Unk0217c7c4 *pool, void *entries, s32 count, s32 entrySize);
void InitSoundRequestQueue(SoundRequestQueue *queue, s32 count, NNSSndHeap *heap);
void ResetSoundRequestQueue(SoundRequestQueue *queue);
void RunSoundRequests(SoundRequestQueue *queue);
void AddSoundRequest(SoundRequestQueue *queue, int sortKey, void (*function)(void *, int), void *firstArgument,
                     int secondArgument);
u32 sound_210DCCC(SoundSetPlayer *player, u32 seqId, u32 firstBankId, u32 secondBankId, LoadedSoundSet *loadedSet);
void sound_seqHandleStart(SoundSetPlayer *player, u32 volume);
void sound_seqHandleStop(SoundSetPlayer *player, u32 fadeSteps);
void sound_seqHandleUnload(SoundSetPlayer *player);
