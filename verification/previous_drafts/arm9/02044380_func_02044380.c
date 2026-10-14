/* Decompiled C draft; module arm9; ROM address 02044380. No matching claim. */
#include "types.h"
#include "deps/02044380_func_02044380.h"

void func_02044380(undefined2 *param_1,undefined1 param_2,undefined1 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint uVar9;
  undefined2 *puVar8;
  
  uVar9 = *(uint *)(uRam02044518 & 0xfffffffc) >> (uRam02044518 & 3) * 8 |
          *(uint *)(uRam02044518 & 0xfffffffc) << (uRam02044518 & 3) * -8 + 0x20;
  puVar6 = (undefined2 *)(uVar9 + 0x210);
  iVar5 = 0xb;
  puVar7 = param_1;
  do {
    puVar8 = puVar7 + 1;
    uVar1 = *puVar7;
    puVar7 = puVar7 + 2;
    uVar2 = *puVar8;
    iVar5 = iVar5 + -1;
    puVar8 = puVar6 + 1;
    *puVar6 = uVar1;
    puVar6 = puVar6 + 2;
    *puVar8 = uVar2;
    uVar3 = uRam02044518;
  } while (iVar5 != 0);
  *(undefined1 *)(uVar9 + 0x23c) = param_2;
  *(undefined1 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x23d) = param_3;
  uVar9 = uRam02044518;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1f0) = 4;
  *(uint *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1e8) =
       (uint)*(byte *)(param_1 + 4);
  *(bool *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x23f) =
       (param_1[0xe] & 0x10) != 0;
  *(undefined1 *)
   ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x240) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x204) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x208) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x200) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x3d8) = 0;
  *(uint *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x1f8) =
       (uint)*(byte *)((int)param_1 + 9);
  StructCO_ConfigureRacerDefault
            (0,*(undefined1 *)(param_1 + 5),*(undefined1 *)((int)param_1 + 0xb),0,0xffffffff,3);
  if ((*(char *)(param_1 + 0xf) == -1) || (*(char *)((int)param_1 + 0x1f) == -1)) {
    StructCO_ConfigureRacerDefault(1,0xffffffff,0xffffffff,4,0xffffffff,3);
    *(undefined4 *)
     ((*(uint *)(uRam02044518 & 0xfffffffc) >> (uRam02044518 & 3) * 8 |
      *(uint *)(uRam02044518 & 0xfffffffc) << (uRam02044518 & 3) * -8 + 0x20) + 0x1fc) = 0;
  }
  else {
    StructCO_ConfigureRacerDefault();
    *(undefined4 *)
     ((*(uint *)(uRam02044518 & 0xfffffffc) >> (uRam02044518 & 3) * 8 |
      *(uint *)(uRam02044518 & 0xfffffffc) << (uRam02044518 & 3) * -8 + 0x20) + 0x1fc) = 2;
  }
  bVar4 = 2;
  do {
    StructCO_ConfigureRacerDefault(bVar4,0xffffffff,0xffffffff,4,0xffffffff,3);
    bVar4 = bVar4 + 1;
  } while (bVar4 < 8);
  return;
}

