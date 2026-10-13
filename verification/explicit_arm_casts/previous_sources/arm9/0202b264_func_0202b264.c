/* Decompiled C draft; module arm9; ROM address 0202b264. No matching claim. */
#include "types.h"
#include "deps/0202b264_func_0202b264.h"

void func_0202b264(void)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = *piRam0202b2b4;
  iVar7 = (uint)*(ushort *)(*(int *)(iVar4 + 0x70) + 6) +
          (uint)*(ushort *)(*(int *)(iVar4 + 0x78) + 6);
  func_02025edc(iVar4 + 0xcc);
  uVar3 = func_02025ebc(*piRam0202b2b4 + 0xcc);
  iVar2 = iRam0202b2b8;
  piVar1 = piRam0202b2b4;
  *(undefined2 *)(*piRam0202b2b4 + iRam0202b2b8) = uVar3;
  iVar6 = 0;
  if (iVar7 != 0) {
    iVar5 = 0;
    do {
      *(undefined2 *)(*(int *)(iVar4 + 0x7c) + iVar5 + 6) = *(undefined2 *)(*piVar1 + iVar2);
      iVar5 = iVar5 + 0x40;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar7);
  }
  return;
}

