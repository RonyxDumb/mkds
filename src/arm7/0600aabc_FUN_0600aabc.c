/* Decompiled C draft; module arm7; ROM address 0600aabc. No matching claim. */
#include "types.h"
#include "deps/0600aabc_FUN_0600aabc.h"

void FUN_0600aabc(undefined2 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_0600aaf4;
  *(undefined2 *)
   ((*(uint *)(DAT_0600aaf4 & 0xfffffffc) >> (DAT_0600aaf4 & 3) * 8 |
    *(uint *)(DAT_0600aaf4 & 0xfffffffc) << (DAT_0600aaf4 & 3) * -8 + 0x20) + 0x3ae) = param_1;
  *DAT_0600aaf8 = param_1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uint)*(ushort *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x33a) << 0x18) <
      0) {
    *DAT_0600aafc = param_1;
  }
  return;
}

