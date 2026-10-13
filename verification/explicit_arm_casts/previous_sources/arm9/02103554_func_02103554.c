/* Decompiled C draft; module arm9; ROM address 02103554. No matching claim. */
#include "types.h"
#include "deps/02103554_func_02103554.h"

void func_02103554(void)

{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  uVar1 = FormatFindMapObjFileBuffer_from_thumb();
  BillboardModel_AllocateFromNsbmdNsbtp_from_thumb(local_8,uVar1,0,0);
  BillboardModel_SomeFn(local_8[0]);
  func_0210340c(uRam02103594,local_8[0]);
  return;
}

