/* Decompiled C draft; module arm9; ROM address 02043a34. No matching claim. */
#include "types.h"
#include "deps/02043a34_func_02043a34.h"

void func_02043a34(void)

{
  if ((int)(*puRam02043a88 & 0x8000) >> 0xf == 0) {
    *(ushort *)
     ((*(uint *)(uRam02043a8c & 0xfffffffc) >> (uRam02043a8c & 3) * 8 |
      *(uint *)(uRam02043a8c & 0xfffffffc) << (uRam02043a8c & 3) * -8 + 0x20) + 2) =
         ((*puRam02043a90 | *puRam02043a88) ^ (ushort)uRam02043a94) & (ushort)uRam02043a94;
  }
  else {
    *(undefined2 *)
     ((*(uint *)(uRam02043a8c & 0xfffffffc) >> (uRam02043a8c & 3) * 8 |
      *(uint *)(uRam02043a8c & 0xfffffffc) << (uRam02043a8c & 3) * -8 + 0x20) + 2) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x02043a84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02043a98)();
  return;
}

