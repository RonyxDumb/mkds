/* Decompiled C draft; module arm9_ov000; ROM address 0218b590. No matching claim. */
#include "types.h"
#include "deps/0218b590_FUN_0218b590.h"

void FUN_0218b590(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 local_118 [260];
  
  puVar4 = local_118;
  iVar3 = DAT_0218b63c;
  do {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0;
  *(undefined4 *)(param_1 + DAT_0218b640) = param_3;
  *(undefined4 *)(param_1 + 0x40) = 0;
  iVar5 = 0;
  if (0 < param_5) {
    do {
      uVar1 = *(undefined4 *)(DAT_0218b644 + (uint)*(byte *)(param_4 + iVar5) * 4);
      iVar2 = func_0x0213a434();
      if (DAT_0218b63c <= iVar3 + iVar2 + 1) break;
      iVar2 = func_0x02135014(local_118 + iVar3,DAT_0218b648,uVar1);
      iVar3 = iVar3 + iVar2;
      FUN_0218a93c(param_1,*(undefined1 *)(param_4 + iVar5));
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
  }
  iVar3 = FUN_0218ca58(param_1 + 0x4c,local_118,param_6,param_7,param_8);
  if ((iVar3 == 0) && (param_2 == 0)) {
    iVar3 = 0;
    while ((*(int *)(param_1 + 0x4c) == 3 || ((0 < *(int *)(param_1 + 0x10) && (iVar3 == 0))))) {
      thunk_EXT_FUN_0200dc3c(10);
      iVar3 = FUN_0218b4bc(param_1);
    }
  }
  return;
}

