/* Decompiled C draft; module arm9; ROM address 02127db8. No matching claim. */
#include "types.h"
#include "deps/02127db8_func_02127db8.h"

void func_02127db8(void)

{
  int *piVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int local_18;
  uint local_14;
  
  uVar2 = uRam02127e2c;
  piVar1 = piRam02127e28;
  local_18 = 0;
  pbVar6 = pbRam02127e24;
  do {
    sVar3 = 0xe;
    if (*(int *)(*piVar1 + 0x18) != local_18) {
      sVar3 = 0xf;
    }
    local_14 = (uint)pbVar6[2];
    if (local_14 <= pbVar6[3]) {
      iVar5 = local_14 << 5;
      do {
        uVar7 = (uint)*pbVar6;
        if (uVar7 <= pbVar6[1]) {
          do {
            iVar4 = *piVar1 + (uVar7 + iVar5) * 2;
            *(ushort *)(iVar4 + 0x2c) = (*(ushort *)(iVar4 + 0x2c) & (ushort)uVar2) + sVar3 * 0x1000
            ;
            uVar7 = uVar7 + 1;
          } while ((int)uVar7 <= (int)(uint)pbVar6[1]);
        }
        iVar5 = iVar5 + 0x20;
        local_14 = local_14 + 1;
      } while ((int)local_14 <= (int)(uint)pbVar6[3]);
    }
    pbVar6 = pbVar6 + 4;
    local_18 = local_18 + 1;
  } while (local_18 < 2);
  return;
}

