/* Decompiled C draft; module arm9; ROM address 02087934. No matching claim. */
#include "types.h"
#include "deps/02087934_func_02087934.h"

void func_02087934(undefined4 param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = uRam020879d0;
  *puRam020879cc = param_1;
  uVar3 = uRam020879dc;
  puVar2 = puRam020879d8;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *puRam020879d8 =
       *(uint *)(uRam020879d4 & 0xfffffffc) >> (uRam020879d4 & 3) * 8 |
       *(uint *)(uRam020879d4 & 0xfffffffc) << (uRam020879d4 & 3) * -8 + 0x20;
  *puVar2 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  puVar4 = puRam020879e0;
  *puVar2 = uVar3;
  puVar2 = puRam020879e4;
  *puRam020879e4 = *puVar4;
  *puVar2 = (uint)(ushort)puVar4[1];
  *puVar2 = *(uint *)((int)puVar4 + 6);
  *puVar2 = (uint)*(ushort *)((int)puVar4 + 10);
  *puVar2 = puVar4[3];
  *puVar2 = (uint)(ushort)puVar4[4];
  *puVar2 = *(uint *)((int)puVar4 + 0x12);
  *puVar2 = (uint)*(ushort *)((int)puVar4 + 0x16);
  return;
}

