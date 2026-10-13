/* Decompiled C draft; module arm9; ROM address 020b6c74. No matching claim. */
#include "types.h"
#include "deps/020b6c74_FormatTimeTrialRecordRacerNameString.h"

void FormatTimeTrialRecordRacerNameString(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_48 [20];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [28];
  
  puVar4 = (undefined1 *)0x0;
  uVar5 = 0;
  uVar6 = 0;
  bVar3 = false;
  do {
    iVar2 = uVar6 * 2;
    uVar6 = uVar6 + 1 & 0xffff;
    *(undefined2 *)(param_2 + iVar2) = 0;
  } while (uVar6 < 0xb);
  if (param_1 == 0) {
    uVar7 = *(uint *)(uRam020b6d94 & 0xfffffffc) >> (uRam020b6d94 & 3) * 8 |
            *(uint *)(uRam020b6d94 & 0xfffffffc) << (uRam020b6d94 & 3) * -8 + 0x20;
    uVar6 = uVar7 + 0x70;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
    if ((uVar6 < 4) && ((1 << (uVar6 & 0xff) & 0xdU) != 0)) {
      bVar3 = true;
    }
    if (bVar3) {
      uVar7 = uVar7 + 0x88;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      puVar4 = (undefined1 *)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
      if (puVar4 == (undefined1 *)0x0) {
        return;
      }
      if (param_3 == 0) {
        uVar5 = GetClampedString10LengthForFontIndex0_from_thumb(puVar4,auStack_48);
      }
      else {
        uVar5 = 10;
      }
    }
  }
  else {
    uVar7 = *(uint *)(uRam020b6d94 & 0xfffffffc) >> (uRam020b6d94 & 3) * 8 |
            *(uint *)(uRam020b6d94 & 0xfffffffc) << (uRam020b6d94 & 3) * -8 + 0x20;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    iVar2 = TimeTrialRecord_CopyFrom_from_thumb
                      (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,param_1 + -1,auStack_34);
    if (iVar2 != 0) {
      puVar4 = auStack_30;
      if (param_3 == 0) {
        uVar5 = GetClampedString10LengthForFontIndex0_from_thumb(puVar4,auStack_48);
      }
      else {
        uVar5 = 10;
      }
    }
  }
  if (puVar4 != (undefined1 *)0x0) {
    CopyString16(param_2,puVar4,uVar5);
    return;
  }
  return;
}

