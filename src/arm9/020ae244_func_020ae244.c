/* Decompiled C draft; module arm9; ROM address 020ae244. No matching claim. */
#include "types.h"
#include "deps/020ae244_func_020ae244.h"

undefined4 func_020ae244(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = func_020ae290();
  if (iVar1 != 0) {
    uVar2 = func_020ae21c(param_1);
    uVar3 = func_020ae1f4(param_1);
    if (((((param_2 & 0xffff) <= uVar2) && (uVar2 <= (param_3 & 0xffff))) &&
        (param_2 >> 0x10 <= uVar3)) && (uVar3 <= param_3 >> 0x10)) {
      return 1;
    }
  }
  return 0;
}

