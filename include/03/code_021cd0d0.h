#pragma once

#include "types.h"

typedef struct ScanParamBlock ScanParamBlock;

extern ScanParamBlock gApScanParamTemplate;

int CountApScanEntries(int *entriesOut);
BOOL StopApScan(void);
BOOL StartApScan(void);
BOOL InitApScan(void);
void ReleaseApScan(void);
void CreateApScan(void);
