/* Decompiled C draft; module arm9; ROM address 020e5e24. No matching claim. */
#include "types.h"
#include "deps/020e5e24_func_020e5e24.h"

void func_020e5e24(int param_1,undefined4 *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x98) + 0x10);
  uVar8 = Multiply64(iVar3,iVar3 >> 0x1f,param_2[8],(int)param_2[8] >> 0x1f);
  *(uint *)(param_1 + 0x5c) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  func_020d720c(param_2 + 3,param_1 + 0xa0);
  puVar7 = (undefined4 *)(param_1 + 0x28);
  puVar6 = (undefined4 *)(param_1 + 200);
  iVar3 = 4;
  do {
    uVar4 = *puVar7;
    uVar5 = puVar7[1];
    puVar7 = puVar7 + 2;
    *puVar6 = uVar4;
    puVar6[1] = uVar5;
    puVar6 = puVar6 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar6 = *puVar7;
  uVar8 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020e5f44,0);
  *(uint *)(param_1 + 0xf8) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  *(undefined2 *)(param_1 + iRam020e5f48) = 0;
  *(undefined4 *)(param_1 + 0xbc) = *param_2;
  *(undefined4 *)(param_1 + 0xc0) = param_2[1];
  *(undefined4 *)(param_1 + 0xc4) = param_2[2];
  VecFx32_AddScale1(-*(int *)(param_1 + 0xf8),param_1 + 0x34,param_1 + 0xbc,param_1 + 4);
  *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xc);
  *(int *)(param_1 + 0xec) = *(int *)(param_1 + 4) >> 4;
  *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 8) >> 4;
  *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xc) >> 4;
  sVar1 = *(short *)((int)param_2 + 0x2a);
  uVar4 = MaybeBoundsCheck(uRam020e5f4c,(int)*(short *)(param_2 + 10));
  uVar2 = MaybeBoundsCheck(uVar4,0xf0);
  *(undefined2 *)(param_1 + 0xfe) = uVar2;
  uVar2 = MaybeBoundsCheck(iRam020e5f50 * sVar1,100);
  *(undefined2 *)(param_1 + 0xfc) = uVar2;
  uVar8 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020e5f54,0);
  *(uint *)(param_1 + iRam020e5f58) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  uVar8 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020e5f5c,0);
  *(uint *)(param_1 + iRam020e5f60) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + iRam020e5f64) = 0;
  return;
}

