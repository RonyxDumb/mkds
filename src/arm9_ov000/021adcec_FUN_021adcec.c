/* Decompiled C draft; module arm9_ov000; ROM address 021adcec. No matching claim. */
#include "types.h"
#include "deps/021adcec_FUN_021adcec.h"

int FUN_021adcec(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  
  local_28 = 0;
  *(undefined4 *)(param_5 + 0x34) = 0;
  iVar5 = 0;
  uVar6 = func_0x0200f5ac();
  puVar1 = DAT_021ade3c;
  local_20 = (uint)uVar6 >> 0x10 | (int)((ulonglong)uVar6 >> 0x20) << 0x10;
  local_38 = param_1;
  local_34 = param_2;
  local_30 = param_3;
  local_2c = param_4;
  do {
    iVar4 = (*(code *)*puVar1)();
    if ((((iVar4 == 0) || (local_34 == 0)) || (*(char *)(param_5 + 8) != '\x04')) ||
       (uVar6 = func_0x0200f5ac(),
       0x9e < (int)(((uint)uVar6 >> 0x10 | (int)((ulonglong)uVar6 >> 0x20) << 0x10) - local_20))) {
      return local_28;
    }
    iVar4 = *(int *)(param_5 + 0x28);
    FUN_021ade40(local_38,local_34,local_30,local_2c,param_5,iVar5);
    uVar6 = func_0x0200f5ac();
    while( true ) {
      FUN_021b04d4();
      iVar2 = (*(code *)*puVar1)();
      if ((iVar2 == 0) || (*(char *)(param_5 + 8) != '\x04')) break;
      if (*(int *)(param_5 + 0x28) == *(int *)(param_5 + 0x30)) break;
      uVar7 = func_0x0200f5ac();
      if ((0xe < (int)(((uint)uVar7 >> 0x10 | (int)((ulonglong)uVar7 >> 0x20) << 0x10) -
                      ((uint)uVar6 >> 0x10 | (int)((ulonglong)uVar6 >> 0x20) << 0x10))) ||
         ((iVar5 != 0 && (*(short *)(param_5 + 0x2c) != 0)))) break;
    }
    uVar3 = *(int *)(param_5 + 0x30) - iVar4;
    local_28 = local_28 + uVar3;
    if (uVar3 != 0) {
      uVar6 = func_0x0200f5ac();
      local_20 = (uint)uVar6 >> 0x10 | (int)((ulonglong)uVar6 >> 0x20) << 0x10;
    }
    *(undefined4 *)(param_5 + 0x28) = *(undefined4 *)(param_5 + 0x30);
    if (((*(char *)(param_5 + 8) == '\x04') && (*(short *)(param_5 + 0x2c) == 0)) && (uVar3 == 0)) {
      if (iVar5 == 0) {
        uVar6 = func_0x0200f5ac();
        while (iVar4 = (*(code *)*puVar1)(), iVar4 != 0) {
          uVar7 = func_0x0200f5ac();
          if ((0xe < (int)(((uint)uVar7 >> 0x10 | (int)((ulonglong)uVar7 >> 0x20) << 0x10) -
                          ((uint)uVar6 >> 0x10 | (int)((ulonglong)uVar6 >> 0x20) << 0x10))) ||
             (FUN_021b04d4(), *(short *)(param_5 + 0x2c) != 0)) break;
        }
        if (*(short *)(param_5 + 0x2c) == 0) {
          iVar5 = 1;
        }
      }
    }
    else {
      iVar5 = 0;
    }
    if (uVar3 < local_34) {
      local_38 = local_38 + uVar3;
      local_34 = local_34 - uVar3;
    }
    else {
      local_38 = local_30 + (uVar3 - local_34);
      local_34 = local_2c - (uVar3 - local_34);
      local_30 = 0;
      local_2c = 0;
    }
  } while( true );
}

