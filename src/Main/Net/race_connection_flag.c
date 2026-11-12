#include "Main/Net/race_connection_flag.h"
#include "Main/Unknown/unk_0217a000.h"

void ClearRaceConnectionFlag(void) {
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_RACE;
}
