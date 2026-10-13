/* Decompiled C draft; module arm9; ROM address 02151718. No matching claim. */
#include "types.h"
#include "deps/02151718_StructDC_SomeFn_0_from_thumb.h"

undefined4 StructDC_SomeFn_0_from_thumb(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_18;
  
  iVar3 = iRam02151788;
  iVar5 = *piRam02151784;
  local_18 = 0;
  iVar4 = param_1;
  do {
    uVar1 = func_020205e8(param_1 + iRam0215178c,iVar4,0xfe);
    *(undefined2 *)(iVar4 + 0xfe) = uVar1;
    do {
      func_021511d8(iVar5,iVar3,iVar4);
      iVar2 = StructDC_SomeFn_5_from_thumb(iVar4,iVar5,iVar3,param_1 + iRam02151790);
    } while (iVar2 == 0);
    iVar4 = iVar4 + iVar3;
    local_18 = local_18 + 1;
    iVar5 = iVar5 + iVar3;
  } while (local_18 < 4);
  iVar3 = func_02151154();
  if (iVar3 != 0) {
    return 1;
  }
  return 0;
}

