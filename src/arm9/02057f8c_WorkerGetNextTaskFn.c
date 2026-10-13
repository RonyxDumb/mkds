/* Decompiled C draft; module arm9; ROM address 02057f8c. No matching claim. */
#include "types.h"
#include "deps/02057f8c_WorkerGetNextTaskFn.h"

uint WorkerGetNextTaskFn(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  puVar4 = (undefined4 *)0x0;
  uVar6 = 0;
  iVar5 = 0;
  do {
    iVar3 = (uint)*(byte *)(param_1 + 0x28) - iVar5;
    if (iVar3 < 0) {
      iVar3 = iVar3 + 10;
    }
    uVar2 = param_1 + iVar3 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) break;
    iVar5 = iVar5 + 1;
    puVar4 = (undefined4 *)(param_1 + iVar3 * 4);
  } while (iVar5 < 10);
  if (puVar4 != (undefined4 *)0x0) {
    uVar6 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
            *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
    *puVar4 = 0;
  }
  return uVar6;
}

