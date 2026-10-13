/* Decompiled C draft; module arm9_ov001; ROM address 0218fcc4. No matching claim. */
#include "types.h"
#include "deps/0218fcc4_FUN_0218fcc4.h"

void FUN_0218fcc4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    uVar4 = 0;
    for (iVar3 = 0;
        (iVar2 < (int)(uint)*(ushort *)(param_1 + 1) &&
        (iVar1 = *(int *)(*param_1 + iVar3), iVar1 != 0)); iVar3 = iVar3 + 4) {
      FUN_021870e4(uVar4,iVar1,uVar4,uVar4,DAT_0218fd18,uVar4);
      if (*(int *)(*DAT_0218fd1c + 8) == 4) {
        FUN_02181b8c(iVar1);
      }
      FUN_02190080(iVar1);
      iVar2 = iVar2 + 1;
    }
  }
  return;
}

