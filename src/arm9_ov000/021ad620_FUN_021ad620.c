/* Decompiled C draft; module arm9_ov000; ROM address 021ad620. No matching claim. */
#include "types.h"
#include "deps/021ad620_FUN_021ad620.h"

undefined4 FUN_021ad620(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 local_10;
  
  iVar1 = DAT_021ad6b0;
  puVar3 = (undefined1 *)FUN_021ad754((undefined2 *)(uintptr_t)(DAT_021ad6b0),3,&local_10);
  if (param_1 == 0) {
    *puVar3 = 0x32;
    puVar3[1] = 4;
    puVar2 = DAT_021ad6b4;
    puVar3[2] = (char)((uint)*DAT_021ad6b4 >> 0x18);
    puVar3[3] = (char)((uint)*puVar2 >> 0x10);
    puVar3[4] = (char)((uint)*puVar2 >> 8);
    puVar3[5] = (char)*puVar2;
    puVar3[6] = 0x36;
    puVar3[7] = 4;
    puVar2 = DAT_021ad6b8;
    puVar3[8] = (char)((uint)*DAT_021ad6b8 >> 0x18);
    puVar3[9] = (char)((uint)*puVar2 >> 0x10);
    puVar3[10] = (char)((uint)*puVar2 >> 8);
    puVar3[0xb] = (char)*puVar2;
    puVar3 = puVar3 + 0xc;
  }
  *puVar3 = 0xff;
  iVar4 = FUN_021ad734(0,DAT_021ad6bc,(int)(uintptr_t)(puVar3 + 1),(int)(puVar3 + 1) - iVar1);
  FUN_021adbf4(iVar1,iVar4 - iVar1);
  return local_10;
}

