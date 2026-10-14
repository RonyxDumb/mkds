/* Decompiled C draft; module arm9; ROM address 02020650. No matching claim. */
#include "types.h"
#include "deps/02020650_ComputeProfileInfoCrcImpl.h"

void ComputeProfileInfoCrcImpl(int param_1,uint *param_2,byte *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
          *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
  uVar4 = 0;
  if (param_4 != 0) {
    do {
      uVar4 = uVar4 + 1;
      uVar3 = param_1 + ((uVar2 ^ *param_3) & 0xff) * 4;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      param_3 = param_3 + 1;
      uVar2 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) ^ uVar2 >> 8;
    } while (uVar4 < param_4);
  }
  *param_2 = uVar2;
  return;
}

