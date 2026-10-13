/* Decompiled C draft; module arm9; ROM address 02087ab0. No matching claim. */
#include "types.h"
#include "deps/02087ab0_func_02087ab0.h"

void func_02087ab0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar4 = puRam02087b70;
  puVar3 = puRam02087b6c;
  *puRam02087b6c = 0;
  puVar5 = puRam02087b74;
  *puRam02087b74 = *puVar4;
  uVar1 = (param_2 << 8) >> 0x10 & 0xffff;
  *puVar5 = (uint)(ushort)puVar4[1];
  *puVar3 = uVar1 << 0x10;
  uVar2 = (param_1 << 8) >> 0x10 & 0xffff;
  *puVar5 = *(uint *)((int)puVar4 + 6);
  *puVar5 = (uint)*(ushort *)((int)puVar4 + 10);
  *puVar3 = uVar2 | uVar1 << 0x10;
  *puVar5 = puVar4[3];
  *puVar5 = (uint)(ushort)puVar4[4];
  *puVar3 = uVar2;
  *puVar5 = *(uint *)((int)puVar4 + 0x12);
  *puVar5 = (uint)*(ushort *)((int)puVar4 + 0x16);
  return;
}

