#pragma once

#include "types.h"
#include "03/System/tasks.h"
#include "wireless_link_control.h"

// Codes UsbScan.mResultCallback gets: when the scan time is up, no entries (NONE), only entries with the flag set
// (FLAGGED) or both kinds (MIXED); FLAGGED is also reported at once when a stored entry shows the flag. Entries with
// the flag clear only give no call. The callback in usb.c also has a case for the code after them, which nothing
// reports.
#define USB_SCAN_RESULT_NONE 0
#define USB_SCAN_RESULT_FLAGGED 1
#define USB_SCAN_RESULT_MIXED 2
#define USB_SCAN_RESULT_NEVER_REPORTED 3

// Values of UsbScan.mReleaseProgress: running, release started by ReleaseUsbScan, the close request answered without an
// error.
#define USB_SCAN_RELEASE_RUNNING 0
#define USB_SCAN_RELEASE_STARTED 1
#define USB_SCAN_RELEASE_DONE 2

extern const u8 gUsbScanEmptyBssid[6];

// One scanned device: its BSSID and a flag.
typedef struct UsbScanEntry {
    /* 0 */ u8 mBssid[6];
    /* 6 */ u8 mFlag;
} UsbScanEntry;

// USB scan state: the scan buffers, found entries, result callback, scan parameters, start time, report task and
// release progress.
struct UsbScan {
    /* 0000 */ u8 mWmSystemBuffer[0xf00];
    /* 0f00 */ u8 mScanBuffer[0x400];
    /* 1300 */ UsbScanEntry mEntries[16];
    /* 1370 */ void (*mResultCallback)(u32);
    /* 1374 */ ScanExParam mScanParam;
    /* 13b8 */ WMStatus mWmStatus;
    /* 1b74 */ u64 mStartTick;
    /* 1b7c */ TaskEntry *mReportTask;
    /* 1b80 */ vu8 mReleaseProgress;
    /* 1b81 */ u8 mPendingResult;
    /* 1b82 */ u8 mReported;
};

typedef struct WMStartScanExCallback WMStartScanExCallback;

#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/wifi_menu_tables.h"

void CheckUsbScanEntries(WMStartScanExCallback *scanResult);
void StoreUsbScanEntries(WMStartScanExCallback *scanResult);
void UsbScanCallback(WirelessMessage *message);
void SetUsbScanCallback(void (*callback)(u32));
BOOL ReleaseUsbScan(void);
BOOL StartUsbScan(void);
BOOL InitUsbScan(void (*callback)(u32));

extern const u8 gUsbSsidPrefix[9];
extern const ScanExParam gUsbScanParamTemplate;
