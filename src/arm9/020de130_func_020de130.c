/* Decompiled C draft; module arm9; ROM address 020de130. No matching claim. */
#include "types.h"
#include "deps/020de130_func_020de130.h"

void func_020de130(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb(uRam020de174);
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020de178,uVar1,0,0);
  BillboardModel_SomeFn(*puRam020de178);
  iVar2 = FindFileBuffer_CRS_CST_from_thumb(uRam020de17c);
  if (iVar2 != 0) {
    BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(puRam020de180,iVar2,0,0);
    BillboardModel_SomeFn(*puRam020de180);
  }
  return;
}

