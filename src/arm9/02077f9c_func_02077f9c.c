/* Decompiled C draft; module arm9; ROM address 02077f9c. No matching claim. */
#include "types.h"
#include "deps/02077f9c_func_02077f9c.h"

void func_02077f9c(undefined4 param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_2 + 0x10) + 4);
  Arm_FlushRange(param_3,0x20);
  iVar2 = DetermineIsP_from_thumb(param_1);
  if (iVar2 == 0) {
    iVar2 = Dict_SomeFn_0(iVar3 + *(int *)(iVar3 + 8) + 4,uRam02078008);
  }
  else {
    iVar2 = Dict_SomeFn_0(iVar3 + *(int *)(iVar3 + 8) + 4,uRam02078004);
  }
  iVar3 = iVar3 + *(int *)(iVar3 + 8);
  uVar1 = *(ushort *)
           (iVar3 + *(int *)(iVar3 + 4 + (uint)*(ushort *)(iVar3 + 10) +
                             iVar2 * (uint)*(ushort *)(iVar3 + 4 + (uint)*(ushort *)(iVar3 + 10)) +
                            4) + 0x1c);
  func_0214c48c();
  SomeDmaCopy_0(param_3,(uint)uVar1 * 0x10,0x20);
  func_0214c3c0();
  return;
}

