/* Decompiled C draft; module arm9_ov001; ROM address 0218cf94. No matching claim. */
#include "types.h"
#include "deps/0218cf94_FUN_0218cf94.h"

void FUN_0218cf94(int *param_1)

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
      *(undefined4 *)(iVar2 + DAT_0218cfe0) = 1;
      iVar1 = func_0x02062ec4();
      if (iVar1 == 0) {
        FUN_0218d1e0(iVar2);
      }
      else {
        FUN_0218d188(iVar2);
      }
      iVar3 = iVar3 + 1;
    }
  }
  func_0x020a2314(DAT_0218cfe4);
  return;
}

