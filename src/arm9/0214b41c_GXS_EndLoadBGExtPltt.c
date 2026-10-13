/* Decompiled C draft; module arm9; ROM address 0214b41c. No matching claim. */
#include "types.h"
#include "deps/0214b41c_GXS_EndLoadBGExtPltt.h"

void GXS_EndLoadBGExtPltt(void)

{
  if ((*(uint *)(uRam0214b460 & 0xfffffffc) >> (uRam0214b460 & 3) * 8 |
      *(uint *)(uRam0214b460 & 0xfffffffc) << (uRam0214b460 & 3) * -8 + 0x20) != 0xffffffff) {
    MI_WaitDma();
  }
  GX_SetBankForSubBGExtPltt
            (*(uint *)((uint)puRam0214b464 & 0xfffffffc) >> ((uint)puRam0214b464 & 3) * 8 |
             *(uint *)((uint)puRam0214b464 & 0xfffffffc) << ((uint)puRam0214b464 & 3) * -8 + 0x20);
  *puRam0214b464 = 0;
  return;
}

