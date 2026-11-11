#pragma once

#include "types.h"

void UpdateUsbChoiceMessageClose(void);
void UpdateUsbChoiceMessageResult(void);
void UpdateUsbMessageClose(void);
void UpdateUsbMessageResult(void);
void UsbEventCallback(u32 eventCode);
void UpdateUsbRelease(void);
void UpdateUsbFadeOut(void);
void StartUsbClose(void);
void UpdateUsbResult(void);
void UpdateUsbNop(void);
void UpdateUsbInput(void);
void UpdateUsb(void);
void UpdateUsbButtonsIn(void);
void UpdateUsbFadeIn(void);
void StartUsbFadeIn(void);
void LoadUsbFilesAndSetBgCnt(void);
void SetupUsb(void);
