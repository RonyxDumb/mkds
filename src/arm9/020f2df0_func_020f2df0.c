/* Decompiled C draft; module arm9; ROM address 020f2df0. No matching claim. */
#include "types.h"
#include "deps/020f2df0_func_020f2df0.h"

void func_020f2df0(int param_1,int param_2,int param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined1 auStack_30 [16];
  
  puVar6 = (uint *)(param_1 + 0x5c);
  iVar7 = param_1 + 0x50;
  VecFx32_Add((uint)(uintptr_t)(puVar6),iVar7,(int *)(uintptr_t)(iVar7));
  uVar4 = param_1 + 0x5cU & 3;
  uVar3 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * (longlong)param_3;
  *(uint *)(param_1 + 0x5c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar4 = param_1 + 0x60U & 3;
  uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * (longlong)param_3;
  *(uint *)(param_1 + 0x60) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar4 = param_1 + 100U & 3;
  uVar3 = *(uint *)(param_1 + 100U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * (longlong)param_3;
  *(uint *)(param_1 + 100) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar4 = param_1 + 0xdcU & 3;
  uVar3 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  iVar2 = func_01ffdee4(iVar7,param_1 + 0xe4,0,uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  if (iVar2 != 0) {
    VecFx32_Add((uint)(uintptr_t)(&local_48),iVar7,(int *)(uintptr_t)(iVar7));
    uVar4 = param_1 + 0xfcU & 3;
    uVar3 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & uRam020f30e0) != 0) {
      uVar4 = param_1 + 300U & 3;
      uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      *(uint *)(param_1 + 300) = uVar4 - 1;
      if ((int)uVar4 < 1) {
        func_020f9334(param_1,iVar7,puVar6,param_2);
      }
      else {
        uVar4 = param_1 + 0x74U & 3;
        uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        *(uint *)(param_1 + 0x74) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x10;
        iVar2 = Vector3_DotProduct((uint)(uintptr_t)(&local_3c),(uint)(uintptr_t)(puVar6));
        uVar3 = uRam020f30e4;
        local_44 = (uint)((longlong)local_38 * (longlong)iVar2) >> 0xc |
                   (int)((ulonglong)((longlong)local_38 * (longlong)iVar2) >> 0x20) << 0x14;
        local_48 = (uint)((longlong)local_3c * (longlong)iVar2) >> 0xc |
                   (int)((ulonglong)((longlong)local_3c * (longlong)iVar2) >> 0x20) << 0x14;
        local_40 = (uint)((longlong)local_34 * (longlong)iVar2) >> 0xc |
                   (int)((ulonglong)((longlong)local_34 * (longlong)iVar2) >> 0x20) << 0x14;
        *puVar6 = (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                  *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) - local_48
        ;
        uVar4 = param_1 + 0x60U & 3;
        uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
        *(uint *)(param_1 + 0x60) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) - local_44;
        uVar4 = param_1 + 100U & 3;
        uVar5 = *(uint *)(param_1 + 100U & 0xfffffffc);
        *(uint *)(param_1 + 100) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) - local_40;
        uVar4 = *(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20;
        lVar1 = (ulonglong)uVar3 * (ulonglong)uVar4;
        *puVar6 = (uint)lVar1 >> 0xc |
                  (((int)uVar4 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
        uVar4 = param_1 + 0x60U & 3;
        uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
        uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
        lVar1 = (ulonglong)uVar3 * (ulonglong)uVar4;
        *(uint *)(param_1 + 0x60) =
             (uint)lVar1 >> 0xc |
             (((int)uVar4 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
        uVar4 = param_1 + 100U & 3;
        uVar5 = *(uint *)(param_1 + 100U & 0xfffffffc);
        uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
        lVar1 = (ulonglong)uVar3 * (ulonglong)uVar4;
        *(uint *)(param_1 + 100) =
             (uint)lVar1 >> 0xc |
             (((int)uVar4 >> 0x1f) * uVar3 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
        VecFx32_AddScale1(-param_4,(uint)(uintptr_t)(&local_48),(uint)(uintptr_t)(puVar6),puVar6);
        *(int *)(param_1 + 0xf0) = local_3c;
        *(int *)(param_1 + 0xf4) = local_38;
        *(int *)(param_1 + 0xf8) = local_34;
      }
    }
    uVar4 = param_1 + 0xfcU & 3;
    uVar3 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & uRam020f30e8) != 0) {
      uVar4 = param_1 + 0x74U & 3;
      uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      *(uint *)(param_1 + 0x74) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x20;
      func_020f92e8((undefined4)(uintptr_t)(puVar6),(undefined4)(uintptr_t)(auStack_30));
      iVar2 = func_020f9290(param_1,(undefined4)(uintptr_t)(auStack_30));
      if (iVar2 != 0) {
        return;
      }
      *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) & 0xbfff;
    }
    uVar4 = param_1 + 0xfcU & 3;
    uVar3 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x8000) != 0) {
      func_020f7070(param_1,1);
      return;
    }
  }
  uVar3 = uRam020f30e0;
  uVar4 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xfbffffff;
  uVar4 = param_1 + 0xfcU & 3;
  uVar5 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & uVar3) == 0) {
    uVar4 = param_1 + 0x60U & 3;
    uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    *(uint *)(param_1 + 0x60) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) - param_2;
    uVar4 = param_1 + 0x60U & 3;
    uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
    if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < -0xa000) {
      *(undefined4 *)(param_1 + 0x60) = 0xffff6000;
    }
    return;
  }
  return;
}

