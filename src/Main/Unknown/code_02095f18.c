#include "Main/Unknown/code_02095f18.h"
#include "Main/Unknown/code_020d7da8.h"

void InitMoveTree(MoveTree *moveTree) {
    InitGroupFollower(&moveTree->mFollower, moveTree->mMapObject.mCourseMapRow, 0);
}
