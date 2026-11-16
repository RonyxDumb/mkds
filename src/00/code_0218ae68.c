#include "00/code_0218ae68.h"
#include "00/code_0218a9bc.h"

u32 func_ov000_0218ae68(Unk0218ae68 *a, SbServer *b) {
    SbServer *d;
    SbServer *c;
    c = NULL;
    d = a->field0;
    while (d != NULL) {
        if (d == b) {
            if (c != NULL) {
                c->field20 = d->field20;
            }
            if (a->field0 == d) {
                a->field0 = d->field20;
            }
            if (a->field4 == d) {
                a->field4 = c;
            }
            a->field8--;
            return 1;
        }
        c = d;
        d = d->field20;
    }
    return 0;
}
