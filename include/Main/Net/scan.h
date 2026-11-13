#pragma once

#include "types.h"
#include "Main/MapObjects/data_0217a000.h" // ScanSlot
#include "code_02142eac.h" // WirelessMessage

void SetGameInfo(void);
void StartDataSharing(void);
void SetEntryCallback(WirelessMessage *event);
void SetEntry(s32 enabled);
void SetMPFrequencyCallback(WirelessMessage *event);
void SetMPFrequency(u32 mpFreq);
void StartMPCallback(WirelessMessage *event);
void StartMP(void);
void StartConnectCallback(WirelessMessage *event);
void StartConnect(WMBssDesc *parentBssDesc, void *customUserData, void (*connectedCallback)(), void (*failedCallback)(),
                  void (*disconnectedCallback)());
void EndScanCallback(WirelessMessage *event);
void EndScan(void);
void StartScanCallback(WirelessMessage *event);
void FindOrAddScanSlot(WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo);
void FillScanSlot(ScanSlot *slot, WMBssDesc *scanBuffer, ScanMacAddress *key, UserGameInfo *gameInfo, u8 entryIndex);
void StartScan(s32 isRepeat, s32 (*resultCallback)(), s32 (*filterCallback)());
