#pragma once

#include "types.h"

void InitBlockEntries(void *heap, s32 mode);
void AllocTransferBuffers(void *heap);
void StartChildSideBlockTransfer(void);
void StartParentSideBlockTransfer(void);
void AddPendingFile(const void *path, void *heap, void **dataOutput, u32 value, s32 uncompress);

void ResetPendingFiles(void);

BOOL LoadPendingFiles(void);
void UncompressPendingFile(void);
