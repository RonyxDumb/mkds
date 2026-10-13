/* Decompiled C draft; module arm9_ov000; ROM address 0218c8e0. No matching claim. */
#include "types.h"
#include "deps/0218c8e0_FUN_0218c8e0.h"

void FUN_0218c8e0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int iVar2;
  
  uVar1 = func_0x0213a434(param_1 + 0x54);
  iVar2 = 0;
  if (0 < param_3) {
    do {
      func_0x02133068(iVar2,uVar1);
      func_0x02133068(*(char *)(param_1 + 0x54 + extraout_r1) * iVar2,8);
      func_0x02133068(iVar2,8);
      *(byte *)(param_1 + extraout_r1_00 + 0x74) =
           *(byte *)(param_1 + extraout_r1_00 + 0x74) ^
           *(byte *)(param_1 + extraout_r1_01 + 0x74) ^ *(byte *)(param_2 + iVar2);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  FUN_0218a7bc(param_1 + DAT_0218c954,param_1 + 0x74,8);
  return;
}

