#pragma once

#include "types.h"
#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/wifi_library_globals.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

void RegisterSelectCharacterCallbacks(void);
void WriteSelectCharacterRegistersWrapper(void);
void AdvanceWiFiSelectCharacterState(void);
void InitWiFiSelectCharacterNop(void);
void ReleaseWiFiSelectCharacterState(void);
void InitWiFiSelectCharacterState(void *heap);

extern WiFiStateCallbacks gWiFiSelectCharacterCallbacks;
extern struct WiFiSelectHeapHolder *gWiFiSelectCharacterState;
