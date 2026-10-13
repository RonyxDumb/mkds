/* Decompiled C draft; module arm9; ROM address 020ffc98. No matching claim. */
#include "types.h"
#include "deps/020ffc98_func_020ffc98.h"

void func_020ffc98(int param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 0xacU & 3;
  uVar4 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  uVar5 = param_1 + 0xb0U & 3;
  uVar2 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  *(uint *)(param_1 + 0xac) =
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
       (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
  uVar1 = param_1 + 0xacU & 3;
  uVar5 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  sVar3 = (short)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
                  (int)*(short *)(param_1 + 0xa8) >> 0xc);
  if (sVar3 < 0x97) {
    sVar3 = 0x96;
  }
  *(short *)(param_1 + 0xa6) = *(short *)(param_1 + 0xa6) + sVar3;
  uVar1 = param_1 + 0x84U & 3;
  uVar5 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uint)*(ushort *)(param_1 + 0xa0) < (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20)) {
    *(undefined2 *)(param_1 + 0x90) = 5;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

