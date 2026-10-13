/* Decompiled C draft; module arm9; ROM address 021489c4. No matching claim. */
#include "types.h"
#include "deps/021489c4_func_021489c4.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_021489c4(void)

{
  ushort uVar1;
  
  uVar1 = *puRam02148a08;
  *puRam02148a0c = 1;
  if (uVar1 != 0) {
    _DAT_04000000 = _DAT_04000000 & 0xfffcffff | (uint)uVar1 << 0x10;
    return;
  }
  _DAT_04000000 = _DAT_04000000 | 0x10000;
  return;
}

