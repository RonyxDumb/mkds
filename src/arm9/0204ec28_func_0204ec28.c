/* Decompiled C draft; module arm9; ROM address 0204ec28. No matching claim. */
#include "types.h"
#include "deps/0204ec28_func_0204ec28.h"

void func_0204ec28(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  
  iVar2 = iRam0204ec9c;
  piVar1 = piRam0204ec98;
  param_1 = param_1 * 8;
  *(byte *)(*(int *)(*piRam0204ec98 + iRam0204ec9c) + param_1) =
       (byte)(((uint)*(byte *)(param_2 + 0x15) << 0x19) >> 0x1a);
  *(byte *)(*(int *)(*piVar1 + iVar2) + param_1 + 1) = (byte)*(undefined4 *)(param_2 + 0x18) & 0xf;
  uVar3 = GetSomeInternalCourseId((uint)(*(int *)(param_2 + 0x18) << 0x17) >> 0x1b);
  iVar2 = iRam0204ec9c;
  piVar1 = piRam0204ec98;
  *(undefined1 *)(*(int *)(*piRam0204ec98 + iRam0204ec9c) + param_1 + 2) = uVar3;
  *(byte *)(*(int *)(*piVar1 + iVar2) + param_1 + 3) =
       (byte)((uint)*(undefined4 *)(param_2 + 0x18) >> 8) >> 1;
  *(byte *)(*(int *)(*piVar1 + iVar2) + param_1 + 4) =
       (byte)((uint)(*(int *)(param_2 + 0x18) << 10) >> 0x1a);
  *(ushort *)(*(int *)(*piVar1 + iVar2) + param_1 + 6) =
       (ushort)((uint)*(undefined4 *)(param_2 + 0x18) >> 0x16);
  return;
}

