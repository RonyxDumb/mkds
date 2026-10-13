/* Decompiled C draft; module arm9; ROM address 020e38a0. No matching claim. */
#include "types.h"
#include "deps/020e38a0_func_020e38a0.h"

void func_020e38a0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xc);
  puVar6 = (undefined4 *)(param_1 + 0x28);
  puVar5 = (undefined4 *)(param_1 + 0xa0);
  iVar4 = 4;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar5 = *puVar6;
  puVar6 = (undefined4 *)(param_1 + 0x28);
  puVar5 = (undefined4 *)(param_1 + 0xc4);
  iVar4 = 4;
  do {
    uVar1 = *puVar6;
    uVar2 = puVar6[1];
    puVar6 = puVar6 + 2;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *puVar5 = *puVar6;
  *(undefined4 *)(param_1 + iRam020e3a04) = 0;
  *(undefined4 *)(param_1 + iRam020e3a08) = 0;
  *(undefined4 *)(param_1 + iRam020e3a0c) = 0;
  *(undefined4 *)(param_1 + iRam020e3a10) = 1;
  iVar4 = _s32_div_f((int)*(short *)(param_2 + 0x28) << 0x10,uRam020e3a14);
  *(short *)(param_1 + iRam020e3a18) = (short)(iVar4 >> 1);
  iVar4 = _s32_div_f(uRam020e3a1c,(int)*(short *)(param_2 + 0x2a));
  puVar3 = (undefined2 *)(param_1 + iRam020e3a20);
  *puVar3 = (short)(iVar4 >> 1);
  *(undefined2 *)(param_1 + iRam020e3a24) = *(undefined2 *)(param_2 + 0x2c);
  *(undefined2 *)(param_1 + iRam020e3a28) = *(undefined2 *)(param_2 + 0x2e);
  *(undefined2 *)(param_1 + iRam020e3a2c) = 0;
  *(undefined2 *)(param_1 + iRam020e3a30) = 0;
  if (*(int *)(*piRam020e3a34 + 8) == 5) {
    *puVar3 = 0;
    iVar4 = _s32_div_f((int)*(short *)(param_2 + 0x30) << 0x10,uRam020e3a14);
    *(short *)(param_1 + iRam020e3a30) = (short)(iVar4 >> 1);
  }
  uVar7 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020e3a38,0);
  *(uint *)(param_1 + iRam020e3a3c) = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
  uVar7 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020e3a40,0);
  *(int *)(param_1 + iRam020e3a44) =
       (int)((uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14) >> 1;
  uVar7 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020e3a48,0);
  *(uint *)(param_1 + iRam020e3a4c) = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
  uVar7 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020e3a50,0);
  *(uint *)(param_1 + iRam020e3a54) = (uint)uVar7 >> 0xc | (int)((ulonglong)uVar7 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + iRam020e3a58) = 0;
  *(undefined4 *)(param_1 + iRam020e3a5c) = 1;
  *(undefined4 *)(param_1 + iRam020e3a60) = 0;
  *(undefined4 *)(param_1 + iRam020e3a64) = 1;
  *(undefined4 *)(param_1 + iRam020e3a6c) = uRam020e3a68;
  *(undefined4 *)(param_1 + iRam020e3a70) = 0;
  *(undefined4 *)(param_1 + iRam020e3a74) = 0;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e3a78;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  if (*(int *)(param_2 + 0x10) < 0) {
    func_020d278c(param_1);
  }
  return;
}

