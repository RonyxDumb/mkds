/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define SND_GetFirstInstDataPos SND_func_0043
#include "SND_bank.h"
#include "OS_mutex.h"
#include "nitro/types.h"
#include "code32.h"

struct SNDInstPos SND_GetFirstInstDataPos(const struct SNDBankData *bankData) {
#pragma unused (bankData)
    struct SNDInstPos retval;
    retval.program = 0;
    retval.index = 0;
    return retval;
}
