/* Decompiled C draft; module arm7; ROM address 03804828. No matching claim. */
#include "types.h"
#include "deps/03804828_FUN_03804828.h"

void FUN_03804828(uint param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  ushort local_10 [4];
  
  if (param_2 != 0) {
    if (param_1 >> 8 < (param_1 + param_2) - 1 >> 8) {
      param_2 = 0x100 - (param_1 & 0xff) & 0xffff;
    }
    local_10[0] = (ushort)(param_1 >> 0x10) & 0xff;
    local_10[1] = (ushort)(param_1 >> 8) & 0xff;
    local_10[2] = (ushort)param_1 & 0xff;
    do {
    } while ((*DAT_0380494c & 0x80) != 0);
    *DAT_0380494c = 0x8900;
    puVar3 = DAT_03804950;
    *DAT_03804950 = 2;
    puVar1 = DAT_0380494c;
    iVar5 = 0;
    do {
      do {
      } while ((*puVar1 & 0x80) != 0);
      *puVar3 = local_10[iVar5] & 0xff;
      puVar4 = DAT_03804950;
      puVar2 = DAT_0380494c;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    for (iVar5 = 0; iVar5 < (int)(param_2 - 1); iVar5 = iVar5 + 1) {
      do {
      } while ((*puVar2 & 0x80) != 0);
      *puVar4 = (ushort)*(byte *)(param_3 + iVar5);
    }
    do {
    } while ((*DAT_0380494c & 0x80) != 0);
    *DAT_0380494c = 0x8100;
    *DAT_03804950 = (ushort)*(byte *)(param_3 + iVar5);
    do {
    } while ((*DAT_0380494c & 0x80) != 0);
  }
  return;
}

