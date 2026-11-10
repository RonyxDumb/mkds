#pragma once

#include "types.h"
#include "Main/Unknown/code_02125de0.h"

void InitMenu(void);
u16 *MenuMB_GetMultiBootParam(void);
BOOL MenuMB_IsMultiBootChild(void);
BOOL MenuMB_IsMultiBootChildWrapper(void);
