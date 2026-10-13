/* Decompiled C draft; module arm9; ROM address 02106dc8. No matching claim. */
#include "types.h"
#include "deps/02106dc8_func_02106dc8.h"

void func_02106dc8(void)

{
  uint uVar1;
  uint uVar2;
  
  NNS_SndPlayerSetTrackMute(uRam02106e5c,uRam02106e60,0);
  func_0212c6f0(uRam02106e64,0);
  if (*(uint *)((uint)puRam02106e68 & 0xfffffffc) >> ((uint)puRam02106e68 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam02106e68 & 0xfffffffc) << ((uint)puRam02106e68 & 3) * -8 + 0x20 != 0) {
    uVar1 = iRam02106e6c + 0xcU & 3;
    uVar2 = *(uint *)(iRam02106e6c + 0xcU & 0xfffffffc);
    if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 1) {
      func_0210d5c0(uRam02106e70);
      uVar1 = iRam02106e74 + 4U & 3;
      uVar2 = *(uint *)(iRam02106e74 + 4U & 0xfffffffc);
      func_0212c678(uRam02106e5c,(int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 0xc);
      func_0212c494(uRam02106e5c,300);
      func_0210faac();
    }
    *puRam02106e68 = 0;
  }
  *(undefined1 *)(iRam02106e6c + 0x17) = 0;
  return;
}

