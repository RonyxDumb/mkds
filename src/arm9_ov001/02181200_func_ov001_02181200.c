/* Decompiled C draft; module arm9_ov001; ROM address 02181200. No matching claim. */
#include "types.h"
#include "deps/02181200_func_ov001_02181200.h"

int func_ov001_02181200(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (-1 < (int)param_1) {
    piVar4 = (int *)*puRam02181264;
    iVar3 = *piVar4;
    if ((((int)param_1 < iVar3) && (-1 < (int)param_2)) && ((int)param_2 < iVar3)) {
      iVar1 = func_0x02133068(param_1,8);
      iVar3 = func_0x02133068(iVar3,8);
      iVar2 = func_0x02133068(param_2,8);
      return piVar4[8] + (param_2 & 7) * 8 + (param_1 & 7) + iVar1 * 0x40 + iVar2 * 0x40 * iVar3;
    }
  }
  return 0;
}

