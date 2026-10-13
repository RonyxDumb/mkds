/* Decompiled C draft; module arm9_ov000; ROM address 0218d574. No matching claim. */
#include "types.h"
#include "deps/0218d574_FUN_0218d574.h"

undefined4 FUN_0218d574(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_58 [8];
  undefined4 local_50;
  uint local_4c;
  undefined1 auStack_48 [72];
  
  local_50 = 8;
  if (*DAT_0218d638 == -1) {
    *DAT_0218d63c = 1;
    return 1;
  }
  iVar1 = FUN_0218e668();
  if (iVar1 != 0) {
    uVar2 = FUN_0218e438(*DAT_0218d638,auStack_48,0x40,0,auStack_58,&local_50);
    iVar1 = FUN_0218d644(auStack_48,uVar2,auStack_58,&local_4c);
    if (iVar1 == 0) {
      FUN_0218e53c(*DAT_0218d638);
      if ((local_4c & 1) == 0) {
        if ((local_4c & 2) == 0) {
          *DAT_0218d63c = 1;
        }
        else {
          *DAT_0218d63c = 3;
        }
      }
      else {
        *DAT_0218d63c = 2;
      }
      return *DAT_0218d63c;
    }
  }
  uVar3 = FUN_0218e8c4();
  if ((uint)(DAT_0218d638[0x14] + DAT_0218d640) < uVar3) {
    if (DAT_0218d638[0x15] == 1) {
      FUN_0218e53c(*DAT_0218d638);
      *DAT_0218d63c = 1;
      return 1;
    }
    FUN_0218d788();
    DAT_0218d638[0x15] = DAT_0218d638[0x15] + 1;
  }
  return 0;
}

