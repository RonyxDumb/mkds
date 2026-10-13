/* Decompiled C draft; module arm9; ROM address 020be9d4. No matching claim. */
#include "types.h"
#include "deps/020be9d4_func_020be9d4.h"

void func_020be9d4(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  undefined6 uVar10;
  undefined1 auStack_18 [12];
  
  uVar2 = func_020b1dbc();
  switch(uVar2) {
  case 0:
    func_020c97c0();
    return;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_020be9e4_default;
  }
  iVar3 = func_020b1d50();
  if (iVar3 * 3 < 1) {
    iVar3 = func_020b1d50();
    uVar2 = FUN_02132440(iVar3 * 0x3000);
    func_021329f8(uVar2,0x3f000000);
  }
  else {
    iVar3 = func_020b1d50();
    uVar2 = FUN_02132440(iVar3 * 0x3000);
    func_02131234(0x3f000000,uVar2);
  }
  uVar4 = func_021322c8();
  uVar7 = DAT_020beb3c;
  *(uint *)((*(uint *)(DAT_020beb3c & 0xfffffffc) >> (DAT_020beb3c & 3) * 8 |
            *(uint *)(DAT_020beb3c & 0xfffffffc) << (DAT_020beb3c & 3) * -8 + 0x20) + 4) =
       (uint)((ulonglong)uVar4 * 0x14) >> 0xc |
       (((int)uVar4 >> 0x1f) * 0x14 + (int)((ulonglong)uVar4 * 0x14 >> 0x20)) * 0x100000;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 4;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar2 = FX_Div(0x2400,uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20);
  *(undefined4 *)
   ((*(uint *)(DAT_020beb3c & 0xfffffffc) >> (DAT_020beb3c & 3) * 8 |
    *(uint *)(DAT_020beb3c & 0xfffffffc) << (DAT_020beb3c & 3) * -8 + 0x20) + 8) = uVar2;
  uVar2 = func_020b1d34();
  uVar4 = (*(uint *)(DAT_020beb3c & 0xfffffffc) >> (DAT_020beb3c & 3) * 8 |
          *(uint *)(DAT_020beb3c & 0xfffffffc) << (DAT_020beb3c & 3) * -8 + 0x20) + 4;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  func_020b503c(uVar2,uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20);
  uVar1 = GetCurrentPlayerRacerId();
  GetDriverVec354(auStack_18,uVar1);
  uVar10 = CheckVectorBounds_Clock_Airship(auStack_18);
  uVar4 = DAT_020beb3c;
  uVar6 = (undefined2)((uint6)uVar10 >> 0x20);
  bVar9 = (int)uVar10 != 0;
  if (bVar9) {
    uVar6 = 0;
  }
  if (!bVar9) {
    uVar6 = 3;
  }
  *(undefined2 *)
   (*(uint *)(DAT_020beb3c & 0xfffffffc) >> (DAT_020beb3c & 3) * 8 |
   *(uint *)(DAT_020beb3c & 0xfffffffc) << (DAT_020beb3c & 3) * -8 + 0x20) = uVar6;
  uVar8 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  iVar3 = 0;
  uVar7 = uVar8 + 0xc & 3;
  uVar5 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  if ((int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) < 1) {
    return;
  }
  do {
    uVar7 = uVar8 + iVar3 * 4 + 0xd4;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    (*(code *)(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20))();
    uVar8 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    iVar3 = iVar3 + 1;
    uVar7 = uVar8 + 0xc & 3;
    uVar5 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  } while (iVar3 < (int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20));
switchD_020be9e4_default:
  return;
}

