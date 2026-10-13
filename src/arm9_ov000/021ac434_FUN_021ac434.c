/* Decompiled C draft; module arm9_ov000; ROM address 021ac434. No matching claim. */
#include "types.h"
#include "deps/021ac434_FUN_021ac434.h"

void FUN_021ac434(undefined1 *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  iVar3 = DAT_021ac484;
  do {
    param_1[iVar2 + 2] = (char)iVar2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < iVar3);
  uVar4 = 0;
  uVar5 = 0;
  iVar3 = 0;
  do {
    bVar1 = param_1[iVar3 + 2];
    uVar5 = uVar5 + (uint)bVar1 + (uint)*(byte *)(param_2 + uVar4) & 0xff;
    param_1[iVar3 + 2] = param_1[uVar5 + 2];
    param_1[uVar5 + 2] = bVar1;
    uVar4 = uVar4 + 1 & 0xff;
    if (param_3 <= (int)uVar4) {
      uVar4 = 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < DAT_021ac484);
  return;
}

