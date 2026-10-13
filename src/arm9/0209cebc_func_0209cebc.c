/* Decompiled C draft; module arm9; ROM address 0209cebc. No matching claim. */
#include "types.h"
#include "deps/0209cebc_func_0209cebc.h"

void func_0209cebc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam0209ceec;
  func_020d2450();
  uVar1 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 0xb4) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

