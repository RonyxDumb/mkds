/* Decompiled C draft; module arm9; ROM address 02132440. No matching claim. */
#include "types.h"
#include "deps/02132440_FUN_02132440.h"

uint FUN_02132440(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 in_lr;
  
  uVar5 = param_1 & 0x80000000;
  uVar3 = param_1;
  if ((int)uVar5 < 0) {
    uVar3 = -param_1;
  }
  if (uVar3 == 0) {
    return 0;
  }
  uVar2 = uVar3 << LZCOUNT(uVar3);
  uVar1 = uVar2 * 2 >> 9;
  uVar3 = uVar5 | uVar1 | (0x9e - LZCOUNT(uVar3)) * 0x800000;
  if ((uVar2 & 0xff) == 0) {
    return uVar3;
  }
  puVar4 = (uint *)GetAlphaFlagsRef();
  uVar6 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
          *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20;
  if ((uVar6 & 0x1000) == 0) {
    *puVar4 = uVar6 | 0x10;
    if ((uVar6 & 0x800000) != 0) {
      if ((uVar6 & 0x400000) == 0) {
        uVar3 = uVar3 - ((int)param_1 >> 0x1f);
      }
      return uVar3;
    }
    if ((uVar6 & 0x400000) == 0) {
      if ((uVar2 & 0x80) == 0) {
        return uVar3;
      }
      if ((uVar2 & 0x7f) != 0 || (uVar1 & 1) != 0) {
        uVar3 = uVar3 + 1;
      }
      return uVar3;
    }
    if (-1 < (int)uVar5) {
      uVar3 = uVar3 + 1;
    }
    return uVar3;
  }
  uVar3 = func_02134238(uVar3,uRam02132508,uVar5,uVar6,in_lr);
  return uVar3;
}

