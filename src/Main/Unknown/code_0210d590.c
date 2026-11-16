#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"

static inline void func_0210d614_inline(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    if (handle == NULL) {
        handle = &data_0217d07c;
    }
    if (scenePlayers->fieldB == 0xff) {
        return;
    }
    sound_startSeq(seqNo, data_0216cb28, handle);
}

void MKDS_SND_210D6CC(ScenePlayers *scenePlayers) {
    scenePlayers->field0 = 2;
    if (scenePlayers->fieldA != 2) {
        return;
    }
    func_0210d614_inline(scenePlayers, data_0217d070.fieldB, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void MKDS_SND_210D65C(ScenePlayers *scenePlayers) {
    scenePlayers->field0 = 3;
    if (scenePlayers->fieldA != 3) {
        return;
    }
    func_0210d614_inline(scenePlayers, data_0217d070.fieldB, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void MKDS_SND_210D614(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    func_0210d614_inline(scenePlayers, seqNo, handle);
}

void MKDS_SND_210D5C0(ScenePlayers *scenePlayers) {
    func_0210d614_inline(scenePlayers, data_0217d070.fieldB, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void sub_210D590(ScenePlayers *scenePlayers, u32 fadeSteps) {
    if (scenePlayers->fieldB == 0xff) {
        return;
    }
    NNS_SndPlayerStopSeq(&scenePlayers->fieldC, fadeSteps);
}
