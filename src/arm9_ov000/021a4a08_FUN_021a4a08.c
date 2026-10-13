/* Decompiled C draft; module arm9_ov000; ROM address 021a4a08. No matching claim. */
#include "types.h"
#include "deps/021a4a08_FUN_021a4a08.h"

undefined4
FUN_021a4a08(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
            undefined4 param_14)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined1 extraout_r1;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  char acStack_58 [68];
  
  puVar4 = DAT_021a4b5c;
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = FUN_021a3690(DAT_021a4b60);
    *param_1 = uVar1;
    puVar4 = (undefined4 *)*param_1;
  }
  FUN_0218e8c4();
  func_0x021384cc();
  func_0x0213a2d0(puVar4 + 1,param_4);
  func_0x0213a2d0(puVar4 + 0x11,param_5);
  puVar4[0x30] = param_3;
  iVar5 = 0;
  puVar4[0x2b] = 0;
  puVar4[0x2c] = 0;
  *puVar4 = param_2;
  puVar4[0x2e] = 1;
  *(undefined4 *)((int)puVar4 + DAT_021a4b64) = param_14;
  puVar4[0x22] = param_8;
  puVar4[0x23] = param_9;
  puVar4[0x24] = param_10;
  puVar4[0x25] = param_11;
  puVar4[0x26] = param_12;
  puVar4[0x27] = param_13;
  puVar4[0x28] = 0;
  puVar4[0x29] = 0;
  puVar4[0x35] = 0;
  puVar4[0x2f] = param_6;
  puVar4[0x31] = 0;
  puVar4[0x32] = param_7;
  *(undefined4 *)((int)puVar4 + DAT_021a4b68) = 0;
  *(undefined2 *)((int)puVar4 + DAT_021a4b6c) = 0;
  puVar4[0x2a] = 0;
  puVar4[0x2d] = 0;
  do {
    uVar1 = func_0x021384dc();
    func_0x02133068(uVar1,0xff);
    *(undefined1 *)((int)puVar4 + iVar5 + 0x84) = extraout_r1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 4);
  iVar5 = 0;
  puVar3 = puVar4;
  do {
    puVar3[0x36] = 0xffffffff;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 10);
  *(undefined4 *)((int)puVar4 + DAT_021a4b70) = 0;
  if (*DAT_021a4b74 == 0) {
    FUN_021a46d4();
  }
  if (param_6 == 0) {
    iVar5 = 1;
  }
  else {
    pcVar2 = DAT_021a4b78;
    if (*DAT_021a4b78 == '\0') {
      func_0x02135014(acStack_58,DAT_021a4b7c,param_4);
      pcVar2 = acStack_58;
    }
    iVar5 = FUN_021a4654((int)(uintptr_t)(pcVar2),DAT_021a4b80,(int)(uintptr_t)(puVar4 + 0x33),0);
  }
  if (iVar5 != 0) {
    return 0;
  }
  return 3;
}

