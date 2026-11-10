#include "Main/Unknown/code_020646c0.h"
#include "Main/Unknown/code_0203be88.h"
#include "ITCM/code_01ffba68.h"

void func_020646c0(Kart *kart) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        FinishKartInCourseMapKind2Shape(&kart->mPos, kart->mIndex);
    }
    AdvanceKartMotion(kart);
}
