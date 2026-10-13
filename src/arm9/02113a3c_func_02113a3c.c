/* Decompiled C draft; module arm9; ROM address 02113a3c. No matching claim. */
#include "types.h"
#include "deps/02113a3c_func_02113a3c.h"

void func_02113a3c(void)

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
  sVar2 = func_02113f1c();
  iVar3 = func_02114158(sVar2 + *(short *)(*piRam02113d70 + 0x74),local_28);
  piVar1 = piRam02113d70;
  if (iVar3 == 0) {
    *(undefined4 *)(*piRam02113d70 + 0x40) = 0;
    iVar3 = *(int *)(*piVar1 + 0x10);
    AllocateReserveTEQSub(9,0,iVar3 + 0xc,*(undefined4 *)(iVar3 + 8));
  }
  else {
    *(undefined4 *)(*piRam02113d70 + 0x40) = 1;
    iVar3 = *(int *)(*piVar1 + 0x20);
    AllocateReserveTEQSub(9,0,iVar3 + 0xc,*(undefined4 *)(iVar3 + 8));
  }
  iVar3 = *piRam02113d70;
  if (*(int *)(iVar3 + 0x40) != 0) {
    if (*(int *)(iVar3 + 0x40) == 1) {
      func_02114298(sVar2 + *(short *)(iVar3 + 0x74),(undefined4)(uintptr_t)(auStack_6c),0x20);
      iVar3 = *piRam02113d70;
      func_0212426c(0,0,*(undefined4 *)(iVar3 + 0x1c),auStack_6c,*(undefined4 *)(iVar3 + 0x18),
                    *(undefined4 *)(iVar3 + 0x24));
      iVar3 = 0;
      pbVar8 = local_28;
      puVar7 = puRam02113d80;
      do {
        FormatIntegerInString16_from_thumb(*pbVar8 - 0x30,(int)(uintptr_t)(auStack_6c));
        iVar5 = *piRam02113d70;
        func_0212426c(0,*puVar7,*(undefined4 *)(iVar5 + 0x1c),auStack_6c,
                      *(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x24));
        pbVar8 = pbVar8 + 1;
        puVar7 = puVar7 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0xc);
      iVar3 = *piRam02113d70;
      func_021141c8(sVar2 + *(short *)(iVar3 + 0x74),*(undefined4 *)(iVar3 + 0x78),
                    *(undefined4 *)(iVar3 + 0x7c));
      iVar5 = *piRam02113d70;
      iVar3 = func_0212497c(1,*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 0x18));
      AllocateReserveTEQSub(0x13,iVar3 << 5,*(undefined4 *)(iVar5 + 0x7c),uRam02113d7c);
      return;
    }
    return;
  }
  func_02114298(sVar2 + *(short *)(iVar3 + 0x74),(undefined4)(uintptr_t)(auStack_6c),0x20);
  iVar3 = *piRam02113d70;
  func_0212426c(0,0,*(undefined4 *)(iVar3 + 0xc),auStack_6c,*(undefined4 *)(iVar3 + 8),
                *(undefined4 *)(iVar3 + 0x14));
  local_40 = func_0211437c(sVar2 + *(short *)(*piRam02113d70 + 0x74));
  local_3c = func_02114360(sVar2 + *(short *)(*piRam02113d70 + 0x74));
  local_38 = func_02114344(sVar2 + *(short *)(*piRam02113d70 + 0x74));
  local_34 = func_02114328(sVar2 + *(short *)(*piRam02113d70 + 0x74));
  local_30 = func_0211430c(sVar2 + *(short *)(*piRam02113d70 + 0x74));
  local_2c = func_021142f0(sVar2 + *(short *)(*piRam02113d70 + 0x74));
  iVar3 = 1;
  puVar6 = &local_40;
  do {
    iVar5 = 0;
    puVar4 = puVar6;
    do {
      if (uRam02113d74 < *puVar4) {
        *puVar4 = uRam02113d74;
      }
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 3);
    puVar6 = puVar6 + 3;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  FormatIntegerInString16_from_thumb(local_40,(int)(uintptr_t)(auStack_6c));
  iVar3 = *piRam02113d70;
  func_02124248(0,*(undefined2 *)(iRam02113d78 + 6),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_3c,(int)(uintptr_t)(auStack_6c));
  iVar3 = *piRam02113d70;
  func_02124248(0,*(undefined2 *)(iRam02113d78 + 8),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_38,(int)(uintptr_t)(auStack_6c));
  iVar3 = *piRam02113d70;
  func_02124248(0,*(undefined2 *)(iRam02113d78 + 10),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_34,auStack_6c);
  iVar3 = *piRam02113d70;
  func_02124248(0,*(undefined2 *)(iRam02113d78 + 0xc),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_30,auStack_6c);
  iVar3 = *piRam02113d70;
  func_02124248(0,*(undefined2 *)(iRam02113d78 + 0xe),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  FormatIntegerInString16_from_thumb(local_2c,auStack_6c);
  iVar3 = *piRam02113d70;
  func_02124248(0,*(undefined2 *)(iRam02113d78 + 0x10),*(undefined4 *)(iVar3 + 0xc),auStack_6c,
                *(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0x14),6);
  func_021142d4(sVar2 + *(short *)(*piRam02113d70 + 0x74),auStack_70);
  func_02116a4c(auStack_70,auStack_6c);
  iVar3 = *piRam02113d70;
  func_02124224(0,0xc,*(undefined4 *)(iVar3 + 0xc),auStack_6c,*(undefined4 *)(iVar3 + 8),
                *(undefined4 *)(iVar3 + 0x14),6);
  iVar3 = *piRam02113d70;
  func_021141c8(sVar2 + *(short *)(iVar3 + 0x74),*(undefined4 *)(iVar3 + 0x78),
                *(undefined4 *)(iVar3 + 0x7c));
  iVar5 = *piRam02113d70;
  iVar3 = func_0212497c(3,*(undefined4 *)(iVar5 + 4),*(undefined4 *)(iVar5 + 8));
  AllocateReserveTEQSub(0x13,iVar3 << 5,*(undefined4 *)(iVar5 + 0x7c),uRam02113d7c);
  return;
}

