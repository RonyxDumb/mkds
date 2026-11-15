#pragma once

#include "types.h"
#include "03/Menu/wifi_menu_shared.h"

void UpdateApScanMessageClose(void);
void UpdateApScanMessageResult(void);
void UpdateApScanRelease(void);
void UpdateApScanFadeOut(void);
void StartApScanClose(void);
void UpdateApScanResult(void);
void UpdateApScanNop(void);
void UpdateApScanInput(void);
void UpdateApScanFrames(void);
void UpdateApScan(void);
void UpdateApScanButtonsIn(void);
void UpdateApScanFadeIn(void);
void StartApScanFadeIn(void);
void LoadApScanFilesAndSetBgCnt(void);
void SetupApScan(void);

extern u8 gApScanKind;
extern u16 gApScanFrames;
