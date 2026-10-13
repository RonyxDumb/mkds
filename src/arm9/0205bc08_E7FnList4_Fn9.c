/* Decompiled C draft; module arm9; ROM address 0205bc08. No matching claim. */
#include "types.h"
#include "deps/0205bc08_E7FnList4_Fn9.h"

void E7FnList4_Fn9(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  func_0205a908();
  func_0205a350();
  uVar3 = *(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
          *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x754 & 3;
  uVar6 = *(uint *)(uVar3 + 0x754 & 0xfffffffc);
  uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  uVar2 = uVar7 + 4 & 3;
  uVar5 = *(uint *)(uVar7 + 4 & 0xfffffffc);
  uVar6 = uVar3 + 0x728 & 3;
  uVar4 = *(uint *)(uVar3 + 0x728 & 0xfffffffc);
  uVar3 = 0x68 - *(ushort *)(uVar3 + 0x724);
  *(uint *)(uVar7 + 4) =
       (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) & 0xff000000 |
       (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0xffffff;
  *(char *)(uVar7 + 7) = (char)(uVar3 * 0x10000 >> 0x10);
  iVar1 = func_0x0219bb50();
  if (*(char *)((*(uint *)(uRam0205be00 & 0xfffffffc) >> (uRam0205be00 & 3) * 8 |
                *(uint *)(uRam0205be00 & 0xfffffffc) << (uRam0205be00 & 3) * -8 + 0x20) + iVar1 + 6)
      < '\0') {
    *(undefined4 *)(uVar7 + 8) = 0;
  }
  else {
    uVar2 = func_0205afa8();
    *(uint *)(uVar7 + 8) =
         uVar2 | (*(byte *)((*(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
                            *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20)
                           + 0x73e) & 0xf) << 0x17;
  }
  func_0205c234(uVar3 & 0xffff);
  func_0205be0c();
  iVar1 = func_0x0219bb50();
  iVar1 = IsRacerFinishedRace(*(undefined1 *)
                               ((*(uint *)(uRam0205be00 & 0xfffffffc) >> (uRam0205be00 & 3) * 8 |
                                *(uint *)(uRam0205be00 & 0xfffffffc) <<
                                (uRam0205be00 & 3) * -8 + 0x20) + iVar1 + 6));
  if ((iVar1 == 0) &&
     ((*(ushort *)
        ((*(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
         *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20) + 0x75c) & 0x200)
      == 0)) {
    iVar1 = GetDirectInputUnitIndex();
    uVar6 = uRam0205be08;
    uVar2 = uRam0205bdfc;
    if (*(short *)(iRam0205be04 + iVar1 * 0x5c) == 0) {
      uVar3 = *(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
              *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20;
      *(short *)(uVar3 + 0x738) = *(short *)(uVar3 + 0x738) + 1;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if (uVar6 < *(ushort *)(uVar2 + 0x738)) {
        *(ushort *)(uVar2 + 0x75c) = *(ushort *)(uVar2 + 0x75c) | 0x200;
        func_021208e8(1);
      }
    }
    else {
      *(undefined2 *)
       ((*(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
        *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20) + 0x738) = 0;
    }
  }
  uVar2 = (*(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
          *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20) + 0x758;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) == 2) {
    iVar1 = func_020b2e34();
    uVar2 = uRam0205bdfc;
    if ((iVar1 != 2) && (iVar1 != 7)) {
      if (iVar1 == 9) {
        *(undefined4 *)
         ((*(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
          *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20) + 0x758) = 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
        *(undefined2 *)(uVar2 + 0x10) = 5;
        *(undefined2 *)(uVar2 + 0x12) = 1;
        return;
      }
      return;
    }
    *(undefined4 *)
     ((*(uint *)(uRam0205bdfc & 0xfffffffc) >> (uRam0205bdfc & 3) * 8 |
      *(uint *)(uRam0205bdfc & 0xfffffffc) << (uRam0205bdfc & 3) * -8 + 0x20) + 0x758) = 4;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar2 + 0x10) = 5;
    *(undefined2 *)(uVar2 + 0x12) = 1;
    return;
  }
  return;
}

