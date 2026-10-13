/* Decompiled C draft; module arm9; ROM address 02018d94. No matching claim. */
#include "types.h"
#include "deps/02018d94_func_02018d94.h"

undefined4 *
func_02018d94(code *param_1,int param_2,int param_3,uint param_4,ushort param_5,ushort param_6)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  puVar1 = (undefined4 *)(*param_1)(0x4c);
  Mem_CpuFill8(puVar1,0,0x4c);
  *(short *)(puVar1 + 0xd) = (short)param_2;
  *(short *)((int)puVar1 + 0x36) = (short)param_3;
  uVar4 = (uint)(puVar1 + 0xe) & 3;
  uVar3 = *(uint *)((uint)(puVar1 + 0xe) & 0xfffffffc);
  puVar1[0xe] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffffffc0 | param_5 & 0x3f;
  uVar4 = (uint)(puVar1 + 0xe) & 3;
  uVar3 = *(uint *)((uint)(puVar1 + 0xe) & 0xfffffffc);
  puVar1[0xe] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffff03f |
                (param_6 & 0x3f) << 6;
  uVar4 = (uint)(puVar1 + 0xe) & 3;
  uVar3 = *(uint *)((uint)(puVar1 + 0xe) & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  puVar1[0xe] = uVar4 & 0xfffc0fff | (uVar4 & 0x3f) << 0xc;
  uVar4 = (uint)(puVar1 + 0xe) & 3;
  uVar3 = *(uint *)((uint)(puVar1 + 0xe) & 0xfffffffc);
  puVar1[0xe] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xff03ffff |
                (param_4 & 0x3f) << 0x12;
  uVar4 = (uint)(puVar1 + 0xe) & 3;
  uVar3 = *(uint *)((uint)(puVar1 + 0xe) & 0xfffffffc);
  puVar1[0xe] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfeffffff;
  uVar4 = (uint)(puVar1 + 0xe) & 3;
  uVar3 = *(uint *)((uint)(puVar1 + 0xe) & 0xfffffffc);
  puVar1[0xe] = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x1ffffff;
  *puVar1 = param_1;
  puVar1[2] = 0;
  puVar1[5] = 0;
  puVar1[8] = 0;
  puVar1[1] = 0;
  puVar1[4] = 0;
  puVar1[7] = 0;
  puVar1[0xf] = 0;
  *(undefined2 *)(puVar1 + 0x12) = 0;
  iVar2 = (*param_1)(param_2 * 0x9c);
  Mem_CpuFill8(iVar2,0,param_2 * 0x9c);
  iVar5 = 0;
  if (0 < param_2) {
    do {
      func_0201e494(puVar1 + 4,iVar2);
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 0x9c;
    } while (iVar5 < param_2);
  }
  iVar2 = (*param_1)(param_3 * 0x44);
  Mem_CpuFill8(iVar2,0,param_3 * 0x44);
  iVar5 = 0;
  if (0 < param_3) {
    do {
      func_0201e494(puVar1 + 7,iVar2);
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 0x44;
    } while (iVar5 < param_3);
  }
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  *(undefined2 *)((int)puVar1 + 0x32) = 0;
  *(undefined2 *)(puVar1 + 0xc) = *(undefined2 *)((int)puVar1 + 0x32);
  return puVar1;
}

