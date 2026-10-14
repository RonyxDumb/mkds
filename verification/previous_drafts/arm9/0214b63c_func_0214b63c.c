/* Decompiled C draft; module arm9; ROM address 0214b63c. No matching claim. */
#include "types.h"
#include "deps/0214b63c_func_0214b63c.h"

void func_0214b63c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((*(uint *)(uRam0214b690 & 0xfffffffc) >> (uRam0214b690 & 3) * 8 |
      *(uint *)(uRam0214b690 & 0xfffffffc) << (uRam0214b690 & 3) * -8 + 0x20) != 0xffffffff) {
    MI_WaitDma();
  }
  func_021498a0(*(uint *)((uint)puRam0214b694 & 0xfffffffc) >> ((uint)puRam0214b694 & 3) * 8 |
                *(uint *)((uint)puRam0214b694 & 0xfffffffc) << ((uint)puRam0214b694 & 3) * -8 + 0x20
               );
  puVar2 = puRam0214b69c;
  puVar1 = puRam0214b698;
  *puRam0214b694 = 0;
  *puVar1 = 0;
  *puVar2 = 0;
  return;
}

