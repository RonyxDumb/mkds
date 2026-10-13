/* Decompiled C draft; module arm9; ROM address 020a826c. No matching claim. */
#include "types.h"
#include "deps/020a826c_func_020a826c.h"

void func_020a826c(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = param_2 + 0xf0U & 3;
  uVar1 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
  switch(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    iVar5 = IsAwardOrStaffRoll();
    if (iVar5 == 1) {
      uVar2 = param_2 + 0xbcU & 3;
      uVar4 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      uVar1 = param_2 + 200U & 3;
      uVar6 = *(uint *)(param_2 + 200U & 0xfffffffc);
      func_0212c6f0(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,0);
      *(uint *)(param_2 + 0xa0) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      *(undefined4 *)(param_2 + 0xf0) = 2;
    }
    uVar2 = param_2 + 0xa8U & 3;
    uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xac) = uVar3;
    uVar1 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xc4U & 3;
      uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xc4) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 != 0) {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b734(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
        return;
      }
      uVar2 = param_2 + 0xbcU & 3;
      uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      func_0210b760(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      return;
    }
    *(undefined4 *)(param_2 + 0xc4) = 0;
    return;
  case 2:
    func_020a8ed8(param_2 + 0xa0,param_2 + 4);
    uVar4 = *(uint *)(DAT_020a8a68 & 0xfffffffc) >> (DAT_020a8a68 & 3) * 8 |
            *(uint *)(DAT_020a8a68 & 0xfffffffc) << (DAT_020a8a68 & 3) * -8 + 0x20;
    uVar2 = uVar4 + 0xc;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((((uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) &&
         (iVar5 = UpdatePlayerLapCountIfNot123((short)*(char *)(uVar4 + 0x62)), iVar5 != 0)) &&
        (uVar2 = param_2 + 0xc4U & 3, uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc),
        uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0)) &&
       (uVar2 = param_2 + 0xc0U & 3, uVar1 = *(uint *)(param_2 + 0xc0U & 0xfffffffc),
       uVar1 >> uVar2 * 8 != 0 || uVar1 << uVar2 * -8 + 0x20 != 0)) {
      uVar3 = func_02110c40();
      uVar2 = param_2 + 0xbcU & 3;
      uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      func_0212c6f0(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20,0);
      *(undefined4 *)(param_2 + 0xa0) = uVar3;
      *(undefined4 *)(param_2 + 0xf0) = 3;
    }
    uVar2 = param_2 + 0xa8U & 3;
    uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xac) = uVar3;
    uVar1 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xc4U & 3;
      uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xc4) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 != 0) {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b734(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
        return;
      }
      uVar2 = param_2 + 0xbcU & 3;
      uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      func_0210b760(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      return;
    }
    *(undefined4 *)(param_2 + 0xc4) = 0;
    return;
  case 3:
    func_020a8ed8(param_2 + 0xa0,param_2 + 4);
    iVar5 = IsRacerFinishedRace((short)*(char *)((*(uint *)(DAT_020a8a68 & 0xfffffffc) >>
                                                  (DAT_020a8a68 & 3) * 8 |
                                                 *(uint *)(DAT_020a8a68 & 0xfffffffc) <<
                                                 (DAT_020a8a68 & 3) * -8 + 0x20) + 0x62));
    if (iVar5 == 0) {
      uVar2 = param_2 + 0xc0U & 3;
      uVar1 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar2 = param_2 + 0xbcU & 3;
        uVar4 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        uVar1 = param_2 + 200U & 3;
        uVar6 = *(uint *)(param_2 + 200U & 0xfffffffc);
        func_0212c6f0(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,0);
        *(uint *)(param_2 + 0xa0) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
        *(undefined4 *)(param_2 + 0xf0) = 2;
      }
    }
    else {
      func_020d2398(param_2);
    }
    uVar2 = param_2 + 0xa8U & 3;
    uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xac) = uVar3;
    uVar1 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xc4U & 3;
      uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xc4) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 != 0) {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b734(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
        return;
      }
      uVar2 = param_2 + 0xbcU & 3;
      uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      func_0210b760(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      return;
    }
    *(undefined4 *)(param_2 + 0xc4) = 0;
    return;
  case 4:
    uVar2 = param_2 + 0xa8U & 3;
    uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xac) = uVar3;
    uVar1 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xc4U & 3;
      uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xc4) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 == 0) {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b760(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      }
      else {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b734(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      }
    }
    else {
      *(undefined4 *)(param_2 + 0xc4) = 0;
    }
    uVar2 = param_2 + 0xd0U & 3;
    uVar1 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xd8);
    *(undefined4 *)(param_2 + 0xd4) = uVar3;
    uVar1 = param_2 + 0xd4U & 3;
    uVar4 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xecU & 3;
      uVar1 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xec) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 != 0) {
        uVar2 = param_2 + 0xe4U & 3;
        uVar1 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
        func_0210b734(param_2 + 200,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
        return;
      }
      uVar2 = param_2 + 0xe4U & 3;
      uVar1 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
      func_0210b760(param_2 + 200,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      return;
    }
    *(undefined4 *)(param_2 + 0xec) = 0;
    return;
  case 5:
    uVar2 = param_2 + 0xa8U & 3;
    uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xac) = uVar3;
    uVar1 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xc4U & 3;
      uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xc4) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 != 0) {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b734(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
        return;
      }
      uVar2 = param_2 + 0xbcU & 3;
      uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      func_0210b760(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      return;
    }
    *(undefined4 *)(param_2 + 0xc4) = 0;
    return;
  case 6:
    uVar2 = param_2 + 0xa8U & 3;
    uVar1 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xac) = uVar3;
    uVar1 = param_2 + 0xacU & 3;
    uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xc4U & 3;
      uVar1 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xc4) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 == 0) {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b760(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      }
      else {
        uVar2 = param_2 + 0xbcU & 3;
        uVar1 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        func_0210b734(param_2 + 0xa0,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      }
    }
    else {
      *(undefined4 *)(param_2 + 0xc4) = 0;
    }
    uVar2 = param_2 + 0xd0U & 3;
    uVar1 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 2) {
      uVar2 = DAT_020a8a64 + 0x68U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x68U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 3) {
      uVar2 = DAT_020a8a64 + 0x8cU & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x8cU & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 4) {
      uVar2 = DAT_020a8a64 + 0xb0U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xb0U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 5) {
      uVar2 = DAT_020a8a64 + 0xd4U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xd4U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 6) {
      uVar2 = DAT_020a8a64 + 0xf8U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0xf8U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else if (uVar2 == 8) {
      uVar2 = DAT_020a8a64 + 0x140U & 3;
      uVar1 = *(uint *)(DAT_020a8a64 + 0x140U & 0xfffffffc);
      uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = 0;
    }
    uVar3 = func_020d4ef4(param_2 + 0xd8);
    *(undefined4 *)(param_2 + 0xd4) = uVar3;
    uVar1 = param_2 + 0xd4U & 3;
    uVar4 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < uVar2) {
      uVar2 = param_2 + 0xecU & 3;
      uVar1 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
      if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
      *(undefined4 *)(param_2 + 0xec) = uVar3;
      iVar5 = IsNotStaffRoll();
      if (iVar5 != 0) {
        uVar2 = param_2 + 0xe4U & 3;
        uVar1 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
        func_0210b734(param_2 + 200,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
        return;
      }
      uVar2 = param_2 + 0xe4U & 3;
      uVar1 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
      func_0210b760(param_2 + 200,uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
      return;
    }
    *(undefined4 *)(param_2 + 0xec) = 0;
  }
  return;
}

