/* Decompiled C draft; module arm9; ROM address 0204b20c. No matching claim. */
#include "types.h"
#include "deps/0204b20c_FindTable0IndexForValue_from_thumb.h"

uint FindTable0IndexForValue_from_thumb(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_2 ==
        (param_1 ^
        *(int *)(iRam0204b254 + uVar1 * 4) + *piRam0204b248 + *piRam0204b24c + *piRam0204b250)) {
      return uVar1;
    }
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x1d);
  return 0xffffffff;
}

