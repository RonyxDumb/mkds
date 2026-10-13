/* Decompiled C draft; module arm9; ROM address 020ebef8. No matching claim. */
#include "types.h"
#include "deps/020ebef8_func_020ebef8.h"

void func_020ebef8(undefined2 *param_1,undefined4 *param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [12];
  uint uVar16;
  
  uVar2 = (*(uint *)(uRam020ec184 & 0xfffffffc) >> (uRam020ec184 & 3) * 8 |
          *(uint *)(uRam020ec184 & 0xfffffffc) << (uRam020ec184 & 3) * -8 + 0x20) + 8;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 4) {
    func_0x0218175c(*param_1);
  }
  uVar3 = uRam020ec184;
  param_1[1] = param_1[1] | *puRam020ec188;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 8;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 5) {
    return;
  }
  piVar4 = (int *)func_020d22c0();
  uVar2 = (uint)(piVar4 + 2) & 3;
  uVar3 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
  uVar12 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar10 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
           *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
  uVar2 = (uint)(piVar4 + 1) & 3;
  uVar6 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  lVar1 = (ulonglong)uVar10 * (ulonglong)uVar12;
  uVar14 = (uint)lVar1;
  uVar3 = (uint)(piVar4 + 3) & 3;
  uVar7 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
  uVar13 = (uint)(piVar4 + 4) & 3;
  uVar15 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar16 = uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20;
  uVar13 = (uint)(piVar4 + 5) & 3;
  uVar15 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
  *piVar4 = uVar16 + uVar14;
  piVar4[1] = (uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20) +
              (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) * uVar10 +
              uVar12 * (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) +
              (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar14);
  uVar2 = (uint)(piVar4 + 1) & 3;
  uVar3 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  if ((uint)(ushort)param_1[0x88] <=
      (uint)((ulonglong)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 100 >> 0x20)) {
    return;
  }
  if (param_1[0x87] != 0) {
    iVar5 = func_020f8a04();
    uVar2 = iVar5 * 0x1c +
            (*(uint *)(uRam020ec18c & 0xfffffffc) >> (uRam020ec18c & 3) * 8 |
            *(uint *)(uRam020ec18c & 0xfffffffc) << (uRam020ec18c & 3) * -8 + 0x20) + 8;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    iVar5 = func_020fa3d0(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,8,(undefined4)(uintptr_t)(param_1 + 2),
                          (undefined4)(uintptr_t)(param_1 + 0x5e));
    if (iVar5 != 0) {
      uVar2 = (uint)(param_2 + 1) & 3;
      uVar3 = *(uint *)((uint)(param_2 + 1) & 0xfffffffc);
      uVar13 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      uVar3 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
              *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
      uVar2 = (uint)(param_2 + 2) & 3;
      uVar6 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
      lVar1 = (longlong)(int)uVar2 * (longlong)(int)uVar2 +
              (longlong)(int)uVar3 * (longlong)(int)uVar3 +
              (longlong)(int)uVar13 * (longlong)(int)uVar13;
      if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
        Vector3_MaybeNormalize((uint)(uintptr_t)(param_2),(int *)(void *)(auStack_3c));
      }
      Vector3_Cross((uint)(uintptr_t)(param_1 + 0x5e),(uint)(uintptr_t)(auStack_3c),(uint *)(void *)(auStack_30));
      piVar4 = (int *)func_020d22c0();
      uVar2 = (uint)(piVar4 + 2) & 3;
      uVar3 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
      uVar16 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      uVar15 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
               *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
      uVar2 = (uint)(piVar4 + 1) & 3;
      uVar6 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar15 * (ulonglong)uVar16;
      uVar7 = (uint)lVar1;
      uVar3 = (uint)(piVar4 + 4) & 3;
      uVar13 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
      uVar12 = uVar13 >> uVar3 * 8 | uVar13 << uVar3 * -8 + 0x20;
      uVar3 = (uint)(piVar4 + 3) & 3;
      uVar14 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
      uVar13 = (uint)(piVar4 + 5) & 3;
      uVar10 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
      *piVar4 = uVar12 + uVar7;
      piVar4[1] = (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) +
                  (uVar14 >> uVar3 * 8 | uVar14 << uVar3 * -8 + 0x20) * uVar15 +
                  uVar16 * (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar12,uVar7);
      uVar2 = (uint)(piVar4 + 1) & 3;
      uVar3 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
      iVar8 = (int)((ulonglong)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 0x1800 >> 0x20) +
              iRam020ec190;
      piVar4 = (int *)func_020d22c0();
      uVar2 = (uint)(piVar4 + 2) & 3;
      uVar3 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
      uVar12 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
      uVar7 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
              *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
      uVar2 = (uint)(piVar4 + 1) & 3;
      uVar6 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar7 * (ulonglong)uVar12;
      uVar15 = (uint)lVar1;
      uVar3 = (uint)(piVar4 + 3) & 3;
      uVar10 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
      uVar13 = (uint)(piVar4 + 4) & 3;
      uVar14 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
      uVar16 = uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20;
      uVar13 = (uint)(piVar4 + 5) & 3;
      uVar14 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
      *piVar4 = uVar16 + uVar15;
      piVar4[1] = (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) +
                  (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) * uVar7 +
                  uVar12 * (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar15);
      uVar9 = param_2[1];
      uVar11 = param_2[2];
      *(undefined4 *)(iVar5 + 0x5c) = *param_2;
      *(undefined4 *)(iVar5 + 0x60) = uVar9;
      *(undefined4 *)(iVar5 + 100) = uVar11;
      VecFx32_AddScale1(iVar8,(uint)(uintptr_t)(auStack_3c),(uint)(uintptr_t)(param_1 + 2),(int *)(uintptr_t)(iVar5 + 0x50));
      VecFx32_AddScale1(0,(uint)(uintptr_t)(auStack_30),iVar5 + 0x50,(int *)(uintptr_t)(iVar5 + 0x50));
      *(undefined4 *)(iVar5 + 0x68) = 0xcd;
      *(undefined4 *)(iVar5 + 0x6c) = 0xcd;
      *(undefined4 *)(iVar5 + 0x70) = 0xcd;
      func_020f6630(iVar5,2,param_1 + 2,param_2);
      return;
    }
    return;
  }
  return;
}

