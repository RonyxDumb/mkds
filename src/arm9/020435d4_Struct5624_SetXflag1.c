/* Decompiled C draft; module arm9; ROM address 020435d4. No matching claim. */
#include "types.h"
#include "deps/020435d4_Struct5624_SetXflag1.h"

void Struct5624_SetXflag1(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(uRam02043608 & 0xfffffffc) >> (uRam02043608 & 3) * 8 |
            *(uint *)(uRam02043608 & 0xfffffffc) << (uRam02043608 & 3) * -8 + 0x20;
    *(ushort *)(uVar1 + 4) = *(ushort *)(uVar1 + 4) | 1;
    return;
  }
  uVar1 = *(uint *)(uRam02043608 & 0xfffffffc) >> (uRam02043608 & 3) * 8 |
          *(uint *)(uRam02043608 & 0xfffffffc) << (uRam02043608 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 4) = *(ushort *)(uVar1 + 4) & 0xfffe;
  return;
}

