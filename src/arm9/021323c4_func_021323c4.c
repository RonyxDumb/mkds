/* Decompiled C draft; module arm9; ROM address 021323c4. No matching claim. */
#include "types.h"
#include "deps/021323c4_func_021323c4.h"

uint func_021323c4(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 in_lr;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar4 = 0x9e;
  if (-1 < (int)param_1) {
    iVar4 = LZCOUNT(param_1);
    param_1 = param_1 << iVar4;
    iVar4 = 0x9e - iVar4;
  }
  uVar3 = param_1 * 2 >> 9;
  uVar1 = uVar3 | iVar4 << 0x17;
  if ((param_1 & 0xff) == 0) {
    return uVar1;
  }
  puVar2 = (uint *)GetAlphaFlagsRef();
  uVar5 = *(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20;
  if ((uVar5 & 0x1000) != 0) {
    uVar3 = func_02134238(uVar1,uRam02132504,param_1 & 0xff,uVar5,in_lr);
    return uVar3;
  }
  *puVar2 = uVar5 | 0x10;
  if ((uVar5 & 0x800000) != 0) {
    return uVar1;
  }
  if ((uVar5 & 0x400000) != 0) {
    return uVar1 + 1;
  }
  if ((param_1 & 0x80) == 0) {
    return uVar1;
  }
  if ((param_1 & 0x7f) != 0 || (uVar3 & 1) != 0) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

