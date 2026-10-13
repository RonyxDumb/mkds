/* Decompiled C draft; module arm9_ov000; ROM address 0218e974. No matching claim. */
#include "types.h"
#include "deps/0218e974_FUN_0218e974.h"

undefined4 FUN_0218e974(int *param_1,int param_2,int param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char local_218 [256];
  char local_118 [260];
  
  pcVar1 = local_218;
  if ((param_1 == (int *)0x0) || (iVar3 = *param_1, iVar3 == 0)) {
    return 2;
  }
  if (*(int *)(iVar3 + DAT_0218eb04) != 0) {
    return 0;
  }
  if (*(int *)(iVar3 + DAT_0218eb08) == 4) {
    FUN_02196590(param_1,DAT_0218eb0c);
    return 2;
  }
  if (param_3 == 0) {
    FUN_02196590(param_1,DAT_0218eb10);
    return 2;
  }
  if (param_4 == 0) {
    FUN_02196590(param_1,DAT_0218eb14);
    return 2;
  }
  FUN_02196914(local_218,param_3,DAT_0218eb18);
  while (local_218[0] != '\0') {
    if (*pcVar1 == '\\') {
      *pcVar1 = '/';
    }
    pcVar1 = pcVar1 + 1;
    local_218[0] = *pcVar1;
  }
  FUN_02196914(local_118,param_4,DAT_0218eb18);
  pcVar1 = local_118;
  while (local_118[0] != '\0') {
    if (*pcVar1 == '\\') {
      *pcVar1 = '/';
    }
    pcVar1 = pcVar1 + 1;
    local_118[0] = *pcVar1;
  }
  if (((param_2 == *(int *)(iVar3 + DAT_0218eb1c)) &&
      (iVar2 = func_0x0213a074(local_218,iVar3 + DAT_0218eb20), iVar2 == 0)) &&
     (iVar2 = func_0x0213a074(local_118,iVar3 + DAT_0218eb24), iVar2 == 0)) {
    return 0;
  }
  *(int *)(iVar3 + DAT_0218eb1c) = param_2;
  FUN_02196914(iVar3 + DAT_0218eb20,local_218,DAT_0218eb18);
  FUN_02196914(iVar3 + DAT_0218eb24,local_118,DAT_0218eb18);
  FUN_02190b80(param_1,iVar3 + DAT_0218eb28,DAT_0218eb2c);
  FUN_02190b58(param_1,iVar3 + DAT_0218eb28,param_2);
  FUN_02190b80(param_1,iVar3 + DAT_0218eb28,DAT_0218eb30);
  FUN_02190b58(param_1,iVar3 + DAT_0218eb28,*(undefined4 *)(iVar3 + DAT_0218eb34));
  FUN_02190b80(param_1,iVar3 + DAT_0218eb28,DAT_0218eb38);
  FUN_02190b80(param_1,iVar3 + DAT_0218eb28,local_218);
  FUN_02190b80(param_1,iVar3 + DAT_0218eb28,DAT_0218eb3c);
  FUN_02190b80(param_1,iVar3 + DAT_0218eb28,local_118);
  FUN_02190b80(param_1,iVar3 + DAT_0218eb28,DAT_0218eb40);
  return 0;
}

