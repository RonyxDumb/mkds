/* Decompiled C draft; module arm7; ROM address 03804bbc. No matching claim. */
#include "types.h"
#include "deps/03804bbc_FUN_03804bbc.h"

void FUN_03804bbc(undefined4 param_1,int param_2,int param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  ushort local_10 [4];
  
  if (param_2 != 0) {
    local_10[0] = (ushort)((uint)param_1 >> 0x10) & 0xff;
    local_10[1] = (ushort)((uint)param_1 >> 8) & 0xff;
    local_10[2] = (ushort)param_1 & 0xff;
    do {
    } while ((*DAT_03804cd4 & 0x80) != 0);
    *DAT_03804cd4 = 0x8900;
    puVar3 = DAT_03804cd8;
    *DAT_03804cd8 = 3;
    puVar1 = DAT_03804cd4;
    iVar6 = 0;
    do {
      do {
      } while ((*puVar1 & 0x80) != 0);
      *puVar3 = local_10[iVar6] & 0xff;
      puVar4 = DAT_03804cd8;
      puVar2 = DAT_03804cd4;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    do {
    } while ((*DAT_03804cd4 & 0x80) != 0);
    for (uVar5 = 0; puVar1 = DAT_03804cd4, uVar5 < param_2 - 1U; uVar5 = uVar5 + 1) {
      *puVar4 = 0;
      do {
      } while ((*puVar2 & 0x80) != 0);
      *(char *)(param_3 + uVar5) = (char)*puVar4;
    }
    *DAT_03804cd4 = 0x8100;
    *DAT_03804cd8 = 0;
    do {
    } while ((*puVar1 & 0x80) != 0);
    *(char *)(param_3 + uVar5) = (char)*DAT_03804cd8;
  }
  return;
}

