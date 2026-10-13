/* Decompiled C draft; module arm9_ov000; ROM address 021ac3e4. No matching claim. */
#include "types.h"
#include "deps/021ac3e4_FUN_021ac3e4.h"

void FUN_021ac3e4(byte *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (uint)*param_1;
  uVar3 = (uint)param_1[1];
  iVar5 = 0;
  if (0 < param_3) {
    do {
      uVar4 = uVar4 + 1 & 0xff;
      bVar1 = param_1[uVar4 + 2];
      uVar3 = uVar3 + bVar1 & 0xff;
      bVar2 = param_1[uVar3 + 2];
      param_1[uVar4 + 2] = bVar2;
      param_1[uVar3 + 2] = bVar1;
      *(byte *)(param_2 + iVar5) =
           *(byte *)(param_2 + iVar5) ^ param_1[((uint)bVar1 + (uint)bVar2 & 0xff) + 2];
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_3);
  }
  *param_1 = (byte)uVar4;
  param_1[1] = (byte)uVar3;
  return;
}

