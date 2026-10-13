/* Decompiled C draft; module arm9; ROM address 020613a0. No matching claim. */
#include "types.h"
#include "deps/020613a0_Task_ReadGhostBins.h"

void Task_ReadGhostBins(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_98 [128];
  
  uVar3 = 0;
  uVar2 = (*(uint *)(uRam02061414 & 0xfffffffc) >> (uRam02061414 & 3) * 8 |
          *(uint *)(uRam02061414 & 0xfffffffc) << (uRam02061414 & 3) * -8 + 0x20) + 0x40;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  do {
    FormatGhostBinPath(uVar3,auStack_98,0x80);
    OpenReadFileBufferSize_from_thumb
              (auStack_98,uVar3 * 0x230 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20),0x230);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0x20);
  ResetSaveDataHolderTaskPendingFlag_from_thumb();
  *(undefined4 *)
   ((*(uint *)(uRam02061414 & 0xfffffffc) >> (uRam02061414 & 3) * 8 |
    *(uint *)(uRam02061414 & 0xfffffffc) << (uRam02061414 & 3) * -8 + 0x20) + 0x40) = 0;
  return;
}

