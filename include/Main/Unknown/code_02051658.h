#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // ScanSlot, ScanBlock, UserGameInfo
#include "code_02142eac.h" // Unk021425e8

void SetGameInfo(void);
void StartDataSharing(void);
void SetEntryCallback(Unk021425e8 *event);
void SetEntry(s32 enabled);
void SetMPFrequencyCallback(Unk021425e8 *event);
void SetMPFrequency(u32 mpFreq);
void StartMPCallback(Unk021425e8 *event);
void StartMP(void);
void StartConnectCallback(Unk021425e8 *event);
void StartConnect(ScanBlock *a, void *b, void (*c)(), void (*d)(), void (*e)());
void EndScanCallback(Unk021425e8 *event);
void EndScan(void);
void StartScanCallback(Unk021425e8 *event);
void FindOrAddScanSlot(ScanBlock *scanBuffer, ScanMacAddress *key, UserGameInfo *c);
void FillScanSlot(ScanSlot *slot, ScanBlock *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo, u8 entryIndex);
void StartScan(s32 a, s32 (*b)(), s32 (*c)());
