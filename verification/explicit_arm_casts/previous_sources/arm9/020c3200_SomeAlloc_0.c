/* Decompiled C draft; module arm9; ROM address 020c3200. No matching claim. */
#include "types.h"
#include "deps/020c3200_SomeAlloc_0.h"

void SomeAlloc_0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int local_48 [9];
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,uRam020c3624);
  puVar1 = puRam020c3628;
  uVar7 = 0;
  *puRam020c3628 = uVar2;
  uVar10 = 0;
  do {
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar7 * 4) = 1;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar7 * 4 + 0x20) =
         0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + uVar7 * 4 + 0x40) =
         0;
    iVar4 = uVar7 * 4;
    uVar7 = uVar7 + 1 & 0xffff;
    *(undefined4 *)
     ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
      *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar4 + 0x80) = 1;
    uVar2 = uRam020c362c;
  } while (uVar7 < 8);
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xa4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xa8) = 0;
  uVar7 = uRam020c3630;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xac) = uVar2;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xb0) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xb4) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0xa0) = 0xffffff00;
  uVar8 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  uVar9 = (uint)*(byte *)(uVar8 + 0x3d0);
  if (uVar9 != 0) {
    do {
      uVar9 = uVar8 + 0x1c & 3;
      uVar3 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
      if (((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) == 1) ||
         (uVar9 = uVar8 + 8 & 3, uVar3 = *(uint *)(uVar8 + 8 & 0xfffffffc),
         (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) == 2)) {
        uVar8 = uVar10 * 0x30 + uVar8 + 0x70;
        uVar9 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
        bVar6 = 0;
        if ((uVar8 < 4) && ((1 << (uVar8 & 0xff) & 0xdU) != 0)) {
          bVar6 = 1;
        }
        iVar4 = func_0205d360(uVar10);
        uVar8 = *(uint *)(uVar7 & 0xfffffffc);
        local_48[uVar10] = iVar4 * 0x10 + (uint)bVar6 * 8;
        uVar8 = (uVar8 >> (uVar7 & 3) * 8 | uVar8 << (uVar7 & 3) * -8 + 0x20) + 8;
        uVar9 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
        if ((uVar8 == 3) || (uVar8 == 5)) {
          iVar4 = func_0205d27c(uVar10);
          local_48[uVar10] = local_48[uVar10] + (8 - iVar4);
        }
        else {
          local_48[uVar10] = local_48[uVar10] + (8 - uVar10);
        }
        uVar2 = func_0205d360(uVar10);
        *(undefined4 *)
         ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
          *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
          uVar10 * 4 + 0x20) = uVar2;
      }
      else {
        uVar8 = uVar10 * 0x30 + uVar8 + 0x70;
        uVar9 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar8 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
        bVar6 = 0;
        if ((uVar8 < 4) && ((1 << (uVar8 & 0xff) & 0xdU) != 0)) {
          bVar6 = 1;
        }
        iVar4 = func_0205d3f0(uVar10);
        iVar5 = func_0205d27c(uVar10);
        local_48[uVar10] = (iVar4 * 0x10 + (uint)bVar6 * 8 + 8) - iVar5;
        uVar2 = func_0205d3f0(uVar10);
        *(undefined4 *)
         ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
          *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
          uVar10 * 4 + 0x20) = uVar2;
      }
      uVar8 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
      uVar9 = (uint)*(byte *)(uVar8 + 0x3d0);
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < uVar9);
  }
  uVar10 = uRam020c3630;
  puVar1 = puRam020c3628;
  uVar7 = 0;
  if (uVar9 != 0) {
    do {
      uVar8 = (uint)puVar1 & 3;
      uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
      *(uint *)((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) + uVar7 * 4 + 0x40) = uVar7;
      local_48[uVar7] = -local_48[uVar7];
      uVar8 = uVar10 & 3;
      uVar9 = *(uint *)(uVar10 & 0xfffffffc);
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(byte *)((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) + 0x3d0));
  }
  func_020ae770((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
                *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20
                ) + 0x40,local_48);
  uVar10 = uRam020c3630;
  puVar1 = puRam020c3628;
  uVar7 = 0;
  if (*(char *)((*(uint *)(uRam020c3630 & 0xfffffffc) >> (uRam020c3630 & 3) * 8 |
                *(uint *)(uRam020c3630 & 0xfffffffc) << (uRam020c3630 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      uVar8 = (uint)puVar1 & 3;
      uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
      iVar4 = (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) + uVar7 * 4;
      uVar8 = iVar4 + 0x40;
      uVar9 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)(iVar4 + 0x60) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      uVar8 = uVar10 & 3;
      uVar9 = *(uint *)(uVar10 & 0xfffffffc);
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(byte *)((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) + 0x3d0));
  }
  uVar2 = uRam020c3634;
  puVar1 = puRam020c3628;
  *(undefined4 *)
   ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
    *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) + 0x20d8)
       = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x20dc) = 0;
  *(undefined4 *)
   ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
    *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + 0x20e0) = 0xffffffe0;
  uVar2 = func_020b47c0(uVar2);
  Gfx_ReadPalette((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
                  *(uint *)((uint)puRam020c3628 & 0xfffffffc) <<
                  ((uint)puRam020c3628 & 3) * -8 + 0x20) + 0xb8,uVar2);
  uVar2 = func_020b47c0(uRam020c3638);
  Gfx_ReadCharGraphicsV2
            ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
             *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
             0xbc,uVar2);
  uVar2 = func_020b47c0(uRam020c363c);
  MaybeReadScreenBlock_0
            ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
             *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
             0xc0,uVar2);
  uVar2 = func_020b47c0(uRam020c3640);
  MaybeReadScreenBlock_0
            ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
             *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
             0xc4,uVar2);
  uVar2 = func_020b47c0(uRam020c3644);
  MaybeReadScreenBlock_0
            ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
             *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
             200,uVar2);
  uVar2 = func_020b47c0(uRam020c3648);
  MaybeReadScreenBlock_0
            ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
             *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
             0xcc,uVar2);
  uVar2 = func_020b47c0(uRam020c364c);
  MaybeReadScreenBlock_0
            ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
             *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
             0xd0,uVar2);
  uVar2 = func_020b47c0(uRam020c3650);
  MaybeReadScreenBlock_0
            ((*(uint *)((uint)puRam020c3628 & 0xfffffffc) >> ((uint)puRam020c3628 & 3) * 8 |
             *(uint *)((uint)puRam020c3628 & 0xfffffffc) << ((uint)puRam020c3628 & 3) * -8 + 0x20) +
             0xd4,uVar2);
  puVar1 = puRam020c3628;
  uVar7 = 0;
  do {
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
    uVar10 = uVar9 + 0xc4;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    *(undefined2 *)(uVar9 + uVar7 * 2 + 0xd8) =
         *(undefined2 *)((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + uVar7 * 2 + 0xc);
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
    uVar10 = uVar9 + 200;
    uVar8 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    iVar4 = uVar7 * 2;
    iVar5 = uVar7 * 2;
    uVar7 = uVar7 + 1 & 0xffff;
    *(undefined2 *)(uVar9 + iVar4 + 0x10d8) =
         *(undefined2 *)((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + iVar5 + 0xc);
  } while (uVar7 < 0x800);
  return;
}

