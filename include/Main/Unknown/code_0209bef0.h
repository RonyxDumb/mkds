#pragma once

#include "types.h"

void *CreateMapObjectDrawList2(void *init, void *forEachObject, void *beforeObjects);
void *CreateMapObjectDrawList1(void *init, void *forEachObject, void *beforeObjects);
void *CreateMapObjectUpdateList(void *init, void *forEachObject, void *beforeObjects);
