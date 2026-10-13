/* Decompiled C draft; module arm9; ROM address 02015894. No matching claim. */
#include "types.h"
#include "deps/02015894_func_02015894.h"

void func_02015894(int param_1,int param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = (uint)*(ushort *)(param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe)) * param_2 +
          param_1 + 8 + (uint)*(ushort *)(param_1 + 0xe) + 4;
  uVar1 = uVar8 + 0x18 & 3;
  uVar3 = *(uint *)(uVar8 + 0x18 & 0xfffffffc);
  uVar6 = uVar8 + 0x1c & 3;
  uVar4 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
  uVar7 = *(uint *)((uint)param_4 & 0xfffffffc) >> ((uint)param_4 & 3) * 8 |
          *(uint *)((uint)param_4 & 0xfffffffc) << ((uint)param_4 & 3) * -8 + 0x20;
  uVar3 = func_02015aa0(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                        uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,param_3);
  uVar1 = uVar8 + 0x20 & 3;
  uVar4 = *(uint *)(uVar8 + 0x20 & 0xfffffffc);
  uVar6 = uVar8 + 0x24 & 3;
  uVar5 = *(uint *)(uVar8 + 0x24 & 0xfffffffc);
  uVar1 = func_02015aa0(param_1,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
                        uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,param_3);
  if ((uVar3 == 0) && (uVar1 == 0)) {
    uVar7 = uVar7 | 4;
  }
  else {
    param_4[9] = uVar3;
    param_4[10] = uVar1;
    uVar7 = uVar7 & 0xfffffffb;
  }
  uVar1 = uVar8 + 0x10 & 3;
  uVar3 = *(uint *)(uVar8 + 0x10 & 0xfffffffc);
  uVar6 = uVar8 + 0x14 & 3;
  uVar4 = *(uint *)(uVar8 + 0x14 & 0xfffffffc);
  iVar2 = func_02015994(param_1,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                        uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20,param_3);
  if (iVar2 != 0x10000000) {
    *(short *)(param_4 + 8) = (short)iVar2;
    *(short *)((int)param_4 + 0x22) = (short)((uint)iVar2 >> 0x10);
  }
  else {
    uVar7 = uVar7 | 2;
  }
  uVar1 = uVar8 + 4 & 3;
  uVar6 = *(uint *)(uVar8 + 4 & 0xfffffffc);
  if (iVar2 != 0x10000000) {
    uVar7 = uVar7 & 0xfffffffd;
  }
  uVar3 = func_02015aa0(param_1,*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20,
                        uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,param_3);
  uVar1 = uVar8 + 8 & 3;
  uVar4 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  uVar6 = uVar8 + 0xc & 3;
  uVar5 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  uVar1 = func_02015aa0(param_1,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
                        uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,param_3);
  if ((uVar3 == 0x1000) && (uVar1 == 0x1000)) {
    uVar7 = uVar7 | 1;
  }
  else {
    param_4[6] = uVar3;
    param_4[7] = uVar1;
    uVar7 = uVar7 & 0xfffffffe;
  }
  *param_4 = uVar7;
  return;
}

