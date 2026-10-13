/* Decompiled C draft; module arm9_ov000; ROM address 0219d210. No matching claim. */
#include "types.h"
#include "deps/0219d210_FUN_0219d210.h"

undefined4 FUN_0219d210(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar1 = FUN_0219d630(iVar2);
      if ((iVar1 != 0) && (iVar1 == param_3)) {
        iVar1 = func_0x02152a24(param_1 + param_2 * 0xc);
        if ((iVar1 == 0) || (iVar1 = func_0x02152a24(param_1 + iVar2 * 0xc), iVar1 != 0)) {
          FUN_0219d288(param_1,param_2,iVar2);
        }
        else {
          FUN_0219d288(param_1,iVar2,param_2);
        }
        *(undefined1 *)(*DAT_0219d284 + 0x1d) = 1;
        return 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return 0;
}

