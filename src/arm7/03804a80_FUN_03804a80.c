/* Decompiled C draft; module arm7; ROM address 03804a80. No matching claim. */
#include "types.h"
#include "deps/03804a80_FUN_03804a80.h"

void FUN_03804a80(undefined4 param_1,int param_2,int param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  ushort local_10 [4];
  
  if (param_2 != 0) {
    local_10[0] = (ushort)((uint)param_1 >> 0x10) & 0xff;
    local_10[1] = (ushort)((uint)param_1 >> 8) & 0xff;
    local_10[2] = (ushort)param_1 & 0xff;
    do {
    } while ((*DAT_03804bb4 & 0x80) != 0);
    *DAT_03804bb4 = 0x8900;
    puVar3 = DAT_03804bb8;
    *DAT_03804bb8 = 0xb;
    puVar1 = DAT_03804bb4;
    iVar5 = 0;
    do {
      do {
      } while ((*puVar1 & 0x80) != 0);
      *puVar3 = local_10[iVar5] & 0xff;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    do {
    } while ((*DAT_03804bb4 & 0x80) != 0);
    *DAT_03804bb8 = 0;
    puVar3 = DAT_03804bb8;
    puVar1 = DAT_03804bb4;
    do {
    } while ((*DAT_03804bb4 & 0x80) != 0);
    for (uVar4 = 0; puVar2 = DAT_03804bb4, uVar4 < param_2 - 1U; uVar4 = uVar4 + 1) {
      *puVar3 = 0;
      do {
      } while ((*puVar1 & 0x80) != 0);
      *(char *)(param_3 + uVar4) = (char)*puVar3;
    }
    *DAT_03804bb4 = 0x8100;
    *DAT_03804bb8 = 0;
    do {
    } while ((*puVar2 & 0x80) != 0);
    *(char *)(param_3 + uVar4) = (char)*DAT_03804bb8;
  }
  return;
}

