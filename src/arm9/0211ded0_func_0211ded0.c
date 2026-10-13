/* Decompiled C draft; module arm9; ROM address 0211ded0. No matching claim. */
#include "types.h"
#include "deps/0211ded0_func_0211ded0.h"

void func_0211ded0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  ushort param_5,int param_6)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar3 = 0xe;
  if ((param_6 != 0) && (param_6 == 1)) {
    uVar3 = 0x1e;
  }
  uVar1 = *(undefined2 *)(iRam0211df30 + param_1 * 2);
  puVar4 = (undefined4 *)*piRam0211df34;
  func_02124748(uVar1,puVar4[1],*puVar4,puVar4[3],param_6,param_4,param_2,param_3);
  iVar2 = *piRam0211df34;
  iVar5 = *(int *)(*(int *)(iVar2 + 8) + 0xc);
  iVar2 = func_02124a68(uVar1,*(undefined4 *)(iVar2 + 4),*(undefined4 *)(iVar2 + 0xc));
  AllocateReserveTEQSub(uVar3,(uint)param_5 << 5,iVar5 + iVar2 * 0x20,0x20);
  return;
}

