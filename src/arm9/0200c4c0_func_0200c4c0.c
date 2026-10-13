/* Decompiled C draft; module arm9; ROM address 0200c4c0. No matching claim. */
#include "types.h"
#include "deps/0200c4c0_func_0200c4c0.h"

void func_0200c4c0(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = uRam0200c504;
  while( true ) {
    uVar2 = Os_DisableIrq();
    param_2[1] = uVar2;
    uVar2 = Os_Lock_GetOwnerId(uVar1);
    *param_2 = uVar2 & 0x40;
    if ((*param_2 != 0) || (iVar3 = Operation_CartArm9(param_1), iVar3 == 0)) break;
    Os_RestoreIrq(param_2[1]);
    WaitByLoop(1);
  }
  return;
}

