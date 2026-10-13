/* Decompiled C draft; module arm9_ov000; ROM address 02197064. No matching claim. */
#include "types.h"
#include "deps/02197064_FUN_02197064.h"

undefined4 FUN_02197064(int param_1,uint param_2,undefined1 *param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  param_3[1] = 2;
  *(ushort *)(param_3 + 2) =
       (ushort)((param_2 & 0xffff) >> 8) | (ushort)((param_2 & 0xffff) << 8) & (ushort)DAT_021970e0;
  if (param_1 == 0) {
    *(undefined4 *)(param_3 + 4) = 0;
  }
  else {
    uVar1 = FUN_0218e374();
    *(undefined4 *)(param_3 + 4) = uVar1;
  }
  if (*(int *)(param_3 + 4) == -1) {
    iVar2 = FUN_021a8f84(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)**(undefined4 **)(iVar2 + 0xc);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar2;
  }
  return 1;
}

