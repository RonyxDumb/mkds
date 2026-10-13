/* Decompiled C draft; module arm9_ov000; ROM address 021ad6c0. No matching claim. */
#include "types.h"
#include "deps/021ad6c0_FUN_021ad6c0.h"

undefined4 FUN_021ad6c0(void)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 local_10 [2];
  
  iVar1 = DAT_021ad728;
  puVar3 = (undefined1 *)FUN_021ad754(DAT_021ad728,1,local_10);
  piVar2 = DAT_021ad72c;
  if (*DAT_021ad72c != 0) {
    *puVar3 = 0x32;
    puVar3[1] = 4;
    puVar3[2] = (char)((uint)*piVar2 >> 0x18);
    puVar3[3] = (char)((uint)*piVar2 >> 0x10);
    puVar3[4] = (char)((uint)*piVar2 >> 8);
    puVar3[5] = (char)*piVar2;
    puVar3 = puVar3 + 6;
  }
  *puVar3 = 0xff;
  iVar4 = FUN_021ad734(0,DAT_021ad730,puVar3 + 1,(int)(puVar3 + 1) - iVar1);
  FUN_021adbf4(iVar1,iVar4 - iVar1);
  return local_10[0];
}

