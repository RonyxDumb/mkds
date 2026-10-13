/* Decompiled C draft; module arm9_ov000; ROM address 021a998c. No matching claim. */
#include "types.h"
#include "deps/021a998c_FUN_021a998c.h"

void FUN_021a998c(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  puVar1 = (undefined1 *)(*(code *)*DAT_021a9a80)(0x83);
  if (puVar1 == (undefined1 *)0x0) {
    *(undefined1 *)(iVar2 + DAT_021a9a84) = 9;
    return;
  }
  *puVar1 = 0x14;
  puVar1[1] = 3;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 1;
  puVar1[5] = 1;
  func_0x0214d168(iVar2 + DAT_021a9a88,0,8);
  puVar1[6] = 0x16;
  puVar1[7] = 3;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0x28;
  puVar1[0xb] = 0x14;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0x24;
  func_0x0214d1fc(iVar2 + DAT_021a9a8c,iVar2 + DAT_021a9a90,0x58);
  FUN_021aa50c(iVar2,puVar1 + 0xf,0);
  func_0x0214d1fc(iVar2 + DAT_021a9a90,iVar2 + DAT_021a9a8c,0x58);
  func_0x0214d1fc(iVar2 + DAT_021a9a94,iVar2 + DAT_021a9a98,0x5c);
  FUN_021aa468(iVar2,puVar1 + 0x1f,0);
  func_0x0214d1fc(iVar2 + DAT_021a9a98,iVar2 + DAT_021a9a94,0x5c);
  FUN_021abca0(iVar2 + DAT_021a9a94,puVar1 + 0xb,0x28);
  FUN_021ab728(iVar2 + DAT_021a9a8c,puVar1 + 0xb,0x28);
  iVar2 = FUN_021aa054(iVar2,puVar1 + 6);
  FUN_021adcec(puVar1,iVar2 + 6,0,0,param_1);
  (*(code *)*DAT_021a9a9c)(puVar1);
  return;
}

