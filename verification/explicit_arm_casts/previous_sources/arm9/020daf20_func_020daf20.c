/* Decompiled C draft; module arm9; ROM address 020daf20. No matching claim. */
#include "types.h"
#include "deps/020daf20_func_020daf20.h"

void func_020daf20(undefined4 param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint uVar13;
  
  *(short *)(param_2 + 0xf0) = *(short *)(param_2 + 0xf0) + 1;
  if (((*(short *)(param_2 + 0xf0) == 0x14) || (*(short *)(param_2 + 0xf0) == 0x28)) &&
     (uVar1 = param_2 + 0x78U & 3, uVar3 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
     ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 4) == 0)) {
    uVar1 = param_2 + 0x70U & 3;
    uVar3 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar6 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = iRam020db040 + 0x68U & 3;
    uVar3 = *(uint *)(iRam020db040 + 0x68U & 0xfffffffc);
    if (uVar6 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
      local_18 = 2;
    }
    else {
      uVar1 = iRam020db040 + 0x8cU & 3;
      uVar3 = *(uint *)(iRam020db040 + 0x8cU & 0xfffffffc);
      if (uVar6 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
        local_18 = 3;
      }
      else {
        local_18 = 4;
      }
    }
    local_1c = param_2 + 4;
    local_20 = uRam020db044;
    local_14 = func_020d4ef4();
    func_0210b7a8(&local_20);
  }
  if (0x27 < *(ushort *)(param_2 + 0xf0)) {
    uVar1 = param_2 + 0xf4U & 3;
    uVar3 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
      uVar4 = *(uint *)(uRam020db048 & 0xfffffffc) >> (uRam020db048 & 3) * 8 |
              *(uint *)(uRam020db048 & 0xfffffffc) << (uRam020db048 & 3) * -8 + 0x20;
      iVar5 = uVar4 + iRam020db04c;
      uVar1 = iVar5 + 8U & 3;
      uVar3 = *(uint *)(iVar5 + 8U & 0xfffffffc);
      uVar11 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = uVar4 + 0x47c & 3;
      uVar3 = *(uint *)(uVar4 + 0x47c & 0xfffffffc);
      uVar10 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = iVar5 + 4U & 3;
      uVar7 = *(uint *)(iVar5 + 4U & 0xfffffffc);
      lVar2 = (ulonglong)uVar10 * (ulonglong)uVar11;
      uVar9 = (uint)lVar2;
      uVar3 = iVar5 + 0xcU & 3;
      uVar8 = *(uint *)(iVar5 + 0xcU & 0xfffffffc);
      uVar6 = iVar5 + 0x10U & 3;
      uVar12 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
      uVar13 = uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20;
      uVar6 = iVar5 + 0x14U & 3;
      uVar12 = *(uint *)(iVar5 + 0x14U & 0xfffffffc);
      *(uint *)(uVar4 + 0x47c) = uVar13 + uVar9;
      *(uint *)(iVar5 + 4) =
           (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) +
           (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) * uVar10 +
           uVar11 * (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) +
           (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar13,uVar9);
      uVar1 = iVar5 + 4U & 3;
      uVar3 = *(uint *)(iVar5 + 4U & 0xfffffffc);
      *(short *)(param_2 + 0xf0) =
           (short)((ulonglong)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x28 >> 0x20);
      *(undefined4 *)(param_2 + 0xf4) = 1;
    }
    else {
      *(undefined2 *)(param_2 + 0xf0) = 0;
    }
  }
  StateDualHandler_Execute(param_2 + 0x80);
  return;
}

