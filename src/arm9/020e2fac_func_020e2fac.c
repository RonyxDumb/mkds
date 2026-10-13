/* Decompiled C draft; module arm9; ROM address 020e2fac. No matching claim. */
#include "types.h"
#include "deps/020e2fac_func_020e2fac.h"

void func_020e2fac(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020e2fd8);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020e2fdc);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020e2fe0,uVar1,uVar2,0);
  BillboardModel_SomeFn(*puRam020e2fe0);
  return;
}

