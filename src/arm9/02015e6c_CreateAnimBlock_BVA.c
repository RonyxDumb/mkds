/* Decompiled C draft; module arm9; ROM address 02015e6c. No matching claim. */
#include "types.h"
#include "deps/02015e6c_CreateAnimBlock_BVA.h"

void CreateAnimBlock_BVA(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  *(uint *)(param_1 + 0xc) =
       *(uint *)(uRam02015eb4 & 0xfffffffc) >> (uRam02015eb4 & 3) * 8 |
       *(uint *)(uRam02015eb4 & 0xfffffffc) << (uRam02015eb4 & 3) * -8 + 0x20;
  *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_3 + 0x17);
  *(undefined4 *)(param_1 + 8) = param_2;
  if (*(char *)(param_1 + 0x19) == '\0') {
    return;
  }
  do {
    *(ushort *)(param_1 + uVar1 * 2 + 0x1a) = (ushort)uVar1 | 0x100;
    uVar1 = uVar1 + 1;
  } while (uVar1 < *(byte *)(param_1 + 0x19));
  return;
}

