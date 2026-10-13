/* Decompiled C draft; module arm9; ROM address 020c4780. No matching claim. */
#include "types.h"
#include "deps/020c4780_func_020c4780.h"

void func_020c4780(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  
  uVar3 = (*(uint *)(uRam020c49f0 & 0xfffffffc) >> (uRam020c49f0 & 3) * 8 |
          *(uint *)(uRam020c49f0 & 0xfffffffc) << (uRam020c49f0 & 3) * -8 + 0x20) + 8;
  uVar11 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) == 1) {
    GetActiveExecutionContext();
    uVar4 = ExecutionContext_GetHeapHandle();
    puVar5 = (undefined4 *)Mem_AllocateHeap(uVar4,0x910);
    puVar1 = puRam020c49f4;
    *puRam020c49f4 = puVar5;
    uVar3 = uRam020c49f0;
    *puVar5 = 1;
    iVar10 = 0;
    if (*(char *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
      do {
        uVar11 = (uint)puVar1 & 3;
        uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
        *(undefined4 *)((uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) + iVar10 * 4 + 4) = 1;
        iVar10 = iVar10 + 1;
      } while (iVar10 < (int)(uint)*(byte *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                                             *(uint *)(uVar3 & 0xfffffffc) <<
                                             (uVar3 & 3) * -8 + 0x20) + 0x3d0));
    }
    puVar1 = puRam020c49f4;
    uVar11 = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puRam020c49f4 & 0xfffffffc) >> ((uint)puRam020c49f4 & 3) * 8 |
      *(uint *)((uint)puRam020c49f4 & 0xfffffffc) << ((uint)puRam020c49f4 & 3) * -8 + 0x20) + 0xc) =
         0;
    uVar3 = (uint)*(byte *)((*(uint *)(uRam020c49f0 & 0xfffffffc) >> (uRam020c49f0 & 3) * 8 |
                            *(uint *)(uRam020c49f0 & 0xfffffffc) << (uRam020c49f0 & 3) * -8 + 0x20)
                           + 0x3d0);
    if (uVar3 != 0) {
      iVar10 = 0;
      iStack_48 = 0;
      do {
        uVar2 = func_020b6338(uVar11);
        GetDriverVec354(&uStack_40,uVar11 & 0xff);
        iVar14 = iStack_48;
        iVar15 = iStack_48;
        do {
          iVar15 = iVar15 + 1;
          iVar13 = iVar10 + (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20)
                   + iVar14;
          *(undefined4 *)(iVar13 + 0x10) = uStack_40;
          *(undefined4 *)(iVar13 + 0x14) = uStack_3c;
          *(undefined4 *)(iVar13 + 0x18) = uStack_38;
          *(undefined2 *)(iVar13 + 0x1c) = uVar2;
          *(undefined4 *)
           (iVar14 + iVar10 + (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                              *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20
                              ) + 0x20) = 0;
          *(undefined4 *)
           (iVar14 + iVar10 + (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                              *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20
                              ) + 0x24) = 3;
          iVar14 = iVar14 + 0x18;
        } while (iVar15 < 0x28);
        uVar11 = uVar11 + 1;
        iVar10 = iVar10 + 0x3c0;
        uVar3 = (uint)*(byte *)((*(uint *)(uRam020c49f0 & 0xfffffffc) >> (uRam020c49f0 & 3) * 8 |
                                *(uint *)(uRam020c49f0 & 0xfffffffc) <<
                                (uRam020c49f0 & 3) * -8 + 0x20) + 0x3d0);
      } while ((int)uVar11 < (int)uVar3);
    }
    iVar10 = iRam020c49fc;
    puVar1 = puRam020c49f4;
    iVar14 = 0;
    if (uVar3 != 0) {
      uVar4 = *puRam020c49f8;
      uVar7 = puRam020c49f8[1];
      uVar8 = puRam020c49f8[2];
      do {
        iVar13 = 0;
        *(undefined4 *)
         ((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar14 * 0x40 +
         0x790) = 0;
        iVar15 = iVar13;
        do {
          iVar9 = iVar14 * 0x40 +
                  (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                  *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20);
          puVar5 = (undefined4 *)(iVar15 + iVar9 + iVar10);
          *puVar5 = uVar4;
          puVar5[1] = uVar7;
          puVar5[2] = uVar8;
          *(undefined4 *)(iVar9 + iVar13 * 4 + 0x7c4) = 0xffffffff;
          iVar15 = iVar15 + 0xc;
          iVar9 = iVar13 * 4;
          iVar13 = iVar13 + 1;
          *(undefined4 *)
           (iVar14 * 0x40 +
            (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
            *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar9 + 0x7b8)
               = 3;
        } while (iVar13 < 3);
        iVar14 = iVar14 + 1;
      } while (iVar14 < (int)(uint)*(byte *)((*(uint *)(uRam020c49f0 & 0xfffffffc) >>
                                              (uRam020c49f0 & 3) * 8 |
                                             *(uint *)(uRam020c49f0 & 0xfffffffc) <<
                                             (uRam020c49f0 & 3) * -8 + 0x20) + 0x3d0));
    }
    iVar10 = iRam020c4a00;
    puVar1 = puRam020c49f4;
    iVar14 = 0;
    iVar15 = 0;
    do {
      iVar13 = (int)((iVar15 + ((uint)(iVar15 >> 3) >> 0x1c)) * 0x1000 >> 0x10) >> 4;
      iVar12 = (int)*(short *)(iVar10 + iVar13 * 4);
      iVar9 = (int)*(short *)(iVar10 + (iVar13 * 2 + 1) * 2);
      *(int *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
               *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
               iVar14 * 0x10 + 0x810) = iVar9;
      iVar15 = iVar15 + 0x10000;
      *(int *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
               *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
               iVar14 * 0x10 + 0x814) = iVar12;
      *(int *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
               *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) +
               iVar14 * 0x10 + 0x818) = -iVar12;
      iVar13 = iVar14 * 0x10;
      iVar14 = iVar14 + 1;
      *(int *)((*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
               *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) + iVar13 +
              0x81c) = iVar9;
    } while (iVar14 < 0x10);
    return;
  }
  return;
}

