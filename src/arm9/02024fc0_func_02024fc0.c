/* Decompiled C draft; module arm9; ROM address 02024fc0. No matching claim. */
#include "types.h"
#include "deps/02024fc0_func_02024fc0.h"

void func_02024fc0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2 + 8U & 3;
  uVar2 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (0x440000 < (int)uVar3) {
    uVar3 = 0x440000;
  }
  uVar2 = param_2 + 0x5cU & 3;
  uVar1 = *(uint *)(param_2 + 0x5cU & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x02024fe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02024fe4)(param_1,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,
                   *(undefined1 *)(param_2 + 4),(int)(uVar3 << 4) >> 0x10);
  return;
}

