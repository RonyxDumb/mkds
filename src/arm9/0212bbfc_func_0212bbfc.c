/* Decompiled C draft; module arm9; ROM address 0212bbfc. No matching claim. */
#include "types.h"
#include "deps/0212bbfc_func_0212bbfc.h"

bool func_0212bbfc(uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)((uint)puRam0212bc1c & 0xfffffffc) >> ((uint)puRam0212bc1c & 3) * 8 |
          *(uint *)((uint)puRam0212bc1c & 0xfffffffc) << ((uint)puRam0212bc1c & 3) * -8 + 0x20;
  bVar2 = (param_1 & uVar1) == 0;
  if (bVar2) {
    *puRam0212bc1c = uVar1 | param_1;
  }
  return bVar2;
}

