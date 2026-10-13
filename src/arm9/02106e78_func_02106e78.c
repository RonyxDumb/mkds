/* Decompiled C draft; module arm9; ROM address 02106e78. No matching claim. */
#include "types.h"
#include "deps/02106e78_func_02106e78.h"

void func_02106e78(void)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = iRam02106ee4 + 0xcU & 3;
  uVar3 = *(uint *)(iRam02106ee4 + 0xcU & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 1) {
    return;
  }
  pbVar1 = (byte *)(iRam02106ee4 + 0x16);
  *(undefined1 *)(iRam02106ee4 + 0x17) = 1;
  if ((*pbVar1 & 1) == 0) {
    NNS_SndPlayerSetTrackMute(uRam02106eec,uRam02106ef0);
    func_0210d614(uRam02106ef4,0x49,uRam02106ef8);
    return;
  }
  *puRam02106ee8 = 1;
  return;
}

