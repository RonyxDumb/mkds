#pragma once

#include "types.h"
#include "00/code_02180608.h"
#include "00/unk_021b4000.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

void RegisterSelectKartCallbacks(void);
void WriteSelectKartRegistersWrapper(void);
void AdvanceWiFiSelectKartState(void);
void InitWiFiSelectKartNop(void);
void ReleaseWiFiSelectKartState(void);
void InitWiFiSelectKartState(void *heap);

extern WiFiStateCallbacks gSelectKartCallbacks;
extern struct WiFiSelectHeapHolder *gWiFiSelectKartState;
