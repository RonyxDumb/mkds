/* Decompiled C draft; module arm9; ROM address 0204b2cc. No matching claim. */
#include "types.h"
#include "deps/0204b2cc_ComputeCRC_from_thumb.h"

uint ComputeCRC_from_thumb(byte *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *local_20;
  uint local_18;
  
  uVar3 = 0;
  local_18 = 0;
  if (param_2 != 0) {
    local_20 = param_1;
    do {
      uVar2 = (uint)*local_20;
      iVar1 = 0;
      do {
        if ((uVar3 & uRam0204b340) == 0) {
          uVar3 = (uVar3 << 0x11) >> 0x10;
        }
        else {
          uVar3 = (uVar3 << 0x11) >> 0x10 ^ (uint)*puRam0204b33c;
        }
        if ((uVar2 & 0x80) != 0) {
          uVar3 = uVar3 ^ 1;
        }
        uVar2 = (uVar2 << 0x19) >> 0x18;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 8);
      local_20 = local_20 + 1;
      local_18 = local_18 + 1 & 0xffff;
    } while (local_18 < param_2);
  }
  return uVar3;
}

