/* Decompiled C draft; module arm9; ROM address 0209b688. No matching claim. */
#include "types.h"
#include "deps/0209b688_StructMapObject_SetNsbtpFrame.h"

void StructMapObject_SetNsbtpFrame(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar3;
  
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    *(short *)(uVar3 + 0x18) = (short)param_2;
    return;
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = param_1 + 0x20U & 3;
    uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(int *)(uVar4 + 0xc) = param_2 << 0xc;
    uVar3 = uVar4 + 0x1c & 3;
    uVar1 = *(uint *)(uVar4 + 0x1c & 0xfffffffc);
    uVar2 = uVar4 + 0xc & 3;
    uVar5 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
    uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + (uint)*(ushort *)(uVar4 + 0x1a) * 4;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) =
         uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    return;
  }
  return;
}

