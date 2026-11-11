#include "Main/Unknown/code_02053e54.h"
#include "Main/Unknown/unk_0217a000.h"

void ClearRaceConnectionFlag(void) {
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_RACE;
}
