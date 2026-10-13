/* Decompiled C draft; module arm9; ROM address 020ac890. No matching claim. */
#include "types.h"
#include "deps/020ac890_func_020ac890.h"

void func_020ac890(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uStack_40;
  undefined1 auStack_3c [12];
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  uint uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uVar4 = param_2 + 0xacU & 3;
  uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  if (*(short *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 900) != 0) {
    uStack_40 = 0x1e;
    func_01ff9048(0x14,&uStack_40,1);
    uVar1 = func_020e6cf8(param_2 + 4);
    func_01ff9048(0x19,uVar1,0xc);
    uVar4 = param_2 + 0xacU & 3;
    uVar3 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    iStack_2c = func_020a23a0(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    iStack_2c = iStack_2c >> 4;
    uStack_30 = 0;
    uStack_28 = 0;
    func_01ff9048(0x1c,&uStack_30,3);
    uVar4 = param_2 + 0xa0U & 3;
    uVar3 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if (uVar4 != 0x1000) {
      uStack_24 = uVar4;
      uStack_20 = uVar4;
      uStack_1c = uVar4;
      func_01ff9048(0x1b,&uStack_24,3);
    }
    func_01ff9048(0x1b,param_2 + 0x1c,3);
    iVar2 = GetGlobalHD4();
    VecFx32_Subtract(param_2 + 4,iVar2 + 0x24,auStack_3c);
    uStack_18 = VecFx32_Norm(auStack_3c);
    uStack_14 = uStack_18;
    uStack_10 = uStack_18;
    func_01ff9048(0x1b,&uStack_18,3);
    DrawObject2D3D(param_1,*(uint *)(uRam020ac9ac & 0xfffffffc) >> (uRam020ac9ac & 3) * 8 |
                           *(uint *)(uRam020ac9ac & 0xfffffffc) << (uRam020ac9ac & 3) * -8 + 0x20,
                   param_2);
    return;
  }
  return;
}

