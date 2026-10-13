/* Decompiled C draft; module arm9_ov000; ROM address 02185984. No matching claim. */
#include "types.h"
#include "deps/02185984_FUN_02185984.h"

undefined4
FUN_02185984(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,
            undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 local_128;
  undefined1 local_126 [6];
  undefined1 local_120;
  undefined1 local_11f;
  undefined1 local_11e;
  undefined1 local_11d;
  undefined1 local_11c;
  undefined1 local_11b;
  undefined1 auStack_11a [4];
  undefined1 local_116;
  undefined1 auStack_115 [2];
  undefined1 local_113;
  undefined1 auStack_112 [5];
  undefined1 auStack_10d [5];
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  int *local_ec;
  undefined4 local_e8;
  undefined1 auStack_e0 [12];
  undefined1 local_d4;
  undefined1 auStack_d3 [13];
  undefined1 auStack_c6 [20];
  undefined1 local_b2;
  undefined1 auStack_b1 [13];
  undefined1 auStack_a4 [33];
  undefined1 auStack_83 [3];
  undefined1 auStack_80 [11];
  undefined1 auStack_75 [15];
  byte local_66 [2];
  undefined1 local_64;
  undefined1 local_63;
  undefined1 auStack_62 [78];
  
  func_0x0200fe58(local_126);
  func_0x0200fddc(local_66);
  iVar1 = func_0x0214e038(&local_108);
  if ((iVar1 != 0) || (iVar1 = func_0x0214df78(&local_f8), iVar1 != 0)) {
    return 5;
  }
  uVar2 = func_0x0200fca0();
  iVar1 = FUN_021a6b10();
  if (iVar1 == 0) {
    func_0x0200fcb4(uVar2);
    return 3;
  }
  func_0x0214d1fc(iVar1,&local_120,6);
  func_0x0214d168(auStack_a4,0,0x21);
  iVar1 = FUN_021a6abc(&local_128);
  if (iVar1 == 0) {
    func_0x0200fcb4(uVar2);
    return 3;
  }
  func_0x0214d1fc(iVar1,auStack_a4,local_128);
  func_0x0200fcb4(uVar2);
  func_0x0214d1fc(DAT_02185ccc,auStack_11a,4);
  local_116 = 0;
  func_0x0214d1fc(DAT_02185cd0,auStack_115,2);
  iVar4 = 0;
  local_113 = 0;
  puVar3 = local_126;
  iVar1 = 0;
  do {
    func_0x0200da28(auStack_e0 + iVar1,DAT_02185cd4,*puVar3);
    puVar3 = puVar3 + 1;
    iVar1 = iVar1 + 2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  local_d4 = 0;
  if (6 < local_66[0]) {
    local_66[0] = 1;
  }
  func_0x0200d9e0(auStack_112,5,DAT_02185cd8,local_64,local_63);
  func_0x0200d9e0(auStack_d3,0xd,DAT_02185cdc,local_108,local_104,local_100,local_f8,local_f4,
                  local_f0);
  func_0x0214d1fc(auStack_62,auStack_c6,0x14);
  local_b2 = 0;
  func_0x0214d168(&local_ec,0,0xc);
  local_e8 = param_5;
  local_ec = param_4;
  if (param_6 == 1) {
    func_0x02151910(DAT_02185ce0);
  }
  else if (DAT_02185ce0[1] == 0 && *DAT_02185ce0 == 0) {
    FUN_021868a4(&local_ec,DAT_02185ce4,DAT_02185ce8);
  }
  else {
    iVar1 = func_0x0213a434(param_2);
    if (iVar1 == 0) {
      return 6;
    }
    FUN_021868a4(&local_ec,DAT_02185ce4,DAT_02185cec);
    FUN_021868a4(&local_ec,DAT_02185cf0,param_2);
    iVar1 = func_0x0213a434(param_3);
    if (iVar1 != 0) {
      FUN_021868a4(&local_ec,DAT_02185cf4,param_3);
    }
  }
  FUN_021868a4(&local_ec,DAT_02185cf8,DAT_02185cfc);
  iVar1 = DAT_02185ce0[1];
  if (iVar1 == 0 && *DAT_02185ce0 == 0) {
    iVar1 = DAT_02185ce0[3];
    func_0x0200d9e0(auStack_75,0xe,DAT_02185d00,DAT_02185ce0[2],iVar1);
  }
  else {
    func_0x0200d9e0(auStack_75,0xe,DAT_02185d00,*DAT_02185ce0,iVar1);
  }
  FUN_021868a4(&local_ec,DAT_02185d04,auStack_75);
  func_0x0200d9e0(auStack_10d,4,DAT_02185d08,(short)DAT_02185ce0[4],iVar1);
  FUN_021868a4(&local_ec,DAT_02185d0c,auStack_10d);
  func_0x0200d9e0(auStack_b1,0xd,DAT_02185d10,local_120,local_11f,local_11e,local_11d,local_11c,
                  local_11b);
  func_0x0200d9e0(auStack_83,0xd,DAT_02185d14,0);
  FUN_0218a67c(auStack_a4,auStack_80);
  FUN_021868a4(&local_ec,DAT_02185d18,auStack_11a);
  FUN_021868a4(&local_ec,DAT_02185d1c,auStack_115);
  FUN_021868a4(&local_ec,DAT_02185d20,DAT_02185d24);
  FUN_021868a4(&local_ec,DAT_02185d28,auStack_e0);
  FUN_021868a4(&local_ec,DAT_02185d2c,*(undefined4 *)(DAT_02185d30 + (uint)local_66[0] * 4));
  FUN_021868a4(&local_ec,DAT_02185d34,auStack_112);
  FUN_021868a4(&local_ec,DAT_02185d38,auStack_d3);
  FUN_021868a4(&local_ec,DAT_02185d3c,auStack_b1);
  FUN_021868a4(&local_ec,DAT_02185d40,auStack_83);
  iVar1 = FUN_02186bd4(param_1,DAT_02185d44,DAT_02185d48);
  if (iVar1 != 0) {
    return 7;
  }
  iVar1 = FUN_02186bd4(param_1,DAT_02185d4c,auStack_11a);
  if (iVar1 != 0) {
    return 7;
  }
  iVar1 = *param_4;
  while (iVar1 != 0) {
    iVar1 = param_4[1];
    uVar2 = func_0x0213a434(iVar1);
    iVar1 = FUN_02186b0c(param_1,*param_4,iVar1,uVar2);
    if (iVar1 != 0) {
      return 8;
    }
    param_4 = param_4 + 2;
    iVar1 = *param_4;
  }
  iVar1 = FUN_02186b0c(param_1,DAT_02185d50,auStack_c6,0x14);
  if (iVar1 == 0) {
    return 0;
  }
  return 8;
}

