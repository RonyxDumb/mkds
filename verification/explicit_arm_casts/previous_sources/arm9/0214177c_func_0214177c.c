/* Decompiled C draft; module arm9; ROM address 0214177c. No matching claim. */
#include "types.h"
#include "deps/0214177c_func_0214177c.h"

void func_0214177c(undefined2 *param_1,uint param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined1 auStack_58 [38];
  undefined2 auStack_32 [19];
  undefined2 *puVar6;
  
  if ((int)param_2 < -0x34) {
    if (-0x36 < (int)param_2) {
      func_02141b5c(param_1,DAT_02141b0c,0xfffffff0);
      return;
    }
    if (param_2 == 0xffffffc0) {
      func_02141b5c(param_1,DAT_02141b08,0xffffffec);
      return;
    }
  }
  else {
    switch(param_2) {
    case 0:
      func_02141b5c(param_1,DAT_02141b38,0);
      return;
    case 1:
      func_02141b5c(param_1,DAT_02141b3c,0);
      return;
    case 2:
      func_02141b5c(param_1,DAT_02141b40,0);
      return;
    case 3:
      func_02141b5c(param_1,DAT_02141b44,0);
      return;
    case 4:
      func_02141b5c(param_1,DAT_02141b48,1);
      return;
    case 5:
      func_02141b5c(param_1,DAT_02141b4c,1);
      return;
    case 6:
      func_02141b5c(param_1,DAT_02141b50,1);
      return;
    case 7:
      func_02141b5c(param_1,DAT_02141b54,2);
      return;
    case 8:
      func_02141b5c(param_1,DAT_02141b58,2);
      return;
    case 0xffffffe0:
      func_02141b5c(param_1,DAT_02141b10,0xfffffff6);
      return;
    case 0xffffffe1:
      break;
    case 0xffffffe2:
      break;
    case 0xffffffe3:
      break;
    case 0xffffffe4:
      break;
    case 0xffffffe5:
      break;
    case 0xffffffe6:
      break;
    case 0xffffffe7:
      break;
    case 0xffffffe8:
      break;
    case 0xffffffe9:
      break;
    case 0xffffffea:
      break;
    case 0xffffffeb:
      break;
    case 0xffffffec:
      break;
    case 0xffffffed:
      break;
    case 0xffffffee:
      break;
    case 0xffffffef:
      break;
    case 0xfffffff0:
      func_02141b5c(param_1,DAT_02141b14,0xfffffffb);
      return;
    case 0xfffffff1:
      break;
    case 0xfffffff2:
      break;
    case 0xfffffff3:
      break;
    case 0xfffffff4:
      break;
    case 0xfffffff5:
      break;
    case 0xfffffff6:
      break;
    case 0xfffffff7:
      break;
    case 0xfffffff8:
      func_02141b5c(param_1,DAT_02141b18,0xfffffffd);
      return;
    case 0xfffffff9:
      func_02141b5c(param_1,DAT_02141b1c,0xfffffffd);
      return;
    case 0xfffffffa:
      func_02141b5c(param_1,DAT_02141b20,0xfffffffe);
      return;
    case 0xfffffffb:
      func_02141b5c(param_1,DAT_02141b24,0xfffffffe);
      return;
    case 0xfffffffc:
      func_02141b5c(param_1,DAT_02141b28,0xfffffffe);
      return;
    case 0xfffffffd:
      func_02141b5c(param_1,DAT_02141b2c,0xffffffff);
      return;
    case 0xfffffffe:
      func_02141b5c(param_1,DAT_02141b30,0xffffffff);
      return;
    case 0xffffffff:
      func_02141b5c(param_1,DAT_02141b34,0xffffffff);
      return;
    }
  }
  func_0214177c(auStack_58,(int)param_2 / 2);
  func_02141c98(param_1,auStack_58,auStack_58);
  if ((param_2 & 1) == 0) {
    return;
  }
  puVar4 = auStack_32;
  iVar3 = 9;
  puVar5 = param_1;
  do {
    puVar6 = puVar5 + 1;
    uVar1 = *puVar5;
    puVar5 = puVar5 + 2;
    uVar2 = *puVar6;
    iVar3 = iVar3 + -1;
    puVar6 = puVar4 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 2;
    *puVar6 = uVar2;
  } while (iVar3 != 0);
  *puVar4 = *puVar5;
  if ((int)param_2 < 1) {
    func_02141b5c(auStack_58,DAT_02141b34,0xffffffff);
  }
  else {
    func_02141b5c(auStack_58,DAT_02141b3c,0);
  }
  func_02141c98(param_1,auStack_32,auStack_58);
  return;
}

