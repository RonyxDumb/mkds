/* Decompiled C draft; module arm9; ROM address 0200f484. No matching claim. */
#include "types.h"
#include "deps/0200f484_OSi_DisplayExContext.h"

void OSi_DisplayExContext(void)

{
  undefined1 auStack_8 [8];
  
  if (*(uint *)(uRam0200f4e0 & 0xfffffffc) >> (uRam0200f4e0 & 3) * 8 != 0 ||
      *(uint *)(uRam0200f4e0 & 0xfffffffc) << (uRam0200f4e0 & 3) * -8 + 0x20 != 0) {
    Os_EnablePU(auStack_8,uRam0200f4e4);
    (*(code *)(*(uint *)(uRam0200f4e0 & 0xfffffffc) >> (uRam0200f4e0 & 3) * 8 |
              *(uint *)(uRam0200f4e0 & 0xfffffffc) << (uRam0200f4e0 & 3) * -8 + 0x20))
              (uRam0200f4ec,
               *(uint *)(uRam0200f4e8 & 0xfffffffc) >> (uRam0200f4e8 & 3) * 8 |
               *(uint *)(uRam0200f4e8 & 0xfffffffc) << (uRam0200f4e8 & 3) * -8 + 0x20);
    Os_DisablePU();
    return;
  }
  return;
}

