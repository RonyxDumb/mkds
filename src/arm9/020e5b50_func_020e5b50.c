/* Decompiled C draft; module arm9; ROM address 020e5b50. No matching claim. */
#include "types.h"
#include "deps/020e5b50_func_020e5b50.h"

void func_020e5b50(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020e5b7c);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020e5b80);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020e5b84,uVar1,uVar2,0);
  BillboardModel_SomeFn(*puRam020e5b84);
  return;
}

