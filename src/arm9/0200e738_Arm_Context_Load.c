/* Decompiled C draft; module arm9; ROM address 0200e738. No matching claim. */
#include "types.h"
#include "deps/0200e738_Arm_Context_Load.h"

void Arm_Context_Load(int param_1)

{
  (*pcRam0200e778)(param_1 + 0x48);
                    /* WARNING: Could not recover jumptable at 0x0200e774. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(*(int *)(param_1 + 0x3c) + -4))
            (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
             *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
  return;
}

