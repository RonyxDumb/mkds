/* Decompiled C draft; module arm9; ROM address 020a5744. No matching claim. */
#include "types.h"
#include "deps/020a5744_func_020a5744.h"

void func_020a5744(uint param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  func_02100138(0x6a);
  iVar2 = func_0209bbfc();
  if (iVar2 != 0) {
    if (param_3 == 0) {
      *(uint *)(iVar2 + 4) =
           *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
      uVar1 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(uint *)(iVar2 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x14000;
      uVar1 = param_1 + 8 & 3;
      uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
      *(uint *)(iVar2 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 0x18) = 0;
      *(undefined4 *)(iVar2 + 0xa0) = 0;
      *(undefined4 *)(iVar2 + 0xa4) = 0;
      *(undefined4 *)(iVar2 + 0xe0) = 1;
    }
    else {
      *(uint *)(iVar2 + 4) =
           *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
      uVar1 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(uint *)(iVar2 + 8) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x32000;
      uVar1 = param_1 + 8 & 3;
      uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
      *(uint *)(iVar2 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 0x2800;
      *(undefined4 *)(iVar2 + 0x18) = 0;
      *(undefined4 *)(iVar2 + 0xa0) = 0;
      uVar1 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      *(uint *)(iVar2 + 0xa4) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x14000;
      *(undefined4 *)(iVar2 + 0xe0) = 0;
    }
    *(undefined4 *)(iVar2 + 0xa8) = 0;
    *(undefined4 *)(iVar2 + 0xc0) = 0;
    *(undefined4 *)(iVar2 + 0xc4) = param_2;
    *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) & 0xfffe;
    *(ushort *)(iVar2 + 2) = *(ushort *)(iVar2 + 2) & 0xffdf;
    func_020a1218(1);
    uVar1 = iVar2 + 0x94U & 3;
    uVar3 = *(uint *)(iVar2 + 0x94U & 0xfffffffc);
    func_0210b98c(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0x138);
    return;
  }
  return;
}

