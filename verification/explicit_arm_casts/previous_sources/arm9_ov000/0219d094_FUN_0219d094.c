/* Decompiled C draft; module arm9_ov000; ROM address 0219d094. No matching claim. */
#include "types.h"
#include "deps/0219d094_FUN_0219d094.h"

undefined4 FUN_0219d094(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  
  local_10 = 0;
  if ((*DAT_0219d124 == 0) || (iVar1 = FUN_0219c3e4(), iVar1 == 0)) {
    return 0;
  }
  uVar2 = FUN_0219c9c4();
  iVar1 = func_0x02152520(uVar2,param_1);
  if ((0 < iVar1) &&
     (iVar3 = FUN_0218ebe8(*(undefined4 *)(*DAT_0219d124 + 4),iVar1,&local_10), iVar3 != 0)) {
    return 0;
  }
  if ((0 < iVar1) && (local_10 != -1)) {
    iVar1 = FUN_0218ec44(*(undefined4 *)(*DAT_0219d124 + 4),local_10,param_2);
    if (iVar1 != 0) {
      return 0;
    }
    return 1;
  }
  return 0;
}

