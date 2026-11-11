#include "01/code_0219b240.h"
#include "01/code_0219b250.h"

u32 IsMapObjectModelNsbcaPlaying(MapObjectModel *mapObjectModel) {
    if (mapObjectModel->mAnimations[0]->mHead.mDone != 1) {
        return 1;
    }
    return 0;
}
