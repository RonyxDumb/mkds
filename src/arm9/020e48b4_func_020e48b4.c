/* Decompiled C draft; module arm9; ROM address 020e48b4. No matching claim. */
#include "types.h"
#include "deps/020e48b4_func_020e48b4.h"

void func_020e48b4(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020e48d8);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020e48dc,uVar1,0,0);
  BillboardModel_SomeFn(*puRam020e48dc);
  return;
}

