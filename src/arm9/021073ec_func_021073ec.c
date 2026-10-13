/* Decompiled C draft; module arm9; ROM address 021073ec. No matching claim. */
#include "types.h"
#include "deps/021073ec_func_021073ec.h"

void func_021073ec(undefined4 param_1,undefined3 param_2,undefined4 *param_3)

{
  int iVar1;
  
  *(undefined1 *)((int)param_3 + 0x15) = 0;
  func_0212c6a0(param_3 + 2);
  *(undefined1 *)((int)param_3 + 0x16) = 0;
  param_3[4] = 0;
  *(undefined1 *)((int)param_3 + 0x17) = 0;
  *param_3 = 0;
  param_3[1] = 0;
  param_3[3] = 0;
  *(undefined1 *)(param_3 + 6) = 0xff;
  *(undefined1 *)((int)param_3 + 0x19) = 0xff;
  param_3[7] = 0xffffffff;
  param_3[8] = 0;
  func_0210d740(uRam021074a0,param_3,param_1,param_2);
  iVar1 = iRam021074a8;
  *(undefined4 *)(iRam021074a8 + 0x18) = uRam021074a4;
  func_0210d9a0(iVar1,0);
  return;
}

