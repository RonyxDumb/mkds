/* Decompiled C draft; module arm9; ROM address 0205edf8. No matching claim. */
#include "types.h"
#include "deps/0205edf8_WriteFriendListSaveDataSection.h"

void WriteFriendListSaveDataSection(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0205ee0c & 0xfffffffc) >> (uRam0205ee0c & 3) * 8 |
          *(uint *)(uRam0205ee0c & 0xfffffffc) << (uRam0205ee0c & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x0205ee08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0205ee10)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

