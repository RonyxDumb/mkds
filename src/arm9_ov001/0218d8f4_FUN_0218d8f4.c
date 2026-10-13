/* Decompiled C draft; module arm9_ov001; ROM address 0218d8f4. No matching claim. */
#include "types.h"
#include "deps/0218d8f4_FUN_0218d8f4.h"

void FUN_0218d8f4(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = (int *)func_0x02100138(DAT_0218d94c);
  if (piVar1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0; (iVar4 < (int)(uint)*(ushort *)(piVar1 + 1) && (*(int *)(*piVar1 + iVar3) != 0))
        ; iVar3 = iVar3 + 4) {
      iVar5 = *(int *)(param_1 + 0xa0);
      uVar2 = func_0x02133068(param_2 * *(int *)(iVar5 + 0x8c),100);
      FUN_02188d64(param_1,*(undefined4 *)(iVar5 + 0x88),uVar2);
      iVar4 = iVar4 + 1;
    }
  }
  return;
}

