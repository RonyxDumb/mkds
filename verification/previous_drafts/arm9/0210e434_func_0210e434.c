/* Decompiled C draft; module arm9; ROM address 0210e434. No matching claim. */
#include "types.h"
#include "deps/0210e434_func_0210e434.h"

void func_0210e434(undefined4 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (((*puRam0210e4bc ==
        (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
        *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20)) &&
      (uVar1 = (uint)(param_1 + 1) & 3, uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc),
      puRam0210e4bc[1] == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))) &&
     (uVar1 = (uint)(param_1 + 2) & 3, uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc),
     puRam0210e4bc[2] == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))) {
    return;
  }
  uVar1 = (uint)(param_1 + 3) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  Sound_MaybeRestoreHeapState
            (*(uint *)(uRam0210e4c0 & 0xfffffffc) >> (uRam0210e4c0 & 3) * 8 |
             *(uint *)(uRam0210e4c0 & 0xfffffffc) << (uRam0210e4c0 & 3) * -8 + 0x20,
             uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  Sound_Context_GetMaybeSavedFrameHeapStateId
            (*(uint *)(uRam0210e4c0 & 0xfffffffc) >> (uRam0210e4c0 & 3) * 8 |
             *(uint *)(uRam0210e4c0 & 0xfffffffc) << (uRam0210e4c0 & 3) * -8 + 0x20);
  uVar3 = puRam0210e4c4[1];
  uVar4 = puRam0210e4c4[2];
  *param_1 = *puRam0210e4c4;
  param_1[1] = uVar3;
  param_1[2] = uVar4;
  return;
}

