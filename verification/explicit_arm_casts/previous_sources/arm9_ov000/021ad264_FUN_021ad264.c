/* Decompiled C draft; module arm9_ov000; ROM address 021ad264. No matching claim. */
#include "types.h"
#include "deps/021ad264_FUN_021ad264.h"

void FUN_021ad264(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  FUN_021ae270();
  FUN_021ae2d8();
  FUN_021ae290(0x44,0x43,*DAT_021ad2ac);
  iVar1 = DAT_021ad2b0;
  puVar2 = (undefined1 *)FUN_021ad754(DAT_021ad2b0,7,0);
  *puVar2 = 0xff;
  iVar3 = FUN_021ad734(0,DAT_021ad2b4,puVar2 + 1,(int)(puVar2 + 1) - iVar1);
  FUN_021adbf4(iVar1,iVar3 - iVar1);
  FUN_021ae258();
  return;
}

