/* Decompiled C draft; module arm9; ROM address 02030ae8. No matching claim. */
#include "types.h"
#include "deps/02030ae8_func_02030ae8.h"

void func_02030ae8(void)

{
  TextSystem_SetSomeValues_from_thumb(0,0);
  func_0212b91c();
  Mem_DestroyHeap(*(undefined4 *)(*piRam02030b10 + iRam02030b14));
  *piRam02030b10 = 0;
  return;
}

