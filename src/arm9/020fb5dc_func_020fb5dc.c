/* Decompiled C draft; module arm9; ROM address 020fb5dc. No matching claim. */
#include "types.h"
#include "deps/020fb5dc_func_020fb5dc.h"

void func_020fb5dc(int param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x260) = 0x28000;
  UNRECOVERED_JUMPTABLE = pcRam020fb618;
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020fb614 & 0xfffffffc) >> (uRam020fb614 & 3) * 8 |
          *(uint *)(uRam020fb614 & 0xfffffffc) << (uRam020fb614 & 3) * -8 + 0x20) + 0x74;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(param_1 + 0x100) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar1 = param_1 + 0x100U & 3;
  uVar2 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  *(uint *)(param_1 + 0x100) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x800;
                    /* WARNING: Could not recover jumptable at 0x020fb610. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

