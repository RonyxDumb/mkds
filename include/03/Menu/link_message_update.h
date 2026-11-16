#pragma once

#include "types.h"

void LinkMessageResultCallback(int callbackResult);
void UpdateLinkMessageRelease(void);
void StartLinkMessageFadeOut(void);
void UpdateLinkMessageNop(void);
void UpdateLinkMessageInputNop(void);
void UpdateLinkMessage(void);

extern u8 gLinkMessageResult;
