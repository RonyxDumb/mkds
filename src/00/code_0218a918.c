#include "00/code_0218a918.h"
#include "00/code_0218a000.h"
#include "00/code_0218a9bc.h"
#include "00/code_0218acf4.h"
#include "00/code_0218aea4.h"
#include "00/code_0218ae68.h"

void func_ov000_0218a98c(Unk0218a9bc *a) {
    SbServer *v1;
    while ((a->field8.field8 < a->field4 && (0 < a->field14.field8))) {
        v1 = func_ov000_0218aea4(&a->field14);
        func_ov000_0218ad44(a, v1);
    }
}

void func_ov000_0218a950(MatchingServerList *a) {
    if (a->field0.field8.field8 != 0) {
        func_ov000_0218aa14(&a->field0, 0);
        func_ov000_0218a9bc(&a->field0);
        if (0 < a->field0.field14.field8) {
            func_ov000_0218a98c(&a->field0);
        }
        if (a->field0.field8.field8 == 0) {
            a->field0.field44(a, 2, 0, a->field0.field48);
        }
    }
}

void func_ov000_0218a93c(Unk0218a9bc *a, u8 b) {
    int v1;
    v1 = a->field40;
    if (v1 < 0x14) {
        a->field40 = v1 + 1;
        a->field2C[v1] = b;
    }
}

void func_ov000_0218a918(MatchingServerList *a, SbServer *b) {
    int v1;
    v1 = func_ov000_0218ae68(&a->field0.field8, b);
    if (v1 == 0) {
        func_ov000_0218ae68(&a->field0.field14, b);
    }
}
