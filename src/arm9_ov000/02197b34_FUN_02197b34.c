/* Decompiled C draft; module arm9_ov000; ROM address 02197b34. No matching claim. */
#include "types.h"
#include "deps/02197b34_FUN_02197b34.h"

int FUN_02197b34(int param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  char extraout_r1;
  char extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int iVar6;
  int iVar7;
  
  uVar3 = func_0x0213a434(DAT_02197bd8);
  iVar4 = FUN_02197ca0((byte *)(uintptr_t)(param_2));
  iVar6 = 0;
  iVar7 = 0;
  do {
    if (((iVar4 == 0) || (iVar6 == 0)) || (iVar6 == 0xd)) {
      uVar5 = func_0x021384dc();
      func_0x02133068(uVar5,0x5d);
      *(char *)(param_1 + iVar6) = extraout_r1 + '!';
    }
    else {
      if ((iVar6 == 1) || (iVar6 == 0xe)) {
        cVar2 = *(char *)(param_2 + iVar6);
      }
      else {
        cVar2 = *(char *)(param_2 + iVar6 + -1);
      }
      bVar1 = *(byte *)(param_2 + iVar6);
      func_0x02133068(iVar6 + (uint)bVar1,uVar3);
      func_0x02133068((int)*(char *)(DAT_02197bd8 + extraout_r1_01) + (uint)bVar1 * iVar6,0x20);
      func_0x02133068(iVar7 * cVar2,uVar3);
      uVar5 = func_0x02134420((uint)*(byte *)(param_2 + extraout_r1_02) ^
                              (int)*(char *)(DAT_02197bd8 + extraout_r1_03));
      func_0x02133068(uVar5,0x5d);
      *(char *)(param_1 + iVar6) = extraout_r1_00 + '!';
    }
    iVar7 = iVar7 + DAT_02197bdc;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x20);
  return param_1;
}

