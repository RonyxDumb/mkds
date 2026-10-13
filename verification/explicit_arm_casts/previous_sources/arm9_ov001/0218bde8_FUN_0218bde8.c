/* Decompiled C draft; module arm9_ov001; ROM address 0218bde8. No matching claim. */
#include "types.h"
#include "deps/0218bde8_FUN_0218bde8.h"

void FUN_0218bde8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218beac + 0x62));
  FUN_02187218(param_1,2,DAT_0218beb0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218beb4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218beb8));
  FUN_0219b1c4(*(undefined4 *)(param_1 + DAT_0218bebc),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bec0),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218beb8),0);
  FUN_02188cd8(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bec4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bec8));
  iVar3 = *(int *)(param_1 + 0xa0);
  FUN_02188a30(param_1,*(undefined4 *)(iVar3 + DAT_0218bed0),*(undefined4 *)(iVar3 + DAT_0218bed4),
               *(undefined4 *)(iVar3 + DAT_0218bed8),*(undefined4 *)(iVar3 + DAT_0218becc));
  FUN_02188968(param_1,iVar1 + 0x80);
  uVar2 = FUN_02187fc0(param_1);
  FUN_02188980(param_1,uVar2);
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218bedc),DAT_0218bee0);
  uVar2 = FUN_02187f7c(param_1);
  *(undefined4 *)(param_1 + DAT_0218beb8) = uVar2;
  FUN_0218c5fc(param_1);
  return;
}

