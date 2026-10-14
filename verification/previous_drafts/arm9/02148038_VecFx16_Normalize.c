/* Decompiled C draft; module arm9; ROM address 02148038. No matching claim. */
#include "types.h"
#include "deps/02148038_VecFx16_Normalize.h"

void VecFx16_Normalize(short *param_1,undefined2 *param_2)

{
  ulonglong uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  ushort *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  puVar2 = puRam02148174;
  uVar11 = (int)*param_1 * (int)*param_1;
  uVar9 = (int)param_1[1] * (int)param_1[1];
  uVar8 = (int)param_1[2] * (int)param_1[2];
  *puRam02148170 = 2;
  *puVar2 = 0;
  puVar3 = puRam02148178;
  uVar10 = uVar11 + uVar9 + uVar8;
  uVar8 = ((int)uVar11 >> 0x1f) + ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar11,uVar9) +
          ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar11 + uVar9,uVar8);
  puVar2[1] = 0x1000000;
  *puVar3 = uVar10;
  puVar4 = puRam0214817c;
  puVar3[1] = uVar8;
  piVar5 = piRam02148180;
  *puVar4 = 1;
  *piVar5 = uVar10 * 4;
  piVar5[1] = uVar8 * 4 | uVar10 >> 0x1e;
  do {
  } while ((*puVar4 & 0x8000) != 0);
  uVar8 = *(uint *)(uRam02148184 & 0xfffffffc) >> (uRam02148184 & 3) * 8 |
          *(uint *)(uRam02148184 & 0xfffffffc) << (uRam02148184 & 3) * -8 + 0x20;
  do {
  } while ((*puRam02148170 & 0x8000) != 0);
  uVar10 = (uint)*param_1;
  uVar11 = *(uint *)(uRam02148188 & 0xfffffffc) >> (uRam02148188 & 3) * 8 |
           *(uint *)(uRam02148188 & 0xfffffffc) << (uRam02148188 & 3) * -8 + 0x20;
  uVar1 = (ulonglong)uVar8 * (ulonglong)uVar11;
  iVar7 = (int)uVar1;
  uVar9 = uRam02148188 + 4 & 3;
  uVar12 = *(uint *)(uRam02148188 + 4 & 0xfffffffc);
  iVar6 = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) * uVar8 +
          uVar11 * ((int)uVar8 >> 0x1f) + (int)(uVar1 >> 0x20);
  *param_2 = (short)((int)(iVar6 * uVar10 +
                           iVar7 * ((int)uVar10 >> 0x1f) +
                           (int)((ulonglong)uVar10 * (uVar1 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd)
  ;
  uVar8 = (uint)param_1[1];
  param_2[1] = (short)((int)(iVar6 * uVar8 +
                             iVar7 * ((int)uVar8 >> 0x1f) +
                             (int)((ulonglong)uVar8 * (uVar1 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd
                      );
  uVar8 = (uint)param_1[2];
  param_2[2] = (short)((int)(iVar6 * uVar8 +
                             iVar7 * ((int)uVar8 >> 0x1f) +
                             (int)((ulonglong)uVar8 * (uVar1 & 0xffffffff) >> 0x20) + 0x1000) >> 0xd
                      );
  return;
}

