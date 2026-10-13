/* Decompiled C draft; module arm9; ROM address 0204ff14. No matching claim. */
#include "types.h"
#include "deps/0204ff14_func_0204ff14.h"

undefined4 func_0204ff14(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar2 = *(uint *)(uRam0204ffb0 & 0xfffffffc) >> (uRam0204ffb0 & 3) * 8 |
          *(uint *)(uRam0204ffb0 & 0xfffffffc) << (uRam0204ffb0 & 3) * -8 + 0x20;
  if (uVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  }
  if (uVar3 == 2) {
    if (*psRam0204ffb4 != 2) {
      if ((int)((uint)*(byte *)(uVar2 + param_1 * 0xe0 + 0x188) << 0x1f) < 0) {
        if (param_2 != 0) {
          Mem_CpuCopy8((ushort *)(uintptr_t)(uVar2 + iRam0204ffb8 + param_1 * 0xe0),(uint *)(uintptr_t)(param_2),0x14);
        }
        uVar1 = 1;
      }
      return uVar1;
    }
    return 0;
  }
  return 0;
}

