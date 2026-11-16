#pragma once

#include "types.h"
#include "wireless_link_control.h"

// Values of ApScanEntry.mCapaLevel: bit clear, bit set, or bit set and a matching element found in the other elements.
#define AP_CAPA_LEVEL_OPEN 0
#define AP_CAPA_LEVEL_ENCRYPTED 1
#define AP_CAPA_LEVEL_SECURITY_ELEMENT 2

// One access point found by a scan: SSID, BSSID, link level and capability level.
typedef struct ApScanEntry {
    /* 00 */ u8 mSsid[0x20];
    /* 20 */ u8 mBssid[6];
    /* 26 */ u16 mLinkLevel;
    /* 28 */ u8 mCapaLevel;
} ApScanEntry;

// The access point scan: its scan buffer, the table of found entries, scan parameters, status and stop request.
typedef struct ApScan {
    /* 0000 */ u8 mUnk_0000[0xf00];
    /* 0f00 */ u8 mScanBuf[0x400];
    /* 1300 */ ApScanEntry mEntries[0x14];
    /* 1648 */ ScanExParam mScanParam;
    /* 168c */ WMStatus mStatus;
    /* 1e48 */ u8 mStopRequested;
    /* 1e49 */ u8 mUnk_1e49[0x17];
} ApScan;
