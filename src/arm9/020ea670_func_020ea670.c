/* Decompiled C draft; module arm9; ROM address 020ea670. No matching claim. */
#include "types.h"
#include "deps/020ea670_func_020ea670.h"

void func_020ea670(int param_1,int param_2)

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
  *piRam020ea734 = iVar1;
  if (param_2 < iVar1) {
    uVar2 = func_020d3c44();
    ModelBlock_SetPolygonId(uVar5,uVar2);
    Maybe_helper_01308c(uVar5,param_2);
  }
  uVar2 = uRam020ea73c;
  uVar4 = uVar5 + 8 & 3;
  uVar3 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  iVar1 = uVar5 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  uVar4 = iVar1 + (uint)*(ushort *)(iVar1 + 10) + 8;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = iVar1 + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0xc;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *puRam020ea738 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  StructML_SetSomeFields(param_1,uVar2,0,4,3);
  func_020849d0(param_1);
  if (param_2 < (int)(*(uint *)((uint)piRam020ea734 & 0xfffffffc) >> ((uint)piRam020ea734 & 3) * 8 |
                     *(uint *)((uint)piRam020ea734 & 0xfffffffc) <<
                     ((uint)piRam020ea734 & 3) * -8 + 0x20)) {
    Maybe_helper_01308c(uVar5);
  }
  *piRam020ea734 = -1;
  return;
}

