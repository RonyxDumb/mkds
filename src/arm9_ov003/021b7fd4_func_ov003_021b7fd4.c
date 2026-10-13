/* Decompiled C draft; module arm9_ov003; ROM address 021b7fd4. No matching claim. */
#include "types.h"
#include "deps/021b7fd4_func_ov003_021b7fd4.h"

void func_ov003_021b7fd4(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam021b8008;
  uVar3 = 0;
  do {
    iVar2 = 0;
    uVar4 = uVar3;
    do {
      if ((uVar4 & 1) == 0) {
        uVar4 = uVar4 >> 1;
      }
      else {
        uVar4 = uVar4 >> 1 ^ uVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 8);
    *param_2 = uVar4;
    param_2 = param_2 + 1;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < iRam021b800c);
  return;
}

