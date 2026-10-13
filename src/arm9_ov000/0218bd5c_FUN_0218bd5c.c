/* Decompiled C draft; module arm9_ov000; ROM address 0218bd5c. No matching claim. */
#include "types.h"
#include "deps/0218bd5c_FUN_0218bd5c.h"

undefined4 FUN_0218bd5c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 local_20;
  undefined4 local_1c;
  
  if (param_3 < 5) {
    return 4;
  }
  FUN_0218c744();
  iVar1 = FUN_0218d2a8(param_1,local_1c,local_20);
  if (iVar1 == -1) {
    uVar2 = FUN_0218af28(param_1,local_1c,local_20);
    iVar3 = FUN_0218aefc();
    if (iVar3 != 0) {
      return 5;
    }
  }
  else {
    uVar2 = FUN_0218d218(param_1,iVar1);
  }
  iVar3 = FUN_0218c550(param_1,uVar2,(byte *)(uintptr_t)(param_2),param_3,0);
  if (iVar3 < 0) {
    return 4;
  }
  if (iVar1 == -1) {
    FUN_0218d340(param_1,uVar2);
  }
  (**(code **)(param_1 + DAT_0218be0c))(param_1,1,uVar2,*(undefined4 *)(param_1 + DAT_0218be08));
  return 0;
}

