/* Decompiled C draft; module arm9_ov001; ROM address 02181844. No matching claim. */
#include "types.h"
#include "deps/02181844_func_ov001_02181844.h"

void func_ov001_02181844(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4
                        )

{
  int *piVar1;
  
  piVar1 = piRam0218185c;
  *(undefined2 *)(*piRam0218185c + 0x10) = param_1;
  *(undefined2 *)(*piVar1 + 0x12) = param_2;
  *(undefined2 *)(*piVar1 + 0x14) = param_3;
  *(undefined2 *)(*piVar1 + 0x16) = param_4;
  return;
}

