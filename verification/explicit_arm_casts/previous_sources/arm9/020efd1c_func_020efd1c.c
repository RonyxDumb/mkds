/* Decompiled C draft; module arm9; ROM address 020efd1c. No matching claim. */
#include "types.h"
#include "deps/020efd1c_func_020efd1c.h"

void func_020efd1c(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar5;
  uint uVar4;
  
  uVar1 = param_1 + 0x1fcU & 3;
  uVar3 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc);
  uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 + 0x48 & 3;
  uVar3 = *(uint *)(uVar4 + 0x48 & 0xfffffffc);
  iVar5 = iRam020efd80;
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0) {
    iVar5 = uVar4 + 0x15c;
  }
  uVar2 = StructMQRacerEntry_SomeFn_71(uVar4);
  uVar1 = uVar4 + 0x590 & 3;
  uVar3 = *(uint *)(uVar4 + 0x590 & 0xfffffffc);
  func_020f98a0(param_2,uVar4 + 0x98,iVar5,(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x40,
                uVar2);
  uVar1 = uVar4 + 0x48 & 3;
  uVar3 = *(uint *)(uVar4 + 0x48 & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0) {
    uVar1 = param_2 + 0x74U & 3;
    uVar3 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x40000000;
  }
  return;
}

