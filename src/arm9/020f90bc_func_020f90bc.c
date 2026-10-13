/* Decompiled C draft; module arm9; ROM address 020f90bc. No matching claim. */
#include "types.h"
#include "deps/020f90bc_func_020f90bc.h"

void func_020f90bc(int param_1)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  UNRECOVERED_JUMPTABLE = pcRam020f90d8;
  uVar1 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  *(uint *)(param_1 + 0x40) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x3fffffe0;
  uVar1 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020f90d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_1,param_1 + 0x50,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

