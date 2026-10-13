/* Decompiled C draft; module arm9_ov001; ROM address 0218a120. No matching claim. */
#include "types.h"
#include "deps/0218a120_FUN_0218a120.h"

void FUN_0218a120(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_1 != (int *)0x0) {
    iVar3 = 0;
    for (iVar4 = 0;
        (iVar3 < (int)(uint)*(ushort *)(param_1 + 1) &&
        (iVar2 = *(int *)(*param_1 + iVar4), iVar2 != 0)); iVar4 = iVar4 + 4) {
      local_1c = 0;
      local_24 = *(undefined4 *)(*(int *)(iVar2 + 0xa0) + 0xfc);
      local_20 = *(undefined4 *)(*(int *)(iVar2 + 0xa0) + DAT_0218a194);
      FUN_02187c88(iVar2,5,&local_24);
      iVar1 = func_0x02062ec4();
      if (iVar1 == 0) {
        FUN_0218a20c(iVar2);
      }
      else {
        FUN_0218a19c(iVar2);
      }
      iVar3 = iVar3 + 1;
    }
  }
  func_0x020a2314(DAT_0218a198);
  return;
}

