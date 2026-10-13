/* Decompiled C draft; module arm7; ROM address 037fc908. No matching claim. */
#include "types.h"
#include "deps/037fc908_FUN_037fc908.h"

void FUN_037fc908(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar3;
  
  uVar4 = 0;
  for (uVar5 = param_1; ((int)uVar4 < 0x10 && (uVar5 != 0)); uVar5 = uVar5 >> 1) {
    if (((uVar5 & 1) != 0) &&
       (iVar6 = uVar4 * 0x54 + DAT_037fc9f4,
       ((*(uint *)((uint)DAT_037fc9f8 & 0xfffffffc) >> ((uint)DAT_037fc9f8 & 3) * 8 |
        *(uint *)((uint)DAT_037fc9f8 & 0xfffffffc) << ((uint)DAT_037fc9f8 & 3) * -8 + 0x20) &
       1 << (uVar4 & 0xff)) == 0)) {
      uVar1 = iVar6 + 0x48U & 3;
      uVar2 = *(uint *)(iVar6 + 0x48U & 0xfffffffc);
      pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
      if (pcVar3 != (code *)0x0) {
        uVar1 = iVar6 + 0x4cU & 3;
        uVar2 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc);
        (*pcVar3)(iVar6,0,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
      }
      FUN_037fbd0c(uVar4,0);
      *(undefined1 *)(iVar6 + 0x22) = 0;
      FUN_037fcac8(iVar6);
      *(byte *)(iVar6 + 3) = *(byte *)(iVar6 + 3) & 7;
      *(byte *)(iVar6 + 3) = *(byte *)(iVar6 + 3) & 0xfe;
    }
    uVar4 = uVar4 + 1;
  }
  if ((param_2 & 1) == 0) {
    *DAT_037fc9f8 =
         *(uint *)((uint)DAT_037fc9f8 & 0xfffffffc) >> ((uint)DAT_037fc9f8 & 3) * 8 |
         *(uint *)((uint)DAT_037fc9f8 & 0xfffffffc) << ((uint)DAT_037fc9f8 & 3) * -8 + 0x20 |
         param_1;
  }
  else {
    *DAT_037fc9fc =
         *(uint *)((uint)DAT_037fc9fc & 0xfffffffc) >> ((uint)DAT_037fc9fc & 3) * 8 |
         *(uint *)((uint)DAT_037fc9fc & 0xfffffffc) << ((uint)DAT_037fc9fc & 3) * -8 + 0x20 |
         param_1;
  }
  return;
}

