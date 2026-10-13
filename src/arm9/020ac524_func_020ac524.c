/* Decompiled C draft; module arm9; ROM address 020ac524. No matching claim. */
#include "types.h"
#include "deps/020ac524_func_020ac524.h"

uint func_020ac524(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = func_02100138();
  iVar3 = func_0210008c();
  iVar4 = func_021000c8(uVar2);
  iVar6 = 0;
  if (0 < iVar4) {
    do {
      uVar5 = iVar3 + iVar6 * 4;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      if ((*(ushort *)(uVar5 + 2) & 0x100) != 0) {
        return uVar5;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  return 0;
}

