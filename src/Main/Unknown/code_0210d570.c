#include "Main/Unknown/code_0210d570.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "Main/Unknown/unk_0217d000.h"

u32 nullsub_14(ScenePlayers *scenePlayers) {
    return (u32) scenePlayers;
}

void sub_210D570(ScenePlayers *scenePlayers, s32 unused) {
    ReleaseAllSoundSources();
    scenePlayers->field0 = 0;
}
