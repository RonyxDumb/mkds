/* Decompiled C draft; module arm9_ov001; ROM address 02188104. No matching claim. */
#include "types.h"
#include "deps/02188104_FUN_02188104.h"

int FUN_02188104(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02188154 + 0x62));
  if (((iVar1 != 0) && (iVar2 = FUN_021881a8(param_1,iVar1 + 0x80,param_2,param_3), iVar2 != 0)) &&
     ((*(uint *)(iVar1 + 0x48) & 0x40) == 0)) {
    return iVar1;
  }
  return 0;
}

