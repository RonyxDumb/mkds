/* Decompiled C draft; module arm9; ROM address 02015c24. No matching claim. */
#include "types.h"
#include "deps/02015c24_func_02015c24.h"

void func_02015c24(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  
  puVar2 = (ushort *)NNS_G3dGetResDataByName(param_1 + (uint)*(ushort *)(param_1 + 0x34));
  uVar1 = param_1 + 0x2cU & 3;
  uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  uVar1 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffff;
  uVar3 = (uint)*puVar2;
  if ((puVar2[1] & 1) == 0) {
    uVar1 = (uVar1 << 0xf) >> 0x10;
    uVar3 = (uVar3 << 0xf) >> 0x10;
  }
  *(uint *)(param_3 + 0x14) = uVar3 + uVar1;
  return;
}

