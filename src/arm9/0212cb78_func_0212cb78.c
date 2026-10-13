/* Decompiled C draft; module arm9; ROM address 0212cb78. No matching claim. */
#include "types.h"
#include "deps/0212cb78_func_0212cb78.h"

void func_0212cb78(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  if (*(uint *)(uRam0212cbd4 & 0xfffffffc) >> (uRam0212cbd4 & 3) * 8 != 0 ||
      *(uint *)(uRam0212cbd4 & 0xfffffffc) << (uRam0212cbd4 & 3) * -8 + 0x20 != 0) {
    uVar5 = uRam0212cbd4 + 0x2c & 3;
    uVar4 = *(uint *)(uRam0212cbd4 + 0x2c & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    if (-1 < (int)uVar5) {
      param_3 = 1 << (uVar5 & 0xff);
    }
    uVar4 = uRam0212cbd4 + 0x24 & 3;
    uVar2 = *(uint *)(uRam0212cbd4 + 0x24 & 0xfffffffc);
    uVar1 = uRam0212cbd4 + 0x28 & 3;
    uVar6 = *(uint *)(uRam0212cbd4 + 0x28 & 0xfffffffc);
    if (-1 >= (int)uVar5) {
      param_3 = 0;
    }
    SND_StopTimer(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20,
                  uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,param_3,0);
    uVar3 = func_02021114();
    Sound_FlushCommand(1);
    func_02021154(uVar3);
    return;
  }
  return;
}

