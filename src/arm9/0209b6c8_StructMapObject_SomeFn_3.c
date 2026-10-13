/* Decompiled C draft; module arm9; ROM address 0209b6c8. No matching claim. */
#include "types.h"
#include "deps/0209b6c8_StructMapObject_SomeFn_3.h"

void StructMapObject_SomeFn_3(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  
  uVar1 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(int *)(uVar4 + 0xc) = param_2 << 0xc;
  uVar1 = uVar4 + 0x1c & 3;
  uVar2 = *(uint *)(uVar4 + 0x1c & 0xfffffffc);
  uVar3 = uVar4 + 0xc & 3;
  uVar5 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (uint)*(ushort *)(uVar4 + 0x1a) * 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) =
       uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  return;
}

