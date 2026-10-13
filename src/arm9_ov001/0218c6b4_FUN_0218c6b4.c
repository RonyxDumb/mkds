/* Decompiled C draft; module arm9_ov001; ROM address 0218c6b4. No matching claim. */
#include "types.h"
#include "deps/0218c6b4_FUN_0218c6b4.h"

void FUN_0218c6b4(int param_1)

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
  FUN_021886f8(param_1,iVar5 << 1,uVar1,iVar3 << 1,*(int *)(iVar4 + DAT_0218c710) << 1,uVar2);
  FUN_0218883c(param_1,0,0,0,DAT_0218c714);
  *(undefined4 *)(param_1 + DAT_0218c71c) = DAT_0218c718;
  *(undefined4 *)(param_1 + DAT_0218c724) = DAT_0218c720;
  return;
}

