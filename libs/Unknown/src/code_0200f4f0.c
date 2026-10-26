#include "code_0200f4f0.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"

// Keeps the word at the fixed address as data_021701c4 when it is in range, else clears it; stores func_0200f36c there
// and at mUnk_fdc of the fixed object unless data_021701c4 is set and bit 30 of func_0200e884() is set.
void func_0200f4f0(void) {
    u32 v;
    Unk0200f4f0 *p;

    v = *(u32 *) 0x027ffd9c;
    if (v >= 0x2600000 && v < 0x2800000) {
        data_021701c4 = (UnkFunc *) v;
    } else {
        data_021701c4 = 0;
    }
    p = (Unk0200f4f0 *) 0x027e3000;
    if (data_021701c4 == 0 || (func_0200e884() & 0x40000000) == 0) {
        *(UnkFunc **) 0x027ffd9c = (UnkFunc *) func_0200f36c;
        p->mUnk_fdc = (UnkFunc *) func_0200f36c;
    }
    data_021701bc = 0;
}
