/* Decompiled C draft; module arm9_ov001; ROM address 0218d87c. No matching claim. */
#include "types.h"
#include "deps/0218d87c_FUN_0218d87c.h"

void FUN_0218d87c(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = (int *)func_0x02100138(DAT_0218d8e8);
  if (piVar1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar5 = 0;
        (iVar4 < (int)(uint)*(ushort *)(piVar1 + 1) &&
        (iVar3 = *(int *)(*piVar1 + iVar5), iVar3 != 0)); iVar5 = iVar5 + 4) {
      uVar2 = func_0x02133068(*(int *)(iVar3 + 0xa8) * *(int *)(*(int *)(iVar3 + 0xa0) + 0xd8) * 100
                              ,param_2);
      *(undefined4 *)(iVar3 + DAT_0218d8ec) = uVar2;
      uVar2 = func_0x02133068(param_2 * *(int *)(*(int *)(param_1 + 0xa0) + 0xd4),100);
      *(undefined4 *)(iVar3 + DAT_0218d8f0) = uVar2;
      iVar4 = iVar4 + 1;
    }
  }
  return;
}

