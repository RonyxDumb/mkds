/* Decompiled C draft; module arm9_ov000; ROM address 021a8014. No matching claim. */
#include "types.h"
#include "deps/021a8014_FUN_021a8014.h"

int FUN_021a8014(int param_1,int param_2,int param_3,int param_4,undefined2 param_5,int param_6,
                undefined4 param_7)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = *(int *)(param_1 + 0x68);
  iVar3 = FUN_021a7064(DAT_021a810c,*(undefined4 *)(iVar2 + DAT_021a8110),param_7);
  if (iVar3 == 0) {
    return -0x21;
  }
  *(undefined1 *)(iVar3 + 0xd) = 0;
  iVar6 = *(int *)(iVar2 + 0xfc);
  iVar5 = *(int *)(iVar2 + 0xf8);
  iVar4 = param_4 + param_3;
  if (iVar4 < iVar5) {
    *(int *)(iVar3 + 0x10) = iVar6 + param_4;
    *(int *)(iVar3 + 0x14) = param_3;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
  }
  else {
    *(int *)(iVar3 + 0x10) = iVar6 + param_4;
    *(int *)(iVar3 + 0x14) = iVar5 - param_4;
    *(int *)(iVar3 + 0x18) = iVar6;
    *(int *)(iVar3 + 0x1c) = param_3 - *(int *)(iVar3 + 0x14);
    iVar4 = *(int *)(iVar3 + 0x1c);
    func_0x0214d1fc(param_2 + *(int *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x18),iVar4);
  }
  func_0x0214d1fc(param_2,*(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14));
  *(short *)(iVar3 + 0x20) = (short)iVar4;
  *(undefined2 *)(iVar2 + DAT_021a8114) = *(undefined2 *)(iVar3 + 0x20);
  if (*(char *)(param_1 + 0x73) == '\x01') {
    if (*(short *)(param_1 + 0x74) == 0) {
      uVar1 = FUN_021ae340();
      *(undefined2 *)(param_1 + 0x74) = uVar1;
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x74);
    }
    *(undefined2 *)(iVar3 + 0x24) = *(undefined2 *)(param_1 + 0x74);
    if ((*(int *)(param_1 + 0x78) == 0) || (param_6 != 0)) {
      *(int *)(iVar3 + 0x28) = param_6;
      *(undefined2 *)(iVar3 + 0x26) = param_5;
    }
    else {
      *(int *)(iVar3 + 0x28) = *(int *)(param_1 + 0x78);
      *(undefined2 *)(iVar3 + 0x26) = *(undefined2 *)(param_1 + 0x76);
    }
  }
  else {
    *(undefined4 *)(iVar3 + 0x28) = 0;
  }
  iVar2 = FUN_021a6fa8(*(undefined4 *)(iVar2 + DAT_021a8110),iVar3);
  if (iVar2 != 0) {
    param_3 = 0;
  }
  return param_3;
}

