/* Decompiled C draft; module arm9_ov000; ROM address 021a4654. No matching claim. */
#include "types.h"
#include "deps/021a4654_FUN_021a4654.h"

undefined4 FUN_021a4654(int param_1,uint param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  *(undefined1 *)(param_3 + 1) = 2;
  *(ushort *)(param_3 + 2) =
       (ushort)((param_2 & 0xffff) >> 8) | (ushort)((param_2 & 0xffff) << 8) & (ushort)DAT_021a46cc;
  if (param_1 == 0) {
    *(undefined4 *)(param_3 + 4) = 0;
  }
  else {
    uVar1 = FUN_0218e374();
    *(undefined4 *)(param_3 + 4) = uVar1;
  }
  if ((*(int *)(param_3 + 4) == -1) && (iVar2 = func_0x0213a074(param_1,DAT_021a46d0), iVar2 != 0))
  {
    iVar3 = FUN_021a8f84(param_1);
    if (iVar3 == 0) {
      return 0;
    }
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)**(undefined4 **)(iVar3 + 0xc);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar3;
  }
  return 1;
}

