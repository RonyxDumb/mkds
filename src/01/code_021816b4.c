#include "01/code_021816b4.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"

s32 func_ov001_021816b4(void) {
    Unk021816b4 *list;
    Unk021816b4_ent *e;
    s32 i;

    list = func_02100138(0x6c);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (e = list->mUnk_00[i]) != 0; i++) {
            if ((e->mUnk_02 & 0x100) == 0) {
                return 1;
            }
        }
    }
    return 0;
}
