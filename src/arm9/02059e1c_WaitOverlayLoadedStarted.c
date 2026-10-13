/* Decompiled C draft; module arm9; ROM address 02059e1c. No matching claim. */
#include "types.h"
#include "deps/02059e1c_WaitOverlayLoadedStarted.h"

void WaitOverlayLoadedStarted(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  bool bVar5;
  uint uVar3;
  
  uVar1 = uRam02059ea0;
  do {
    uVar4 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar3 = uVar4 + 4 & 3;
    uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    bVar5 = uVar3 == 2;
    if (((!bVar5) && (uVar3 == 1)) &&
       (uVar3 = uVar4 + 100 & 3, uVar2 = *(uint *)(uVar4 + 100 & 0xfffffffc),
       ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 1) == 0)) {
      Fs_OverlayInfo_Start(uVar4 + 0x2c);
      Fs_File_Close((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x58);
      bVar5 = true;
      *(undefined4 *)
       ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 4) = 2;
    }
  } while (!bVar5);
  return;
}

