/* Decompiled C draft; module arm9_ov000; ROM address 0218eff8. No matching claim. */
#include "types.h"
#include "deps/0218eff8_FUN_0218eff8.h"

undefined4
FUN_0218eff8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_218 [129];
  
  if (((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) || (param_2 == 0)) {
    return 2;
  }
  if (param_5 == (code *)0x0) {
    FUN_02196590(param_1,DAT_0218f098);
    return 2;
  }
  if (*(int *)(iVar2 + DAT_0218f09c) != 0) {
    puVar3 = local_218;
    iVar2 = 0x10;
    do {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      puVar3[7] = 0;
      puVar3 = puVar3 + 8;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    *puVar3 = 0;
    (*param_5)(param_1,local_218,param_6);
    return 0;
  }
  if (*(int *)(iVar2 + DAT_0218f0a0) == 4) {
    FUN_02196590(param_1,DAT_0218f0a4);
    return 2;
  }
  uVar1 = FUN_0219222c();
  return uVar1;
}

