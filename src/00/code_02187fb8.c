#include "00/code_02187fb8.h"

void func_ov000_02187fb8(void) {
    if ((*(int *) &data_ov000_021b4cb0) != 0) {
        if (data_ov000_021b4cac != 0) {
            func_ov000_02187274(data_ov000_021b4cac);
        }
        func_ov000_02186474();
        if (*(int *) ((*(int *) &data_ov000_021b4cb0) + 0x188) != 0) {
            func_0200e084((Unk0200db5c *) ((*(int *) &data_ov000_021b4cb0) + 0x11c));
        }
        *(u32 *) ((*(int *) &data_ov000_021b4cb0) + 4) = 0xfffffff9;
    }
}
