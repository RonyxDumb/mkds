/* Decompiled C draft; module arm9; ROM address 02148a10. No matching claim. */
#include "types.h"
#include "deps/02148a10_SomeDispcntInit.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SomeDispcntInit(void)

{
  ushort *puVar1;
  
  puVar1 = puRam02148a54;
  *puRam02148a50 = 0;
  *puVar1 = (ushort)(_DAT_04000000 >> 0x10) & 3;
  _DAT_04000000 = _DAT_04000000 & 0xfffcffff;
  return;
}

