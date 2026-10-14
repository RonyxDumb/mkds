/* Decompiled C draft; module arm9; ROM address 0210e920. No matching claim. */
#include "types.h"
#include "deps/0210e920_LoadCertainSwarSbnkSarc.h"

void LoadCertainSwarSbnkSarc(void)

{
  int iVar1;
  
  iVar1 = Sound_LoadSwar(1,*(uint *)(uRam0210e988 & 0xfffffffc) >> (uRam0210e988 & 3) * 8 |
                           *(uint *)(uRam0210e988 & 0xfffffffc) << (uRam0210e988 & 3) * -8 + 0x20);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = Sound_LoadSbnkWithFlags
                    (0,2,*(uint *)(uRam0210e988 & 0xfffffffc) >> (uRam0210e988 & 3) * 8 |
                         *(uint *)(uRam0210e988 & 0xfffffffc) << (uRam0210e988 & 3) * -8 + 0x20);
  if (iVar1 != 0) {
    Sound_LoadSarc(0,*(uint *)(uRam0210e988 & 0xfffffffc) >> (uRam0210e988 & 3) * 8 |
                     *(uint *)(uRam0210e988 & 0xfffffffc) << (uRam0210e988 & 3) * -8 + 0x20);
    return;
  }
  return;
}

