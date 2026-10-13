/* Decompiled C draft; module arm9; ROM address 020ec9c0. No matching claim. */
#include "types.h"
#include "deps/020ec9c0_func_020ec9c0.h"

void func_020ec9c0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int unaff_r11;
  bool bVar10;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uVar6;
  
  uVar3 = param_1 + 300U & 3;
  uVar5 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  lVar1 = (longlong)(int)(param_2 - uVar6) * (longlong)param_3;
  bVar10 = ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x40000000) != 0;
  iVar9 = param_1 + 0x170;
  *(uint *)(param_1 + 300) = uVar6 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
  if (bVar10) {
    unaff_r11 = 1;
  }
  uVar3 = param_1 + 300U & 3;
  uVar5 = *(uint *)(param_1 + 300U & 0xfffffffc);
  puVar8 = (undefined4 *)(param_1 + 0x50);
  puVar7 = (uint *)(param_1 + 0x5c);
  if (!bVar10) {
    unaff_r11 = 0;
  }
  func_020d84c0(iVar9,uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  iVar2 = func_020d849c(iVar9);
  if (iVar2 != 0) {
    do {
      uVar3 = param_1 + 0x168U & 3;
      uVar4 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
      uVar5 = param_1 + 0x16cU & 3;
      uVar6 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
      *(uint *)(param_1 + 0x21c) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
      *(uint *)(param_1 + 0x220) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      func_020f371c(param_1 + 0x21c,param_1 + 0x168,param_4,param_5);
      uVar3 = param_1 + 0x168U & 3;
      uVar5 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
      uVar3 = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x18;
      uVar5 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      iVar2 = func_020f3fa8(iVar9,uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
    } while (iVar2 != 0);
  }
  if (unaff_r11 == 0) {
    uVar3 = param_1 + 0x158U & 3;
    uVar5 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
    if ((uVar5 >> uVar3 * 8 == 0 && uVar5 << uVar3 * -8 + 0x20 == 0) ||
       (uVar3 = param_1 + 0x74U & 3, uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
       ((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x20000) == 0)) {
      func_020d8474(iVar9,puVar8);
    }
    else {
      uVar3 = param_1 + 0x54U & 3;
      uVar5 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      local_54 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
      func_020d8460(iVar9,puVar8);
      uVar3 = param_1 + 0x54U & 3;
      uVar5 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      if ((int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) < (int)local_54) {
        *(uint *)(param_1 + 0x54) = local_54;
      }
    }
    uVar3 = param_1 + 0x54U & 3;
    uVar4 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
    uVar5 = param_1 + 0x60U & 3;
    uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    *(uint *)(param_1 + 0x54) =
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) +
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  }
  else {
    local_34 = *puVar8;
    uStack_30 = *(undefined4 *)(param_1 + 0x54);
    uStack_2c = *(undefined4 *)(param_1 + 0x58);
    func_020d8488(iVar9,puVar8);
    *(undefined4 *)(param_1 + 0x60) = 0;
    uVar3 = param_1 + 0x158U & 3;
    uVar5 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
    if (uVar5 >> uVar3 * 8 == 0 && uVar5 << uVar3 * -8 + 0x20 == 0) {
      VecFx32_Subtract(puVar8,&local_34,&local_34);
      iVar9 = VecFx32_CrossProduct_0(&local_34,param_1 + 0xf0);
      if (0 < iVar9) {
        VecFx32_AddScale1(-iVar9,param_1 + 0xf0,puVar8,puVar8);
      }
    }
  }
  uVar3 = param_1 + 0xdcU & 3;
  uVar5 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  iVar9 = func_01ffdee4(puVar8,param_1 + 0xe4,0,uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,4,
                        (int)*(short *)(param_1 + 0xda),&local_58,&local_4c,&local_40,param_1 + 0xfc
                        ,0,0,0,0);
  if (iVar9 != 0) {
    uVar3 = param_1 + 0x158U & 3;
    uVar5 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
    if (uVar5 >> uVar3 * 8 == 0 && uVar5 << uVar3 * -8 + 0x20 == 0) {
      VecFx32_Add(&local_58,puVar8,puVar8);
    }
    else if (0 < (int)local_54) {
      uVar3 = param_1 + 0x54U & 3;
      uVar5 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      *(uint *)(param_1 + 0x54) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + local_54;
    }
    uVar3 = param_1 + 0xfcU & 3;
    uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & uRam020ece10) != 0) {
      iVar9 = Vector3_DotProduct(&local_4c,puVar7);
      *puVar7 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) -
                ((uint)((longlong)(int)local_4c * (longlong)iVar9) >> 0xc |
                (int)((ulonglong)((longlong)(int)local_4c * (longlong)iVar9) >> 0x20) << 0x14);
      uVar3 = param_1 + 0x60U & 3;
      uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      *(uint *)(param_1 + 0x60) =
           (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) -
           ((uint)((longlong)(int)local_48 * (longlong)iVar9) >> 0xc |
           (int)((ulonglong)((longlong)(int)local_48 * (longlong)iVar9) >> 0x20) << 0x14);
      uVar3 = param_1 + 100U & 3;
      uVar5 = *(uint *)(param_1 + 100U & 0xfffffffc);
      *(uint *)(param_1 + 100) =
           (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) -
           ((uint)((longlong)(int)local_44 * (longlong)iVar9) >> 0xc |
           (int)((ulonglong)((longlong)(int)local_44 * (longlong)iVar9) >> 0x20) << 0x14);
      uVar3 = param_1 + 0xf0U & 3;
      uVar5 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
      if (((local_4c == (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20)) &&
          (uVar3 = param_1 + 0xf4U & 3, uVar5 = *(uint *)(param_1 + 0xf4U & 0xfffffffc),
          local_48 == (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20))) &&
         (uVar3 = param_1 + 0xf8U & 3, uVar5 = *(uint *)(param_1 + 0xf8U & 0xfffffffc),
         local_44 == (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20))) {
        bVar10 = true;
      }
      else {
        bVar10 = false;
      }
      if (!bVar10) {
        *(uint *)(param_1 + 0xf0) = local_4c;
        *(uint *)(param_1 + 0xf4) = local_48;
        *(uint *)(param_1 + 0xf8) = local_44;
        uVar3 = param_1 + 0x74U & 3;
        uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        *(uint *)(param_1 + 0x74) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20 | 0x100;
      }
    }
    uVar3 = param_1 + 0xfcU & 3;
    uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    if (((uVar3 & uRam020ece14) != 0) &&
       (uVar5 = param_1 + 0x15cU & 3, uVar6 = *(uint *)(param_1 + 0x15cU & 0xfffffffc),
       uVar6 >> uVar5 * 8 != 0 || uVar6 << uVar5 * -8 + 0x20 != 0)) {
      iVar9 = Vector3_DotProduct(&local_40,puVar7);
      local_58 = (uint)((longlong)local_40 * (longlong)iVar9) >> 0xc |
                 (int)((ulonglong)((longlong)local_40 * (longlong)iVar9) >> 0x20) << 0x14;
      local_54 = (uint)((longlong)local_3c * (longlong)iVar9) >> 0xc |
                 (int)((ulonglong)((longlong)local_3c * (longlong)iVar9) >> 0x20) << 0x14;
      local_50 = (uint)((longlong)local_38 * (longlong)iVar9) >> 0xc |
                 (int)((ulonglong)((longlong)local_38 * (longlong)iVar9) >> 0x20) << 0x14;
      *puVar7 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) - local_58;
      uVar3 = param_1 + 0x60U & 3;
      uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      *(uint *)(param_1 + 0x60) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) - local_54;
      uVar3 = param_1 + 100U & 3;
      uVar5 = *(uint *)(param_1 + 100U & 0xfffffffc);
      *(uint *)(param_1 + 100) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) - local_50;
      VecFx32_Subtract(puVar7,&local_58,puVar7);
      uVar5 = uRam020ece18;
      uVar3 = *(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
              *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20;
      lVar1 = (ulonglong)uRam020ece18 * (ulonglong)uVar3;
      *puVar7 = (uint)lVar1 >> 0xc |
                (((int)uVar3 >> 0x1f) * uRam020ece18 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar3 = param_1 + 0x60U & 3;
      uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
      lVar1 = (ulonglong)uVar5 * (ulonglong)uVar3;
      *(uint *)(param_1 + 0x60) =
           (uint)lVar1 >> 0xc |
           (((int)uVar3 >> 0x1f) * uVar5 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar3 = param_1 + 100U & 3;
      uVar6 = *(uint *)(param_1 + 100U & 0xfffffffc);
      uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
      lVar1 = (ulonglong)uVar5 * (ulonglong)uVar3;
      *(uint *)(param_1 + 100) =
           (uint)lVar1 >> 0xc |
           (((int)uVar3 >> 0x1f) * uVar5 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      func_020f6fc4(param_1,1);
      return;
    }
    if (((uVar3 & 0x8000) != 0) &&
       (uVar3 = param_1 + 0x44U & 3, uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) != 5)) {
      func_020f7070(param_1,1);
      return;
    }
  }
  func_020f2150(param_1);
  uVar3 = param_1 + 0xe4U & 3;
  uVar5 = *(uint *)(param_1 + 0xe4U & 0xfffffffc);
  *puVar7 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
            *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) -
            (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 0x58U & 3;
  uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar5 = param_1 + 0xecU & 3;
  uVar6 = *(uint *)(param_1 + 0xecU & 0xfffffffc);
  *(uint *)(param_1 + 100) =
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) -
       (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  return;
}

