/* Decompiled C draft; module arm9; ROM address 020f0d04. No matching claim. */
#include "types.h"
#include "deps/020f0d04_func_020f0d04.h"

void func_020f0d04(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  
  uVar4 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if ((*(ushort *)(param_1 + 0x78) & 0xf00) == 0) {
    iVar3 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) * 0xa8;
    uVar4 = (*(uint *)(uRam020f0df4 & 0xfffffffc) >> (uRam020f0df4 & 3) * 8 |
            *(uint *)(uRam020f0df4 & 0xfffffffc) << (uRam020f0df4 & 3) * -8 + 0x20) + iVar3 + 0x48;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    pcVar5 = (code *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    uVar1 = (*pcVar5)(0,param_1,1);
    (*pcVar5)(uVar1,param_1,0);
    uVar4 = (*(uint *)(uRam020f0df4 & 0xfffffffc) >> (uRam020f0df4 & 3) * 8 |
            *(uint *)(uRam020f0df4 & 0xfffffffc) << (uRam020f0df4 & 3) * -8 + 0x20) + iVar3 + 0x50;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    (*(code *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20))(param_1);
  }
  else {
    uVar1 = func_020fe4c0(0,param_1,1);
    func_020fe4c0(uVar1,param_1,0);
    func_020fe4b4(param_1);
    if ((*(ushort *)(param_1 + 0x78) & 0x800) != 0) {
      CARD_func_0054__mkds_f70f0(param_1);
    }
    if ((*(ushort *)(param_1 + 0x78) & 0x400) != 0) {
      CARD_func_0054__mkds_f705c(param_1);
    }
    if ((*(ushort *)(param_1 + 0x78) & 0x200) != 0) {
      func_020f7600(param_1);
    }
    if ((*(ushort *)(param_1 + 0x78) & 0x100) != 0) {
      func_020f73fc(param_1);
    }
  }
  uVar4 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20 | 0x20000000;
  return;
}

