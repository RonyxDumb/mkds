/* Decompiled C draft; module arm9; ROM address 02079038. No matching claim. */
#include "types.h"
#include "deps/02079038_Model_CreateFromNsbmdNsbtx2_from_thumb.h"

void Model_CreateFromNsbmdNsbtx2_from_thumb(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Model_CreateFromNsbmdNsbtx();
  Model_Render(param_1,3);
  ModelBlock_SomeMatFn(iVar1,1);
  uVar2 = Dict_SomeFn_0(iVar1 + *(int *)(iVar1 + 8) + 4,uRam02079074);
  func_02013468(iVar1,uVar2,0);
  return;
}

