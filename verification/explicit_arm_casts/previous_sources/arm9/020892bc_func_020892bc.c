/* Decompiled C draft; module arm9; ROM address 020892bc. No matching claim. */
#include "types.h"
#include "deps/020892bc_func_020892bc.h"

void func_020892bc(int param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
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
  
  local_18 = *puRam02089484;
  uStack_14 = puRam02089484[1];
  uStack_10 = puRam02089484[2];
  VecFx32_CrossProduct(param_1 + 0x30,&local_18,param_1 + 0x60);
  *(short *)(param_1 + 0x6c) = *(short *)(param_1 + 0x6c) + 1;
  if (*(ushort *)(param_1 + 0x6e) < *(ushort *)(param_1 + 0x6c)) {
    *(undefined2 *)(param_1 + 0x6c) = 0;
    piVar2 = (int *)func_0208537c();
    uVar6 = (uint)(piVar2 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
    uVar9 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
            *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
    uVar6 = (uint)(piVar2 + 1) & 3;
    uVar4 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar7 * (ulonglong)uVar9;
    uVar13 = (uint)lVar1;
    uVar8 = (uint)(piVar2 + 4) & 3;
    uVar14 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
    uVar15 = uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20;
    uVar8 = (uint)(piVar2 + 3) & 3;
    uVar5 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
    uVar14 = (uint)(piVar2 + 5) & 3;
    uVar10 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
    *piVar2 = uVar15 + uVar13;
    piVar2[1] = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) +
                (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * uVar7 +
                uVar9 * (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar13);
    *(undefined2 *)(param_1 + 0x6e) = 0;
    piVar2 = (int *)func_0208537c();
    uVar6 = (uint)(piVar2 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar2 + 2) & 0xfffffffc);
    uVar9 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar2 & 0xfffffffc) >> ((uint)piVar2 & 3) * 8 |
            *(uint *)((uint)piVar2 & 0xfffffffc) << ((uint)piVar2 & 3) * -8 + 0x20;
    uVar6 = (uint)(piVar2 + 1) & 3;
    uVar4 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar7 * (ulonglong)uVar9;
    uVar15 = (uint)lVar1;
    uVar8 = (uint)(piVar2 + 4) & 3;
    uVar14 = *(uint *)((uint)(piVar2 + 4) & 0xfffffffc);
    uVar13 = uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20;
    uVar8 = (uint)(piVar2 + 3) & 3;
    uVar5 = *(uint *)((uint)(piVar2 + 3) & 0xfffffffc);
    uVar14 = (uint)(piVar2 + 5) & 3;
    uVar10 = *(uint *)((uint)(piVar2 + 5) & 0xfffffffc);
    *piVar2 = uVar13 + uVar15;
    piVar2[1] = (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) +
                (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * uVar7 +
                uVar9 * (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar13,uVar15);
    uVar6 = (uint)(piVar2 + 1) & 3;
    uVar8 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    uVar6 = (short)((ushort)((ushort)((uVar8 >> uVar6 * 8) >> 0x10) |
                            (ushort)((uVar8 << uVar6 * -8 + 0x20) >> 0x10)) >> 4) * 0x2000;
    uVar14 = (uVar6 + 0x800 >> 0xc | (uint)(0xfffff7ff < uVar6) << 0x14) - 0x1000;
    lVar1 = (ulonglong)uRam02089488 * (ulonglong)uVar14;
    uVar4 = (uint)lVar1;
    uVar6 = param_1 + 0x74U & 3;
    uVar8 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    iVar11 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
             (uVar4 + 0x800 >> 0xc |
             (((int)uVar14 >> 0x1f) * uRam02089488 + (int)((ulonglong)lVar1 >> 0x20) +
             (uint)(0xfffff7ff < uVar4)) * 0x100000);
    iVar3 = AbsValue(iVar11);
    iVar12 = iVar11;
    if ((iRam0208948c < iVar3) && (iVar12 = iRam0208948c, iVar11 < 1)) {
      iVar12 = iRam02089490;
    }
    *(int *)(param_1 + 0x74) = iVar12;
  }
  uVar6 = param_1 + 0x28U & 3;
  uVar14 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar8 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar6 = (uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) + 0x24;
  uVar14 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar14 * 8 | uVar6 << uVar14 * -8 + 0x20) + 0x800;
  uVar6 = param_1 + 0x60U & 3;
  uVar8 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar14 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * (longlong)(int)uVar14;
  *(uint *)(param_1 + 0x60) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 100U & 3;
  uVar8 = *(uint *)(param_1 + 100U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * (longlong)(int)uVar14;
  *(uint *)(param_1 + 100) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar6 = param_1 + 0x68U & 3;
  uVar8 = *(uint *)(param_1 + 0x68U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * (longlong)(int)uVar14;
  *(uint *)(param_1 + 0x68) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  return;
}

