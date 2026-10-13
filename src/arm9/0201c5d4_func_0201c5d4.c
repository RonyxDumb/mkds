/* Decompiled C draft; module arm9; ROM address 0201c5d4. No matching claim. */
#include "types.h"
#include "deps/0201c5d4_func_0201c5d4.h"

void func_0201c5d4(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar3 = puRam0201c684;
  uVar7 = uRam0201c680;
  uVar1 = (uint)(param_2 << 8) >> 0x10;
  uVar2 = (uint)(param_1 << 8) >> 0x10;
  *puRam0201c67c = 1;
  puVar4 = puRam0201c688;
  uVar6 = uVar7 & (param_3 + -0x1000) * 0x10000 >> 0x16;
  uVar8 = uVar7 & (param_4 + 0x1000) * 0x10000 >> 0x16;
  uVar9 = uVar7 & (param_3 + 0x1000) * 0x10000 >> 0x16;
  uVar7 = uVar7 & (param_4 + -0x1000) * 0x10000 >> 0x16;
  *puVar3 = 0;
  *puVar4 = uVar6 | uVar8 << 0x14;
  *puVar3 = uVar2;
  *puVar4 = uVar9 | uVar8 << 0x14;
  *puVar3 = uVar2 | uVar1 << 0x10;
  *puVar4 = uVar9 | uVar7 << 0x14;
  *puVar3 = uVar1 << 0x10;
  puVar5 = puRam0201c68c;
  *puVar4 = uVar6 | uVar7 << 0x14;
  *puVar5 = 0;
  return;
}

