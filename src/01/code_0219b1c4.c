#include "01/code_0219b1c4.h"
#include "Main/Unknown/code_02087000.h"
#include "01/code_0219b834.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0212b000.h"

void func_ov001_0219b208(Unk0219b250 *a, s32 b, s32 c, s32 d) {
    func_02087e90(a->mUnk_1c, b);
    a->mUnk_1c->mUnk_08 = c;
    func_02087cfc(a->mUnk_1c, b, d != 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1);
}

void func_ov001_0219b1fc(Unk0219b250 *a) {
    func_02087de0(a->mUnk_28);
}

void func_ov001_0219b1c4(Unk0219b250 *a, s32 b, s32 c, s32 d) {
    func_02087e90(a->mUnk_28, b);
    a->mUnk_20->mUnk_08 = c;
    func_02087cfc(a->mUnk_28, b, d != 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1);
}
