/* Decompiled C draft; module arm9; ROM address 02001a44. No matching claim. */
#include "types.h"
#include "deps/02001a44_Logo_StateHandler_ReadSaveData_First.h"

void Logo_StateHandler_ReadSaveData_First(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  ReadSaveData_NonGhost_from_thumb();
  uVar3 = *(uint *)(uRam02001a70 & 0xfffffffc) >> (uRam02001a70 & 3) * 8 |
          *(uint *)(uRam02001a70 & 0xfffffffc) << (uRam02001a70 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x2c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar3 + 0x2c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
  return;
}

