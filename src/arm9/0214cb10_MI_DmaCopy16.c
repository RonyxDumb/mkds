/* Decompiled C draft; module arm9; ROM address 0214cb10. No matching claim. */
#include "types.h"
#include "deps/0214cb10_MI_DmaCopy16.h"

void MI_DmaCopy16(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  if (param_4 != 0) {
    MIi_CheckDma0SourceAddress(param_1,param_2,param_4,0);
    uVar1 = iRam0214cb84 + (param_1 * 3 + 2) * 4;
    do {
    } while (((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) & 0x80000000) != 0);
    func_01fffec4(param_1,param_2,param_3,param_4 >> 1 | 0x80000000);
    do {
    } while (((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) & 0x80000000) != 0);
    return;
  }
  return;
}

