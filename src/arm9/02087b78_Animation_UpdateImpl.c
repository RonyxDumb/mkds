/* Decompiled C draft; module arm9; ROM address 02087b78. No matching claim. */
#include "types.h"
#include "deps/02087b78_Animation_UpdateImpl.h"

void Animation_UpdateImpl(int param_1)

{
  uint uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar3;
  uint uVar4;
  
  *(undefined2 *)(param_1 + 2) = 0;
  UNRECOVERED_JUMPTABLE = pcRam02087b98;
  uVar1 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(uint *)(param_1 + 0xc) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
                    /* WARNING: Could not recover jumptable at 0x02087b94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

