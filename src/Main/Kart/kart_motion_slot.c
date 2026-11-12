#include "Main/Kart/kart_motion_slot.h"
#include "Main/Menu/title_scene.h"
#include "ITCM/kart_motion.h"

void AdvanceKartMotionSlot(Kart *kart) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        FinishKartInCourseMapKind2Shape(&kart->mPos, kart->mIndex);
    }
    AdvanceKartMotion(kart);
}
