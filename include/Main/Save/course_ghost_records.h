#pragma once

#include "types.h"

void SetStructYE_RunATFunction(void *records);
void TaskFunction_StructYE(void);

typedef struct GhostRecordHead GhostRecordHead;

GhostRecordHead *AllocateStructYE(void *heap);
