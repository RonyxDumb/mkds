/* Decompiled C draft; module arm9; ROM address 01ffb0cc. No matching claim. */
#include "types.h"
#include "deps/01ffb0cc_func_01ffb0cc.h"

void func_01ffb0cc(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = iRam01ffb124;
  *(short *)(param_1 + 0x4fc) = *(short *)(param_1 + 0x4fc) + 1;
  if (7 < *(ushort *)(param_1 + 0x4fc)) {
    *(undefined2 *)(param_1 + 0x4fc) = 0;
  }
  iVar3 = iRam01ffb12c;
  uVar4 = iRam01ffb128 + (uint)*(ushort *)(param_1 + 0x4fc) * 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x4f0) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = iVar2 + (uint)*(ushort *)(param_1 + 0x4fc) * 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x4f4) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar4 = iVar3 + (uint)*(ushort *)(param_1 + 0x4fc) * 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x4f8) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  return;
}

