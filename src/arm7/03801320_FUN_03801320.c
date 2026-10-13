/* Decompiled C draft; module arm7; ROM address 03801320. No matching claim. */
#include "types.h"
#include "deps/03801320_FUN_03801320.h"

void FUN_03801320(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint local_8;
  undefined4 local_4;
  
  if ((param_3 & 0xffff) < 5) {
    local_8 = param_3;
    local_4 = param_4;
    FUN_037faf70(param_3 & 0xffff);
    iVar1 = DAT_038013e4;
    uVar4 = DAT_038013e4 + 0x48cU & 3;
    uVar2 = *(uint *)(DAT_038013e4 + 0x48cU & 0xfffffffc);
    *(undefined4 *)(DAT_038013e8 + (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 0x18) =
         param_1;
    uVar4 = iVar1 + 0x48cU & 3;
    uVar2 = *(uint *)(iVar1 + 0x48cU & 0xfffffffc);
    *(undefined4 *)(DAT_038013ec + (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 0x18) =
         param_2;
    puVar3 = &local_8;
    for (iVar5 = 0; puVar3 = puVar3 + 1, iVar5 < (int)(local_8 & 0xffff); iVar5 = iVar5 + 1) {
      uVar4 = iVar1 + 0x48cU & 3;
      uVar2 = *(uint *)(iVar1 + 0x48cU & 0xfffffffc);
      *(uint *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 0x18 + iVar1 + iVar5 * 4 + 0x314
               ) = *puVar3;
    }
    uVar4 = DAT_038013e4 + 0x48cU & 3;
    uVar2 = *(uint *)(DAT_038013e4 + 0x48cU & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    *(uint *)(DAT_038013e4 + 0x48c) = uVar4 + 1 & 0xf;
    FUN_037faf84();
    FUN_037f9854(DAT_038013f0,uVar4 * 0x18 + DAT_038013e8,0);
  }
  return;
}

