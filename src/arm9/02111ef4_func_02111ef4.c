/* Decompiled C draft; module arm9; ROM address 02111ef4. No matching claim. */
#include "types.h"
#include "deps/02111ef4_func_02111ef4.h"

void func_02111ef4(void)

{
  ushort uVar1;
  int *piVar2;
  undefined2 uVar3;
  
  piVar2 = piRam02111f44;
  *(int *)(*piRam02111f44 + 0x54) = *(int *)(*piRam02111f44 + 0x54) + 1;
  uVar3 = func_020ae488(*(undefined4 *)(*piVar2 + 0x54));
  piVar2 = piRam02111f44;
  uVar1 = *(ushort *)(*(int *)(*piRam02111f44 + 0x30) + 6);
  *(undefined2 *)(*(int *)(*piRam02111f44 + 0x3c) + iRam02111f48) = uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam02111f4c) = uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam02111f50) = uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar1 + 5) * 0x40 + 4) = uVar3;
  if (9 < *(int *)(*piVar2 + 0x54)) {
    func_02113298();
  }
  return;
}

