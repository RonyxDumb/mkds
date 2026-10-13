/* Decompiled C draft; module arm9; ROM address 020d1de8. No matching claim. */
#include "types.h"
#include "deps/020d1de8_func_020d1de8.h"

void func_020d1de8(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 local_64 [21];
  uint uVar13;
  
  uVar12 = uRam020d1fd0;
  puVar14 = local_64;
  iVar11 = 5;
  puVar15 = puRam020d1fcc;
  do {
    uVar4 = *puVar15;
    uVar6 = puVar15[1];
    uVar7 = puVar15[2];
    uVar8 = puVar15[3];
    puVar15 = puVar15 + 4;
    *puVar14 = uVar4;
    puVar14[1] = uVar6;
    puVar14[2] = uVar7;
    puVar14[3] = uVar8;
    puVar14 = puVar14 + 4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  if (param_2 < 0) {
    *(undefined4 *)
     ((*(uint *)(uRam020d1fd0 & 0xfffffffc) >> (uRam020d1fd0 & 3) * 8 |
      *(uint *)(uRam020d1fd0 & 0xfffffffc) << (uRam020d1fd0 & 3) * -8 + 0x20) + 0x24) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x18) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x1c) = 0;
    *(undefined2 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x20) = 0;
    return;
  }
  if (param_2 < 0x14) {
    uVar4 = local_64[param_2];
    func_020b4cec((uint *)(uintptr_t)((*(uint *)(uRam020d1fd0 & 0xfffffffc) >> (uRam020d1fd0 & 3) * 8 |
                  *(uint *)(uRam020d1fd0 & 0xfffffffc) << (uRam020d1fd0 & 3) * -8 + 0x20) + 8),uVar4)
    ;
    uVar12 = uRam020d1fd0;
    *(undefined4 *)
     ((*(uint *)(uRam020d1fd0 & 0xfffffffc) >> (uRam020d1fd0 & 3) * 8 |
      *(uint *)(uRam020d1fd0 & 0xfffffffc) << (uRam020d1fd0 & 3) * -8 + 0x20) + 0x24) = 0;
    uVar9 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
            *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
    *(uint *)(uVar9 + 0x18) = uVar9 + 8;
    *(undefined4 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x1c) = uVar4;
    uVar3 = func_020ae5c4(param_1);
    uVar2 = uRam020d1fd0;
    *(undefined2 *)
     ((*(uint *)(uRam020d1fd0 & 0xfffffffc) >> (uRam020d1fd0 & 3) * 8 |
      *(uint *)(uRam020d1fd0 & 0xfffffffc) << (uRam020d1fd0 & 3) * -8 + 0x20) + 0x20) = uVar3;
    uVar5 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    uVar12 = uVar5 + 0x18;
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar13 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
    param_1 = param_1 + (uint)*(ushort *)(uVar5 + 0x20) * 0x20;
    *(short *)(param_1 + 6) =
         (short)((int)(*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                      *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) >> 4);
    uVar12 = uVar13 + 4 & 3;
    uVar9 = *(uint *)(uVar13 + 4 & 0xfffffffc);
    *(short *)(param_1 + 0xe) =
         (short)((int)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) >> 4);
    uVar12 = uVar13 + 8 & 3;
    uVar9 = *(uint *)(uVar13 + 8 & 0xfffffffc);
    *(short *)(param_1 + 0x16) =
         (short)((int)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) >> 4);
    uVar12 = uVar13 + 0xc & 3;
    uVar9 = *(uint *)(uVar13 + 0xc & 0xfffffffc);
    *(short *)(param_1 + 0x1e) =
         (short)((int)(uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) >> 4);
    uVar9 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    uVar12 = uVar9 + 0x1c;
    uVar5 = uVar12 & 3;
    uVar13 = *(uint *)(uVar12 & 0xfffffffc);
    uVar9 = uVar9 + 0x18;
    uVar12 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)((uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) + 0xc) =
         uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20;
    uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18;
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    puVar10 = (uint *)(uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20);
    puVar1 = puVar10 + 3;
    uVar12 = (uint)puVar1 & 3;
    uVar9 = *(uint *)((uint)puVar1 & 0xfffffffc);
    *puVar10 = uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20;
    uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18;
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    *(undefined4 *)((uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) + 8) = 0;
    uVar12 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18;
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar5 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
    uVar12 = uVar5 + 8;
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    *(uint *)(uVar5 + 4) = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
    return;
  }
  if (param_2 < 0x78) {
    *(undefined4 *)
     ((*(uint *)(uRam020d1fd0 & 0xfffffffc) >> (uRam020d1fd0 & 3) * 8 |
      *(uint *)(uRam020d1fd0 & 0xfffffffc) << (uRam020d1fd0 & 3) * -8 + 0x20) + 0x24) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x18) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x1c) = 0x1000;
    *(undefined2 *)
     ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
      *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x20) = 0;
    return;
  }
  uVar4 = ComputeValueInterpolation_from_thumb(1,0,0x80,param_2 + -0x78,0x14);
  uVar12 = uRam020d1fd0;
  *(undefined4 *)
   ((*(uint *)(uRam020d1fd0 & 0xfffffffc) >> (uRam020d1fd0 & 3) * 8 |
    *(uint *)(uRam020d1fd0 & 0xfffffffc) << (uRam020d1fd0 & 3) * -8 + 0x20) + 0x24) = uVar4;
  *(undefined4 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x18) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x1c) = 0x1000;
  *(undefined2 *)
   ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
    *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x20) = 0;
  return;
}

