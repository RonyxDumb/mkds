#include "wm_etc.h"
#include "arena_cache_init.h"
#include "wireless_data_sharing.h"
#include "os_thread.h"
#include "wm_system.h"
#include "cpu_copy_clear_16.h"

u8 tmpUserGameInfoBuf[0x80];

// Sets the WEP mode (0 to 3) and key (command 20). Needs state 2 or later; the key is required for a mode above 0.
int WM_SetWEPKey(WirelessMessageCallback callback, u32 wepmode, void *wepkey) {
    int result;

    result = WMi_CheckIdle();
    if (result != 0) {
        return result;
    }
    if (wepmode > 3) {
        return 6;
    }
    if (wepmode != 0) {
        if (wepkey == 0) {
            return 6;
        }
        DC_StoreRange(wepkey, 0x50);
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_SET_BASIC_CIPHER_KEY, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_SET_BASIC_CIPHER_KEY, 2, wepmode, wepkey);
    if (result == 0) {
        result = 2;
    }
    return result;
}

// Same as WM_SetWEPKey with a key id (command 39).
int WM_SetWEPKeyEx(WirelessMessageCallback callback, u16 wepmode, u16 wepkeyid, void *wepkey) {
    int result;

    result = WMi_CheckIdle();
    if (result != 0) {
        return result;
    }
    if (wepmode > 3) {
        return 6;
    }
    if (wepmode != 0) {
        if (wepkey == 0) {
            return 6;
        }
        DC_StoreRange(wepkey, 0x50);
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_SET_CIPHER_KEY, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_SET_CIPHER_KEY, 3, wepmode, wepkey, wepkeyid);
    if (result == 0) {
        result = 2;
    }
    return result;
}

// Sets the game info the parent sends in its beacon (command 24); at most 0x70 bytes. Needs state 7 or 9.
int WM_SetGameInfo(WirelessMessageCallback callback, const void *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid,
                   u8 attr) {
    int result;

    result = WMi_CheckStateEx(2, 7, 9);
    if (result != 0) {
        return result;
    }
    if (userGameInfo == 0) {
        return 6;
    }
    if (userGameInfoSize > 0x70) {
        return 6;
    }
    MIi_CpuCopy16(userGameInfo, tmpUserGameInfoBuf, userGameInfoSize);
    DC_StoreRange(tmpUserGameInfoBuf, userGameInfoSize);
    WMi_SetCallbackTable(WIRELESS_REQUEST_SET_HOST_ADVERT, callback);
    result =
        WMi_SendCommand(WIRELESS_REQUEST_SET_HOST_ADVERT, 5, tmpUserGameInfoBuf, userGameInfoSize, ggid, tgid, attr);
    if (result == 0) {
        result = 2;
    }
    return result;
}

// Turns the beacon indication on or off (command 25). Needs state 2 or later.
int WM_SetBeaconIndication(WirelessMessageCallback callback, u16 flag) {
    int result;

    result = WMi_CheckIdle();
    if (result != 0) {
        return result;
    }
    if (flag != 0 && flag != 1) {
        return 6;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_WATCH_BEACONS, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_WATCH_BEACONS, 1, flag);
    if (result == 0) {
        result = 2;
    }
    return result;
}

// Sets the connection life times (command 29). Needs state 2 or later.
int WM_SetLifeTime(WirelessMessageCallback callback, u32 tableNumber, u32 camLifeTime, u32 frameLifeTime,
                   u16 mpLifeTime) {
    int result;

    result = WMi_CheckIdle();
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_SET_TIMEOUT, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_SET_TIMEOUT, 4, tableNumber, camLifeTime, frameLifeTime, mpLifeTime);
    if (result == 0) {
        result = 2;
    }
    return result;
}

// Measures the radio use of a channel (command 30). Needs state 2.
int WM_MeasureChannel(WirelessMessageCallback callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime) {
    WMArm9Buf *work;
    u16 *request;
    int result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, 2);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_MEASURE_CHANNEL, callback);
    request = work->mRequestArea;
    request[0] = 0x1e;
    request[1] = ccaMode;
    request[2] = edThreshold;
    request[3] = channel;
    request[4] = measureTime;
    result = WMi_SendCommand(WIRELESS_REQUEST_MEASURE_CHANNEL, 0);
    if (result == 0) {
        result = 2;
    }
    return result;
}

// Allows or refuses new children (command 33). Needs state 7 or 9.
int WM_SetEntry(WirelessMessageCallback callback, BOOL enabled) {
    int result;

    result = WMi_CheckStateEx(2, 7, 9);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(WIRELESS_REQUEST_SET_JOIN_ALLOWED, callback);
    result = WMi_SendCommand(WIRELESS_REQUEST_SET_JOIN_ALLOWED, 1, enabled);
    if (result == 0) {
        result = 2;
    }
    return result;
}
