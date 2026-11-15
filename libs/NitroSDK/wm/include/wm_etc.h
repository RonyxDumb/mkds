#pragma once

#include "types.h"
#include "code_02142eac.h" // WirelessMessageCallback

// Copy of the game info that WM_SetGameInfo sends.
extern u8 tmpUserGameInfoBuf[0x80];

int WM_SetEntry(WirelessMessageCallback callback, BOOL enabled);
int WM_MeasureChannel(WirelessMessageCallback callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime);
int WM_SetLifeTime(WirelessMessageCallback callback, u32 tableNumber, u32 camLifeTime, u32 frameLifeTime,
                   u16 mpLifeTime);
int WM_SetBeaconIndication(WirelessMessageCallback callback, u16 flag);
int WM_SetGameInfo(WirelessMessageCallback callback, const void *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid,
                   u8 attr);
int WM_SetWEPKeyEx(WirelessMessageCallback callback, u16 wepmode, u16 wepkeyid, void *wepkey);
int WM_SetWEPKey(WirelessMessageCallback callback, u32 wepmode, void *wepkey);
