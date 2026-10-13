/* Decompiled C draft; module arm9; ROM address 0202511c. No matching claim. */
#include "types.h"
#include "deps/0202511c_MaybeGetMusicForMenu.h"

int MaybeGetMusicForMenu(undefined4 param_1,undefined1 *param_2)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  undefined1 auStack_18 [2];
  undefined1 local_16;
  
  uVar5 = DAT_02025538;
  iVar7 = DAT_02025530;
  iVar8 = 0x36;
  bVar2 = false;
  switch(param_1) {
  case 0:
    iVar8 = 0x33;
    break;
  case 1:
    iVar8 = 0x32;
    break;
  case 2:
    uVar6 = *(uint *)(DAT_0202552c & 0xfffffffc) >> (DAT_0202552c & 3) * 8 |
            *(uint *)(DAT_0202552c & 0xfffffffc) << (DAT_0202552c & 3) * -8 + 0x20;
    uVar5 = uVar6 + 0xc & 3;
    uVar4 = *(uint *)(uVar6 + 0xc & 0xfffffffc);
    switch(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) {
    case 0:
      goto LAB_020251b0;
    case 1:
      iVar8 = 0x33;
      break;
    case 2:
LAB_020251b0:
      uVar5 = uVar6 + 8 & 3;
      uVar4 = *(uint *)(uVar6 + 8 & 0xfffffffc);
      iVar8 = GetCourseBgmInfo(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                               *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20);
      bVar2 = true;
      if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) != 4) break;
      uVar5 = *(uint *)(DAT_0202552c & 0xfffffffc) >> (DAT_0202552c & 3) * 8 |
              *(uint *)(DAT_0202552c & 0xfffffffc) << (DAT_0202552c & 3) * -8 + 0x20;
      if (*(char *)(uVar5 + 0x2e) == '\x04') {
        param_2[1] = 0x2a;
      }
      else {
        switch(*(undefined1 *)(uVar5 + 0x2f)) {
        case 0:
          break;
        case 1:
          param_2[1] = 0x2c;
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 8:
          break;
        case 9:
          break;
        case 10:
        }
      }
      bVar1 = *(byte *)(uVar5 + 0x2e);
      bVar9 = true;
      if (0x15 < bVar1) {
        if (bVar1 < 0x32) {
          if (bVar1 == 0x31) goto LAB_020252fc;
        }
        else if ((bVar1 < 0x34) && (0x31 < bVar1)) {
          if (bVar1 == 0x32) {
            param_2[2] = 0x26;
          }
          else {
            if (bVar1 != 0x33) goto LAB_020252f8;
            param_2[2] = 0x28;
          }
          goto LAB_020252fc;
        }
        goto LAB_020252f8;
      }
      if (bVar1 < 0x15) {
        if (bVar1 < 0xb) {
          if ((bVar1 < 9) || ((bVar1 != 9 && (bVar1 != 10)))) {
LAB_020252f8:
            bVar9 = false;
          }
          else {
            param_2[2] = 0x25;
          }
        }
        else {
          if (bVar1 != 0x11) goto LAB_020252f8;
          param_2[2] = 0x29;
        }
      }
      else {
        param_2[2] = 0x27;
      }
LAB_020252fc:
      if (bVar9) {
        param_2[3] = 0x22;
      }
      break;
    case 3:
      uVar5 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      if ((int)uVar5 < 0x15) {
        if ((0x13 < (int)uVar5) || (uVar5 == 0xe)) {
LAB_02025374:
          iVar8 = 2;
          goto LAB_02025390;
        }
LAB_0202538c:
        iVar8 = 1;
      }
      else {
        if ((int)uVar5 < 0x1a) {
          if (uVar5 == 0x19) goto LAB_02025374;
          goto LAB_0202538c;
        }
        if ((0x22 < (int)uVar5) || ((int)uVar5 < 0x21)) goto LAB_0202538c;
        if (uVar5 == 0x21) {
          iVar8 = 4;
        }
        else {
          if (uVar5 != 0x22) goto LAB_0202538c;
          iVar8 = 3;
        }
      }
LAB_02025390:
      iVar7 = IsInBossMissionStage();
      uVar5 = DAT_0202552c;
      if (iVar7 == 0) {
        iVar7 = DAT_02025530 + iVar8 * 4;
        uVar3 = *(undefined1 *)(iVar7 + 1);
        bVar2 = true;
        *param_2 = *(undefined1 *)(DAT_02025530 + iVar8 * 4);
        param_2[1] = uVar3;
        uVar3 = *(undefined1 *)(iVar7 + 3);
        param_2[2] = *(undefined1 *)(iVar7 + 2);
        param_2[3] = uVar3;
        uVar4 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
        uVar5 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        GetCourseBgmInfo(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,auStack_18);
        param_2[2] = local_16;
      }
      else {
        iVar8 = 6;
      }
      break;
    case 4:
      iVar8 = 5;
      break;
    case 5:
      iVar8 = 0x2a;
      break;
    case 6:
      iVar8 = 0x33;
    }
    break;
  case 3:
    goto LAB_02025490;
  case 4:
    iVar8 = 0x33;
    break;
  case 5:
    iVar8 = 0x33;
    break;
  case 6:
    if (*DAT_02025534 == 2) {
      iVar8 = 0x33;
    }
    else {
      iVar8 = 0x2e;
    }
    break;
  case 7:
    goto LAB_02025490;
  case 8:
    iVar8 = 0x2f;
    break;
  case 9:
    iVar8 = 0x31;
    break;
  case 10:
    iVar8 = 0x29;
    uVar3 = *(undefined1 *)(DAT_02025530 + 0xa5);
    bVar2 = true;
    *param_2 = *(undefined1 *)(DAT_02025530 + 0xa4);
    param_2[1] = uVar3;
    uVar3 = *(undefined1 *)(iVar7 + 0xa7);
    param_2[2] = *(undefined1 *)(iVar7 + 0xa6);
    param_2[3] = uVar3;
    uVar3 = func_0211127c();
    param_2[1] = uVar3;
    break;
  case 0xb:
    goto LAB_02025490;
  case 0xc:
    iVar8 = 0x2d;
    break;
  case 0xd:
    iVar8 = 0x2e;
    break;
  case 0xe:
LAB_02025490:
    iVar8 = 0x30;
    uVar3 = *(undefined1 *)(DAT_02025530 + 0xc1);
    bVar2 = true;
    *param_2 = *(undefined1 *)(DAT_02025530 + 0xc0);
    param_2[1] = uVar3;
    uVar3 = *(undefined1 *)(iVar7 + 0xc3);
    param_2[2] = *(undefined1 *)(iVar7 + 0xc2);
    param_2[3] = uVar3;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    bVar9 = uVar5 != 0;
    if (bVar9) {
      uVar5 = 0xff;
    }
    uVar3 = (undefined1)uVar5;
    if (bVar9) {
      param_2[1] = uVar3;
      param_2[2] = uVar3;
      param_2[3] = uVar3;
    }
    break;
  case 0xf:
    iVar8 = 0x33;
  }
  if ((!bVar2) && (param_2 != (undefined1 *)0x0)) {
    iVar7 = DAT_02025530 + iVar8 * 4;
    uVar3 = *(undefined1 *)(iVar7 + 1);
    *param_2 = *(undefined1 *)(DAT_02025530 + iVar8 * 4);
    param_2[1] = uVar3;
    uVar3 = *(undefined1 *)(iVar7 + 3);
    param_2[2] = *(undefined1 *)(iVar7 + 2);
    param_2[3] = uVar3;
  }
  return iVar8;
}

