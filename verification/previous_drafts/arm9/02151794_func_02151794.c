/* Decompiled C draft; module arm9; ROM address 02151794. No matching claim. */
#include "types.h"
#include "deps/02151794_func_02151794.h"

undefined4 func_02151794(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *local_20;
  int local_1c;
  
  iVar2 = iRam02151800;
  iVar3 = *piRam021517fc;
  local_1c = 0;
  local_20 = param_2;
  do {
    if (*local_20 != 0) {
      do {
        func_021511d8(iVar3,iVar2,param_1);
        iVar1 = StructDC_SomeFn_5_from_thumb(param_1,iVar3,iVar2,param_3);
      } while (iVar1 == 0);
    }
    local_20 = local_20 + 1;
    param_1 = param_1 + iVar2;
    local_1c = local_1c + 1;
    iVar3 = iVar3 + iVar2;
  } while (local_1c < 4);
  iVar2 = func_02151154();
  if (iVar2 != 0) {
    return 1;
  }
  return 0;
}

