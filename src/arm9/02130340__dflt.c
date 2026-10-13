/* Decompiled C draft; module arm9; ROM address 02130340. No matching claim. */
#include "types.h"
#include "deps/02130340__dflt.h"

undefined8 _dflt(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0x80000000;
  if ((int)uVar2 < 0) {
    param_1 = -param_1;
  }
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = param_1 << LZCOUNT(param_1);
  return CONCAT44(uVar2 | (uint)(iVar1 * 2) >> 0xc | (0x41e - LZCOUNT(param_1)) * 0x100000,
                  iVar1 << 0x15);
}

