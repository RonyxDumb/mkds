/* Decompiled C draft; module arm9; ROM address 020048cc. No matching claim. */
#include "types.h"
#include "deps/020048cc_File_If1Set2AndUnk20.h"

void File_If1Set2AndUnk20(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  Os_DisableIrq();
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) {
    uVar2 = param_1 + 0xcU & 3;
    uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 2;
    uVar2 = param_1 + 8U & 3;
    uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar3 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    uVar2 = uVar3 + 0x1c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(uint *)(uVar3 + 0x1c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x20;
  }
  Os_RestoreIrq();
  return;
}

