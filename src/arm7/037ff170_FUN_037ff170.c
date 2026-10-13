/* Decompiled C draft; module arm7; ROM address 037ff170. No matching claim. */
#include "types.h"
#include "deps/037ff170_FUN_037ff170.h"

undefined4 FUN_037ff170(int param_1,uint param_2,int param_3,undefined2 *param_4)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  
  if ((int)param_2 < 0) {
    return 0;
  }
  FUN_037fc298(param_1);
  uVar5 = param_1 + 0x38U & 3;
  uVar1 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if ((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) <= param_2) {
    FUN_037fc294();
    return 0;
  }
  uVar5 = param_1 + param_2 * 4 + 0x3c;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  *(char *)param_4 = (char)uVar5;
  switch(*(undefined1 *)param_4) {
  case 0:
    break;
  case 1:
    goto LAB_037ff210;
  case 2:
    goto LAB_037ff210;
  case 3:
    goto LAB_037ff210;
  case 4:
    goto LAB_037ff210;
  case 5:
LAB_037ff210:
    iVar4 = 5;
    puVar2 = param_4 + 1;
    puVar6 = (undefined2 *)(param_1 + (uVar5 >> 8));
    do {
      *puVar2 = *puVar6;
      iVar4 = iVar4 + -1;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar4 != 0);
LAB_037ff2e0:
    FUN_037fc294();
    return 1;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    iVar4 = param_1 + (uVar5 >> 8);
    uVar5 = (uint)*(byte *)(param_1 + (uVar5 >> 8));
    if ((param_3 < (int)uVar5) || ((int)(uint)*(byte *)(iVar4 + 1) < param_3)) {
      FUN_037fc294();
      return 0;
    }
    puVar2 = (undefined2 *)((param_3 - uVar5) * 0xc + iVar4);
    iVar4 = 6;
    do {
      puVar2 = puVar2 + 1;
      *param_4 = *puVar2;
      iVar4 = iVar4 + -1;
      param_4 = param_4 + 1;
    } while (iVar4 != 0);
    goto LAB_037ff2e0;
  case 0x11:
    iVar4 = 0;
    param_1 = param_1 + (uVar5 >> 8);
    while ((int)(uint)*(byte *)(param_1 + iVar4) < param_3) {
      iVar4 = iVar4 + 1;
      if (7 < iVar4) {
        FUN_037fc294();
        return 0;
      }
    }
    iVar3 = 6;
    puVar2 = (undefined2 *)(iVar4 * 0xc + param_1 + 8);
    do {
      *param_4 = *puVar2;
      iVar3 = iVar3 + -1;
      puVar2 = puVar2 + 1;
      param_4 = param_4 + 1;
    } while (iVar3 != 0);
    goto LAB_037ff2e0;
  }
  FUN_037fc294();
  return 0;
}

