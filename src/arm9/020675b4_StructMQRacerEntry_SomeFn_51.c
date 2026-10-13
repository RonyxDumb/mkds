/* Decompiled C draft; module arm9; ROM address 020675b4. No matching claim. */
#include "types.h"
#include "deps/020675b4_StructMQRacerEntry_SomeFn_51.h"

bool StructMQRacerEntry_SomeFn_51(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = func_0208c5b8(*(undefined2 *)(param_1 + 0x74));
  uVar6 = iVar2 + 0x34U & 3;
  uVar3 = *(uint *)(iVar2 + 0x34U & 0xfffffffc);
  uVar1 = iVar2 + 0x40U & 3;
  uVar5 = *(uint *)(iVar2 + 0x40U & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 == 0 && uVar3 << uVar6 * -8 + 0x20 == 0) {
    uVar6 = iVar2 + 0x38U & 3;
    uVar3 = *(uint *)(iVar2 + 0x38U & 0xfffffffc);
    uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  }
  else {
    uVar6 = 0;
  }
  uVar3 = iVar2 + 0x3cU & 3;
  uVar4 = *(uint *)(iVar2 + 0x3cU & 0xfffffffc);
  return (uVar5 >> uVar1 * 8 != 0 || uVar5 << uVar1 * -8 + 0x20 != 0) ||
         ((uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) || uVar6 != 0);
}

