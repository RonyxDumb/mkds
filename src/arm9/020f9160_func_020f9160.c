/* Decompiled C draft; module arm9; ROM address 020f9160. No matching claim. */
#include "types.h"
#include "deps/020f9160_func_020f9160.h"

undefined4 func_020f9160(int param_1)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10000) == 0) &&
     (uVar1 = param_1 + 0xd4U & 3, uVar3 = *(uint *)(param_1 + 0xd4U & 0xfffffffc),
     (int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x3fffffe0) <= iRam020f91bc)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((!bVar2) &&
     (uVar1 = param_1 + 0xd4U & 3, uVar3 = *(uint *)(param_1 + 0xd4U & 0xfffffffc),
     iRam020f91c0 < (int)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x3fffffe0))) {
    return 1;
  }
  return 0;
}

