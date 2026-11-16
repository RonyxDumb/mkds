#pragma once

#include "types.h"
#include "03/Net/ap_scan_types.h"

int CountApScanEntries(ApScanEntry **entriesOut);
BOOL StopApScan(void);
BOOL StartApScan(void);
BOOL InitApScan(void);
void ReleaseApScan(void);
void CreateApScan(void);

extern const ScanExParam gApScanParamTemplate;
