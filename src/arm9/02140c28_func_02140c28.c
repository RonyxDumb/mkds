/* Decompiled C draft; module arm9; ROM address 02140c28. No matching claim. */
#include "types.h"
#include "deps/02140c28_func_02140c28.h"

void func_02140c28(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  
  iVar5 = (int)*(short *)(param_1 + 2);
  func_02140d74(param_4);
  uVar3 = param_4 + 5U & 3;
  uVar1 = *(uint *)(param_4 + 5U & 0xfffffffc);
  if (9 < ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xff)) {
    return;
  }
  if (0x20 < iVar5) {
    iVar5 = 0x20;
  }
  func_021420c0(param_4,iVar5);
  uVar3 = param_4 + 4U & 3;
  uVar1 = *(uint *)(param_4 + 4U & 0xfffffffc);
  uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xff;
  if ((int)uVar3 < iVar5) {
    puVar6 = (uint *)(param_4 + 4);
    do {
      uVar2 = ((*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
               *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) & 0xff) + 1 &
              0xff | (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                     *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) &
                     0xffffff00;
      uVar1 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
      *puVar6 = uVar2 >> uVar1 | uVar2 << 0x20 - uVar1;
      puVar4 = (uint *)(param_4 + uVar3 + 5);
      uVar1 = (*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
              *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xffffff00;
      uVar3 = (4 - ((uint)puVar4 & 3)) * 8 & 0x1f;
      *puVar4 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
      uVar3 = param_4 + 4U & 3;
      uVar1 = *(uint *)(param_4 + 4U & 0xfffffffc);
      uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xff;
    } while ((int)uVar3 < iVar5);
  }
  iVar5 = 0;
  *(short *)(param_4 + 2) = *(short *)(param_4 + 2) - ((short)uVar3 + -1);
  uVar3 = param_4 + 4U & 3;
  uVar1 = *(uint *)(param_4 + 4U & 0xfffffffc);
  if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xff) != 0) {
    do {
      uVar3 = param_4 + iVar5 + 5;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      puVar6 = (uint *)(param_4 + iVar5 + 5);
      uVar1 = ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xff) + 0x30 & 0xff |
              (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
              *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) & 0xffffff00;
      uVar3 = (4 - ((uint)puVar6 & 3)) * 8 & 0x1f;
      *puVar6 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
      iVar5 = iVar5 + 1;
      uVar3 = param_4 + 4U & 3;
      uVar1 = *(uint *)(param_4 + 4U & 0xfffffffc);
    } while (iVar5 < (int)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0xff));
    return;
  }
  return;
}

