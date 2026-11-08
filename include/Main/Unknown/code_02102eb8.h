#pragma once

#include "types.h"

typedef struct ItemGesso ItemGesso;

unsigned int SetupItemGesso(ItemGesso *gesso, s32 fromData);
BOOL SetupNextItemGessoStep(ItemGesso *gesso);
void ResetItemGesso(ItemGesso *gesso);
