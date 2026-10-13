/* Decompiled C draft; module arm9; ROM address 020b6078. No matching claim. */
#include "types.h"
#include "deps/020b6078_func_020b6078.h"

void func_020b6078(undefined1 param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_18 [2];
  int local_10;
  uint uVar8;
  
  uVar1 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
          *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
  uVar7 = uVar1 + 0x2c;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  uVar1 = uVar1 + 0x30;
  uVar7 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar7 = uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20;
  GetDriverMaybeSfxPosition(local_18,param_1);
  iVar2 = GetCurrentInternalCourseId_0();
  if (iVar2 < 0x17) {
    if (iVar2 < 0x14) {
      if (iVar2 == 0xb) goto LAB_020b60e8;
    }
    else {
      if (iVar2 == 0x14) {
LAB_020b60e8:
        iVar2 = func_020b523c();
        if (iVar2 == 0) {
          uVar3 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
                  *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
          uVar1 = uVar3 + 0x3c;
          uVar6 = uVar1 & 3;
          uVar5 = *(uint *)(uVar1 & 0xfffffffc);
          uVar3 = uVar3 + 0x40;
          uVar1 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          uVar4 = func_020b57b4(local_10 - uVar8,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                                uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
          SomeFxProduct(0x80000,uVar4);
          iVar2 = func_020b5250();
          *param_2 = iVar2 + 0x78;
        }
        else {
          uVar3 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
                  *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
          uVar1 = uVar3 + 0x3c;
          uVar6 = uVar1 & 3;
          uVar5 = *(uint *)(uVar1 & 0xfffffffc);
          uVar3 = uVar3 + 0x40;
          uVar1 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          uVar4 = func_020b57b4(uVar8 - local_10,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                                uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
          SomeFxProduct(0x80000,uVar4);
          iVar2 = func_020b5250();
          *param_2 = iVar2 + 0xf8;
        }
        uVar8 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
                *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
        uVar1 = uVar8 + 0x44;
        uVar3 = uVar1 & 3;
        uVar6 = *(uint *)(uVar1 & 0xfffffffc);
        uVar8 = uVar8 + 0x48;
        uVar1 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar4 = func_020b57b4(local_18[0] - uVar7,uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20,
                              uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
        SomeFxProduct(0x98000,uVar4);
        iVar2 = func_020b5250();
        param_2[1] = iVar2 + 0x28;
        return;
      }
      if (iVar2 == 0x16) {
        iVar2 = func_020b523c();
        if (iVar2 == 0) {
          uVar3 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
                  *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
          uVar1 = uVar3 + 0x3c;
          uVar6 = uVar1 & 3;
          uVar5 = *(uint *)(uVar1 & 0xfffffffc);
          uVar3 = uVar3 + 0x40;
          uVar1 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          uVar4 = func_020b57b4(local_10 - uVar8,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                                uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
          SomeFxProduct(0x80000,uVar4);
          iVar2 = func_020b5250();
          *param_2 = iVar2 + 0x78;
        }
        else {
          uVar3 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
                  *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
          uVar1 = uVar3 + 0x3c;
          uVar6 = uVar1 & 3;
          uVar5 = *(uint *)(uVar1 & 0xfffffffc);
          uVar3 = uVar3 + 0x40;
          uVar1 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          uVar4 = func_020b57b4(uVar8 - local_10,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                                uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
          SomeFxProduct(0x80000,uVar4);
          iVar2 = func_020b5250();
          *param_2 = iVar2 + 0xf8;
        }
        uVar8 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
                *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
        uVar1 = uVar8 + 0x44;
        uVar3 = uVar1 & 3;
        uVar6 = *(uint *)(uVar1 & 0xfffffffc);
        uVar8 = uVar8 + 0x48;
        uVar1 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        uVar4 = func_020b57b4(local_18[0] - uVar7,uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20,
                              uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
        SomeFxProduct(0x98000,uVar4);
        iVar2 = func_020b5250();
        param_2[1] = iVar2 + 0x28;
        return;
      }
    }
  }
  else if (iVar2 == 0x26) goto LAB_020b60e8;
  iVar2 = func_020b523c();
  if (iVar2 == 0) {
    uVar3 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
            *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
    uVar1 = uVar3 + 0x3c;
    uVar6 = uVar1 & 3;
    uVar5 = *(uint *)(uVar1 & 0xfffffffc);
    uVar3 = uVar3 + 0x40;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = func_020b57b4(local_18[0] - uVar8,uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                          uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    SomeFxProduct(0x80000,uVar4);
    iVar2 = func_020b5250();
    *param_2 = iVar2 + 0x78;
  }
  else {
    uVar3 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
            *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
    uVar1 = uVar3 + 0x3c;
    uVar6 = uVar1 & 3;
    uVar5 = *(uint *)(uVar1 & 0xfffffffc);
    uVar3 = uVar3 + 0x40;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = func_020b57b4(uVar8 - local_18[0],uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
                          uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    SomeFxProduct(0x80000,uVar4);
    iVar2 = func_020b5250();
    *param_2 = iVar2 + 0xf8;
  }
  uVar8 = *(uint *)(uRam020b6334 & 0xfffffffc) >> (uRam020b6334 & 3) * 8 |
          *(uint *)(uRam020b6334 & 0xfffffffc) << (uRam020b6334 & 3) * -8 + 0x20;
  uVar1 = uVar8 + 0x44;
  uVar3 = uVar1 & 3;
  uVar6 = *(uint *)(uVar1 & 0xfffffffc);
  uVar8 = uVar8 + 0x48;
  uVar1 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar4 = func_020b57b4(local_10 - uVar7,uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20,
                        uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
  SomeFxProduct(0x98000,uVar4);
  iVar2 = func_020b5250();
  param_2[1] = iVar2 + 0x28;
  return;
}

