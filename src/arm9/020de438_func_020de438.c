/* Decompiled C draft; module arm9; ROM address 020de438. No matching claim. */
#include "types.h"
#include "deps/020de438_func_020de438.h"

void func_020de438(void)

{
  undefined4 uVar1;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020de478);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020de47c,uVar1,0,0);
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020de480);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020de484,uVar1,0,0);
  BillboardModel_SomeFn(*puRam020de47c);
  BillboardModel_SomeFn(*puRam020de484);
  return;
}

