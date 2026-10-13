/* Decompiled C draft; module arm9; ROM address 020846c0. No matching claim. */
#include "types.h"
#include "deps/020846c0_func_020846c0.h"

void func_020846c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  
  uVar11 = (uint)*(byte *)((*(uint *)(uRam020848c0 & 0xfffffffc) >> (uRam020848c0 & 3) * 8 |
                           *(uint *)(uRam020848c0 & 0xfffffffc) << (uRam020848c0 & 3) * -8 + 0x20) +
                          0x3d0);
  uVar8 = Mem_AllocateHeap(param_1,uVar11 << 1);
  *puRam020848c4 = uVar8;
  uVar8 = Mem_AllocateHeap(param_1,uVar11 * 0xc);
  *puRam020848c8 = uVar8;
  uVar8 = Mem_AllocateHeap(param_1,uVar11 << 2);
  *puRam020848cc = uVar8;
  uVar8 = Mem_AllocateHeap(param_1,uVar11 << 2);
  puVar5 = puRam020848d0;
  *puRam020848d0 = uVar8;
  puVar4 = puRam020848cc;
  puVar3 = puRam020848c8;
  puVar2 = puRam020848c4;
  uVar9 = uRam020848c0;
  uVar14 = 0;
  if (uVar11 != 0) {
    do {
      uVar13 = 0;
      do {
        uVar12 = (uint)puVar3 & 3;
        uVar15 = *(uint *)((uint)puVar3 & 0xfffffffc);
        *(undefined4 *)
         (uVar14 * 0xc + (uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20) + uVar13 * 4) = 0;
        uVar13 = uVar13 + 1 & 0xffff;
      } while (uVar13 < 3);
      uVar13 = (uint)puVar4 & 3;
      uVar12 = *(uint *)((uint)puVar4 & 0xfffffffc);
      *(undefined4 *)((uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + uVar14 * 4) = 0;
      uVar13 = (uint)puVar5 & 3;
      uVar12 = *(uint *)((uint)puVar5 & 0xfffffffc);
      *(undefined4 *)((uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + uVar14 * 4) = 0;
      uVar13 = uVar9 & 3;
      uVar12 = *(uint *)(uVar9 & 0xfffffffc);
      if (uVar14 == (int)*(char *)((uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + 0x62)) {
        *(undefined2 *)
         ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar14 * 2) = 0;
      }
      else {
        *(undefined2 *)
         ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + uVar14 * 2) = 1;
      }
      uVar14 = uVar14 + 1 & 0xffff;
    } while (uVar14 < uVar11);
  }
  puVar6 = puRam020848d8;
  uVar9 = *(uint *)(uRam020848c0 & 0xfffffffc) >> (uRam020848c0 & 3) * 8 |
          *(uint *)(uRam020848c0 & 0xfffffffc) << (uRam020848c0 & 3) * -8 + 0x20;
  *puRam020848d8 = (short)uRam020848d4;
  uVar14 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar14 = uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20;
  if ((int)uVar14 < 0x13) {
    if (uVar14 != 0x12) goto LAB_02084840;
  }
  else {
    if ((0x20 < (int)uVar14) || ((int)uVar14 < 0x1a)) goto LAB_02084840;
    if (uVar14 == 0x1a) {
      *puVar6 = (short)uRam020848e4;
      goto LAB_02084840;
    }
    if (uVar14 == 0x1c) {
      *puVar6 = (short)uRam020848e0;
      goto LAB_02084840;
    }
    if (uVar14 != 0x20) goto LAB_02084840;
  }
  *puRam020848d8 = (short)uRam020848dc;
LAB_02084840:
  puVar2 = puRam020848f0;
  piVar7 = piRam020848ec;
  uVar9 = *(uint *)(uRam020848c0 & 0xfffffffc) >> (uRam020848c0 & 3) * 8 |
          *(uint *)(uRam020848c0 & 0xfffffffc) << (uRam020848c0 & 3) * -8 + 0x20;
  *piRam020848e8 = (int)(*(byte *)(uVar9 + 0x3d0) - 1) / 2;
  iVar10 = *(byte *)(uVar9 + 0x3d0) - 1;
  iVar1 = iVar10 >> 0x1f;
  *piVar7 = ((uint)(iVar10 * -0x80000000 + iVar1) >> 0x1f | iVar1 << 1) - iVar1;
  *puVar2 = 0x1000;
  uVar14 = uVar9 + 0x10 & 3;
  uVar9 = *(uint *)(uVar9 + 0x10 & 0xfffffffc);
  uVar14 = uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20;
  if (uVar14 != 0) {
    if (uVar14 == 1) {
      *puVar2 = uRam020848f4;
    }
    return;
  }
  *puVar2 = uRam020848f8;
  return;
}

