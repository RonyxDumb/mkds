/* Decompiled C draft; module arm9; ROM address 02043544. No matching claim. */
#include "types.h"
#include "deps/02043544_Struct5624_SetXflag2.h"

void Struct5624_SetXflag2(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = GetCurrentSceneId();
  if ((iVar1 == 2) && (param_1 != 0)) {
    uVar2 = *(uint *)(uRam02043598 & 0xfffffffc) >> (uRam02043598 & 3) * 8 |
            *(uint *)(uRam02043598 & 0xfffffffc) << (uRam02043598 & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 4) = *(ushort *)(uVar2 + 4) | 2;
    return;
  }
  uVar2 = *(uint *)(uRam02043598 & 0xfffffffc) >> (uRam02043598 & 3) * 8 |
          *(uint *)(uRam02043598 & 0xfffffffc) << (uRam02043598 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 4) = *(ushort *)(uVar2 + 4) & 0xfffd;
  return;
}

