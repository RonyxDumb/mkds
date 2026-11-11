#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

extern WiFiStateCallbacks gSelectKartCallbacks;

void RegisterSelectKartCallbacks(void);
void WriteSelectKartRegistersWrapper(void);
void AdvanceWiFiSelectKartState(void);
void InitWiFiSelectKartNop(void);
void ReleaseWiFiSelectKartState(void);
void InitWiFiSelectKartState(void *heap);
