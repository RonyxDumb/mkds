#include "Main/Unknown/code_0208bd20.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_0207e000.h"

void AdvanceKartAiForStaffRoll(KartAi *kartAi) {
    AdvanceStaffRollKartAi(kartAi);
    AdvanceKartAiTurnSpeedLimit(&kartAi->mUnk_e8, kartAi);
}
