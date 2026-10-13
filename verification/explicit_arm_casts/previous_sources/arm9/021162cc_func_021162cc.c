/* Decompiled C draft; module arm9; ROM address 021162cc. No matching claim. */
#include "types.h"
#include "deps/021162cc_func_021162cc.h"

void func_021162cc(void)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  undefined2 *puVar7;
  byte *pbVar8;
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [32];
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28 [20];
  
  local_4c = 0;
  uStack_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  sVar2 = func_02116870();
  iVar3 = func_02114158(sVar2 + *(short *)(*piRam02116610 + 0x80),local_28);
  piVar1 = piRam02116610;
  if (iVar3 == 0) {
    *(undefined4 *)(*piRam02116610 + 0x40) = 0;
    iVar3 = *(int *)(*piVar1 + 0x10);
    AllocateReserveTEQSub(9,0,iVar3 + 0xc,*(undefined4 *)(iVar3 + 8));
  }
  else {
    *(undefined4 *)(*piRam02116610 + 0x40) = 1;
    iVar3 = *(int *)(*piVar1 + 0x20);
    AllocateReserveTEQSub(9,0,iVar3 + 0xc,*(undefined4 *)(iVar3 + 8));
  }
  iVar3 = *piRam02116610;
  if (*(int *)(iVar3 + 0x40) != 0) {
    if (*(int *)(iVar3 + 0x40) == 1) {
      func_02114298(sVar2 + *(short *)(iVar3 + 0x80),auStack_6c,0x20);
      iVar3 = *piRam02116610;
      func_0212426c(0,0,*(undefined4 *)(iVar3 + 0x1c),auStack_6c,*(undefined4 *)(iVar3 + 0x18),
                    *(undefined4 *)(iVar3 + 0x24));
      iVar3 = 0;
      pbVar8 = local_28;
      puVar7 = puRam02116620;
      do {
        FormatIntegerInString16_from_thumb(*pbVar8 - 0x30,auStack_6c);
        iVar5 = *piRam02116610;
        func_0212426c(0,*puVar7,*(undefined4 *)(iVar5 + 0x1c),auStack_6c,
                      *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x24));
        pbVar8 = pbVar8 + 1;
        puVar7 = puVar7 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0xc);
      iVar3 = *piRam02116610;
      func_021141c8(sVar2 + *(short *)(iVar3 + 0x80),*(undefined4 *)(iVar3 + 0x88),
                    *(undefined4 *)(iVar3 + 0x8c));
      iVar5 = *piRam02116610;
      iVar3 = func_0212497c(1,*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 0x18));
      AllocateReserveTEQSub(0x13,iVar3 << 5,*(undefined4 *)(iVar5 + 0x8c),uRam0211661c);
      return;
    }
    return;
  }
  func_02114298(sVar2 + *(short *)(iVar3 + 0x80),auStack_6c,0x20);
  iVar3 = *piRam02116610;
  func_0212426c(0,0,*(undefined4 *)(iVar3 + 0xc),auStack_6c,*(undefined4 *)(iVar3 + 8),
                *(undefined4 *)(iVar3 + 0x14));
  local_40 = func_0211437c(sVar2 + *(short *)(*piRam02116610 + 0x80));
  local_3c = func_02114360(sVar2 + *(short *)(*piRam02116610 + 0x80));
  local_38 = func_02114344(sVar2 + *(short *)(*piRam02116610 + 0x80));
  local_34 = func_02114328(sVar2 + *(short *)(*piRam02116610 + 0x80));
  local_30 = func_0211430c(sVar2 + *(short *)(*piRam02116610 + 0x80));
  local_2c = func_021142f0(sVar2 + *(short *)(*piRam02116610 + 0x80));
  iVar3 = 1;
  puVar6 = &local_40;
  do {
    iVar5 = 0;
    puVar4 = puVar6;
    do {
      if (uRam02116614 < *puVar4) {
        *puVar4 = uRam02116614;
      }
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    puVar6 = puVar6 + 3;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  FormatIntegerInString16_from_thumb(local_40,auStack_6c);
  iVar3 = *piRam02116610;
  func_02124248(0,*(undefined2 *)(iRam02116618 + 6),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_3c,auStack_6c);
  iVar3 = *piRam02116610;
  func_02124248(0,*(undefined2 *)(iRam02116618 + 8),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_38,auStack_6c);
  iVar3 = *piRam02116610;
  func_02124248(0,*(undefined2 *)(iRam02116618 + 10),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_34,auStack_6c);
  iVar3 = *piRam02116610;
  func_02124248(0,*(undefined2 *)(iRam02116618 + 0xc),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_30,auStack_6c);
  iVar3 = *piRam02116610;
  func_02124248(0,*(undefined2 *)(iRam02116618 + 0xe),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_2c,auStack_6c);
  iVar3 = *piRam02116610;
  func_02124248(0,*(undefined2 *)(iRam02116618 + 0x10),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  func_021142d4(sVar2 + *(short *)(*piRam02116610 + 0x80),auStack_70);
  func_02116a4c(auStack_70,auStack_6c);
  iVar3 = *piRam02116610;
  func_02124224(0,0xc,*(undefined4 *)(iVar3 + 0xc),auStack_6c,*(undefined4 *)(iVar3 + 8),
                *(undefined4 *)(iVar3 + 0x14),6);
  iVar3 = *piRam02116610;
  func_021141c8(sVar2 + *(short *)(iVar3 + 0x80),*(undefined4 *)(iVar3 + 0x88),
                *(undefined4 *)(iVar3 + 0x8c));
  iVar5 = *piRam02116610;
  iVar3 = func_0212497c(3,*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 8));
  AllocateReserveTEQSub(0x13,iVar3 << 5,*(undefined4 *)(iVar5 + 0x8c),uRam0211661c);
  return;
}

