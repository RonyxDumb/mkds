#pragma once

#include "types.h"
#include "00/code_02180608.h"
#include "00/unk_021b4000.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

void RegisterSelectCharacterCallbacks(void);
void WriteSelectCharacterRegistersWrapper(void);
void AdvanceWiFiSelectCharacterState(void);
void InitWiFiSelectCharacterNop(void);
void ReleaseWiFiSelectCharacterState(void);
void InitWiFiSelectCharacterState(void *heap);

extern WiFiStateCallbacks gSelectCharacterCallbacks;
extern struct WiFiSelectHeapHolder *gWiFiSelectCharacterState;
