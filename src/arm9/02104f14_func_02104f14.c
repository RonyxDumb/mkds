/* Decompiled C draft; module arm9; ROM address 02104f14. No matching claim. */
#include "types.h"
#include "deps/02104f14_func_02104f14.h"

void func_02104f14(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  UNRECOVERED_JUMPTABLE = pcRam02104f50;
  uVar2 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  uVar3 = iRam02104f4c + uVar2 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
    *(undefined4 *)(iRam02104f54 + uVar2 * 4) = 1;
  }
  uVar3 = param_1 + 0x134U & 3;
  uVar1 = *(uint *)(param_1 + 0x134U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02104f48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
  return;
}

