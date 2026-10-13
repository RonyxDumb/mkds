/* Decompiled C draft; module arm9; ROM address 0212d03c. No matching claim. */
#include "types.h"
#include "deps/0212d03c_NNSi_SndCaptureMain.h"

void NNSi_SndCaptureMain(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = uRam0212d0e8;
  if (*(uint *)(uRam0212d0e8 & 0xfffffffc) >> (uRam0212d0e8 & 3) * 8 == 0 &&
      *(uint *)(uRam0212d0e8 & 0xfffffffc) << (uRam0212d0e8 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = uRam0212d0e8 + 4 & 3;
  uVar3 = *(uint *)(uRam0212d0e8 + 4 & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    iVar6 = uRam0212d0e8 + 0x3c;
    NNS_Snd_func_02068a34(iVar6);
    uVar1 = uVar2 + 0x4c & 3;
    uVar3 = *(uint *)(uVar2 + 0x4c & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) &&
       (iVar4 = NNS_Snd_func_02068a4c(iVar6), iVar4 != 0)) {
      func_0212cbd8();
      return;
    }
    iVar6 = func_0212f7f8(iVar6);
    uVar3 = uVar2 + 0x50 & 3;
    uVar5 = *(uint *)(uVar2 + 0x50 & 0xfffffffc);
    uVar1 = iVar6 >> 8;
    if (uVar1 != (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20)) {
      uVar3 = uVar2 + 0x24 & 3;
      uVar5 = *(uint *)(uVar2 + 0x24 & 0xfffffffc);
      SND_SetChannelVolume(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,uVar1,0);
      *(uint *)(uVar2 + 0x50) = uVar1;
      return;
    }
    return;
  }
  return;
}

