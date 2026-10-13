/* Decompiled C draft; module arm9_ov003; ROM address 021b8010. No matching claim. */
#include "types.h"
#include "deps/021b8010_func_ov003_021b8010.h"

uint func_ov003_021b8010(uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  if (param_4 == 0) {
    func_ov003_021b7fd4(0,param_5);
  }
  iVar1 = 0;
  if (0 < param_3) {
    do {
      param_1 = param_1 >> 8 ^
                *(uint *)(param_5 + ((param_1 ^ *(byte *)(param_2 + iVar1)) & 0xff) * 4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_3);
  }
  return param_1;
}

