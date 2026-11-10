#pragma once

#include "types.h"

typedef struct BlockTransferRecord BlockTransferRecord;

void RemoveGhostDataBlocks(void);
void AddGhostDataBlockWrapper(void *data, u32 size);
void AddGhostDataBlock(void *data, u32 size);
void StartMPWithBuffers(void);
void SetOwnIndexFromConnection(void);
void BlockDataRequestCallback(BlockTransferRecord *record);
void StartBlockDataRequest(void);
void BlockNodeRequestCallback(BlockTransferRecord *record);
void StartBlockNodeRequest(void);
void BlockCountRequestCallback(BlockTransferRecord *record);
void StartBlockCountRequest(void);
