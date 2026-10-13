/* Decompiled C draft; module arm9; ROM address 0200bb98. No matching claim. */
#include "types.h"
#include "deps/0200bb98_func_0200bb98.h"

void func_0200bb98(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  if (*psRam0200bbec == 0) {
    *psRam0200bbec = 1;
    Mem_CpuFill8((uint *)(uintptr_t)(param_1),0,uRam0200bbf0);
    piVar1 = piRam0200bbf4;
    *piRam0200bbf4 = param_1;
    *(undefined2 *)(param_1 + iRam0200bbf8) = 0;
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(*piVar1 + iRam0200bbfc),0x16);
    func_0200991c(*piRam0200bbf4 + iRam0200bc00);
    func_020092a4();
    func_02009908(uRam0200bc04,uRam0200bc08);
  }
  return;
}

