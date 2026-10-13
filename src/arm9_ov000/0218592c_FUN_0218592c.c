/* Decompiled C draft; module arm9_ov000; ROM address 0218592c. No matching claim. */
#include "types.h"
#include "deps/0218592c_FUN_0218592c.h"

void FUN_0218592c(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)func_0x02036bec(param_1,8);
  piVar1 = DAT_02185950;
  *DAT_02185950 = (int)puVar2;
  *puVar2 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  func_0x02036f10(0x1e);
  return;
}

