/* Decompiled C draft; module arm9; ROM address 0207aec8. No matching claim. */
#include "types.h"
#include "deps/0207aec8_func_0207aec8.h"

void func_0207aec8(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_14;
  
  if ((*(ushort *)(param_1 + 0x70) & 1) != 0) {
    uStack_20 = 0x1e;
    func_01ff9048(0x14,&uStack_20,1);
    func_01ff9048(0x19,param_2,0xc);
    if (param_3 != 0) {
      uVar1 = param_3 + 8 & 3;
      uVar2 = *(uint *)(param_3 + 8 & 0xfffffffc);
      uStack_14 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar1 = param_3 + 4 & 3;
      uVar2 = *(uint *)(param_3 + 4 & 0xfffffffc);
      uStack_18 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uStack_1c = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
                  *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
      func_01ff9048(0x1b,&uStack_1c,3);
    }
    StructAD00Sh_SomeFn_3(param_1,*(ushort *)(param_1 + 0x6e) & 0xff);
    uVar1 = param_1 + 0x58U & 3;
    uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    uVar1 = iRam0207afa4 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1);
    StructAD00Sh_SomeFn_4
              (param_1,*(ushort *)(param_1 + 0x6e) & 0xff,*(ushort *)(param_1 + 0x6c) & 0xff);
    uVar1 = param_1 + 0x58U & 3;
    uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    uVar1 = iRam0207afa4 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1);
    return;
  }
  return;
}

