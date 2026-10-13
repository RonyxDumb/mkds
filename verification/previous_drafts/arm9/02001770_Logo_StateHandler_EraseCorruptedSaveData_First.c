/* Decompiled C draft; module arm9; ROM address 02001770. No matching claim. */
#include "types.h"
#include "deps/02001770_Logo_StateHandler_EraseCorruptedSaveData_First.h"

void Logo_StateHandler_EraseCorruptedSaveData_First(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  EraseNonGhostSaveDataSections_from_thumb();
  uVar2 = (*(uint *)(uRam020017c8 & 0xfffffffc) >> (uRam020017c8 & 3) * 8 |
          *(uint *)(uRam020017c8 & 0xfffffffc) << (uRam020017c8 & 3) * -8 + 0x20) + 0x38;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0x7e);
  TextSystem_DisplayProgressDialog_from_thumb(uVar3,1,1,1,0,1);
  *(undefined4 *)
   ((*(uint *)(uRam020017c8 & 0xfffffffc) >> (uRam020017c8 & 3) * 8 |
    *(uint *)(uRam020017c8 & 0xfffffffc) << (uRam020017c8 & 3) * -8 + 0x20) + 0x34) = 0;
  return;
}

