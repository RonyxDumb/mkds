/* Decompiled C draft; module arm9; ROM address 0212b874. No matching claim. */
#include "types.h"
#include "deps/0212b874_func_0212b874.h"

void func_0212b874(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar3 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar2 = iRam0212b914 - param_1;
  do {
    iVar1 = *piRam0212b918 + iVar3;
    *(ushort *)(*piRam0212b918 + local_1c + 0xc) =
         (ushort)((*(int *)(iVar1 + 0x34) * iVar2 + *(int *)(iVar1 + 100) * param_1 >> 0xc) << 10) |
         (ushort)(*(int *)(iVar1 + 0x2c) * iVar2 + *(int *)(iVar1 + 0x5c) * param_1 >> 0xc) |
         (ushort)((*(int *)(iVar1 + 0x30) * iVar2 + *(int *)(iVar1 + 0x60) * param_1 >> 0xc) << 5);
    iVar3 = iVar3 + 0xc;
    local_1c = local_1c + 2;
    local_20 = local_20 + 1;
  } while (local_20 < 4);
  iVar2 = *piRam0212b918;
  if (*(int *)(iVar2 + 0x8c) == 0) {
    AllocateReserveTEQSub(0x1e,(uint)*(byte *)(iVar2 + 8) << 5,iVar2 + 10,0x20);
    return;
  }
  *(undefined4 *)(iVar2 + 0x8c) = 0;
  return;
}

