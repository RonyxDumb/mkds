#include "03/code_021b7ba8.h"
#include "03/code_021b7ba0.h"

void ClearPollEntry(PollEntry *object) {
    object->mDescriptor = 0;
    object->mAskedBits = 0;
    object->mFoundBits = 0;
}
