#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

extern WiFiStateCallbacks gSelectCharacterCallbacks;

void RegisterSelectCharacterCallbacks(void);
void WriteSelectCharacterRegistersWrapper(void);
void AdvanceWiFiSelectCharacterState(void);
void InitWiFiSelectCharacterNop(void);
void ReleaseWiFiSelectCharacterState(void);
void InitWiFiSelectCharacterState(void *heap);
