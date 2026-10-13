/* Decompiled C draft; module arm9; ROM address 02013a88. No matching claim. */
#include "types.h"
#include "deps/02013a88_BMA0_LoadRawData.h"

int BMA0_LoadRawData(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe)) * param_2 +
          param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return param_1 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

