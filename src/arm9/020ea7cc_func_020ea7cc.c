/* Decompiled C draft; module arm9; ROM address 020ea7cc. No matching claim. */
#include "types.h"
#include "deps/020ea7cc_func_020ea7cc.h"

void func_020ea7cc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar1 = func_02013344(uVar4,0);
  *piRam020ea848 = iVar1;
  if (param_2 < iVar1) {
    uVar2 = func_020d3c44();
    ModelBlock_SetPolygonId(uVar4,uVar2);
    Maybe_helper_01308c(uVar4,param_2);
  }
  func_020849d0(param_1);
  if (param_2 < (int)(*(uint *)((uint)piRam020ea848 & 0xfffffffc) >> ((uint)piRam020ea848 & 3) * 8 |
                     *(uint *)((uint)piRam020ea848 & 0xfffffffc) <<
                     ((uint)piRam020ea848 & 3) * -8 + 0x20)) {
    Maybe_helper_01308c(uVar4);
  }
  *piRam020ea848 = -1;
  return;
}

