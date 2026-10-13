/* Decompiled C draft; module arm9; ROM address 020da5f0. No matching claim. */
#include "types.h"
#include "deps/020da5f0_func_020da5f0.h"

void func_020da5f0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020da61c);
  uVar2 = FormatFindMapObjFileBuffer_from_thumb(uRam020da620);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020da624,uVar1,uVar2,0);
  BillboardModel_SomeFn(*puRam020da624);
  return;
}

