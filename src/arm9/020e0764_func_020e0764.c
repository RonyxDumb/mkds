/* Decompiled C draft; module arm9; ROM address 020e0764. No matching claim. */
#include "types.h"
#include "deps/020e0764_func_020e0764.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 func_020e0764(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  bool bVar18;
  undefined8 uVar19;
  int iStack_40;
  int aiStack_3c [3];
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uVar6;
  
  VecFx32_Subtract(param_2,param_1 + 0xf4,aiStack_3c);
  iVar3 = VecFx32_CrossProduct_0((uint)(uintptr_t)(aiStack_3c),param_1 + 0x28);
  iVar4 = VecFx32_CrossProduct_0((uint)(uintptr_t)(aiStack_3c),param_1 + 0x40);
  uVar6 = param_1 + 0x100U & 3;
  uVar5 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar2 = (longlong)iVar3 * (longlong)iVar3 + (longlong)iVar4 * (longlong)iVar4;
  uVar5 = (uint)lVar2;
  iVar11 = (int)((ulonglong)lVar2 >> 0x20);
  iVar15 = uVar6 + param_3;
  iVar16 = (int)((ulonglong)((longlong)iVar15 * (longlong)iVar15) >> 0x20);
  bVar17 = (uint)((longlong)iVar15 * (longlong)iVar15) < uVar5;
  if ((int)(iVar16 - (iVar11 + (uint)bVar17)) < 0 !=
      (SBORROW4(iVar16,iVar11) != SBORROW4(iVar16 - iVar11,(uint)bVar17))) {
    return 0;
  }
  puVar14 = (uint *)((ulonglong)((longlong)(int)uVar6 * (longlong)(int)uVar6) >> 0x20);
  bVar17 = (uint)((longlong)(int)uVar6 * (longlong)(int)uVar6) < uVar5;
  bVar18 = SBORROW4((int)puVar14,iVar11) != SBORROW4((int)puVar14 - iVar11,(uint)bVar17);
  puVar7 = (ushort *)((int)puVar14 - (iVar11 + (uint)bVar17));
  puVar8 = puVar7;
  if ((int)puVar7 < 0 != bVar18) {
    puVar8 = puRam020e0b9c;
  }
  if ((int)puVar7 < 0 == bVar18) {
    uVar1 = *puRam020e0ba0;
  }
  else {
    uVar1 = *puVar8;
  }
  uVar6 = (uint)uVar1;
  iVar11 = VecFx32_CrossProduct_0((uint)(uintptr_t)(aiStack_3c),param_1 + 0x34);
  if (iVar11 < 1) {
    uVar5 = param_1 + 0x104U & 3;
    uVar12 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
    uVar5 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
    iVar16 = uVar5 + param_3;
    if (iVar11 + iVar16 < 0 != SBORROW4(iVar11,-iVar16)) {
      return 0;
    }
    if ((int)(iVar11 + uVar5) < 0 == SBORROW4(iVar11,-uVar5)) {
      uVar6 = uVar6 | 0x50;
    }
    else {
      uVar6 = uVar6 | 0x60;
    }
  }
  else {
    uVar5 = param_1 + 0x104U & 3;
    uVar12 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
    uVar5 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
    iVar16 = uVar5 + param_3;
    if (iVar16 < iVar11) {
      return 0;
    }
    if ((int)uVar5 < iVar11) {
      uVar6 = uVar6 | 0xa0;
    }
    else {
      uVar6 = uVar6 | 0x90;
    }
  }
  if ((uVar6 & 0x1000) != 0) {
    if ((uVar6 & 0x80) == 0) {
      iVar16 = -(iVar16 + iVar11);
    }
    else {
      iVar16 = iVar16 - iVar11;
    }
    iStack_40 = iVar16;
    if (iVar16 < 1) {
      iStack_40 = -iVar16;
    }
    if ((uVar6 & 0x10) != 0) {
      uVar5 = 0;
      aiStack_3c[1] = 0;
      aiStack_3c[0] = iVar3;
      aiStack_3c[2] = iVar4;
      uVar19 = func_020d6f78((uint)(uintptr_t)(aiStack_3c),aiStack_3c);
      iVar3 = (int)uVar19;
      if (iVar3 == 0) {
        puVar14 = &uStack_30;
        uVar19 = *puRam020e0ba4;
        uVar5 = *(uint *)(puRam020e0ba4 + 1);
      }
      iVar15 = iVar15 - iVar3;
      if (iVar3 == 0) {
        *(undefined8 *)puVar14 = uVar19;
        puVar14[2] = uVar5;
      }
      else {
        uVar5 = param_1 + 0x28U & 3;
        uVar12 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
        lVar2 = (longlong)(int)(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) *
                (longlong)aiStack_3c[0];
        uStack_30 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        uVar5 = param_1 + 0x2cU & 3;
        uVar12 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
        lVar2 = (longlong)(int)(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) *
                (longlong)aiStack_3c[0];
        uStack_2c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        uVar5 = param_1 + 0x30U & 3;
        uVar12 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
        lVar2 = (longlong)(int)(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) *
                (longlong)aiStack_3c[0];
        uStack_28 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
        VecFx32_AddScale1(aiStack_3c[2],param_1 + 0x40,(uint)(uintptr_t)(&uStack_30),&uStack_30);
      }
      if (iVar15 < iStack_40) goto LAB_020e0a60;
    }
    func_020e1a80(param_3,iVar16,iStack_40,uVar6);
    return 1;
  }
  uVar5 = 0;
  aiStack_3c[1] = 0;
  aiStack_3c[0] = iVar3;
  aiStack_3c[2] = iVar4;
  uVar19 = func_020d6f78((uint)(uintptr_t)(aiStack_3c),aiStack_3c);
  iVar3 = (int)uVar19;
  if (iVar3 == 0) {
    puVar14 = &uStack_30;
    uVar19 = *puRam020e0ba8;
    uVar5 = *(uint *)(puRam020e0ba8 + 1);
  }
  iVar15 = iVar15 - iVar3;
  if (iVar3 == 0) {
    *(undefined8 *)puVar14 = uVar19;
    puVar14[2] = uVar5;
  }
  else {
    uVar5 = param_1 + 0x28U & 3;
    uVar12 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) *
            (longlong)aiStack_3c[0];
    uStack_30 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar5 = param_1 + 0x2cU & 3;
    uVar12 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) *
            (longlong)aiStack_3c[0];
    uStack_2c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar5 = param_1 + 0x30U & 3;
    uVar12 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) *
            (longlong)aiStack_3c[0];
    uStack_28 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    VecFx32_AddScale1(aiStack_3c[2],param_1 + 0x40,(uint)(uintptr_t)(&uStack_30),&uStack_30);
  }
  if ((uVar6 & 0x10) == 0) {
    uVar5 = uVar6 & 0x80;
    bVar17 = uVar5 != 0;
    if (bVar17) {
      uVar5 = param_1 + 0x104U & 3;
      uVar12 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
      uVar5 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
    }
    uVar12 = param_1 + 0x100U & 3;
    uVar13 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
    if (bVar17) {
      iVar11 = iVar11 - uVar5;
    }
    else {
      uVar5 = param_1 + 0x104U & 3;
      uVar9 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
      uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
    }
    if (!bVar17) {
      iVar11 = iVar11 + uVar5;
    }
    uVar10 = func_020e16dc(param_3,iVar3 - (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20),
                           iVar11,uVar6);
    return uVar10;
  }
LAB_020e0a60:
  func_020e1a80(param_3,iVar15,iVar3,uVar6);
  return 1;
}

