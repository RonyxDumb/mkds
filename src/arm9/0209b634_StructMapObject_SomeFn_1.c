/* Decompiled C draft; module arm9; ROM address 0209b634. No matching claim. */
#include "types.h"
#include "deps/0209b634_StructMapObject_SomeFn_1.h"

uint StructMapObject_SomeFn_1(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    return (uint)*(ushort *)(uVar3 + 0x1a);
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
    uVar3 = param_1 + 0x20U & 3;
    uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    iVar1 = Animation_GetCurrentLength(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
    return (uint)(iVar1 << 4) >> 0x10;
  }
  return 0;
}

