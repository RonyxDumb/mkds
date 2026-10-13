/* Decompiled C draft; module arm9_ov000; ROM address 021906e4. No matching claim. */
#include "types.h"
#include "deps/021906e4_FUN_021906e4.h"

int FUN_021906e4(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 *param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_24;
  undefined4 local_20;
  int local_1c [2];
  
  if (param_3 == (int *)0x0) {
    func_0x0213442c(DAT_021907c4,DAT_021907c8,0,DAT_021907cc);
  }
  iVar5 = *param_3;
  local_24 = param_3[2];
  iVar4 = param_3[3];
  iVar2 = local_24 - iVar4;
  iVar3 = 0;
  if (iVar2 == 0) {
    return 0;
  }
  do {
    iVar1 = FUN_02190aa8(param_1,param_2,iVar5 + iVar4 + iVar3,iVar2,&local_20,local_1c,(char *)(uintptr_t)(param_6));
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_1c[0] == 0) break;
    iVar3 = iVar3 + local_1c[0];
    iVar2 = iVar2 - local_1c[0];
  } while (iVar2 != 0);
  if (param_5 == 0) {
    iVar4 = iVar4 + iVar3;
  }
  else if (0 < iVar3) {
    func_0x02134df8((uint *)(uintptr_t)(iVar5),(uint *)(uintptr_t)(iVar5 + iVar3),iVar2 + 1);
    local_24 = local_24 - iVar3;
  }
  if (local_24 < 0) {
    func_0x0213442c(DAT_021907d0,DAT_021907c8,0,DAT_021907d4);
  }
  if (iVar4 < 0) {
    func_0x0213442c(DAT_021907d8,DAT_021907c8,0,DAT_021907dc);
  }
  if (local_24 < iVar4) {
    func_0x0213442c(DAT_021907e0,DAT_021907c8,0,DAT_021907e4);
  }
  param_3[2] = local_24;
  param_3[3] = iVar4;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = local_20;
  }
  return 0;
}

