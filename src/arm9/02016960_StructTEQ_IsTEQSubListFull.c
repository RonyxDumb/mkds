/* Decompiled C draft; module arm9; ROM address 02016960. No matching claim. */
#include "types.h"
#include "deps/02016960_StructTEQ_IsTEQSubListFull.h"

bool StructTEQ_IsTEQSubListFull(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  return (uint)*(ushort *)(param_1 + 0xc) == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

