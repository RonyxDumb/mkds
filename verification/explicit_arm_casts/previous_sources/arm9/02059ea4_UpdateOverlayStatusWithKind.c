/* Decompiled C draft; module arm9; ROM address 02059ea4. No matching claim. */
#include "types.h"
#include "deps/02059ea4_UpdateOverlayStatusWithKind.h"

void UpdateOverlayStatusWithKind(uint param_1)

{
  uint uVar1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar2;
  
  uVar4 = *(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
          *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20;
  uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  if (uVar5 == param_1) {
    return;
  }
  uVar2 = uVar4 + 4 & 3;
  uVar1 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  switch(uVar2) {
  case 0:
    uVar5 = param_1 * 0xc + uVar4 + 8;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    Fs_OverlayInfo_Load(uVar4 + 0x2c,0,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    Fs_File_Initialize((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
                       *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) +
                       0x58);
    uVar4 = *(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
            *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20;
    Fs_OverlayInfo_LoadImageAsync(uVar4 + 0x2c,uVar4 + 0x58);
    uVar5 = DAT_0205a0e0;
    *(undefined4 *)
     ((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
      *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) + 4) = 1;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) = param_1;
    return;
  case 1:
    break;
  case 2:
    if (((uVar2 == 1) || (uVar2 == 2)) &&
       (uVar4 = uVar5 * 0xc + uVar4 + 8, uVar5 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       iVar3 = Fs_UnloadOverlay(0,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20),
       uVar4 = DAT_0205a0e0, iVar3 != 0)) {
      *(undefined4 *)
       (*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
       *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) = 4;
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 4) = 0;
      uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xa4;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
        Mem_Exp_Finalize();
        *(undefined4 *)
         ((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
          *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) + 0xa4) = 0;
      }
    }
    uVar2 = *(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
            *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20;
    uVar4 = param_1 * 0xc + uVar2 + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    Fs_OverlayInfo_Load(uVar2 + 0x2c,0,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    Fs_File_Initialize((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
                       *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) +
                       0x58);
    uVar4 = *(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
            *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20;
    Fs_OverlayInfo_LoadImageAsync(uVar4 + 0x2c,uVar4 + 0x58);
    uVar5 = DAT_0205a0e0;
    *(undefined4 *)
     ((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
      *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) + 4) = 1;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) = param_1;
    return;
  case 3:
    if (((uVar2 == 1) || (uVar2 == 2)) &&
       (uVar4 = uVar5 * 0xc + uVar4 + 8, uVar5 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       iVar3 = Fs_UnloadOverlay(0,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20),
       uVar4 = DAT_0205a0e0, iVar3 != 0)) {
      *(undefined4 *)
       (*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
       *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) = 4;
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 4) = 0;
      uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0xa4;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
        Mem_Exp_Finalize();
        *(undefined4 *)
         ((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
          *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) + 0xa4) = 0;
      }
    }
    uVar2 = *(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
            *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20;
    uVar4 = param_1 * 0xc + uVar2 + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    Fs_OverlayInfo_Load(uVar2 + 0x2c,0,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
    Fs_File_Initialize((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
                       *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) +
                       0x58);
    uVar4 = *(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
            *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20;
    Fs_OverlayInfo_LoadImageAsync(uVar4 + 0x2c,uVar4 + 0x58);
    uVar5 = DAT_0205a0e0;
    *(undefined4 *)
     ((*(uint *)(DAT_0205a0e0 & 0xfffffffc) >> (DAT_0205a0e0 & 3) * 8 |
      *(uint *)(DAT_0205a0e0 & 0xfffffffc) << (DAT_0205a0e0 & 3) * -8 + 0x20) + 4) = 1;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) = param_1;
  }
  return;
}

