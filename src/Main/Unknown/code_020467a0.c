#include "Main/Unknown/code_020467a0.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/unk_021759c0.h"

void rconf_resetMatch(void) {
    u32 value0;
    u32 courseNumber;
    rres_reset();
    value0 = (u32) &gRaceMultiConfig;
    courseNumber = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x200u);
    *(u16 *) ((value0) + (72)) = courseNumber;
}
