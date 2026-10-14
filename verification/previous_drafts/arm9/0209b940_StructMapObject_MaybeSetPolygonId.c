/* Decompiled C draft; module arm9; ROM address 0209b940. No matching claim. */
#include "types.h"
#include "deps/0209b940_StructMapObject_MaybeSetPolygonId.h"

void StructMapObject_MaybeSetPolygonId(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    uVar2 = uVar3 + 0x14 & 3;
    uVar1 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
    *(uint *)(uVar3 + 0x14) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xc0ffffff;
    uVar2 = uVar3 + 0x14 & 3;
    uVar1 = *(uint *)(uVar3 + 0x14 & 0xfffffffc);
    *(uint *)(uVar3 + 0x14) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | param_2 << 0x18;
  }
  uVar3 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    uVar3 = uVar3 + 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    ModelBlock_SetPolygonId(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,param_2);
  }
  uVar3 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    *(short *)(uVar3 + 0x6c) = (short)param_2;
  }
  return;
}

