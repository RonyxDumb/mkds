/* Decompiled C draft; module arm9; ROM address 0214b338. No matching claim. */
#include "types.h"
#include "deps/0214b338_GXS_EndLoadOBJExtPltt.h"

void GXS_EndLoadOBJExtPltt(void)

{
  if ((*(uint *)(uRam0214b37c & 0xfffffffc) >> (uRam0214b37c & 3) * 8 |
      *(uint *)(uRam0214b37c & 0xfffffffc) << (uRam0214b37c & 3) * -8 + 0x20) != 0xffffffff) {
    MI_WaitDma();
  }
  GX_SetBankForSubOBJExtPltt
            (*(uint *)((uint)puRam0214b380 & 0xfffffffc) >> ((uint)puRam0214b380 & 3) * 8 |
             *(uint *)((uint)puRam0214b380 & 0xfffffffc) << ((uint)puRam0214b380 & 3) * -8 + 0x20);
  *puRam0214b380 = 0;
  return;
}

