/* Decompiled C draft; module arm9_ov001; ROM address 02196e54. No matching claim. */
#include "types.h"
#include "deps/02196e54_FUN_02196e54.h"

void FUN_02196e54(void)

{
  int *piVar1;
  
  piVar1 = DAT_02196e80;
  *(undefined4 *)(*DAT_02196e80 + 0x54) = 0xc;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  func_0x02128374();
  FUN_021972f4();
  *(undefined4 *)(*(int *)(*DAT_02196e80 + 0x3c) + DAT_02196e84) = 0;
  return;
}

