/* Decompiled C draft; module arm9; ROM address 0214d3d8. No matching claim. */
#include "types.h"
#include "deps/0214d3d8_MIi_CardDmaCopy32.h"

void MIi_CardDmaCopy32(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  MIi_CheckAnotherAutoDMA(param_1,0xffffffff);
  MIi_CheckDma0SourceAddress(param_1,param_2,param_4,0x1000000);
  if (param_4 != 0) {
    uVar3 = iRam0214d45c + (param_1 * 3 + 2) * 4;
    do {
      uVar1 = uVar3 & 3;
      uVar2 = *(uint *)(uVar3 & 0xfffffffc);
    } while (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x80000000) != 0);
    func_01ffff38(param_1,param_2,param_3,uRam0214d460);
    return;
  }
  return;
}

