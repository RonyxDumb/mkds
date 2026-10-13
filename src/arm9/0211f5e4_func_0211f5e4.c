/* Decompiled C draft; module arm9; ROM address 0211f5e4. No matching claim. */
#include "types.h"
#include "deps/0211f5e4_func_0211f5e4.h"

void func_0211f5e4(void)

{
  ushort uVar1;
  int *piVar2;
  
  piVar2 = piRam0211f614;
  *(undefined4 *)(*piRam0211f614 + 0x20) = 0;
  *(undefined4 *)(*piVar2 + 0x24) = 0;
  uVar1 = *(ushort *)(*(int *)(*piVar2 + 4) + 6);
  *(undefined2 *)(*(int *)(*piVar2 + 0x10) + iRam0211f618) = 0xc0;
  *(undefined2 *)(*(int *)(*piVar2 + 0x10) + (uVar1 + 0xe) * 0x40 + 6) = 0xc0;
  return;
}

