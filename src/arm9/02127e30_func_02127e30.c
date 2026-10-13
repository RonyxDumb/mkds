/* Decompiled C draft; module arm9; ROM address 02127e30. No matching claim. */
#include "types.h"
#include "deps/02127e30_func_02127e30.h"

void func_02127e30(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  byte *pbVar9;
  short sVar10;
  int iVar11;
  int local_30;
  int local_18;
  
  local_30 = 0;
  bVar1 = pbRam02127ef8[1];
  bVar2 = *pbRam02127ef8;
  bVar3 = pbRam02127ef8[3];
  bVar4 = pbRam02127ef8[2];
  pbVar9 = pbRam02127ef4;
  do {
    bVar5 = false;
    if ((local_30 == *(int *)(*piRam02127efc + 0x18)) && (*(int *)(*piRam02127efc + 0x14) != 0)) {
      bVar5 = true;
    }
    local_18 = 0;
    if (-1 < (int)((uint)bVar3 - (uint)bVar4)) {
      sVar8 = 0;
      do {
        iVar11 = 0;
        if (-1 < (int)((uint)bVar1 - (uint)bVar2)) {
          do {
            iVar7 = iVar11 + (uint)*pbVar9 + (local_18 + (uint)pbVar9[1]) * 0x20;
            iVar6 = *piRam02127efc;
            sVar10 = (short)*(undefined4 *)(iVar6 + iRam02127f00);
            if (bVar5) {
              sVar10 = (short)*(undefined4 *)(iVar6 + iRam02127f04);
            }
            sVar10 = sVar8 + sVar10 + (short)iVar11;
            if (bVar5) {
              iVar6 = iVar6 + iVar7 * 2;
              *(ushort *)(iVar6 + 0x2c) =
                   sVar10 + (*(ushort *)(iVar6 + 0x2c) & (ushort)uRam02127f08) + (short)uRam02127f0c
              ;
            }
            else {
              iVar6 = iVar6 + iVar7 * 2;
              *(ushort *)(iVar6 + 0x2c) =
                   sVar10 + (*(ushort *)(iVar6 + 0x2c) & (ushort)uRam02127f10);
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 <= (int)((uint)bVar1 - (uint)bVar2));
        }
        sVar8 = sVar8 + 0x20;
        local_18 = local_18 + 1;
      } while (local_18 <= (int)((uint)bVar3 - (uint)bVar4));
    }
    pbVar9 = pbVar9 + 2;
    local_30 = local_30 + 1;
  } while (local_30 < 2);
  return;
}

