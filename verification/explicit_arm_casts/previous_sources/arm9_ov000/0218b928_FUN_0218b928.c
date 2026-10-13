/* Decompiled C draft; module arm9_ov000; ROM address 0218b928. No matching claim. */
#include "types.h"
#include "deps/0218b928_FUN_0218b928.h"

undefined4 FUN_0218b928(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_600 [2];
  undefined2 local_5fe;
  undefined4 local_5fc;
  undefined4 local_5f8;
  undefined1 auStack_5f4 [1504];
  
  local_5f8 = 8;
  iVar1 = FUN_0218e668(*(undefined4 *)((int)param_1 + DAT_0218b9f4));
  do {
    if (iVar1 == 0) {
      iVar1 = FUN_0218e8c4();
      if (DAT_0218ba00 < (uint)(iVar1 - *(int *)((int)param_1 + DAT_0218b9fc))) {
        FUN_0218e53c(*(undefined4 *)((int)param_1 + DAT_0218b9f4));
        *(undefined4 *)((int)param_1 + DAT_0218b9f4) = 0xffffffff;
        *param_1 = 1;
        (**(code **)((int)param_1 + DAT_0218ba0c))
                  (param_1,3,*DAT_0218ba04,*(undefined4 *)((int)param_1 + DAT_0218ba08));
      }
      return 0;
    }
    iVar1 = FUN_0218e438(*(undefined4 *)((int)param_1 + DAT_0218b9f4),auStack_5f4,DAT_0218b9f8,0,
                         auStack_600,&local_5f8);
    if ((iVar1 != -1) && (iVar1 = FUN_0218d2a8(param_1,local_5fc,local_5fe), iVar1 == -1)) {
      uVar2 = FUN_0218af28(param_1,local_5fc,local_5fe);
      iVar1 = FUN_0218aefc();
      if (iVar1 != 0) {
        return 5;
      }
      FUN_0218af24(uVar2,0x11);
      FUN_0218d340(param_1,uVar2);
    }
    iVar1 = FUN_0218e668(*(undefined4 *)((int)param_1 + DAT_0218b9f4));
  } while( true );
}

