/* Decompiled C draft; module arm9; ROM address 02041bb0. No matching claim. */
#include "types.h"
#include "deps/02041bb0_func_02041bb0.h"

void func_02041bb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *(byte *)((*(uint *)(uRam02041db8 & 0xfffffffc) >> (uRam02041db8 & 3) * 8 |
                    *(uint *)(uRam02041db8 & 0xfffffffc) << (uRam02041db8 & 3) * -8 + 0x20) + 0x3d0)
          - 1 & 0xffff;
  iVar3 = func_0205d27c(param_3);
  uVar6 = *(uint *)(uRam02041db8 & 0xfffffffc) >> (uRam02041db8 & 3) * 8 |
          *(uint *)(uRam02041db8 & 0xfffffffc) << (uRam02041db8 & 3) * -8 + 0x20;
  uVar4 = uVar6 + 0xc & 3;
  uVar5 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
  uVar2 = iVar3 - 1U & 0xffff;
  if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 6) {
    func_02041dc8(param_1,param_2,0,0,0);
    return;
  }
  uVar4 = uVar6 + 8 & 3;
  uVar5 = *(uint *)(uVar6 + 8 & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if (uVar4 == 1) {
    func_02041dc8(param_1,param_2,0,0x800,0);
    return;
  }
  if (uVar4 == 2) {
    func_02041dc8(param_1,param_2,
                  uVar2 + *(byte *)((*(uint *)(uRam02041dbc & 0xfffffffc) >> (uRam02041dbc & 3) * 8
                                    | *(uint *)(uRam02041dbc & 0xfffffffc) <<
                                      (uRam02041dbc & 3) * -8 + 0x20) + 0x4f8) & 7,0,0);
    return;
  }
  if (uVar4 == 4) {
    if (1 < *(byte *)(uVar6 + 0x3d0)) {
      func_02041dc8(param_1,param_2,param_3,(param_3 * -2 + 1) * 0x14000 + 0x800,0);
      return;
    }
    func_02041dc8(param_1,param_2,0,0x800,0);
    return;
  }
  uVar6 = (uint)*(byte *)(iRam02041dc0 + uVar1 * 2);
  uVar5 = uVar2;
  uVar4 = uVar6;
  if (uVar6 <= uVar2) {
    uVar4 = (uint)*(byte *)(iRam02041dc4 + uVar1 * 2);
    uVar5 = uVar2 - uVar6;
  }
  if ((uVar4 & 1) == 1) {
    iVar3 = (uVar5 - ((int)uVar4 >> 1)) * 2;
  }
  else {
    iVar3 = (uVar5 * 2 + 1) - uVar4;
  }
  if ((uVar6 <= uVar2) && (uVar6 == *(byte *)(iRam02041dc4 + uVar1 * 2))) {
    iVar3 = iVar3 + 1;
  }
  func_02041dc8(param_1,param_2,0,iVar3 * 0x11000,uVar2 * 0x19000 + (uint)(uVar6 <= uVar2) * 0x14000
               );
  return;
}

