/* Decompiled C draft; module arm9; ROM address 0202a340. No matching claim. */
#include "types.h"
#include "deps/0202a340_func_0202a340.h"

void func_0202a340(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *piRam0202a35c + 0x98 + param_2 * 4;
  func_02025cd0((short *)(uintptr_t)(param_1),*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 3),
                *(undefined2 *)(*piRam0202a35c + 0x98 + param_2 * 4));
  return;
}

