/* Decompiled C draft; module arm9; ROM address 02062a0c. No matching claim. */
#include "types.h"
#include "deps/02062a0c_CreateGlobalTD.h"

void CreateGlobalTD(void)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined2 *puVar9;
  undefined4 uVar10;
  int iVar11;
  bool bVar12;
  
  puVar3 = puRam02062b48;
  uVar7 = uRam02062b44;
  *(undefined4 *)
   ((*(uint *)(uRam02062b44 & 0xfffffffc) >> (uRam02062b44 & 3) * 8 |
    *(uint *)(uRam02062b44 & 0xfffffffc) << (uRam02062b44 & 3) * -8 + 0x20) + 4) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 8) = 0;
  uVar6 = uRam02062b4c;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x14) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0xc) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x18) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1c) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x30) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x34) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x3c) = 0;
  uVar8 = puVar3[1];
  uVar10 = puVar3[2];
  iVar11 = 1;
  *(short *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x40) = (short)*puVar3;
  *(short *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x42) = (short)uVar8;
  *(short *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
             *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x44) = (short)uVar10;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0xc;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)((*(uint *)(uRam02062b44 & 0xfffffffc) >> (uRam02062b44 & 3) * 8 |
            *(uint *)(uRam02062b44 & 0xfffffffc) << (uRam02062b44 & 3) * -8 + 0x20) + 0x28) =
       (uint)((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) - 3 < 3);
  uVar4 = uRam02062b4c;
  uVar7 = (*(uint *)(uRam02062b4c & 0xfffffffc) >> (uRam02062b4c & 3) * 8 |
          *(uint *)(uRam02062b4c & 0xfffffffc) << (uRam02062b4c & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)((*(uint *)(uRam02062b44 & 0xfffffffc) >> (uRam02062b44 & 3) * 8 |
            *(uint *)(uRam02062b44 & 0xfffffffc) << (uRam02062b44 & 3) * -8 + 0x20) + 0x2c) =
       (uint)((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) == 4);
  uVar2 = uRam02062b44;
  uVar7 = uVar4 & 3;
  uVar6 = *(uint *)(uVar4 & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0xc;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if ((uVar7 != 5) && (uVar7 != 6)) {
    iVar11 = 0;
  }
  bVar12 = iVar11 != 0;
  if (bVar12) {
    iVar11 = 1;
  }
  if (!bVar12) {
    iVar11 = 0;
  }
  *(int *)((*(uint *)(uRam02062b44 & 0xfffffffc) >> (uRam02062b44 & 3) * 8 |
           *(uint *)(uRam02062b44 & 0xfffffffc) << (uRam02062b44 & 3) * -8 + 0x20) + 0x38) = iVar11;
  uVar7 = uVar2 & 3;
  uVar6 = *(uint *)(uVar2 & 0xfffffffc);
  puVar9 = (undefined2 *)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
  puVar1 = puVar9 + 0x1c;
  uVar7 = (uint)puVar1 & 3;
  uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  bVar12 = uVar7 != 0;
  if (bVar12) {
    uVar7 = 1;
  }
  uVar5 = (undefined2)uVar7;
  if (!bVar12) {
    uVar5 = 0;
  }
  *puVar9 = uVar5;
  return;
}

