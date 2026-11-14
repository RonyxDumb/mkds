#pragma once

#include "types.h"
#include "code_021458c4.h" // CARDiCommon, CARDRomStat

// Added to the offset of every ROM read in CARDi_ReadRom; CARD_Init writes 0 and nothing else writes it.
extern u32 gRomBaseOffset;
extern CARDRomStat gRomReadState;

UnkFunc *CARDi_GetRomAccessor(void);
int CARD_WaitRomAsync(void);
void CARD_Init(void);
void CARDi_ReadRom(u32 dma, u32 src, u32 dst, u32 len, UnkFunc *callback, u32 callbackArg, u32 isAsync);
void CARDi_ReadRomSyncCore(CARDiCommon *c);
void CARDi_ReadCard(CARDRomStat *p);
int CARDi_TryReadCardDma(CARDRomStat *p);
void CARDi_OnReadCard(void);
void CARDi_SetCardDma(void);
void CARDi_SetRomOp(u32 cmd1, u32 cmd2);
int CARDi_ReadFromCache(CARDRomStat *p);
int CARDi_Request(CARDiCommon *p, int reqType, int retryCount);
void CARDi_TaskThread(void *arg);
