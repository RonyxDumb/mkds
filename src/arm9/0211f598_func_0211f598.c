/* Decompiled C draft; module arm9; ROM address 0211f598. No matching claim. */
#include "types.h"
#include "deps/0211f598_func_0211f598.h"

void func_0211f598(void)

{
  ushort uVar1;
  int *piVar2;
  
  piVar2 = piRam0211f5c8;
  *(undefined4 *)(*piRam0211f5c8 + 0x20) = 2;
  *(undefined4 *)(*piVar2 + 0x24) = 0;
  uVar1 = *(ushort *)(*(int *)(*piVar2 + 4) + 6);
  *(undefined2 *)(*(int *)(*piVar2 + 0x10) + iRam0211f5cc) = 0;
  *(undefined2 *)(*(int *)(*piVar2 + 0x10) + (uVar1 + 0xe) * 0x40 + 6) = 0;
  return;
}

