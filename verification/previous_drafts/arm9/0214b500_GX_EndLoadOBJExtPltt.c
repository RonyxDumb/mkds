/* Decompiled C draft; module arm9; ROM address 0214b500. No matching claim. */
#include "types.h"
#include "deps/0214b500_GX_EndLoadOBJExtPltt.h"

void GX_EndLoadOBJExtPltt(void)

{
  undefined4 *puVar1;
  
  if ((*(uint *)(uRam0214b54c & 0xfffffffc) >> (uRam0214b54c & 3) * 8 |
      *(uint *)(uRam0214b54c & 0xfffffffc) << (uRam0214b54c & 3) * -8 + 0x20) != 0xffffffff) {
    MI_WaitDma();
  }
  GX_SetBankForOBJExtPltt
            (*(uint *)((uint)puRam0214b550 & 0xfffffffc) >> ((uint)puRam0214b550 & 3) * 8 |
             *(uint *)((uint)puRam0214b550 & 0xfffffffc) << ((uint)puRam0214b550 & 3) * -8 + 0x20);
  puVar1 = puRam0214b554;
  *puRam0214b550 = 0;
  *puVar1 = 0;
  return;
}

