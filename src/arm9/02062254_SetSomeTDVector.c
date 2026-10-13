/* Decompiled C draft; module arm9; ROM address 02062254. No matching claim. */
#include "types.h"
#include "deps/02062254_SetSomeTDVector.h"

void SetSomeTDVector(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam02062280;
  *(ushort *)
   ((*(uint *)(uRam02062280 & 0xfffffffc) >> (uRam02062280 & 3) * 8 |
    *(uint *)(uRam02062280 & 0xfffffffc) << (uRam02062280 & 3) * -8 + 0x20) + 0x40) =
       (ushort)(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8) |
       (ushort)(*(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(ushort *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x42) =
       (ushort)(uVar3 >> uVar1 * 8) | (ushort)(uVar3 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  *(ushort *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x44) =
       (ushort)(uVar3 >> uVar1 * 8) | (ushort)(uVar3 << uVar1 * -8 + 0x20);
  return;
}

