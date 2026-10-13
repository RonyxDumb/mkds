/* Decompiled C draft; module arm9; ROM address 020e4474. No matching claim. */
#include "types.h"
#include "deps/020e4474_func_020e4474.h"

void func_020e4474(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x14cU & 3;
  uVar3 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
  uVar4 = param_1 + 0x150U & 3;
  uVar2 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
  *(uint *)(param_1 + 0x14c) =
       (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) +
       (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
  uVar1 = param_1 + 0x14cU & 3;
  uVar4 = *(uint *)(param_1 + 0x14cU & 0xfffffffc);
  *(short *)(param_1 + 0x7e) =
       *(short *)(param_1 + 0x7e) +
       (short)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * (int)*(short *)(param_1 + 0x14a)
              >> 0xc);
  uVar1 = param_1 + 0x84U & 3;
  uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uint)*(ushort *)(param_1 + 0x144) < (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
    *(undefined2 *)(param_1 + 0x90) = 1;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

