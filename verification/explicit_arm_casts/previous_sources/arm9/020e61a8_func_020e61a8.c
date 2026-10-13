/* Decompiled C draft; module arm9; ROM address 020e61a8. No matching claim. */
#include "types.h"
#include "deps/020e61a8_func_020e61a8.h"

void func_020e61a8(undefined4 param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_30 [16];
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar5 = iRam020e62fc;
  uVar1 = uRam020e62f8;
  puVar6 = (ushort *)(param_2 + 0x100);
  uVar2 = *puVar6;
  *puVar6 = uVar2 + *(short *)(param_2 + 0xfe);
  uVar7 = (uint)*puVar6;
  uVar3 = *(ushort *)(param_2 + 0xfc);
  sVar4 = *(short *)(iVar5 + ((int)uVar7 >> 4) * 4);
  if ((((uVar2 < uVar1) && (uVar1 <= uVar7)) || ((uVar2 < uRam020e6300 && (uRam020e6300 <= uVar7))))
     && (uVar1 = param_2 + 0x78U & 3, uVar7 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
        ((uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) & 4) == 0)) {
    uVar1 = param_2 + 0x70U & 3;
    uVar7 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar8 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
    uVar1 = iRam020e6304 + 0x68U & 3;
    uVar7 = *(uint *)(iRam020e6304 + 0x68U & 0xfffffffc);
    if (uVar8 == (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20)) {
      local_18 = 2;
    }
    else {
      uVar1 = iRam020e6304 + 0x8cU & 3;
      uVar7 = *(uint *)(iRam020e6304 + 0x8cU & 0xfffffffc);
      if (uVar8 == (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20)) {
        local_18 = 3;
      }
      else {
        local_18 = 4;
      }
    }
    local_1c = param_2 + 4;
    local_20 = uRam020e6308;
    local_14 = func_020d4ef4();
    func_0210b7a8(&local_20);
  }
  func_020d7734(param_2 + 0xa0,(uint)uVar3 * (int)sVar4 >> 0xc & 0xffff,auStack_30);
  func_01ffccd0(param_2 + 0x28,auStack_30);
  uVar1 = param_2 + 0xf8U & 3;
  uVar7 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
  VecFx32_AddScale1(-(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20),param_2 + 0x34,param_2 + 0xbc
                    ,param_2 + 4);
  uVar1 = param_2 + 4U & 3;
  uVar7 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0xec) = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar7 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0xf0) = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0xf4) = (int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) >> 4;
  VecFx32_Subtract(param_2 + 4,param_2 + 0xb0,param_2 + 0x10);
  *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(param_2 + 0xc);
  return;
}

