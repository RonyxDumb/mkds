/* Decompiled C draft; module arm9; ROM address 0200148c. No matching claim. */
#include "types.h"
#include "deps/0200148c_Logo_StateHandler_EraseSaveData_First.h"

void Logo_StateHandler_EraseSaveData_First(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  OverwriteEmptySaveData_from_thumb();
  uVar4 = *(uint *)(uRam020014fc & 0xfffffffc) >> (uRam020014fc & 3) * 8 |
          *(uint *)(uRam020014fc & 0xfffffffc) << (uRam020014fc & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x2c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1f) < 0) {
    uVar4 = uVar4 + 0x38;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar3 = Bmg_GetRawStringPointer_from_thumb(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,0x7e)
    ;
    TextSystem_DisplayProgressDialog_from_thumb(uVar3,1,1,1);
    *(undefined4 *)
     ((*(uint *)(uRam020014fc & 0xfffffffc) >> (uRam020014fc & 3) * 8 |
      *(uint *)(uRam020014fc & 0xfffffffc) << (uRam020014fc & 3) * -8 + 0x20) + 0x34) = 0;
    return;
  }
  return;
}

