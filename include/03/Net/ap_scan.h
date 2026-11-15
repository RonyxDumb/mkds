#pragma once

#include "types.h"
#include "03/types_021da26c.h"


int CountApScanEntries(int *entriesOut);
BOOL StopApScan(void);
BOOL StartApScan(void);
BOOL InitApScan(void);
void ReleaseApScan(void);
void CreateApScan(void);

extern const ScanExParam gApScanParamTemplate;
