/* Decompiled C draft; module arm9_ov000; ROM address 0218bb44. No matching claim. */
#include "types.h"
#include "deps/0218bb44_FUN_0218bb44.h"

int FUN_0218bb44(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0218e668(*(undefined4 *)((int)param_1 + DAT_0218bbf8));
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = param_1[0x20];
  iVar1 = FUN_0218e460(*(undefined4 *)((int)param_1 + DAT_0218bbf8),param_1[0x1f] + iVar2,
                       DAT_0218bbfc - iVar2,0);
  if (iVar1 + 1U < 2) {
    FUN_0218cf30((int)(uintptr_t)(param_1));
    return 3;
  }
  param_1[0x20] = param_1[0x20] + iVar1;
  iVar1 = 0;
  if ((*param_1 == 2) || (0 < *(int *)((int)param_1 + DAT_0218bc00))) {
    FUN_0218a6f4((int)param_1 + DAT_0218bc04,param_1[0x1f] + iVar2,param_1[0x20] - iVar2);
  }
  if (*param_1 == 3) {
    iVar1 = FUN_0218c15c(param_1);
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((*param_1 == 2) && (0 < param_1[0x20])) {
    iVar1 = FUN_0218bc08((int)(uintptr_t)(param_1));
    return iVar1;
  }
  return 0;
}

