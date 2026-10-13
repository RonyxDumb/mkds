/* Decompiled C draft; module arm9; ROM address 021343b0. No matching claim. */
#include "types.h"
#include "deps/021343b0_func_021343b0.h"

undefined4 func_021343b0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar2 = iRam0213441c;
  uVar6 = 0;
  iVar5 = 1;
  iVar3 = iRam0213441c;
  do {
    uVar1 = iVar3 + 4U & 3;
    uVar4 = *(uint *)(iVar3 + 4U & 0xfffffffc);
    if ((((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) << 0x16) >> 0x1d != 0) &&
       (iVar3 = func_021349c4(), iVar3 != 0)) {
      uVar6 = 0xffffffff;
    }
    if (iVar5 < 3) {
      iVar3 = iVar2 + iVar5 * 0x4c;
      iVar5 = iVar5 + 1;
    }
    else {
      iVar3 = 0;
    }
  } while (iVar3 != 0);
  return uVar6;
}

