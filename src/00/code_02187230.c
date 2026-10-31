#include "00/code_02187230.h"

u32 func_ov000_02187230(int param_1) {
    func_0200ed34((void *) (param_1 + 0xa28));
    if (*(int *) (param_1 + 0xa40) == 1) {
        func_0200ecc4((void *) (param_1 + 0xa28));
        return 0;
    }
    func_0200ecc4((void *) (param_1 + 0xa28));
    func_0200dc3c((u32) 10);
    return 1;
}
