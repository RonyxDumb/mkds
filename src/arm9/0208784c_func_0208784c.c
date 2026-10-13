/* Decompiled C draft; module arm9; ROM address 0208784c. No matching claim. */
#include "types.h"
#include "deps/0208784c_func_0208784c.h"

void func_0208784c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  
  puVar6 = puRam02087910;
  puVar5 = puRam0208790c;
  *puRam0208790c = uRam02087908;
  puVar7 = puRam02087914;
  uVar1 = (param_2 << 8) >> 0x10 & 0xffff;
  uVar2 = (param_1 << 8) >> 0x10 & 0xffff;
  uVar4 = puVar6[1];
  *puRam02087914 = *puVar6;
  *puVar7 = (uint)(ushort)uVar4;
  *puVar5 = uVar1 << 0x10 | 6;
  uVar3 = *(ushort *)((int)puVar6 + 10);
  *puVar7 = *(uint *)((int)puVar6 + 6);
  *puVar7 = (uint)uVar3;
  *puVar5 = uVar2 | uVar1 << 0x10;
  uVar1 = puVar6[4];
  *puVar7 = puVar6[3];
  *puVar7 = (uint)(ushort)uVar1;
  *puVar5 = uVar2 | 0x60000;
  uVar3 = *(ushort *)((int)puVar6 + 0x16);
  *puVar7 = *(uint *)((int)puVar6 + 0x12);
  *puVar7 = (uint)uVar3;
  return;
}

