#pragma once

#include "types.h"
#include "sound_archive_load.h"

void IntrusiveListWrapper_InsertFirstItem(NNSFndList *list, void *object);
void IntrusiveListWrapper_InitializeEmpty(NNSFndList *list, u16 offset);
