/* Decompiled C draft; module arm9_ov000; ROM address 0219914c. No matching claim. */
#include "types.h"
#include "deps/0219914c_FUN_0219914c.h"

undefined4 FUN_0219914c(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_600 [2];
  ushort local_5fe;
  undefined4 local_5fc;
  undefined4 local_5f8;
  undefined1 auStack_5f4 [1504];
  
  iVar2 = FUN_0218e668(*param_1);
  uVar1 = DAT_02199224;
  do {
    if (iVar2 == 0) {
      return 1;
    }
    local_5f8 = 8;
    iVar2 = FUN_0218e438(*param_1,auStack_5f4,DAT_02199228,0,auStack_600,&local_5f8);
    if (iVar2 == -1) {
      iVar2 = FUN_0218e368(*param_1);
      if (iVar2 == -0xf) {
        iVar2 = FUN_0219922c(param_1,local_5fc,
                             (int)(uint)local_5fe >> 8 | (uint)local_5fe << 8 & uVar1 & 0xffff);
        if (iVar2 == 0) {
          return 0;
        }
      }
      else if (iVar2 != -0x23) {
        FUN_0219a044(param_1);
        return 0;
      }
    }
    else {
      iVar2 = FUN_021992d4(param_1,auStack_5f4,iVar2,local_5fc,
                           (int)(uint)local_5fe >> 8 | (uint)local_5fe << 8 & uVar1 & 0xffff);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = FUN_0218e668(*param_1);
  } while( true );
}

