/* Decompiled C draft; module arm9; ROM address 020e1f54. No matching claim. */
#include "types.h"
#include "deps/020e1f54_func_020e1f54.h"

void func_020e1f54(int param_1,int param_2,int *param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  *(int **)(param_1 + iRam020e2064) = param_3;
  uVar2 = _s32_div_f(iRam020e2068 * *(short *)(param_2 + 0x28),100);
  func_020d7da8(param_1 + 0xd8,param_2,uVar2);
  *(undefined2 *)(param_1 + 0xfc) = *(undefined2 *)(param_2 + 0x2a);
  *(undefined2 *)(param_1 + iRam020e206c) = *(undefined2 *)(param_2 + 0x2c);
  iVar3 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_2 + 0x26),*(undefined2 *)(param_1 + 0xfc))
  ;
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar3 + 4);
  uVar6 = Multiply64(*param_3,*param_3 >> 0x1f,*(int *)(param_1 + 0x1c),
                     *(int *)(param_1 + 0x1c) >> 0x1f);
  *(uint *)(param_1 + iRam020e2070) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(param_3[1],param_3[1] >> 0x1f,*(int *)(param_1 + 0x20),
                     *(int *)(param_1 + 0x20) >> 0x1f);
  *(uint *)(param_1 + iRam020e2074) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(param_3[2],param_3[2] >> 0x1f,*(int *)(param_1 + 0x24),
                     *(int *)(param_1 + 0x24) >> 0x1f);
  *(uint *)(param_1 + iRam020e2078) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(param_3[3],param_3[3] >> 0x1f,*(int *)(param_1 + 0x24),
                     *(int *)(param_1 + 0x24) >> 0x1f);
  *(uint *)(param_1 + iRam020e207c) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar1 = MaybeBoundsCheck(*(short *)(param_2 + 0x28) * 0xfa,100);
  puVar4 = (undefined2 *)(param_1 + iRam020e2080);
  *puVar4 = uVar1;
  *(undefined2 *)(param_1 + iRam020e2084) = *puVar4;
  *(int *)(param_1 + iRam020e2088) = param_3[4];
  *(int *)(param_1 + iRam020e208c) = param_3[5] >> 4;
  *(int *)(param_1 + iRam020e2090) = param_3[6] >> 4;
  *(int *)(param_1 + iRam020e2094) = param_3[7];
  func_020e1e98(param_1);
  *(int *)(param_1 + iRam020e2098) = param_3[0xb];
  uVar2 = func_020d286c(param_1);
  puVar5 = (undefined4 *)(param_1 + iRam020e209c);
  *puVar5 = uVar2;
  func_0210b850(*puVar5);
  *(undefined4 *)(*(int *)(param_1 + 0x94) + 0x30) = uRam020e20a0;
  *(int *)(param_1 + iRam020e20a4) = param_3[0xc];
  return;
}

