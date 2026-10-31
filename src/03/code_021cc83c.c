#include "03/code_021cc83c.h"
#include "03/code_021bf4f4.h"
#include "03/code_021bf5c8.h"
#include "03/code_021bf86c.h"
#include "03/code_021be610.h"
#include "03/code_021c2120.h"
#include "03/code_021cc000.h"
#include "03/code_021cc4ec.h"
#include "03/code_021cc76c.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/unk_021da000.h"
#include "code_0200fd1c.h"
#include "code_0214cfe4.h"

void func_ov003_021cc83c(void) {
    u16 a[12];
    Unk0200fddc b;
    data_ov003_021da258 = 0;
    func_ov003_021cc7b8();
    func_ov003_021bf86c(8);
    func_ov003_021bf5ec(2);
    func_0200fddc(&b);
    a[0] = 0;
    func_0214cfe4(a[0], &a[1], 0x16);
    func_0214cffc(b.mUnk_04, &a[1], b.mUnk_18 * 2);
    func_ov003_021bf4f4((u32) &a[1], 0x6d);
    func_ov003_021beef8(0);
    func_ov003_021ce920(func_ov003_021cc4ec);
    func_ov003_021cdc10(0xb);
    func_ov003_021c212c(func_ov003_021cc790);
}
