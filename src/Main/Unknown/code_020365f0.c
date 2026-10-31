#include "Main/Unknown/code_020365f0.h"
#include "Main/Unknown/code_020366bc.h"
#include "Main/Unknown/code_02039044.h"
#include "Main/Unknown/code_0200f168.h"
#include "Main/Unknown/code_02036678.h"
#include "Main/Unknown/code_02036c4c.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"

void func_020365f0(void) {
    u32 a;
    func_020366bc();
    func_0203907c();
    data_02174e78.mUnk_04 = (u32) ARM9_TEXT_START;
    data_02174e78.mUnk_08 = func_0200f168(0);
    func_02036678();
    a = func_0200f168(0);
    data_02174e78.mUnk_0c = func_02036c4c(a, func_0200f17c(0) - a);
    func_02036590(&data_02174e88, 0);
    data_02174e78.mUnk_10 = data_usa_021646ec;
    func_020394cc();
}
