/* Decompiled C draft; module arm9; ROM address 02050764. No matching claim. */
#include "types.h"
#include "deps/02050764_func_02050764.h"

void func_02050764(int param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  undefined1 auStack_20 [24];
  
  if (*(short *)(param_1 + 2) != 0) {
    return;
  }
  uVar1 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  if (*(ushort *)(param_1 + 0x10) < 2) {
    return;
  }
  if (*(ushort *)(param_1 + 0x10) < 0x19) {
    DC_InvalidateRangeNoClean();
    uVar1 = param_1 + 0xcU & 3;
    uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    Mem_CpuCopy8(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,auStack_20,
                 *(undefined2 *)(param_1 + 0x10));
    sVar2 = *(short *)(param_1 + 4);
    if (sVar2 == 7) {
      return;
    }
    if (sVar2 != 9) {
      if (sVar2 == 0x15) {
        func_0205081c(*(undefined2 *)(param_1 + 0x12),auStack_20);
        return;
      }
      return;
    }
    return;
  }
  return;
}

