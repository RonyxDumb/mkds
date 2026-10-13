/* Decompiled C draft; module arm7; ROM address 06012edc. No matching claim. */
#include "types.h"
#include "deps/06012edc_FUN_06012edc.h"

void FUN_06012edc(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_060131d8 & 0xfffffffc) >> (DAT_060131d8 & 3) * 8 |
          *(uint *)(DAT_060131d8 & 0xfffffffc) << (DAT_060131d8 & 3) * -8 + 0x20;
  iVar2 = uVar3 + DAT_060131dc;
  thunk_FUN_037fb24c(0,iVar2,0xb0);
  *(undefined2 *)(uVar3 + 0x42c) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined2 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x20) = 0;
  *(undefined2 *)(iVar2 + 0x28) = 0;
  *(undefined4 *)(iVar2 + 0x34) = 0;
  uVar1 = (undefined2)DAT_060131e0;
  *(undefined2 *)(iVar2 + 0xa2) = uVar1;
  *(undefined2 *)(iVar2 + 0xa4) = uVar1;
                    /* WARNING: Could not recover jumptable at 0x06012f48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (3 < *(ushort *)(uVar3 + 0x350)) {
    if (*(short *)(uVar3 + 0x334) != 0) {
      *(ushort *)(uVar3 + 0x3ce) = *(ushort *)(uVar3 + 0x3ce) | 0x4000;
    }
    return;
  }
  (*(code *)((uint)*(ushort *)(uVar3 + 0x350) * 4 + 0x6012f50))();
  return;
}

