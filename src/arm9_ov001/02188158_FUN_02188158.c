/* Decompiled C draft; module arm9_ov001; ROM address 02188158. No matching claim. */
#include "types.h"
#include "deps/02188158_FUN_02188158.h"

int FUN_02188158(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = func_0x020fd7f0();
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = func_0x020fd7a4(iVar4);
      if ((iVar2 != 0) && (iVar3 = FUN_021881a8(param_1,iVar2 + 0x50,param_2,param_3), iVar3 != 0))
      {
        return iVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return 0;
}

