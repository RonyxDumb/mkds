#include "00/code_0219488c.h"
#include "00/code_02194840.h"
#include "00/code_021948bc.h"

s32 func_ov000_0219488c(GpConnection *a, const char *b, const char *c, void **d) {
    Unk0219488cArg e;

    e.field0 = b;
    e.field4 = c;
    e.field8 = d;
    e.fieldC = FALSE;
    GpiForEachProfileWhileNonZero(a, func_ov000_021948bc, &e);
    if (e.fieldC == FALSE) {
        *d = NULL;
    }
    return 0;
}
