/* Decompiled C draft; module arm9; ROM address 0209ea90. No matching claim. */
#include "types.h"
#include "deps/0209ea90_func_0209ea90.h"

void func_0209ea90(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam0209eb00;
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  *(undefined2 *)(param_1 + 0xa0) =
       *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x28);
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  *(short *)(param_1 + 0xa2) =
       *(short *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x2e) + 1;
  func_020d28e0();
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  return;
}

