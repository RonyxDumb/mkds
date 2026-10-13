/* Decompiled C draft; module arm9; ROM address 0214c1bc. No matching claim. */
#include "types.h"
#include "deps/0214c1bc_func_0214c1bc.h"

void func_0214c1bc(void)

{
  undefined4 *puVar1;
  
  if ((*(uint *)(uRam0214c208 & 0xfffffffc) >> (uRam0214c208 & 3) * 8 |
      *(uint *)(uRam0214c208 & 0xfffffffc) << (uRam0214c208 & 3) * -8 + 0x20) != 0xffffffff) {
    MI_WaitDma();
  }
  func_021493b0(*(uint *)((uint)puRam0214c20c & 0xfffffffc) >> ((uint)puRam0214c20c & 3) * 8 |
                *(uint *)((uint)puRam0214c20c & 0xfffffffc) << ((uint)puRam0214c20c & 3) * -8 + 0x20
               );
  puVar1 = puRam0214c210;
  *puRam0214c20c = 0;
  *puVar1 = 0;
  return;
}

