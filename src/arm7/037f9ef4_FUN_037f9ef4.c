/* Decompiled C draft; module arm7; ROM address 037f9ef4. No matching claim. */
#include "types.h"
#include "deps/037f9ef4_FUN_037f9ef4.h"

uint FUN_037f9ef4(int param_1,undefined4 *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  FUN_037faf70();
  *(undefined4 **)(DAT_037f9f98 + param_1 * 4) = param_2;
  param_2[4] = param_2 + 5;
  param_2[1] = param_4;
  for (iVar4 = 0; uVar2 = (uint)(param_2 + 1) & 3,
      uVar1 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc),
      iVar4 < (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20); iVar4 = iVar4 + 1) {
    uVar2 = (uint)(param_2 + 4) & 3;
    uVar1 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    iVar3 = uVar2 + iVar4 * 0xc;
    *(undefined4 *)(uVar2 + iVar4 * 0xc) = 0xffffffff;
    *(undefined4 *)(iVar3 + 8) = 0;
    uVar2 = iVar3 + 8U & 3;
    uVar1 = *(uint *)(iVar3 + 8U & 0xfffffffc);
    *(uint *)(iVar3 + 4) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  }
  *param_2 = 0xffffffff;
  uVar2 = (uint)(param_2 + 4) & 3;
  uVar1 = *(uint *)((uint)(param_2 + 4) & 0xfffffffc);
  param_2[2] = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + param_4 * 0xc + 0x1f & 0xffffffe0
  ;
  param_2[3] = param_3 & 0xffffffe0;
  FUN_037faf84();
  uVar2 = (uint)(param_2 + 2) & 3;
  uVar1 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
  return uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
}

