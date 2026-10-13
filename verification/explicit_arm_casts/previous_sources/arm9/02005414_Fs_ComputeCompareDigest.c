/* Decompiled C draft; module arm9; ROM address 02005414. No matching claim. */
#include "types.h"
#include "deps/02005414_Fs_ComputeCompareDigest.h"

bool Fs_ComputeCompareDigest(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint local_68;
  undefined1 local_64 [20];
  undefined1 auStack_50 [64];
  
  puVar4 = &local_68;
  Mem_CpuFill8(local_64,0,0x14);
  Mem_CpuCopy8(*(uint *)(uRam020054b0 & 0xfffffffc) >> (uRam020054b0 & 3) * 8 |
               *(uint *)(uRam020054b0 & 0xfffffffc) << (uRam020054b0 & 3) * -8 + 0x20,auStack_50,
               *(uint *)(uRam020054b4 & 0xfffffffc) >> (uRam020054b4 & 3) * 8 |
               *(uint *)(uRam020054b4 & 0xfffffffc) << (uRam020054b4 & 3) * -8 + 0x20);
  local_68 = *(uint *)(uRam020054b4 & 0xfffffffc) >> (uRam020054b4 & 3) * 8 |
             *(uint *)(uRam020054b4 & 0xfffffffc) << (uRam020054b4 & 3) * -8 + 0x20;
  func_02150808(local_64,param_2,param_3,auStack_50);
  uVar3 = 0;
  do {
    puVar4 = puVar4 + 1;
    uVar1 = param_1 + uVar3 & 3;
    uVar2 = *(uint *)(param_1 + uVar3 & 0xfffffffc);
    if (*puVar4 != (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) break;
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x14);
  return uVar3 == 0x14;
}

