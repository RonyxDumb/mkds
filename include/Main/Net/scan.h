#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217a000.h" // ScanSlot
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
void StartConnect(WMBssDesc *parentBssDesc, void *customUserData, void (*connectedCallback)(), void (*failedCallback)(),
                  void (*disconnectedCallback)());
void EndScanCallback(Unk021425e8 *event);
void EndScan(void);
void StartScanCallback(Unk021425e8 *event);
void FindOrAddScanSlot(WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo);
void FillScanSlot(ScanSlot *slot, WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo, u8 entryIndex);
void StartScan(s32 isRepeat, s32 (*resultCallback)(), s32 (*filterCallback)());
