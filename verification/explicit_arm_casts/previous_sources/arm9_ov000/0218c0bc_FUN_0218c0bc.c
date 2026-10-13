/* Decompiled C draft; module arm9_ov000; ROM address 0218c0bc. No matching claim. */
#include "types.h"
#include "deps/0218c0bc_FUN_0218c0bc.h"

undefined4 FUN_0218c0bc(int param_1,byte *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_1c;
  uint local_18;
  
  uVar3 = (uint)*param_2;
  param_2 = param_2 + 1;
  param_3 = param_3 + -1;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0218c9d4();
  }
  uVar1 = FUN_0218dc94(8,uVar3,0);
  *(undefined4 *)(param_1 + 8) = uVar1;
  if (*(int *)(param_1 + 8) == 0) {
    return 5;
  }
  iVar4 = 0;
  if (uVar3 != 0) {
    do {
      if (param_3 < 2) {
        return 4;
      }
      iVar2 = FUN_0218d0c8(param_2 + 1,param_3 + -1);
      if (iVar2 == -1) {
        return 4;
      }
      local_18 = (uint)*param_2;
      local_1c = FUN_0218d134(param_1,param_2 + 1);
      FUN_0218dbc0(*(undefined4 *)(param_1 + 8),&local_1c);
      param_2 = param_2 + iVar2 + 1;
      param_3 = param_3 - (iVar2 + 1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)uVar3);
  }
  return 0;
}

