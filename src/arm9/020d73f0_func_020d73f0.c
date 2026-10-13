/* Decompiled C draft; module arm9; ROM address 020d73f0. No matching claim. */
#include "types.h"
#include "deps/020d73f0_func_020d73f0.h"

void func_020d73f0(int *param_1,int *param_2)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  ushort *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar12;
  uint uVar11;
  uint uVar13;
  
  puVar2 = puRam020d7584;
  uVar13 = (uint)(param_1 + 1) & 3;
  uVar10 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar11 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
  uVar10 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar13 = (uint)(param_1 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar8 = uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20;
  uVar13 = (uint)(param_1 + 3) & 3;
  uVar12 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
  uVar10 = uVar13 * uVar13 + uVar8 * uVar8 + uVar10 * uVar10 + uVar11 * uVar11;
  uVar13 = (int)uVar10 >> 0x1f;
  if ((0 < (int)(uVar13 + (uRam020d7578 < uVar10)) !=
       SBORROW4(-uVar13,(uint)(uRam020d7578 < uVar10))) &&
     ((int)uVar13 < (int)(uint)(uVar10 < uRam020d757c))) {
    iVar6 = param_1[1];
    iVar7 = param_1[2];
    iVar9 = param_1[3];
    *param_2 = *param_1;
    param_2[1] = iVar6;
    param_2[2] = iVar7;
    param_2[3] = iVar9;
    return;
  }
  *puRam020d7580 = 2;
  *puVar2 = 0;
  puVar3 = puRam020d7588;
  puVar2[1] = 0x1000000;
  *puVar3 = uVar10;
  puVar4 = puRam020d758c;
  puVar3[1] = uVar13;
  piVar5 = piRam020d7590;
  *puVar4 = 1;
  *piVar5 = uVar10 * 4;
  piVar5[1] = uVar13 << 2 | uVar10 >> 0x1e;
  do {
  } while ((*puVar4 & 0x8000) != 0);
  uVar13 = *(uint *)(uRam020d7594 & 0xfffffffc) >> (uRam020d7594 & 3) * 8 |
           *(uint *)(uRam020d7594 & 0xfffffffc) << (uRam020d7594 & 3) * -8 + 0x20;
  do {
  } while ((*puRam020d7580 & 0x8000) != 0);
  uVar8 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar11 = *(uint *)(uRam020d7598 & 0xfffffffc) >> (uRam020d7598 & 3) * 8 |
           *(uint *)(uRam020d7598 & 0xfffffffc) << (uRam020d7598 & 3) * -8 + 0x20;
  uVar1 = (ulonglong)uVar13 * (ulonglong)uVar11;
  iVar7 = (int)uVar1;
  uVar10 = uRam020d7598 + 4 & 3;
  uVar12 = *(uint *)(uRam020d7598 + 4 & 0xfffffffc);
  iVar6 = (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) * uVar13 +
          uVar11 * ((int)uVar13 >> 0x1f) + (int)(uVar1 >> 0x20);
  *param_2 = (int)(iVar6 * uVar8 +
                   iVar7 * ((int)uVar8 >> 0x1f) +
                   (int)((ulonglong)uVar8 * (uVar1 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar13 = (uint)(param_1 + 1) & 3;
  uVar10 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
  param_2[1] = (int)(iVar6 * uVar13 +
                     iVar7 * ((int)uVar13 >> 0x1f) +
                     (int)((ulonglong)uVar13 * (uVar1 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar13 = (uint)(param_1 + 2) & 3;
  uVar10 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
  param_2[2] = (int)(iVar6 * uVar13 +
                     iVar7 * ((int)uVar13 >> 0x1f) +
                     (int)((ulonglong)uVar13 * (uVar1 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  uVar13 = (uint)(param_1 + 3) & 3;
  uVar10 = *(uint *)((uint)(param_1 + 3) & 0xfffffffc);
  uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
  param_2[3] = (int)(iVar6 * uVar13 +
                     iVar7 * ((int)uVar13 >> 0x1f) +
                     (int)((ulonglong)uVar13 * (uVar1 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd;
  return;
}

