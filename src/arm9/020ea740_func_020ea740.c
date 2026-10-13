/* Decompiled C draft; module arm9; ROM address 020ea740. No matching claim. */
#include "types.h"
#include "deps/020ea740_func_020ea740.h"

void func_020ea740(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar1 = func_02013344(uVar5,0);
  *piRam020ea7c8 = iVar1;
  if (param_2 < iVar1) {
    uVar2 = func_020d3c44();
    ModelBlock_SetPolygonId(uVar5,uVar2);
    Maybe_helper_01308c(uVar5,param_2);
  }
  uVar4 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  func_0201290c(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0,0,1);
  if (param_2 < (int)(*(uint *)((uint)piRam020ea7c8 & 0xfffffffc) >> ((uint)piRam020ea7c8 & 3) * 8 |
                     *(uint *)((uint)piRam020ea7c8 & 0xfffffffc) <<
                     ((uint)piRam020ea7c8 & 3) * -8 + 0x20)) {
    Maybe_helper_01308c(uVar5);
  }
  *piRam020ea7c8 = -1;
  return;
}

