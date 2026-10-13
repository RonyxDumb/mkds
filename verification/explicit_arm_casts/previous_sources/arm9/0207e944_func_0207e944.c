/* Decompiled C draft; module arm9; ROM address 0207e944. No matching claim. */
#include "types.h"
#include "deps/0207e944_func_0207e944.h"

void func_0207e944(int param_1)

{
  uint uVar1;
  longlong lVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uVar9;
  uint uVar15;
  
  local_18 = *puRam0207eaec;
  uStack_14 = puRam0207eaec[1];
  uStack_10 = puRam0207eaec[2];
  Vector3_Cross(param_1 + 0x10,&local_18,param_1 + 0x60);
  *(short *)(param_1 + 0x6c) = *(short *)(param_1 + 0x6c) + 1;
  if (*(ushort *)(param_1 + 0x6e) < *(ushort *)(param_1 + 0x6c)) {
    *(undefined2 *)(param_1 + 0x6c) = 0;
    piVar3 = (int *)func_0208537c();
    uVar1 = (uint)(piVar3 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar3 + 2) & 0xfffffffc);
    uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
            *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
    uVar1 = (uint)(piVar3 + 1) & 3;
    uVar5 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar7 * (ulonglong)uVar9;
    uVar13 = (uint)lVar2;
    uVar8 = (uint)(piVar3 + 4) & 3;
    uVar14 = *(uint *)((uint)(piVar3 + 4) & 0xfffffffc);
    uVar15 = uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20;
    uVar8 = (uint)(piVar3 + 3) & 3;
    uVar6 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
    uVar14 = (uint)(piVar3 + 5) & 3;
    uVar10 = *(uint *)((uint)(piVar3 + 5) & 0xfffffffc);
    *piVar3 = uVar15 + uVar13;
    piVar3[1] = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) +
                (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) * uVar7 +
                uVar9 * (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
                (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar15,uVar13);
    *(undefined2 *)(param_1 + 0x6e) = 0;
    piVar3 = (int *)func_0208537c();
    uVar1 = (uint)(piVar3 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar3 + 2) & 0xfffffffc);
    uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
            *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
    uVar1 = (uint)(piVar3 + 1) & 3;
    uVar5 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar7 * (ulonglong)uVar9;
    uVar15 = (uint)lVar2;
    uVar8 = (uint)(piVar3 + 4) & 3;
    uVar14 = *(uint *)((uint)(piVar3 + 4) & 0xfffffffc);
    uVar13 = uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20;
    uVar8 = (uint)(piVar3 + 3) & 3;
    uVar6 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
    uVar14 = (uint)(piVar3 + 5) & 3;
    uVar10 = *(uint *)((uint)(piVar3 + 5) & 0xfffffffc);
    *piVar3 = uVar13 + uVar15;
    piVar3[1] = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) +
                (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) * uVar7 +
                uVar9 * (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
                (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar15);
    uVar1 = (uint)(piVar3 + 1) & 3;
    uVar8 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
    uVar14 = ((uint)((int)(short)((ushort)((ushort)((uVar8 >> uVar1 * 8) >> 0x10) |
                                          (ushort)((uVar8 << uVar1 * -8 + 0x20) >> 0x10)) >> 4) <<
                    0xd) >> 0xc) - 0x1000;
    lVar2 = (ulonglong)uRam0207eaf0 * (ulonglong)uVar14;
    uVar1 = param_1 + 0x74U & 3;
    uVar8 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    iVar11 = (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) +
             ((uint)lVar2 >> 0xc |
             (((int)uVar14 >> 0x1f) * uRam0207eaf0 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000);
    iVar4 = AbsValue(iVar11);
    iVar12 = iVar11;
    if ((iRam0207eaf4 < iVar4) && (iVar12 = iRam0207eaf4, iVar11 < 1)) {
      iVar12 = iRam0207eaf8;
    }
    *(int *)(param_1 + 0x74) = iVar12;
  }
  uVar1 = param_1 + 8U & 3;
  uVar14 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar8 = param_1 + 0x74U & 3;
  uVar7 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar1 = (uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20) + 0x1c;
  uVar14 = uVar1 & 3;
  uVar6 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = param_1 + 0x60U & 3;
  uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar14 * 8 | uVar6 << uVar14 * -8 + 0x20);
  uVar14 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)uVar14;
  *(uint *)(param_1 + 0x60) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 100U & 3;
  uVar8 = *(uint *)(param_1 + 100U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) * (longlong)(int)uVar14;
  *(uint *)(param_1 + 100) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_1 + 0x68U & 3;
  uVar8 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) * (longlong)(int)uVar14;
  *(uint *)(param_1 + 0x68) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  return;
}

