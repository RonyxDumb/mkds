/* Decompiled C draft; module arm9_ov001; ROM address 0218c63c. No matching claim. */
#include "types.h"
#include "deps/0218c63c_FUN_0218c63c.h"

void FUN_0218c63c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0xa0);
  iVar3 = *(int *)(iVar4 + 0xc);
  iVar5 = *(int *)(iVar4 + 8);
  uVar1 = func_0x02133068(iVar5,0x14);
  uVar2 = func_0x02133068(iVar3,0x14);
  FUN_021886f8(param_1,iVar5 * 3,uVar1,iVar3 * 3,*(int *)(iVar4 + DAT_0218c69c) * 3,uVar2);
  FUN_0218883c(param_1,0,0,0,DAT_0218c6a0);
  *(undefined4 *)(param_1 + DAT_0218c6a8) = DAT_0218c6a4;
  *(undefined4 *)(param_1 + DAT_0218c6b0) = DAT_0218c6ac;
  return;
}

