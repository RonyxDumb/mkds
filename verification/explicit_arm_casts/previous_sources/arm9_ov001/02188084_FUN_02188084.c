/* Decompiled C draft; module arm9_ov001; ROM address 02188084. No matching claim. */
#include "types.h"
#include "deps/02188084_FUN_02188084.h"

int FUN_02188084(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_021880fc + 0x62));
  if (((((iVar1 != 0) && ((*(uint *)(iVar1 + 0x48) & 0x40) == 0)) &&
       ((param_3 != 0 || (param_4 != 0)))) &&
      ((param_3 == 0 || (iVar2 = FUN_02188f04(param_1,iVar1 + 0x80,param_3), iVar2 != 0)))) &&
     ((param_4 == 0 ||
      (iVar2 = FUN_02188eac(param_1,*(int *)(param_1 + DAT_02188100) + param_2,iVar1 + 0x80,param_4)
      , iVar2 != 0)))) {
    return iVar1;
  }
  return 0;
}

