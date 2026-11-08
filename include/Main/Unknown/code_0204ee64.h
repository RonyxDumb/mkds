#pragma once

#include "types.h"

typedef struct BlockTransferRecord BlockTransferRecord;

void RemoveGhostDataBlocks(void);
void func_0204eeac(void *data, u32 size);
void AddGhostDataBlock(void *data, u32 size);
void func_0204ef1c(void);
void SetOwnIndexFromConnection(void);
void BlockDataRequestCallback(BlockTransferRecord *record);
void StartBlockDataRequest(void);
void BlockNodeRequestCallback(BlockTransferRecord *record);
void StartBlockNodeRequest(void);
void BlockCountRequestCallback(BlockTransferRecord *record);
void StartBlockCountRequest(void);
