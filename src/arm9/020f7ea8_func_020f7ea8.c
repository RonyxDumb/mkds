/* Decompiled C draft; module arm9; ROM address 020f7ea8. No matching claim. */
#include "types.h"
#include "deps/020f7ea8_func_020f7ea8.h"

undefined1 func_020f7ea8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar2 = param_2 + 0x44U & 3;
  uVar3 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  return *(undefined1 *)
          ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) +
          (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * 0xe + iRam020f7ec4);
}

