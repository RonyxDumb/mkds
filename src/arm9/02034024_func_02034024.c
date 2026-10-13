/* Decompiled C draft; module arm9; ROM address 02034024. No matching claim. */
#include "types.h"
#include "deps/02034024_func_02034024.h"

void func_02034024(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_94;
  int local_90;
  int local_88;
  int local_7c;
  int local_74;
  int local_70 [8];
  uint local_50 [8];
  uint local_30 [8];
  
  iVar9 = 0;
  local_74 = 0;
  iVar8 = 0;
  iVar6 = 0;
  iVar3 = *piRam02034180;
  if (0 < *(int *)(iVar3 + 0xd8)) {
    piVar1 = local_70;
    iVar4 = iVar3;
    do {
      *piVar1 = *(int *)(iVar4 + 0xe8);
      piVar1 = piVar1 + 1;
      iVar4 = iVar4 + 0xc;
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar3 + 0xd8));
  }
  uVar2 = 0;
  iVar3 = *piRam02034180;
  if (0 < *(int *)(iVar3 + 0xd8)) {
    puVar5 = local_50;
    puVar7 = local_30;
    iVar6 = *piRam02034184;
    do {
      if (*(int *)(iVar6 + (uVar2 & 0xffff) * 0x30 + 0x74) == 0) {
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
        iVar9 = iVar9 + 1;
      }
      else {
        *puVar7 = uVar2;
        puVar7 = puVar7 + 1;
        iVar8 = iVar8 + 1;
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < *(int *)(iVar3 + 0xd8));
  }
  local_90 = 0;
  if (0 < iVar9) {
    iVar3 = -1;
    local_88 = 0;
    do {
      iVar6 = iVar3;
      if (0 < iVar9) {
        puVar5 = local_50;
        iVar4 = iVar3;
        iVar10 = local_88;
        do {
          if (iVar4 < local_70[*puVar5]) {
            iVar4 = local_70[*puVar5];
            iVar6 = iVar10;
          }
          puVar5 = puVar5 + 1;
          iVar10 = iVar10 + 1;
        } while (iVar10 < iVar9);
      }
      *(int *)(*piRam02034180 + local_50[iVar6] * 0xc + 0xec) = local_74;
      local_74 = local_74 + 1;
      local_70[local_50[iVar6]] = -2;
      local_90 = local_90 + 1;
    } while (local_90 < iVar9);
  }
  if ((local_74 < 4) && (iVar8 < 5)) {
    local_74 = 4;
  }
  local_94 = 0;
  if (0 < iVar8) {
    iVar3 = -1;
    local_7c = 0;
    do {
      iVar6 = iVar3;
      if (0 < iVar8) {
        puVar5 = local_30;
        iVar9 = local_7c;
        iVar4 = iVar3;
        do {
          if (iVar4 < local_70[*puVar5]) {
            iVar6 = iVar9;
            iVar4 = local_70[*puVar5];
          }
          puVar5 = puVar5 + 1;
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar8);
      }
      *(int *)(*piRam02034180 + local_30[iVar6] * 0xc + 0xec) = local_74;
      local_74 = local_74 + 1;
      local_70[local_30[iVar6]] = -2;
      local_94 = local_94 + 1;
    } while (local_94 < iVar8);
  }
  return;
}

