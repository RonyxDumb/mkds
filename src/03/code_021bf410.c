#include "03/code_021bf410.h"

// non-matching: 0x28 bytes, original 0x2c; 13 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
u32 func_ov003_021bf410(void) {
    if (*((unsigned char *) ((u32) (&data_ov003_021da10c))) == '\0') {
        return 0;
    }
    func_ov003_021d2168((int) (1));
    *((s8 *) ((u32) (&data_ov003_021da10c))) = '\0';
    return 1;
}
