#pragma once

#include "types.h"
#include "03/Menu/scroll_bar.h"
#include "03/Net/ap_scan_types.h"
#include "03/Menu/wifi_menu_tables.h"
#include "03/Menu/wifi_menu_shared.h"
#include "wireless_link_control.h"

// The result of an access point scan: the error code, state, channel list and the found devices with their link levels.
typedef struct WMStartScanExCallback {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mErrcode;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mState;
    /* 0a */ u16 mChannelList;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mBssDescCount;
    /* 10 */ WMBssDesc *mBssDesc[0x10];
    /* 50 */ u16 mLinkLevel[0x10];
} WMStartScanExCallback;

void StoreApScanEntries(WMStartScanExCallback *scanResult);
void ApScanCallback(WirelessMessage *message);

// Bit of WMBssDesc.mCapaInfo that is set for a network with encryption, and the ids of the beacon elements that mark
// a security element.
#define AP_SCAN_CAPA_INFO_ENCRYPTED 0x10
#define AP_SCAN_ELEMENT_ID_SECURITY 0x30
#define AP_SCAN_ELEMENT_ID_VENDOR 0xdd

extern const u8 gOtherElementPrefix[4];
