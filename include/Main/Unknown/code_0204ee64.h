#pragma once

#include "types.h"

typedef struct WBTCommand WBTCommand;

void RemoveGhostDataBlocks(void);
void AddGhostDataBlockWrapper(void *data, u32 size);
void AddGhostDataBlock(void *data, u32 size);
void StartMPWithBuffers(void);
void SetWbtOwnAidFromConnection(void);
void BlockDataRequestCallback(WBTCommand *record);
void StartBlockDataRequest(void);
void BlockNodeRequestCallback(WBTCommand *record);
void StartBlockNodeRequest(void);
void BlockCountRequestCallback(WBTCommand *record);
void StartBlockCountRequest(void);
