#pragma once

#include "types.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/wifi_library_globals.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

void RegisterSelectKartCallbacks(void);
void WriteSelectKartRegistersWrapper(void);
void AdvanceWiFiSelectKartState(void);
void InitWiFiSelectKartNop(void);
void ReleaseWiFiSelectKartState(void);
void InitWiFiSelectKartState(void *heap);

extern WiFiStateCallbacks gWiFiSelectKartCallbacks;
extern struct WiFiSelectHeapHolder *gWiFiSelectKartState;
