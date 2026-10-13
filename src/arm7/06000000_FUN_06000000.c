/* Decompiled C draft; module arm7; ROM address 06000000. No matching claim. */
#include "types.h"
#include "deps/06000000_FUN_06000000.h"

int FUN_06000000(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar5;
  int iVar6;
  uint uVar4;
  
  iVar5 = 0;
  thunk_FUN_037faf70();
  uVar4 = DAT_0600006c + 0x54cU & 3;
  uVar3 = *(uint *)(DAT_0600006c + 0x54cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    for (iVar6 = 0; iVar6 < 0x20; iVar6 = iVar6 + 1) {
      iVar1 = iVar6 * 0x10;
      uVar3 = uVar4 + iVar6 * 0x10 + 0xf8;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0x8000) != 0) {
        iVar6 = uVar4 + 0xf8;
        iVar5 = iVar6 + iVar1;
        uVar4 = iVar6 + iVar1 & 3;
        uVar3 = *(uint *)(iVar6 + iVar1 & 0xfffffffc);
        *(uint *)(iVar6 + iVar1) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffff7fff;
        break;
      }
    }
  }
  thunk_FUN_037faf84();
  return iVar5;
}

