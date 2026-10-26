#include "01/code_0219a258.h"
#include "01/code_0219a950.h"
#include "Main/Unknown/unk_02175628.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_02128210.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"
#include "code_0201ea58.h"

void func_ov001_0219a258(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    u16 flags;
    s32 b;
    s32 a;
    u16 v;

    func_0201ea84(data_ov001_021a9bf0->mUnk_14, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    flags = data_02175628[i].mUnk_00 & 2;
    if (flags == 0) {
        b = 0;
        a = 0;
        v = data_02175628[i].mUnk_4c;
        if (v == 0 && data_02175628[i].mUnk_58 < 5) {
            a = 1;
        }
        if (a == 0 && data_02175628[i].mUnk_54 == 0 && v != 0) {
            b = 1;
        }
        if (b == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            return;
        }
    }
    func_ov001_0219ad7c();
    func_02128310(0);
}
