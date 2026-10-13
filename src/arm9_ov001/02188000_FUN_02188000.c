/* Decompiled C draft; module arm9_ov001; ROM address 02188000. No matching claim. */
#include "types.h"
#include "deps/02188000_FUN_02188000.h"

int FUN_02188000(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_02188078 + 0x62));
  if (((((iVar1 != 0) && ((*(uint *)(iVar1 + 0x48) & 0x40) == 0)) &&
       ((param_2 != 0 || (param_3 != 0)))) &&
      ((param_2 == 0 || (iVar2 = FUN_02188f04(param_1,(int *)(uintptr_t)(iVar1 + 0x80),param_2), iVar2 != 0)))) &&
     ((param_3 == 0 ||
      (iVar2 = FUN_02188eac(param_1,(uint)*(ushort *)(iVar1 + DAT_0218807c) + DAT_02188080,
                            (int *)(uintptr_t)(iVar1 + 0x80),param_3), iVar2 != 0)))) {
    return iVar1;
  }
  return 0;
}

