/* Decompiled C draft; module arm9; ROM address 0214ce08. No matching claim. */
#include "types.h"
#include "deps/0214ce08_func_0214ce08.h"

void func_0214ce08(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  iVar1 = iRam0214cec0;
  uVar5 = iRam0214cec0 + 0xcU & 3;
  uVar4 = *(uint *)(iRam0214cec0 + 0xcU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (uVar5 == 0) {
    return;
  }
  uVar4 = iRam0214cec0 + 8U & 3;
  uVar6 = *(uint *)(iRam0214cec0 + 8U & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  if (0x1d7 < uVar5) {
    uVar5 = 0x1d8;
  }
  uVar6 = iRam0214cec0 + 0xcU & 3;
  uVar2 = *(uint *)(iRam0214cec0 + 0xcU & 0xfffffffc);
  iVar3 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - uVar5;
  *(int *)(iRam0214cec0 + 0xc) = iVar3;
  *(uint *)(iVar1 + 8) = uVar4 + uVar5;
  if (iVar3 != 0) {
    uVar6 = iVar1 + 4U & 3;
    uVar2 = *(uint *)(iVar1 + 4U & 0xfffffffc);
    func_01ffff38(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,uVar4,uRam0214cec8,
                  uRam0214cecc | uVar5 >> 2);
    SetIF(0x200000);
    return;
  }
  uVar6 = iVar1 + 4U & 3;
  uVar2 = *(uint *)(iVar1 + 4U & 0xfffffffc);
  OSi_EnterDmaCallback(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,uRam0214cec4,0);
  uVar6 = iRam0214cec0 + 4U & 3;
  uVar2 = *(uint *)(iRam0214cec0 + 4U & 0xfffffffc);
  func_01ffff38(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20,uVar4,uRam0214cec8,
                uVar5 >> 2 | 0xc4400000);
  SetIF(0x200000);
  return;
}

