/* Decompiled C draft; module arm9; ROM address 020dfd64. No matching claim. */
#include "types.h"
#include "deps/020dfd64_func_020dfd64.h"

void func_020dfd64(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  StateDualHandler_Create(param_1 + 0x80,uRam020dfea4,3,param_1);
  uVar1 = _s32_div_f((int)*(short *)(param_2 + 0x28) << 0xc,100);
  puVar3 = (undefined4 *)(param_1 + iRam020dfea8);
  *puVar3 = uVar1;
  func_020d7da8(param_1 + iRam020dfeac,param_2,*puVar3);
  *(undefined2 *)(param_1 + iRam020dfeb0) = 0;
  puVar5 = (undefined4 *)(param_1 + 0x28);
  puVar3 = (undefined4 *)(param_1 + 0xa0);
  iVar4 = 4;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    *puVar3 = uVar1;
    puVar3[1] = uVar2;
    puVar3 = puVar3 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar3 = *puVar5;
  *(undefined4 *)(param_1 + iRam020dfeb4) = 0;
  *(undefined4 *)(param_1 + iRam020dfeb8) = 0;
  *(undefined4 *)(param_1 + iRam020dfebc) = 0;
  *(undefined4 *)(param_1 + iRam020dfec0) = 0;
  uVar6 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020dfec4);
  *(uint *)(param_1 + iRam020dfec8) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020dfecc,0);
  *(int *)(param_1 + iRam020dfed0) =
       (int)((uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14) >> 1;
  uVar6 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020dfed4,0);
  *(uint *)(param_1 + iRam020dfed8) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020dfed4,0);
  *(uint *)(param_1 + iRam020dfedc) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + iRam020dfee0) = 0;
  *(undefined4 *)(param_1 + iRam020dfee4) = 1;
  *(undefined4 *)(param_1 + iRam020dfee8) = 0;
  *(undefined4 *)(param_1 + iRam020dfeec) = 0;
  *(undefined4 *)(param_1 + iRam020dfef4) = uRam020dfef0;
  func_020d90a8(param_1 + iRam020dfeac);
  func_020d8918(param_1 + iRam020dfeac,param_1 + 4,param_1 + 0x10);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + iRam020dfef8) = 0;
  *(undefined4 *)(param_1 + iRam020dfefc) = 0;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020dff00;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  *(undefined2 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x92) = 1;
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(iRam020dff04 + 0xc);
  return;
}

