/* Decompiled C draft; module arm9_ov000; ROM address 021a4940. No matching claim. */
#include "types.h"
#include "deps/021a4940_FUN_021a4940.h"

void FUN_021a4940(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_20 [8];
  undefined4 local_18;
  
  local_18 = 8;
  if ((param_1[0x31] != 0) && (iVar2 = FUN_0218e668(*param_1), iVar1 = DAT_021a499c, iVar2 != 0)) {
    do {
      iVar2 = FUN_0218e438(*param_1,iVar1,0xff,0,auStack_20,&local_18);
      if (iVar2 != -1) {
        *(undefined1 *)(iVar1 + iVar2) = 0;
        FUN_021a3c14(param_1,iVar1,iVar2,auStack_20);
      }
      iVar2 = FUN_0218e668(*param_1);
    } while (iVar2 != 0);
  }
  return;
}

