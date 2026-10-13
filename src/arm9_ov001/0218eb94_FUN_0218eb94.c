/* Decompiled C draft; module arm9_ov001; ROM address 0218eb94. No matching claim. */
#include "types.h"
#include "deps/0218eb94_FUN_0218eb94.h"

void FUN_0218eb94(int param_1)

{
  longlong *plVar1;
  undefined4 *puVar2;
  int iVar3;
  longlong lVar4;
  
  func_0x0207a974((short)*(char *)(*DAT_0218ec2c + 0x62));
  plVar1 = (longlong *)func_0x020d22d0();
  lVar4 = func_0x02133048((int)plVar1[1],*(undefined4 *)((int)plVar1 + 0xc),(int)*plVar1,
                          *(undefined4 *)((int)plVar1 + 4));
  *plVar1 = lVar4 + plVar1[2];
  puVar2 = (undefined4 *)FUN_02187fc0(param_1);
  *(undefined4 *)(param_1 + 4) = *puVar2;
  iVar3 = FUN_02187fc0(param_1);
  *(int *)(param_1 + 8) = *(int *)(*(int *)(param_1 + 0xa0) + 0x80) + *(int *)(iVar3 + 4);
  iVar3 = FUN_02187fc0(param_1);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + 8);
  FUN_02187218(param_1,5,DAT_0218ec30);
  FUN_0218f900(param_1);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218ec34),0);
  if (*DAT_0218ec38 != 5) {
    *DAT_0218ec3c = *DAT_0218ec38;
  }
  *DAT_0218ec38 = 5;
  return;
}

