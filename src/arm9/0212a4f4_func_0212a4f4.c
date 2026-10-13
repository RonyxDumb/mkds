/* Decompiled C draft; module arm9; ROM address 0212a4f4. No matching claim. */
#include "types.h"
#include "deps/0212a4f4_func_0212a4f4.h"

void func_0212a4f4(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  piVar1 = piRam0212a5f0;
  iVar5 = 0;
  local_30 = 0;
  local_2c = iRam0212a5e8;
  local_28 = 0;
  local_24 = iRam0212a5ec;
  iVar3 = 0;
  do {
    iVar8 = 0;
    iVar4 = local_2c;
    do {
      iVar7 = 0;
      do {
        *(undefined4 *)(*(int *)(iVar5 + *piVar1 + 0x74) + (uint)*(byte *)(iVar4 + iVar7) * 0x40) =
             0;
        iVar7 = iVar7 + 1;
      } while (iVar7 < 3);
      iVar7 = *piVar1;
      *(undefined4 *)
       (*(int *)(iVar5 + iVar7 + 0x74) +
       ((uint)*(byte *)(local_24 + iVar8) + (uint)*(ushort *)(*(int *)(local_28 + iVar7 + 0x9c) + 6)
       ) * 0x40) = 0;
      iVar4 = iVar4 + 3;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    iVar5 = iVar5 + 8;
    local_2c = local_2c + 6;
    local_28 = local_28 + 4;
    local_24 = local_24 + 2;
    local_30 = local_30 + 1;
  } while (local_30 < 2);
  iVar4 = 0;
  pbVar6 = pbRam0212a5f8;
  iVar5 = iRam0212a5f4;
  do {
    iVar8 = 0;
    if (*pbVar6 != 0) {
      do {
        *(undefined4 *)
         (*(int *)(iVar4 + *piRam0212a5f0 + 0x74) + (uint)*(byte *)(iVar5 + iVar8) * 0x40) = 0;
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)(uint)*pbVar6);
    }
    piVar1 = piRam0212a5f0;
    iVar4 = iVar4 + 8;
    iVar5 = iVar5 + 0xc;
    pbVar6 = pbVar6 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  iVar8 = 0;
  iVar4 = 0;
  iVar5 = 0;
  iVar3 = iRam0212a5fc;
  do {
    iVar7 = 0;
    do {
      *(undefined4 *)(*(int *)(iVar4 + *piVar1 + 0x74) + (uint)*(byte *)(iVar3 + iVar7) * 0x40) = 0;
      piVar2 = piRam0212a5f0;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 4);
    iVar4 = iVar4 + 8;
    iVar3 = iVar3 + 4;
    iVar8 = iVar8 + 1;
    pbVar6 = pbRam0212a600;
  } while (iVar8 < 2);
  do {
    *(undefined4 *)(*(int *)(*piVar2 + 0x7c) + (uint)*pbVar6 * 0x40) = 0;
    iVar5 = iVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (iVar5 < 10);
  return;
}

