/* Decompiled C draft; module arm9_ov000; ROM address 021992d4. No matching claim. */
#include "types.h"
#include "deps/021992d4_FUN_021992d4.h"

/* WARNING: Removing unreachable block (ram,0x0219945a) */
/* WARNING: Removing unreachable block (ram,0x02199464) */
/* WARNING: Removing unreachable block (ram,0x0219946e) */

undefined4 FUN_021992d4(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_18;
  
  local_1c = FUN_0219a5b0(param_1,param_4,param_5);
  if ((*(int *)(param_1 + 0x2c) != 0) &&
     (iVar3 = FUN_02197f28(param_1,local_1c,param_4,param_5,0,param_2,param_3,0), iVar3 == 0)) {
    return 0;
  }
  if ((param_3 < 3) || (iVar3 = func_0x02134d30(param_2,DAT_021994c0,2), iVar3 != 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (local_1c == 0) {
    iVar3 = FUN_02197e8c(param_1,param_4,param_5,param_2,param_3,&local_18);
    if (iVar3 == 0) {
      return 0;
    }
    if (local_18 != 0) {
      return 1;
    }
    if ((!bVar2) || (*(char *)(param_2 + 2) != '\x01')) {
      if (((!bVar2) || (*(char *)(param_2 + 2) != 'h')) &&
         (iVar3 = FUN_02198b50(param_1,param_4,param_5), iVar3 == 0)) {
        return 0;
      }
      return 1;
    }
    if (*(int *)(param_1 + 0x20) == 0) {
      return 1;
    }
    iVar3 = FUN_0219883c(param_1,&local_1c,param_4,param_5);
    if (iVar3 != 0) {
      if ((iVar3 != 5) && (iVar3 = FUN_02198b50(param_1,param_4,param_5), iVar3 == 0)) {
        return 0;
      }
      return 1;
    }
  }
  iVar3 = local_1c;
  if (*(int *)(local_1c + 0xc) == 7) {
    if (((!bVar2) || (*(char *)(param_2 + 2) != 'h')) &&
       (iVar3 = FUN_02198b8c((undefined4 *)(uintptr_t)(local_1c)), iVar3 == 0)) {
      return 0;
    }
    return 1;
  }
  if (((bVar2) && (3 < param_3)) &&
     (iVar4 = func_0x02134d30(param_2 + 2,DAT_021994c0,2), iVar4 == 0)) {
    param_2 = param_2 + 2;
    param_3 = param_3 + -2;
    bVar2 = false;
  }
  if (bVar2) {
    bVar1 = *(byte *)(param_2 + 2);
    if (7 < bVar1) {
      iVar3 = FUN_021994c4(iVar3,bVar1,param_2,param_3);
      if (iVar3 == 0) {
        return 0;
      }
      return 1;
    }
    iVar3 = FUN_021996fc(iVar3,bVar1,param_2,param_3);
    if (iVar3 == 0) {
      return 0;
    }
    return 1;
  }
  iVar3 = FUN_02199e50(iVar3,param_2,param_3);
  if (iVar3 == 0) {
    return 0;
  }
  return 1;
}

