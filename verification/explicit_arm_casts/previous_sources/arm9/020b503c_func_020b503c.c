/* Decompiled C draft; module arm9; ROM address 020b503c. No matching claim. */
#include "types.h"
#include "deps/020b503c_func_020b503c.h"

void func_020b503c(uint *param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = func_020b6368();
  uVar1 = Maybe_helper_0b5270();
  *(undefined2 *)
   ((*(uint *)(uRam020b5238 & 0xfffffffc) >> (uRam020b5238 & 3) * 8 |
    *(uint *)(uRam020b5238 & 0xfffffffc) << (uRam020b5238 & 3) * -8 + 0x20) + 0x1c) = uVar1;
  uVar1 = Maybe_get_15d4b4_10(uVar2);
  uVar3 = uRam020b5238;
  *(undefined2 *)
   ((*(uint *)(uRam020b5238 & 0xfffffffc) >> (uRam020b5238 & 3) * 8 |
    *(uint *)(uRam020b5238 & 0xfffffffc) << (uRam020b5238 & 3) * -8 + 0x20) + 0x1e) = uVar1;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = SomeFxProduct((int)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x1c),
                        param_2);
  uVar3 = uRam020b5238;
  *(undefined4 *)
   ((*(uint *)(uRam020b5238 & 0xfffffffc) >> (uRam020b5238 & 3) * 8 |
    *(uint *)(uRam020b5238 & 0xfffffffc) << (uRam020b5238 & 3) * -8 + 0x20) + 0x20) = uVar2;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = SomeFxProduct((int)*(short *)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x1e),
                        param_2);
  *(undefined4 *)
   ((*(uint *)(uRam020b5238 & 0xfffffffc) >> (uRam020b5238 & 3) * 8 |
    *(uint *)(uRam020b5238 & 0xfffffffc) << (uRam020b5238 & 3) * -8 + 0x20) + 0x24) = uVar2;
  iVar4 = func_020b1dbc();
  if (iVar4 == 2) {
    func_020b5290();
  }
  FX_Div(0xb0000,param_2);
  uVar2 = func_020b5250();
  *(undefined4 *)
   ((*(uint *)(uRam020b5238 & 0xfffffffc) >> (uRam020b5238 & 3) * 8 |
    *(uint *)(uRam020b5238 & 0xfffffffc) << (uRam020b5238 & 3) * -8 + 0x20) + 0x18) = uVar2;
  uVar2 = FX_Inv(param_2);
  uVar5 = SomeFxProduct((int)*(short *)((*(uint *)(uRam020b5238 & 0xfffffffc) >>
                                         (uRam020b5238 & 3) * 8 |
                                        *(uint *)(uRam020b5238 & 0xfffffffc) <<
                                        (uRam020b5238 & 3) * -8 + 0x20) + 0x1c),uVar2);
  uVar3 = SomeFxProduct((int)*(short *)((*(uint *)(uRam020b5238 & 0xfffffffc) >>
                                         (uRam020b5238 & 3) * 8 |
                                        *(uint *)(uRam020b5238 & 0xfffffffc) <<
                                        (uRam020b5238 & 3) * -8 + 0x20) + 0x1e),uVar2);
  iVar4 = func_020b523c();
  if (iVar4 == 0) {
    param_1[8] = uVar5;
    uVar7 = (uint)(param_1 + 8) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    *param_1 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    param_1[10] = -uVar3;
    uVar7 = (uint)(param_1 + 10) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    param_1[2] = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  }
  else {
    param_1[8] = -uVar5;
    uVar7 = (uint)(param_1 + 8) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    *param_1 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    param_1[10] = uVar3;
    uVar7 = (uint)(param_1 + 10) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    param_1[2] = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  }
  param_1[9] = uVar3;
  uVar3 = (uint)(param_1 + 9) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
  param_1[1] = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
  param_1[0xb] = uVar5;
  uVar5 = (uint)(param_1 + 0xb) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 0xb) & 0xfffffffc);
  param_1[3] = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  func_020b58f8(param_1);
  iVar4 = GetCurrentInternalCourseId_0();
  if (iVar4 < 0x22) {
    if (0x20 < iVar4) {
LAB_020b5218:
      func_020b57f8(param_1 + 8);
      return;
    }
    if (iVar4 < 0x1d) {
      if ((0x1b < iVar4) ||
         (((iVar4 < 0x15 && (0xd < iVar4)) &&
          ((iVar4 == 0xe || ((iVar4 == 0x12 || (iVar4 == 0x14)))))))) goto LAB_020b5218;
    }
    else if (iVar4 == 0x1e) goto LAB_020b5218;
  }
  else if (iVar4 < 0x31) {
    if (0x2f < iVar4) {
LAB_020b5228:
      func_020b5658(param_1 + 8);
      return;
    }
    if (iVar4 == 0x26) goto LAB_020b5218;
  }
  else if (iVar4 == 0x32) goto LAB_020b5228;
  param_1[8] = *param_1;
  param_1[9] = param_1[1];
  param_1[10] = param_1[2];
  param_1[0xb] = param_1[3];
  param_1[0xc] = param_1[4];
  param_1[0xd] = param_1[5];
  param_1[0xe] = param_1[6];
  param_1[0xf] = param_1[7];
  return;
}

