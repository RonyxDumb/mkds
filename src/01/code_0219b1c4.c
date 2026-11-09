#include "01/code_0219b1c4.h"
#include "Main/Unknown/code_02087000.h"
#include "01/code_0219b540.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_02087cfc.h"

void func_ov001_0219b208(MapObjectModel *a, s32 b, s32 c, s32 d) {
    StartModelAnimationBlend(a->mAnimations[0], b);
    a->mAnimations[0]->mHead.mFrameStep = c;
    func_02087cfc(a->mAnimations[0], ((u16) b), (d != 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1));
}

void func_ov001_0219b1fc(MapObjectModel *a) {
    AdvanceModelAnimation(a->mAnimations[3]);
}

void func_ov001_0219b1c4(MapObjectModel *a, s32 b, s32 c, s32 d) {
    StartModelAnimationBlend(a->mAnimations[3], b);
    a->mAnimations[1]->mHead.mFrameStep = c;
    func_02087cfc(a->mAnimations[3], ((u16) b), (d != 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1));
}
