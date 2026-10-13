/* Decompiled C draft; module arm9; ROM address 020d159c. No matching claim. */
#include "types.h"
#include "deps/020d159c_LoadStaffRollDataOam.h"

void LoadStaffRollDataOam(void)

{
  uint uVar1;
  uint uVar2;
  
  Arm_FlushRange((*(uint *)(uRam020d1628 & 0xfffffffc) >> (uRam020d1628 & 3) * 8 |
                 *(uint *)(uRam020d1628 & 0xfffffffc) << (uRam020d1628 & 3) * -8 + 0x20) + 0x10,
                 0x400);
  CopyToOamA((*(uint *)(uRam020d1628 & 0xfffffffc) >> (uRam020d1628 & 3) * 8 |
             *(uint *)(uRam020d1628 & 0xfffffffc) << (uRam020d1628 & 3) * -8 + 0x20) + 0x10,0,0x400)
  ;
  uVar1 = *(uint *)(uRam020d1628 & 0xfffffffc) >> (uRam020d1628 & 3) * 8 |
          *(uint *)(uRam020d1628 & 0xfffffffc) << (uRam020d1628 & 3) * -8 + 0x20;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0x1a4) {
    BrightCtx_SomeFn_0(0x78,1);
    return;
  }
  if (uVar2 == uRam020d162c) {
    BrightCtx_SomeFn_1(0x78,1);
    return;
  }
  return;
}

