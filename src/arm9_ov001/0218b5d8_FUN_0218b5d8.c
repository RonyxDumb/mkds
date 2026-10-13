/* Decompiled C draft; module arm9_ov001; ROM address 0218b5d8. No matching claim. */
#include "types.h"
#include "deps/0218b5d8_FUN_0218b5d8.h"

void FUN_0218b5d8(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    iVar3 = 0;
    for (iVar4 = 0;
        (iVar3 < (int)(uint)*(ushort *)(param_1 + 1) &&
        (iVar2 = *(int *)(*param_1 + iVar4), iVar2 != 0)); iVar4 = iVar4 + 4) {
      FUN_0219b1c4(*(undefined4 *)(iVar2 + DAT_0218b638),
                   *(undefined4 *)(*(int *)(iVar2 + 0xa0) + 0x80),
                   *(undefined4 *)(*(int *)(iVar2 + 0xa0) + 0x50),0);
      iVar1 = func_0x02062ec4();
      if (iVar1 == 0) {
        FUN_0218b7c8(iVar2);
      }
      else {
        FUN_0218b770(iVar2);
      }
      iVar3 = iVar3 + 1;
    }
  }
  func_0x020a2314(DAT_0218b63c);
  return;
}

