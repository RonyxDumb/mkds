/* Decompiled C draft; module arm9; ROM address 02046b40. No matching claim. */
#include "types.h"
#include "deps/02046b40_StateDualHandler_Execute.h"

void StateDualHandler_Execute(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  int iVar5;
  code *pcVar3;
  
  if (*(short *)(param_1 + 0x12) == 0) {
    iVar5 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
            (uint)*(ushort *)(param_1 + 0xe) * 8;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined2 *)(param_1 + 0x12) = 0;
    *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(param_1 + 0x10) = 0;
    uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar2 = uVar4 + (uint)*(ushort *)(param_1 + 0xe) * 8;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    iVar5 = uVar4 + (uint)*(ushort *)(param_1 + 0xe) * 8;
    if (pcVar3 != (code *)0x0) {
      uVar2 = param_1 + 8 & 3;
      uVar1 = *(uint *)(param_1 + 8 & 0xfffffffc);
      (*pcVar3)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
    }
  }
  uVar2 = iVar5 + 4U & 3;
  uVar1 = *(uint *)(iVar5 + 4U & 0xfffffffc);
  pcVar3 = (code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    uVar2 = param_1 + 8 & 3;
    uVar1 = *(uint *)(param_1 + 8 & 0xfffffffc);
    (*pcVar3)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  }
  uVar2 = param_1 + 4 & 3;
  uVar1 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(uint *)(param_1 + 4) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 1;
  return;
}

