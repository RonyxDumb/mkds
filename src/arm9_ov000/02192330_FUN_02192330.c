/* Decompiled C draft; module arm9_ov000; ROM address 02192330. No matching claim. */
#include "types.h"
#include "deps/02192330_FUN_02192330.h"

undefined4 FUN_02192330(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar1 + DAT_0219239c,DAT_021923a0);
  FUN_02190b58(param_1,iVar1 + DAT_0219239c,*(undefined4 *)(iVar1 + DAT_021923a4));
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar1 + DAT_0219239c,DAT_021923a8);
  FUN_02190b58(param_1,iVar1 + DAT_0219239c,param_2);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar1 + DAT_0219239c,DAT_021923ac);
  FUN_02190b58(param_1,iVar1 + DAT_0219239c,param_3);
  FUN_02190b80((undefined4)(uintptr_t)(param_1),iVar1 + DAT_0219239c,DAT_021923b0);
  return 0;
}

