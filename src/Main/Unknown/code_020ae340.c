#include "Main/Unknown/code_020ae340.h"
#include "Main/Unknown/code_0203b680.h"
#include "Main/Unknown/code_0203b69c.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/unk_02168000.h"

#pragma optimize_for_size on
#pragma thumb on

// non-matching: same size; only the stack offsets of the file result and the two counts differ; 8 lines differ; first: original
// `str r0, [sp, #4]`, ours `str r0, [sp, #12]`
void func_020ae340(u32 a, u8 *b, u8 *c) {
    void *f;
    s32 n;
    s32 m;
    u8 i;
    u8 j;

    f = func_02047a28("/missionTable.mtbl");
    n = func_0203b6a4((u32) f);
    m = func_0203b69c((u32) f);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a == func_0203b680((u32) f, i, j)) {
                *b = i;
                *c = j;
            }
        }
    }
}

u32 func_020ae3a4(s32 a, s32 b) {
    return data_02168024[a * 4 + b];
}

#pragma thumb off
