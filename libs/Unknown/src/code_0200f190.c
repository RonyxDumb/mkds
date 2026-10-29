#include "code_0200f190.h"
#include "code_0200f328.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200ef24.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"

// On the first call fills the tables of func_0200ef24 and func_0200ef38 for indices 0 and 3 to 6 from
// func_0200ef4c and func_0200f038, and clears index 2.
void func_0200f210(void) {
    if (data_021701b4 != 0) {
        return;
    }
    data_021701b4 = 1;
    func_0200ef38(0, func_0200f038(0));
    func_0200ef24(0, func_0200ef4c(0));
    func_0200ef24(2, 0);
    func_0200ef38(2, 0);
    func_0200ef38(3, func_0200f038(3));
    func_0200ef24(3, func_0200ef4c(3));
    func_0200ef38(4, func_0200f038(4));
    func_0200ef24(4, func_0200ef4c(4));
    func_0200ef38(5, func_0200f038(5));
    func_0200ef24(5, func_0200ef4c(5));
    func_0200ef38(6, func_0200f038(6));
    func_0200ef24(6, func_0200ef4c(6));
}

// Fills index 2 of both tables, then unless data_021701b8 is nonzero and the low two bits of func_0200e884() are
// not 1, passes one constant each to func_0200f35c and func_0200f364.
void func_0200f190(void) {
    func_0200ef38(2, func_0200f038(2));
    func_0200ef24(2, func_0200ef4c(2));
    if (data_021701b8 != 0 && (func_0200e884() & 3) != 1) {
        return;
    }
    func_0200f35c(0x200002b);
    func_0200f364(0x23e0021);
}
