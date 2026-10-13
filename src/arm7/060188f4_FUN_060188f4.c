/* Decompiled C draft; module arm7; ROM address 060188f4. No matching claim. */
#include "types.h"
#include "deps/060188f4_FUN_060188f4.h"

undefined4 FUN_060188f4(uint *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar4 = (*(uint *)(DAT_06018998 & 0xfffffffc) >> (DAT_06018998 & 3) * 8 |
          *(uint *)(DAT_06018998 & 0xfffffffc) << (DAT_06018998 & 3) * -8 + 0x20) + 0x318;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = (uint)*(ushort *)(uVar4 + 2);
  if ((uVar5 < 0xa4) || (DAT_0601899c < uVar5)) {
    uVar3 = 2;
  }
  else {
    iVar6 = uVar4 + 2;
    uVar4 = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      uVar2 = FUN_060096c4((ushort *)(uintptr_t)(iVar6));
      iVar6 = iVar6 + 1;
      uVar4 = FUN_060095d0(uVar2,uVar4 & 0xffff);
    }
    uVar5 = (*(uint *)(DAT_06018998 & 0xfffffffc) >> (DAT_06018998 & 3) * 8 |
            *(uint *)(DAT_06018998 & 0xfffffffc) << (DAT_06018998 & 3) * -8 + 0x20) + 0x318;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = (uint)*(ushort *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
    if (param_1 != (uint *)0x0) {
      *param_1 = uVar5 | uVar4 << 0x10;
    }
    if (uVar4 == uVar5) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}

