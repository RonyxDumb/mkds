/* Decompiled C draft; module arm9; ROM address 0207f05c. No matching claim. */
#include "types.h"
#include "deps/0207f05c_func_0207f05c.h"

void func_0207f05c(uint param_1)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar17;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 auStack_6c [12];
  undefined1 auStack_60 [12];
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [12];
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uVar16;
  
  iVar3 = func_02080cc0(param_1 + 8);
  uVar11 = param_1 + 0x90 & 3;
  uVar8 = *(uint *)(param_1 + 0x90 & 0xfffffffc);
  if (((uVar8 >> uVar11 * 8 == 0 && uVar8 << uVar11 * -8 + 0x20 == 0) && (0 < iVar3)) && (iVar3 < 5)
     ) {
    bVar2 = false;
    piVar4 = (int *)func_0208537c();
    uVar11 = (uint)(piVar4 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
    uVar13 = uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20;
    uVar12 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
             *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
    uVar11 = (uint)(piVar4 + 1) & 3;
    uVar9 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar12 * (ulonglong)uVar13;
    uVar17 = (uint)lVar1;
    uVar8 = (uint)(piVar4 + 4) & 3;
    uVar15 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
    uVar16 = uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20;
    uVar8 = (uint)(piVar4 + 3) & 3;
    uVar10 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
    uVar15 = (uint)(piVar4 + 5) & 3;
    uVar14 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
    *piVar4 = uVar16 + uVar17;
    piVar4[1] = (uVar14 >> uVar15 * 8 | uVar14 << uVar15 * -8 + 0x20) +
                (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) * uVar12 +
                uVar13 * (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar17);
    uVar11 = (uint)(piVar4 + 1) & 3;
    uVar15 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    uVar8 = param_1 + 0x88 & 3;
    uVar9 = *(uint *)(param_1 + 0x88 & 0xfffffffc);
    if (((int)(short)((ushort)((ushort)((uVar15 >> uVar11 * 8) >> 0x10) |
                              (ushort)((uVar15 << uVar11 * -8 + 0x20) >> 0x10)) >> 4) <=
         (int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20)) &&
       (uVar8 = param_1 + 0x9c & 3, uVar9 = *(uint *)(param_1 + 0x9c & 0xfffffffc),
       uVar11 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x2a4,
       uVar15 = uVar11 & 3, uVar11 = *(uint *)(uVar11 & 0xfffffffc),
       (int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) <=
       (int)(uVar11 >> uVar15 * 8 | uVar11 << uVar15 * -8 + 0x20))) {
      uVar11 = param_1 + 8 & 3;
      uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
      uVar11 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x18;
      uVar8 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      puVar5 = (undefined4 *)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20);
      local_78 = *puVar5;
      uStack_74 = puVar5[1];
      uStack_70 = puVar5[2];
      local_30 = *DAT_0207f2e0;
      uStack_2c = DAT_0207f2e0[1];
      uStack_28 = DAT_0207f2e0[2];
      Vector3_Cross(param_1 + 0x10,&local_30,auStack_6c);
      VecFx32_Subtract((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x80,
                       &local_78,auStack_60);
      VecFx32_CrossProduct_0(auStack_60,auStack_6c);
      uVar11 = param_1 + 8 & 3;
      uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
      uVar11 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x1c;
      uVar8 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      iVar6 = AbsValue();
      if (iVar6 < (int)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20)) {
        bVar2 = true;
      }
    }
    if (bVar2) {
      switch(iVar3) {
      case 0:
        break;
      case 1:
        *(undefined4 *)(param_1 + 0x90) = 1;
        *(undefined4 *)(param_1 + 0x94) = 1;
        *(undefined4 *)(param_1 + 0x98) = 0;
        *(undefined4 *)(param_1 + 0xa0) = 1;
        break;
      case 2:
        *(undefined4 *)(param_1 + 0x90) = 1;
        *(undefined4 *)(param_1 + 0x94) = 1;
        *(undefined4 *)(param_1 + 0x98) = 0;
        *(undefined4 *)(param_1 + 0xa0) = 0;
        break;
      case 3:
        *(undefined4 *)(param_1 + 0x90) = 1;
        *(undefined4 *)(param_1 + 0x94) = 2;
        *(undefined4 *)(param_1 + 0x98) = 0;
        *(undefined4 *)(param_1 + 0xa0) = 1;
        break;
      case 4:
        *(undefined4 *)(param_1 + 0x90) = 1;
        *(undefined4 *)(param_1 + 0x94) = 2;
        *(undefined4 *)(param_1 + 0x98) = 0;
        *(undefined4 *)(param_1 + 0xa0) = 0;
      }
    }
  }
  uVar11 = param_1 + 0x90 & 3;
  uVar8 = *(uint *)(param_1 + 0x90 & 0xfffffffc);
  if ((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) != 2) {
    return;
  }
  if (iVar3 != 5) {
    return;
  }
  *(undefined4 *)(param_1 + 0x90) = 3;
  uVar11 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar11 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x18;
  uVar8 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  puVar5 = (undefined4 *)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20);
  uStack_54 = *puVar5;
  uStack_50 = puVar5[1];
  uStack_4c = puVar5[2];
  uStack_24 = *DAT_0207f2e0;
  uStack_20 = DAT_0207f2e0[1];
  uStack_1c = DAT_0207f2e0[2];
  Vector3_Cross(param_1 + 0x10,&uStack_24,auStack_48);
  VecFx32_Subtract((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x80,&uStack_54,
                   auStack_3c);
  uVar7 = VecFx32_CrossProduct_0(auStack_3c,auStack_48);
  uVar11 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar11 = (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) + 0x1c;
  uVar8 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar7 = FX_Div(uVar7,(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) + 0x1000);
  *(undefined4 *)(param_1 + 0x74) = uVar7;
  uVar11 = param_1 + 0x74 & 3;
  uVar8 = *(uint *)(param_1 + 0x74 & 0xfffffffc);
  iVar3 = AbsValue(uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20);
  if (0x1000 < iVar3) {
    uVar11 = param_1 + 0x74 & 3;
    uVar8 = *(uint *)(param_1 + 0x74 & 0xfffffffc);
    if (0 < (int)(uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x74) = 0x1000;
    }
    *(undefined4 *)(param_1 + 0x74) = 0xfffff000;
  }
  uVar11 = param_1 + 0x74 & 3;
  uVar8 = *(uint *)(param_1 + 0x74 & 0xfffffffc);
  *(int *)(param_1 + 0x74) = (int)(uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) >> 1;
  return;
}

