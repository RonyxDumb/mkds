#include "00/code_02194840.h"
#include "00/GameSpy/gpiBuddy.h"
#include "00/code_02194874.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/GameSpy/hashtable.h"

BOOL GpiForEachProfileWhileNonZero(GpConnection *a, void *b, void *c) {
    GpiConnection *r;
    Unk02194840Arg d;

    r = a->mGpiConnection;
    d.field0 = a;
    d.field4 = b;
    d.field8 = c;
    if (HashtableFindByFn(r->mProfileList.mTable, (s32) func_ov000_02194874, &d) == NULL) {
        return TRUE;
    }
    return FALSE;
}
