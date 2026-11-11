#pragma once

#include "types.h"

typedef struct Rect Rect;

extern u16 gMacAddressFormat[];
extern u16 gDashSeparatedNumbersFormat[];
extern u16 gDashesFormat[];
extern Rect gJb5InfoMacAddressRect;
extern Rect gJb5InfoUserIdRect;

void PrintJb5Info(void);
