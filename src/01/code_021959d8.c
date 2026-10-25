#include "01/code_021959d8.h"
#include "01/code_02195a6c.h"
#include "01/code_02193b1c.h"
#include "01/code_021972f4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/unk_0216c000.h"

void func_ov001_021959d8(void) {
    Unk02175628Index i;
    u16 f;
    s32 b;

    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 2;
    if (f == 0) {
        f = 0;
        b = 0;
        if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
            b = 1;
        }
        if (b == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
            f = 1;
        }
        if (f == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            return;
        }
    }
    func_ov001_02196d8c();
    func_02128310(0);
}
