/* Decompiled C draft; module arm9; ROM address 020d2234. No matching claim. */
#include "types.h"
#include "deps/020d2234_func_020d2234.h"

undefined4 func_020d2234(ushort *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  uint uVar3;
  
  uVar5 = (uint)*param_1;
  uVar3 = param_2 + 0x44U & 3;
  uVar2 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  iVar4 = 0;
  if (99 < uVar5) {
    do {
      uVar5 = uVar5 - 100;
      iVar4 = iVar4 + 1;
    } while (99 < (int)uVar5);
  }
  iVar1 = func_020d6d8c(0,uVar3,iVar4,uVar5);
  if (iVar1 != 0) {
    iVar4 = func_020d6d34(0,uVar3,iVar4,uVar5,3);
    if (iVar4 == 2) {
      return 1;
    }
  }
  return 0;
}

