#include "Main/Unknown/code_0205b0b4.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0205b0b4(void) {
    if ((gWiFiRaceSync->mFlags & 0x80) != 0) {
        RemoveDroppedParticipants();
    }
    AdvanceStateMachine(&gWiFiRaceSync->mStateMachine);
}
