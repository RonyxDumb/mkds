/* Decompiled C draft; module arm9; ROM address 020f9c08. No matching claim. */
#include "types.h"
#include "deps/020f9c08_func_020f9c08.h"

undefined4 func_020f9c08(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x11cU & 3;
  uVar2 = *(uint *)(param_1 + 0x11cU & 0xfffffffc);
  if (((300 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) &&
      (uVar1 = param_1 + 0x74U & 3, uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc),
      ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000) != 0)) &&
     (uVar1 = param_1 + 0x120U & 3, uVar2 = *(uint *)(param_1 + 0x120U & 0xfffffffc),
     (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == uRam020f9c3c)) {
    return 1;
  }
  return 0;
}

