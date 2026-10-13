/* Decompiled C draft; module arm9_ov000; ROM address 0218df5c. No matching claim. */
#include "types.h"
#include "deps/0218df5c_FUN_0218df5c.h"

int FUN_0218df5c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = 0;
    if (0 < param_1[1]) {
      iVar2 = 0;
      do {
        iVar1 = FUN_0218dc44(*(undefined4 *)(*param_1 + iVar2));
        iVar3 = iVar3 + iVar1;
        iVar2 = iVar2 + 4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1[1]);
    }
    return iVar3;
  }
  func_0x0213442c(DAT_0218dfac,DAT_0218dfb0,0,0x61);
  return 0;
}

