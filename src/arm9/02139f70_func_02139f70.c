/* Decompiled C draft; module arm9; ROM address 02139f70. No matching claim. */
#include "types.h"
#include "deps/02139f70_func_02139f70.h"

uint func_02139f70(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    return param_1;
  }
  uVar6 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff;
  if (uVar6 == 0) {
    return param_1;
  }
  uVar1 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff;
  if (uVar1 != 0) {
    uVar4 = param_1 + 1;
    do {
      uVar2 = param_2 + 1;
      uVar3 = uVar4;
      if (uVar1 == uVar6) {
        do {
          uVar5 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                  *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) & 0xff;
          uVar1 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xff;
          if (uVar1 != uVar5) break;
          uVar2 = uVar2 + 1;
          uVar3 = uVar3 + 1;
        } while (uVar1 != 0);
        if (uVar5 == 0) {
          return uVar4 - 1;
        }
      }
      uVar1 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xff;
      uVar4 = uVar4 + 1;
    } while (uVar1 != 0);
  }
  return 0;
}

