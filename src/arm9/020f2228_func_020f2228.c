/* Decompiled C draft; module arm9; ROM address 020f2228. No matching claim. */
#include "types.h"
#include "deps/020f2228_func_020f2228.h"

void func_020f2228(int param_1,int param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int *piVar10;
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined1 auStack_38 [4];
  undefined4 local_34;
  int local_2c;
  int local_28;
  int local_24;
  
  piVar10 = (int *)(param_1 + 0x50);
  puVar9 = (uint *)(param_1 + 0x5c);
  VecFx32_Add((uint)(uintptr_t)(puVar9),(uint)(uintptr_t)(piVar10),piVar10);
  uVar8 = param_1 + 0xdcU & 3;
  uVar6 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  iVar3 = func_01ffdee4(piVar10,(undefined4 *)(uintptr_t)(param_1 + 0xe4),0,uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20,
                        *(undefined2 *)(param_1 + 0x164),(int)*(short *)(param_1 + 0xda),&local_50,
                        &local_44,(int *)(void *)(auStack_38),(uint *)(uintptr_t)(param_1 + 0xfc),0,0,0,0);
  if (iVar3 != 0) {
    uVar8 = param_1 + 0xfcU & 3;
    uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    uVar6 = param_1 + 0x158U & 3;
    uVar4 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
    uVar8 = (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) & 0x80000;
    if (uVar4 >> uVar6 * 8 == 0 && uVar4 << uVar6 * -8 + 0x20 == 0) {
      VecFx32_Add((uint)(uintptr_t)(&local_50),(uint)(uintptr_t)(piVar10),piVar10);
    }
    else if (0 < local_4c) {
      uVar6 = param_1 + 0x54U & 3;
      uVar4 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      *(uint *)(param_1 + 0x54) = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + local_4c;
    }
    uVar6 = param_1 + 0xfcU & 3;
    uVar4 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & uRam020f2750) != 0) {
      uVar6 = param_1 + 0xf0U & 3;
      uVar4 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
      if (((local_44 == (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20)) &&
          (uVar6 = param_1 + 0xf4U & 3, uVar4 = *(uint *)(param_1 + 0xf4U & 0xfffffffc),
          local_40 == (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20))) &&
         (uVar6 = param_1 + 0xf8U & 3, uVar4 = *(uint *)(param_1 + 0xf8U & 0xfffffffc),
         local_3c == (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (!bVar2) {
        *(uint *)(param_1 + 0xf0) = local_44;
        *(uint *)(param_1 + 0xf4) = local_40;
        *(uint *)(param_1 + 0xf8) = local_3c;
        uVar6 = param_1 + 0x74U & 3;
        uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        *(uint *)(param_1 + 0x74) = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20 | 0x100;
        if (uVar8 == 0) {
          func_020f2a6c((uint)(uintptr_t)((undefined4 *)(param_1 + 0x130)),(uint)(uintptr_t)(&local_44),(int *)(uintptr_t)(param_1 + 0x13c));
        }
        else {
          iVar3 = Vector3_DotProduct((uint)(uintptr_t)(&local_44),param_1 + 0x13c);
          uVar6 = param_1 + 0x13cU & 3;
          uVar4 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
          *(uint *)(param_1 + 0x13c) =
               (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) -
               ((uint)((longlong)(int)local_44 * (longlong)iVar3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_44 * (longlong)iVar3) >> 0x20) << 0x14);
          uVar6 = param_1 + 0x140U & 3;
          uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
          *(uint *)(param_1 + 0x140) =
               (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) -
               ((uint)((longlong)(int)local_40 * (longlong)iVar3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_40 * (longlong)iVar3) >> 0x20) << 0x14);
          uVar6 = param_1 + 0x144U & 3;
          uVar4 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
          *(uint *)(param_1 + 0x144) =
               (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) -
               ((uint)((longlong)(int)local_3c * (longlong)iVar3) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_3c * (longlong)iVar3) >> 0x20) << 0x14);
          uVar6 = param_1 + 0x140U & 3;
          uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
          uVar5 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
          uVar6 = param_1 + 0x13cU & 3;
          uVar4 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
          uVar4 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
          uVar6 = param_1 + 0x144U & 3;
          uVar7 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
          uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
          lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
                  (longlong)(int)uVar4 * (longlong)(int)uVar4 +
                  (longlong)(int)uVar5 * (longlong)(int)uVar5;
          if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
            Vector3_MaybeNormalize(param_1 + 0x13c,(int *)(uintptr_t)(param_1 + 0x13c));
          }
          *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(param_1 + 0x13c);
          *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_1 + 0x140);
          *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(param_1 + 0x144);
        }
        Vector3_Cross(param_1 + 0x13c,(uint)(uintptr_t)(&local_44),(uint *)(uintptr_t)(param_1 + 0x148));
      }
    }
    uVar6 = param_1 + 0xfcU & 3;
    uVar4 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & uRam020f2754) != 0) {
      uVar6 = param_1 + 0x158U & 3;
      uVar4 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
      if (uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) {
        *piVar10 = (*(uint *)((uint)piVar10 & 0xfffffffc) >> ((uint)piVar10 & 3) * 8 |
                   *(uint *)((uint)piVar10 & 0xfffffffc) << ((uint)piVar10 & 3) * -8 + 0x20) +
                   local_50;
        uVar6 = param_1 + 0x58U & 3;
        uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
        *(uint *)(param_1 + 0x58) = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + local_48;
      }
      if (uVar8 == 0) {
        local_34 = 0;
        func_020f2768(param_1,(uint)(uintptr_t)(auStack_38));
      }
      else {
        VecFx32_Subtract((uint)(uintptr_t)(auStack_38),param_1 + 0xf0,(int *)(void *)(auStack_38));
        func_020f288c(param_1,(uint)(uintptr_t)(auStack_38));
      }
      *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) & 0xbfff;
      uVar6 = param_1 + 0x15cU & 3;
      uVar4 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
      if (uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) {
        uVar6 = param_1 + 0x74U & 3;
        uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        *(uint *)(param_1 + 0x74) = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20 | 0x20;
        uVar6 = param_1 + 0x154U & 3;
        uVar4 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
        *(uint *)(param_1 + 0x154) = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) - 1;
      }
    }
    uVar4 = uRam020f2750;
    uVar6 = param_1 + 300U & 3;
    uVar5 = *(uint *)(param_1 + 300U & 0xfffffffc);
    uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = param_1 + 0x13cU & 3;
    uVar7 = *(uint *)(param_1 + 0x13cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * (longlong)(int)uVar5;
    *puVar9 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar6 = param_1 + 0x140U & 3;
    uVar7 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * (longlong)(int)uVar5;
    *(uint *)(param_1 + 0x60) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar6 = param_1 + 0x144U & 3;
    uVar7 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * (longlong)(int)uVar5;
    *(uint *)(param_1 + 100) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar6 = param_1 + 0xfcU & 3;
    uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & uVar4) != 0) {
      uVar6 = param_1 + 0x54U & 3;
      uVar7 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      uVar4 = param_1 + 0xe8U & 3;
      uVar5 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
      local_4c = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) -
                 (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
      if ((0x5000 < local_4c) && (uVar8 == 0)) {
        local_4c = 0x5000;
      }
      uVar8 = param_1 + 0x60U & 3;
      uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      if ((int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) < local_4c) {
        *(int *)(param_1 + 0x60) = local_4c;
      }
    }
    uVar6 = uRam020f2758;
    uVar8 = param_1 + 0x154U & 3;
    uVar4 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
    if ((int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) < 0) {
      uVar8 = *(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
              *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20;
      lVar1 = (ulonglong)uRam020f2758 * (ulonglong)uVar8;
      *puVar9 = (uint)lVar1 >> 0xc |
                (((int)uVar8 >> 0x1f) * uRam020f2758 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar8 = param_1 + 0x60U & 3;
      uVar4 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
      uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
      lVar1 = (ulonglong)uVar6 * (ulonglong)uVar8;
      *(uint *)(param_1 + 0x60) =
           (uint)lVar1 >> 0xc |
           (((int)uVar8 >> 0x1f) * uVar6 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      uVar8 = param_1 + 100U & 3;
      uVar4 = *(uint *)(param_1 + 100U & 0xfffffffc);
      uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
      lVar1 = (ulonglong)uVar6 * (ulonglong)uVar8;
      *(uint *)(param_1 + 100) =
           (uint)lVar1 >> 0xc |
           (((int)uVar8 >> 0x1f) * uVar6 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      func_020f6fc4(param_1,1);
      return;
    }
    uVar8 = param_1 + 0xfcU & 3;
    uVar6 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if ((((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) & 0x8000) != 0) &&
       (uVar8 = param_1 + 0x44U & 3, uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
       (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) != 5)) {
      func_020f7070(param_1,1);
      return;
    }
  }
  uVar8 = param_1 + 300U & 3;
  uVar6 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar8 = param_2 - uVar6;
  lVar1 = (ulonglong)uVar8 * 0x29;
  *(uint *)(param_1 + 300) =
       uVar6 + ((uint)lVar1 >> 0xc |
               (((int)uVar8 >> 0x1f) * 0x29 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar8 = param_1 + 0xfcU & 3;
  uVar6 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  if (((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) & uRam020f2750) != 0) {
    uVar8 = param_1 + 0xf0U & 3;
    uVar6 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
    local_2c = (int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) >> 2;
    uVar8 = param_1 + 0xf4U & 3;
    uVar6 = *(uint *)(param_1 + 0xf4U & 0xfffffffc);
    local_28 = (int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) >> 2;
    uVar8 = param_1 + 0xf8U & 3;
    uVar6 = *(uint *)(param_1 + 0xf8U & 0xfffffffc);
    local_24 = (int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) >> 2;
    VecFx32_Subtract(param_1 + 0x5c,(uint)(uintptr_t)(&local_2c),param_1 + 0x5c);
    return;
  }
  uVar8 = param_1 + 0x60U & 3;
  uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  if ((int)uVar8 < 1) {
    *(uint *)(param_1 + 0x60) = uVar8 - iRam020f2764;
    uVar8 = param_1 + 0x60U & 3;
    uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    if (-0xa001 < (int)(uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20)) {
      return;
    }
    uVar8 = param_1 + 0x74U & 3;
    uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) & 0x20000) != 0) {
      *(undefined4 *)(param_1 + 0x60) = 0xffff6000;
    }
    return;
  }
  piVar10 = (int *)(param_1 + 0x60);
  *(uint *)(param_1 + 0x60) = uVar8 - iRam020f275c;
  uVar8 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) & 0x20000) == 0) {
    return;
  }
  uVar8 = param_1 + 0x60U & 3;
  uVar6 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  if (0xa000 < (int)uVar8) {
    *piVar10 = (int)(*(uint *)((uint)piVar10 & 0xfffffffc) >> ((uint)piVar10 & 3) * 8 |
                    *(uint *)((uint)piVar10 & 0xfffffffc) << ((uint)piVar10 & 3) * -8 + 0x20) >> 3;
    return;
  }
  *(uint *)(param_1 + 0x60) =
       (uint)((ulonglong)uRam020f2760 * (ulonglong)uVar8) >> 0xc |
       (((int)uVar8 >> 0x1f) * uRam020f2760 +
       (int)((ulonglong)uRam020f2760 * (ulonglong)uVar8 >> 0x20)) * 0x100000;
  return;
}

