/* Decompiled C draft; module arm9; ROM address 020ea8a8. No matching claim. */
#include "types.h"
#include "deps/020ea8a8_func_020ea8a8.h"

void func_020ea8a8(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar1 = func_02013344(uVar5,0);
  if (param_4 < iVar1) {
    uVar2 = func_02013378(uVar5,0);
    uVar3 = func_020d3c44();
    ModelBlock_SetPolygonId(uVar5,uVar3);
    Maybe_helper_01308c(uVar5,param_4);
    func_020849f8(param_1,param_2,param_3);
    ModelBlock_SetPolygonId(uVar5,uVar2);
    Maybe_helper_01308c(uVar5,iVar1);
    return;
  }
  func_020849f8(param_1,param_2,param_3);
  return;
}

