/* Decompiled C draft; module arm9_ov000; ROM address 0218c468. No matching claim. */
#include "types.h"
#include "deps/0218c468_FUN_0218c468.h"

undefined4 FUN_0218c468(undefined4 param_1,byte *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 local_20 [2];
  undefined4 local_1c [2];
  
  if (param_3 < 1) {
    return 0;
  }
  uVar1 = (uint)*param_2;
  iVar2 = FUN_0218c8ac();
  if (param_3 < iVar2) {
    return 0;
  }
  if (((uVar1 & 0x40) != 0) &&
     (iVar3 = FUN_0218c794(param_1,param_2 + iVar2,param_3 - iVar2), iVar3 == 0)) {
    return 0;
  }
  uVar1 = uVar1 & 0x80;
  if ((uVar1 != 0) && (iVar2 = FUN_0218c84c(param_2 + iVar2,param_3 - iVar2), iVar2 == 0)) {
    return 0;
  }
  iVar2 = func_0x02134d30(param_2 + 1,DAT_0218c54c,4);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  FUN_0218c744(param_1,param_2,param_3,local_1c,local_20,uVar1);
  uVar4 = FUN_0218af28(param_1,local_1c[0],local_20[0]);
  iVar2 = FUN_0218aefc();
  if (iVar2 != 0) {
    return 0xfffffffe;
  }
  uVar5 = FUN_0218c550(param_1,uVar4,param_2,param_3,1);
  FUN_0218d340(param_1,uVar4);
  return uVar5;
}

