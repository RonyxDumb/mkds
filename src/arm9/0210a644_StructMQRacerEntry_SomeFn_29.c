/* Decompiled C draft; module arm9; ROM address 0210a644. No matching claim. */
#include "types.h"
#include "deps/0210a644_StructMQRacerEntry_SomeFn_29.h"

void StructMQRacerEntry_SomeFn_29(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = uRam0210a660;
  *(uint *)(param_1 + 0x484) =
       *(uint *)(uRam0210a65c & 0xfffffffc) >> (uRam0210a65c & 3) * 8 |
       *(uint *)(uRam0210a65c & 0xfffffffc) << (uRam0210a65c & 3) * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  return;
}

