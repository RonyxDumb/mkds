/* Decompiled C draft; module arm9; ROM address 020db2b8. No matching claim. */
#include "types.h"
#include "deps/020db2b8_func_020db2b8.h"

void func_020db2b8(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  *(int *)(param_1 + 0xf0) = (int)*(short *)(param_2 + 0x28);
  uVar1 = uRam020db3c0;
  if (*(int *)(param_1 + 0xf0) != 0) {
    uVar1 = uRam020db3bc;
  }
  func_020d7da8(param_1 + 200,param_2,uVar1);
  *(undefined2 *)(param_1 + 0xec) = *(undefined2 *)(param_2 + 0x2a);
  uVar2 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020db3c4,0);
  *(uint *)(param_1 + 0xf4) = (uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14;
  uVar2 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020db3c8,0);
  *(uint *)(param_1 + 0xf8) = (uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14;
  uVar2 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020db3cc,0);
  *(uint *)(param_1 + 0xfc) = (uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14;
  uVar2 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020db3d0,0);
  *(uint *)(param_1 + iRam020db3d4) = (uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + iRam020db3d8) = *(undefined4 *)(param_1 + 0x20);
  *(uint *)(param_1 + iRam020db3dc) =
       (*(uint *)(param_1 + 0x20) << 0xd) >> 0xc | (*(uint *)(param_1 + 0x20) >> 0x13) << 0x14;
  uVar2 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020db3c0,0);
  *(uint *)(param_1 + 0xc4) = (uint)uVar2 >> 0xc | (int)((ulonglong)uVar2 >> 0x20) << 0x14;
  func_020db430(param_1);
  if (*(int *)(param_1 + 0xf0) == 0) {
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(iRam020db3e0 + 0xc);
    return;
  }
  func_020d27fc(param_1);
  return;
}

