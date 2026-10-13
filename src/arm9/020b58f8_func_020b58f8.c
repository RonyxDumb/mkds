/* Decompiled C draft; module arm9; ROM address 020b58f8. No matching claim. */
#include "types.h"
#include "deps/020b58f8_func_020b58f8.h"

void func_020b58f8(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_18;
  int iStack_14;
  int local_10;
  
  uVar12 = *(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
           *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20;
  uVar9 = uVar12 + 0x4c & 3;
  uVar10 = *(uint *)(uVar12 + 0x4c & 0xfffffffc);
  uVar8 = uVar12 + 0x50 & 3;
  uVar2 = *(uint *)(uVar12 + 0x50 & 0xfffffffc);
  uVar7 = uVar12 + 0x8c & 3;
  uVar3 = *(uint *)(uVar12 + 0x8c & 0xfffffffc);
  if (uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0) {
    uVar1 = GetCurrentPlayerRacerId();
    GetDriverVec354(&local_18,uVar1);
  }
  else {
    local_18 = *(int *)(uVar12 + 0x90);
    iStack_14 = *(int *)(uVar12 + 0x94);
    local_10 = *(int *)(uVar12 + 0x98);
  }
  iVar4 = func_020b1dbc();
  if (iVar4 == 3) {
    piVar5 = (int *)func_020b57e4();
    local_18 = *piVar5;
    iStack_14 = piVar5[1];
    local_10 = piVar5[2];
  }
  uVar3 = *(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
          *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20;
  uVar7 = uVar3 + 0x5c;
  uVar12 = uVar7 & 3;
  uVar11 = *(uint *)(uVar7 & 0xfffffffc);
  uVar3 = uVar3 + 0x60;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar6 = func_020b57b4(local_18 - (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20),
                        uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20,
                        uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
  uVar6 = SomeFxProduct(0x200000,uVar6);
  uVar7 = uRam020b5ae4;
  *(undefined4 *)
   (*(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
   *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20) = uVar6;
  uVar9 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
  uVar9 = uVar7 + 100;
  uVar3 = uVar9 & 3;
  uVar10 = *(uint *)(uVar9 & 0xfffffffc);
  uVar7 = uVar7 + 0x68;
  uVar9 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar6 = func_020b57b4(local_10 - (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20),
                        uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20,
                        uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20);
  uVar6 = SomeFxProduct(0x200000,uVar6);
  uVar8 = uRam020b5ae4;
  *(undefined4 *)
   ((*(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
    *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20) + 4) = uVar6;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar8 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar6 = func_020b5250(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
  uVar7 = uRam020b5ae4;
  *(undefined4 *)
   ((*(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
    *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20) + 0x10) = uVar6;
  uVar9 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x10;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
  uVar9 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 4;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar6 = func_020b5250(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20);
  uVar7 = uRam020b5ae4;
  *(undefined4 *)
   ((*(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
    *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20) + 0x14) = uVar6;
  uVar9 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x14;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
  uVar9 = param_1 + 0x10U & 3;
  uVar8 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) - 0x80;
  uVar9 = param_1 + 0x14U & 3;
  uVar8 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x1c) = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) - 0x60;
  uVar9 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x10;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
  if ((int)uVar9 < 1) {
    uVar6 = FUN_02132440(uVar9 << 0xc);
    func_021329f8(uVar6,0x3f000000);
  }
  else {
    uVar6 = FUN_02132440(uVar9 << 0xc);
    func_02131234(0x3f000000,uVar6);
  }
  uVar9 = *(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
          *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20;
  iVar4 = func_021322c8();
  uVar8 = uRam020b5ae4;
  *(uint *)(uVar9 + 8) =
       (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
       *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) - iVar4;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar9 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 0x14;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar9 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
  if ((int)uVar9 < 1) {
    uVar6 = FUN_02132440(uVar9 << 0xc);
    func_021329f8(uVar6,0x3f000000);
  }
  else {
    uVar6 = FUN_02132440(uVar9 << 0xc);
    func_02131234(0x3f000000,uVar6);
  }
  uVar7 = *(uint *)(uRam020b5ae4 & 0xfffffffc) >> (uRam020b5ae4 & 3) * 8 |
          *(uint *)(uRam020b5ae4 & 0xfffffffc) << (uRam020b5ae4 & 3) * -8 + 0x20;
  iVar4 = func_021322c8();
  uVar9 = uVar7 + 4;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  *(uint *)(uVar7 + 0xc) = (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) - iVar4;
  return;
}

