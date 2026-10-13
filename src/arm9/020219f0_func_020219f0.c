/* Decompiled C draft; module arm9; ROM address 020219f0. No matching claim. */
#include "types.h"
#include "deps/020219f0_func_020219f0.h"

undefined4 func_020219f0(int param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  uVar4 = *(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
          *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20;
  uVar5 = param_1 + 0x38U & 3;
  uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) <= uVar4) {
    return 0;
  }
LAB_02021a0c:
  uVar5 = param_1 + uVar4 * 4 + 0x3c;
  uVar3 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  *param_2 = (byte)uVar5;
  bVar1 = *param_2;
  if (0x10 < bVar1) {
    if (bVar1 == 0x11) {
      iVar6 = param_1 + (uVar5 >> 8);
      uVar5 = (uint)(param_3 + 1) & 3;
      uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
      uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
      if ((uVar5 < 8) && (*(char *)(iVar6 + uVar5) != '\0')) {
        iVar6 = uVar5 * 0xc + iVar6;
        uVar2 = *(undefined2 *)(iVar6 + 10);
        *(undefined2 *)param_2 = *(undefined2 *)(iVar6 + 8);
        *(undefined2 *)(param_2 + 2) = uVar2;
        uVar2 = *(undefined2 *)(iVar6 + 0xe);
        *(undefined2 *)(param_2 + 4) = *(undefined2 *)(iVar6 + 0xc);
        *(undefined2 *)(param_2 + 6) = uVar2;
        uVar2 = *(undefined2 *)(iVar6 + 0x12);
        *(undefined2 *)(param_2 + 8) = *(undefined2 *)(iVar6 + 0x10);
        *(undefined2 *)(param_2 + 10) = uVar2;
        uVar5 = (uint)(param_3 + 1) & 3;
        uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
        param_3[1] = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 1;
        return 1;
      }
    }
    goto switchD_02021a30_default;
  }
  if (0xf < bVar1) {
    pbVar7 = (byte *)(param_1 + (uVar5 >> 8));
    uVar5 = (uint)(param_3 + 1) & 3;
    uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
    uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    if (uVar5 < ((uint)pbVar7[1] - (uint)*pbVar7) + 1) {
      uVar2 = *(undefined2 *)(pbVar7 + uVar5 * 0xc + 4);
      *(undefined2 *)param_2 = *(undefined2 *)(pbVar7 + uVar5 * 0xc + 2);
      *(undefined2 *)(param_2 + 2) = uVar2;
      uVar2 = *(undefined2 *)(pbVar7 + uVar5 * 0xc + 8);
      *(undefined2 *)(param_2 + 4) = *(undefined2 *)(pbVar7 + uVar5 * 0xc + 6);
      *(undefined2 *)(param_2 + 6) = uVar2;
      uVar2 = *(undefined2 *)(pbVar7 + uVar5 * 0xc + 0xc);
      *(undefined2 *)(param_2 + 8) = *(undefined2 *)(pbVar7 + uVar5 * 0xc + 10);
      *(undefined2 *)(param_2 + 10) = uVar2;
      uVar5 = (uint)(param_3 + 1) & 3;
      uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
      param_3[1] = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 1;
      return 1;
    }
    goto switchD_02021a30_default;
  }
  switch(bVar1) {
  case 0:
    goto switchD_02021a30_default;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  default:
    goto switchD_02021a30_default;
  }
  iVar6 = param_1 + (uVar5 >> 8);
  uVar2 = *(undefined2 *)(iVar6 + 2);
  *(undefined2 *)(param_2 + 2) = *(undefined2 *)(param_1 + (uVar5 >> 8));
  *(undefined2 *)(param_2 + 4) = uVar2;
  uVar2 = *(undefined2 *)(iVar6 + 6);
  *(undefined2 *)(param_2 + 6) = *(undefined2 *)(iVar6 + 4);
  *(undefined2 *)(param_2 + 8) = uVar2;
  *(undefined2 *)(param_2 + 10) = *(undefined2 *)(iVar6 + 8);
  *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) + 1;
  return 1;
switchD_02021a30_default:
  *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) + 1;
  param_3[1] = 0;
  uVar4 = *(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
          *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20;
  uVar5 = param_1 + 0x38U & 3;
  uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) <= uVar4) {
    return 0;
  }
  goto LAB_02021a0c;
}

