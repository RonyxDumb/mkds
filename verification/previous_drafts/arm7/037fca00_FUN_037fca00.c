/* Decompiled C draft; module arm7; ROM address 037fca00. No matching claim. */
#include "types.h"
#include "deps/037fca00_FUN_037fca00.h"

void FUN_037fca00(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  code *pcVar4;
  
  iVar2 = DAT_037fcac0;
  uVar5 = 0;
  for (; ((int)uVar5 < 0x10 && (param_1 != 0)); param_1 = param_1 >> 1) {
    if (((param_1 & 1) != 0) &&
       (iVar6 = uVar5 * 0x54 + iVar2,
       ((*(uint *)(DAT_037fcac4 & 0xfffffffc) >> (DAT_037fcac4 & 3) * 8 |
        *(uint *)(DAT_037fcac4 & 0xfffffffc) << (DAT_037fcac4 & 3) * -8 + 0x20) &
       1 << (uVar5 & 0xff)) == 0)) {
      uVar1 = iVar6 + 0x48U & 3;
      uVar3 = *(uint *)(iVar6 + 0x48U & 0xfffffffc);
      pcVar4 = (code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      if (pcVar4 != (code *)0x0) {
        uVar1 = iVar6 + 0x4cU & 3;
        uVar3 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc);
        (*pcVar4)(iVar6,0,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      }
      FUN_037fbd0c(uVar5,0);
      *(undefined1 *)(iVar6 + 0x22) = 0;
      FUN_037fcac8(iVar6);
      *(byte *)(iVar6 + 3) = *(byte *)(iVar6 + 3) & 7;
      *(byte *)(iVar6 + 3) = *(byte *)(iVar6 + 3) & 0xfe;
    }
    uVar5 = uVar5 + 1;
  }
  return;
}

