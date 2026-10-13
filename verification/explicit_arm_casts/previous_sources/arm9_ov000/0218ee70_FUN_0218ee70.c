/* Decompiled C draft; module arm9_ov000; ROM address 0218ee70. No matching claim. */
#include "types.h"
#include "deps/0218ee70_FUN_0218ee70.h"

undefined4 FUN_0218ee70(int *param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  char local_418 [1032];
  
  pcVar1 = local_418;
  if ((param_1 == (int *)0x0) || (iVar2 = *param_1, iVar2 == 0)) {
    return 2;
  }
  if (*(int *)(iVar2 + DAT_0218ef78) != 0) {
    return 0;
  }
  if (*(int *)(iVar2 + DAT_0218ef7c) == 4) {
    FUN_02196590(param_1,DAT_0218ef80);
    return 2;
  }
  if (param_3 == 0) {
    FUN_02196590(param_1,DAT_0218ef84);
    return 2;
  }
  FUN_02196914(local_418,param_3,DAT_0218ef88);
  while (local_418[0] != '\0') {
    if (*pcVar1 == '\\') {
      *pcVar1 = '/';
    }
    pcVar1 = pcVar1 + 1;
    local_418[0] = *pcVar1;
  }
  FUN_02190b80(param_1,iVar2 + DAT_0218ef8c,DAT_0218ef90);
  FUN_02190b80(param_1,iVar2 + DAT_0218ef8c,DAT_0218ef94);
  FUN_02190b58(param_1,iVar2 + DAT_0218ef8c,*(undefined4 *)(iVar2 + DAT_0218ef98));
  FUN_02190b80(param_1,iVar2 + DAT_0218ef8c,DAT_0218ef9c);
  FUN_02190b58(param_1,iVar2 + DAT_0218ef8c,param_2);
  FUN_02190b80(param_1,iVar2 + DAT_0218ef8c,DAT_0218efa0);
  FUN_02190b80(param_1,iVar2 + DAT_0218ef8c,local_418);
  FUN_02190b80(param_1,iVar2 + DAT_0218ef8c,DAT_0218efa4);
  return 0;
}

