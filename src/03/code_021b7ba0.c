#include "03/code_021b7ba0.h"

void SetPollEntryForRead(s32 value, PollEntry *object) {
    object->mDescriptor = value;
    object->mAskedBits = 1;
}
