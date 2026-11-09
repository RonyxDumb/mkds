#include "01/code_0219b240.h"
#include "01/code_0219b250.h"

u32 func_ov001_0219b240(MapObjectModel *a) {
    if (a->mAnimations[0]->mHead.mDone != 1) {
        return 1;
    }
    return 0;
}
