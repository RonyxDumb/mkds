/* Decompiled C draft; module arm9; ROM address 0207729c. No matching claim. */
#include "types.h"
#include "deps/0207729c_StructHD_SomeFn.h"

void StructHD_SomeFn(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined2 uVar13;
  
  param_1[9] = uRam020775ac;
  uVar7 = uRam020775b4;
  param_1[10] = uRam020775b0;
  puVar2 = puRam020775b8;
  param_1[0xb] = uVar7;
  uVar7 = puVar2[1];
  uVar9 = puVar2[2];
  param_1[6] = *puVar2;
  param_1[7] = uVar7;
  param_1[8] = uVar9;
  uVar9 = *puRam020775bc;
  uVar8 = puRam020775bc[1];
  uVar10 = puRam020775bc[2];
  uVar7 = puRam020775bc[1];
  uVar11 = puRam020775bc[2];
  *param_1 = *puRam020775bc;
  param_1[1] = uVar7;
  param_1[2] = uVar11;
  uVar7 = puRam020775c0[1];
  uVar11 = puRam020775c0[2];
  param_1[3] = *puRam020775c0;
  param_1[4] = uVar7;
  param_1[5] = uVar11;
  Matrix4x3_Identity(param_1 + 0xc);
  uVar7 = puRam020775c4[1];
  uVar11 = puRam020775c4[2];
  param_1[0x57] = *puRam020775c4;
  param_1[0x58] = uVar7;
  param_1[0x59] = uVar11;
  param_1[0x5a] = 0;
  uVar7 = uRam020775d0;
  iVar3 = iRam020775cc;
  uVar1 = *puRam020775c8;
  param_1[0x19] = (uint)uVar1;
  param_1[0x18] = uVar1 + 5;
  uVar5 = uRam020775d4;
  uVar6 = (uint)(param_1 + 0x18) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0x18) & 0xfffffffc);
  *(undefined2 *)(param_1 + 0x1a) =
       *(undefined2 *)
        (iVar3 + ((int)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0xffff) >> 4) * 4);
  uVar6 = (uint)(param_1 + 0x18) & 3;
  uVar4 = *(uint *)((uint)(param_1 + 0x18) & 0xfffffffc);
  *(undefined2 *)((int)param_1 + 0x6a) =
       *(undefined2 *)
        (iVar3 + (((int)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0xffff) >> 4) * 2 + 1)
                 * 2);
  param_1[0x1b] = uVar7;
  param_1[0x1c] = 0x400;
  param_1[0x23] = 0x640000;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x18;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x24;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  param_1[0x1d] = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar6 = (uint)(param_1 + 0x1d) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 0x1d) & 0xfffffffc);
  uVar13 = 0xffff;
  if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 0x1000) {
    param_1[0x1d] = 0x640000;
  }
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  puVar2 = puRam020775b8;
  param_1[0x21] = 0;
  uVar7 = *puVar2;
  uVar11 = puVar2[1];
  uVar12 = puVar2[2];
  param_1[0x27] = uVar7;
  param_1[0x28] = uVar11;
  param_1[0x29] = uVar12;
  param_1[0x24] = uVar7;
  param_1[0x25] = uVar11;
  param_1[0x26] = uVar12;
  param_1[0x30] = uVar9;
  param_1[0x31] = uVar8;
  param_1[0x32] = uVar10;
  uVar5 = uRam020775d8;
  param_1[0x33] = 0;
  uVar4 = uRam020775dc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  param_1[0x35] = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  param_1[0x36] = 1;
  uVar6 = uVar4 & 3;
  uVar5 = *(uint *)(uVar4 & 0xfffffffc);
  param_1[0x37] = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = (uint)(param_1 + 0x37) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 0x37) & 0xfffffffc);
  param_1[0x38] = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  param_1[0x39] = 0;
  param_1[0x3a] = 0x1000;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0x1000;
  param_1[0x3d] = uVar7;
  param_1[0x3e] = uVar11;
  param_1[0x3f] = uVar12;
  param_1[0x40] = uVar7;
  param_1[0x41] = uVar11;
  param_1[0x42] = uVar12;
  param_1[0x43] = uVar7;
  param_1[0x44] = uVar11;
  param_1[0x45] = uVar12;
  param_1[0x46] = uVar7;
  param_1[0x47] = uVar11;
  param_1[0x48] = uVar12;
  *(undefined1 *)(param_1 + 0x4c) = 0;
  param_1[0x49] = uVar7;
  param_1[0x4a] = uVar11;
  param_1[0x4b] = uVar12;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x53] = 0;
  *(undefined2 *)(param_1 + 0x54) = 1;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x52] = 0;
  *(undefined2 *)(param_1 + 0x84) = 0;
  param_1[0x85] = 0xffffffff;
  *(undefined2 *)(param_1 + 0x8f) = 0;
  param_1[0x8a] = 0;
  *(undefined2 *)(param_1 + 0x8b) = 0;
  param_1[0x8c] = 0;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x62] = uVar7;
  param_1[99] = uVar11;
  param_1[100] = uVar12;
  param_1[0x5f] = uVar7;
  param_1[0x60] = uVar11;
  param_1[0x61] = uVar12;
  param_1[0x95] = 3;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = uVar7;
  param_1[0x99] = uVar11;
  param_1[0x9a] = uVar12;
  param_1[0x2a] = uVar7;
  param_1[0x2b] = uVar11;
  param_1[0x2c] = uVar12;
  param_1[0x2d] = uVar7;
  param_1[0x2e] = uVar11;
  param_1[0x2f] = uVar12;
  if (*(char *)((*(uint *)(uRam020775e0 & 0xfffffffc) >> (uRam020775e0 & 3) * 8 |
                *(uint *)(uRam020775e0 & 0xfffffffc) << (uRam020775e0 & 3) * -8 + 0x20) + 0x57) ==
      '\0') {
    uVar13 = 1;
  }
  *(undefined2 *)(param_1 + 0x9b) = uVar13;
  param_1[0x87] = 0;
  param_1[0x88] = 0;
  *(undefined2 *)(param_1 + 0x83) = 0;
  *(undefined2 *)((int)param_1 + 0x20e) = 0;
  *(undefined2 *)(param_1 + 0x89) = 0;
  param_1[0x22] = 0x1000;
  return;
}

