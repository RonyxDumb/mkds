/* Decompiled C draft; module arm9; ROM address 02132200. No matching claim. */
#include "types.h"
#include "deps/02132200_func_02132200.h"

longlong func_02132200(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 in_lr;
  longlong lVar5;
  
  uVar2 = param_1 * 0x200;
  uVar3 = param_1 >> 0x17 & 0xff;
  if (uVar3 == 0) {
    if (uVar2 == 0) {
      return ((ulonglong)param_1 & 0x80000000) << 0x20;
    }
    iVar4 = LZCOUNT(uVar2 >> 1);
    uVar3 = 1 - iVar4;
    uVar2 = ((uVar2 >> 1) << iVar4) * 2;
  }
  else if (uVar3 == 0xff) {
    if (uVar2 == 0) {
      return (ulonglong)(uRam021322c0 | param_1 & 0x80000000) << 0x20;
    }
    if ((uVar2 & 0x80000000) == 0) {
      puVar1 = (uint *)GetAlphaFlagsRef();
      uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
              *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
      if ((uVar2 & 0x100) != 0) {
        lVar5 = func_02134188(param_1,DAT_021322c4,puVar1,uVar2,in_lr);
        return lVar5;
      }
      *puVar1 = uVar2 | 1;
    }
    return 0x7fffffffffffffff;
  }
  return CONCAT44(param_1 & 0x80000000 | uVar2 >> 0xc | (uVar3 + 0x380) * 0x100000,uVar2 << 0x14);
}

