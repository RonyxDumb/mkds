#pragma once

#include "types.h"
#include "sound_archive_load.h"

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;

s32 ComputeSomeAllocSize_1(s32 blockCount);
void *IntrusiveListWrapper_GetAtIndex(NNSFndList *list, u16 index);
void *IntrusiveListWrapper_GetPrevItem(NNSFndList *list, void *object);
void *IntrusiveListWrapper_NextItem(NNSFndList *list, void *object);
void IntrusiveListWrapper_RemoveItem(NNSFndList *list, void *object);
void IntrusiveListWrapper_SomeFn_0(NNSFndList *list, void *target, void *object);
void IntrusiveListWrapper_InsertFirst(NNSFndList *list, void *object);
void IntrusiveListWrapper_InsertLast(NNSFndList *list, void *object);
