/* Decompiled C draft; module arm9; ROM address 0209b388. No matching claim. */
#include "types.h"
#include "deps/0209b388_func_0209b388.h"

void func_0209b388(int param_1,int param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_28 [2];
  uint local_20;
  uint uVar12;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    piVar3 = (int *)func_020d22d0();
    uVar2 = (uint)(piVar3 + 2) & 3;
    uVar5 = *(uint *)((uint)(piVar3 + 2) & 0xfffffffc);
    uVar8 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
            *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
    uVar2 = (uint)(piVar3 + 1) & 3;
    uVar6 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar7 * (ulonglong)uVar8;
    uVar10 = (uint)lVar1;
    uVar5 = (uint)(piVar3 + 3) & 3;
    uVar9 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
    uVar4 = (uint)(piVar3 + 4) & 3;
    uVar11 = *(uint *)((uint)(piVar3 + 4) & 0xfffffffc);
    uVar12 = uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20;
    uVar4 = (uint)(piVar3 + 5) & 3;
    uVar11 = *(uint *)((uint)(piVar3 + 5) & 0xfffffffc);
    *piVar3 = uVar12 + uVar10;
    piVar3[1] = (uVar11 >> uVar4 * 8 | uVar11 << uVar4 * -8 + 0x20) +
                (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) * uVar7 +
                uVar8 * (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar12,uVar10);
    uVar2 = (uint)(piVar3 + 1) & 3;
    uVar5 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
    uVar2 = (uint)*(short *)(iRam0209b5ec +
                            (((int)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) >> 0x10) >> 4)
                             * 2 + 1) * 2);
    lVar1 = (ulonglong)uVar2 * 0x1800;
    uVar2 = (uint)lVar1 >> 0xc |
            (((int)uVar2 >> 0x1f) * 0x1800 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    *(uint *)(param_1 + 0x10) = uVar2;
    *(uint *)(param_1 + 0x18) = uVar2;
    piVar3 = (int *)func_020d22d0();
    uVar2 = (uint)(piVar3 + 2) & 3;
    uVar5 = *(uint *)((uint)(piVar3 + 2) & 0xfffffffc);
    uVar12 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
            *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20;
    uVar2 = (uint)(piVar3 + 1) & 3;
    uVar6 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar7 * (ulonglong)uVar12;
    uVar11 = (uint)lVar1;
    uVar5 = (uint)(piVar3 + 3) & 3;
    uVar10 = *(uint *)((uint)(piVar3 + 3) & 0xfffffffc);
    uVar4 = (uint)(piVar3 + 4) & 3;
    uVar8 = *(uint *)((uint)(piVar3 + 4) & 0xfffffffc);
    uVar9 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
    uVar4 = (uint)(piVar3 + 5) & 3;
    uVar8 = *(uint *)((uint)(piVar3 + 5) & 0xfffffffc);
    *piVar3 = uVar9 + uVar11;
    piVar3[1] = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
                (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) * uVar7 +
                uVar12 * (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar9,uVar11);
    uVar2 = (uint)(piVar3 + 1) & 3;
    uVar5 = *(uint *)((uint)(piVar3 + 1) & 0xfffffffc);
    if ((int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) < 0) {
      *(short *)(param_1 + 0xa0) = (short)uRam0209b5e4;
    }
    else {
      *(short *)(param_1 + 0xa0) = (short)uRam0209b5e8;
    }
  }
  else {
    VecFx32_Subtract(param_1 + 4,param_2,local_28);
    uVar2 = param_3 + 8 & 3;
    uVar5 = *(uint *)(param_3 + 8 & 0xfffffffc);
    uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    uVar2 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
            *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
    if ((int)((int)((ulonglong)((longlong)(int)local_20 * (longlong)(int)uVar2) >> 0x20) -
             ((int)((ulonglong)((longlong)(int)local_28[0] * (longlong)(int)uVar5) >> 0x20) +
             (uint)((uint)((longlong)(int)local_20 * (longlong)(int)uVar2) <
                   (uint)((longlong)(int)local_28[0] * (longlong)(int)uVar5)))) < 0) {
      *(short *)(param_1 + 0xa0) = (short)uRam0209b5e4;
      local_28[0] = uVar5;
      local_20 = -uVar2;
    }
    else {
      local_28[0] = -uVar5;
      *(short *)(param_1 + 0xa0) = (short)uRam0209b5e8;
      local_20 = uVar2;
    }
    *(uint *)(param_1 + 0x10) =
         (uint)((ulonglong)local_28[0] * 0x1800) >> 0xc |
         (((int)local_28[0] >> 0x1f) * 0x1800 + (int)((ulonglong)local_28[0] * 0x1800 >> 0x20)) *
         0x100000;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(uint *)(param_1 + 0x18) =
         (uint)((ulonglong)local_20 * 0x1800) >> 0xc |
         (((int)local_20 >> 0x1f) * 0x1800 + (int)((ulonglong)local_20 * 0x1800 >> 0x20)) * 0x100000
    ;
  }
  if (param_4 != 0) {
    uVar2 = param_1 + 0x10U & 3;
    uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    *(uint *)(param_1 + 0x10) =
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) +
         (int)(*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
              *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20) / 2;
    uVar2 = param_4 + 8 & 3;
    uVar4 = *(uint *)(param_4 + 8 & 0xfffffffc);
    uVar5 = param_1 + 0x18U & 3;
    uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    *(uint *)(param_1 + 0x18) =
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
         (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) / 2;
  }
  *(undefined4 *)(param_1 + 0x14) = 0x4000;
  *(undefined4 *)(param_1 + 0xa4) = 300;
  *(undefined4 *)(param_1 + 0x114) = 2;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam0209b5f0;
  return;
}

