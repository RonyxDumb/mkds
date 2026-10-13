/* Decompiled C draft; module arm9; ROM address 02078e4c. No matching claim. */
#include "types.h"
#include "deps/02078e4c_func_02078e4c.h"

void func_02078e4c(undefined4 param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *piRam02078ec4;
  if ((-1 < *(short *)(iVar2 + iRam02078ed0)) &&
     (*(int *)(iVar2 + iRam02078ec8 + *(short *)(iVar2 + iRam02078ecc) * 0x34 + 0x2c) == 0)) {
    iVar3 = *(int *)(*(int *)(iVar2 + *(short *)(iVar2 + iRam02078ed0) * 0xb8 + 0x6c) + 4);
    iVar2 = Dict_SomeFn_0(iVar3 + *(int *)(iVar3 + 8) + 4,uRam02078ed4);
    iVar3 = iVar3 + *(int *)(iVar3 + 8);
    iVar3 = iVar3 + *(int *)(iVar3 + 4 + (uint)*(ushort *)(iVar3 + 10) +
                             iVar2 * (uint)*(ushort *)(iVar3 + 4 + (uint)*(ushort *)(iVar3 + 10)) +
                            4);
    uVar1 = *(ushort *)(iVar3 + 0x1c);
    AllocateReserveTEQSub(0,(*(uint *)(iVar3 + 0x14) & uRam02078ed8) << 3,param_1,uRam02078edc);
    AllocateReserveTEQSub(1,(uint)uVar1 * 0x10,param_2,0x20);
  }
  return;
}

