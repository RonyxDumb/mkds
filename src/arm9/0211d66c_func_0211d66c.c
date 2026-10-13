/* Decompiled C draft; module arm9; ROM address 0211d66c. No matching claim. */
#include "types.h"
#include "deps/0211d66c_func_0211d66c.h"

void func_0211d66c(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  piVar1 = piRam0211d82c;
  iVar4 = *piRam0211d82c;
  uVar5 = (uint)*(ushort *)(*(int *)(iVar4 + 4) + 6);
  if (*(int *)(*piRam0211d830 + 0x20) == 2) {
    *(undefined4 *)(*(int *)(iVar4 + 0x14) + iRam0211d834) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x14) + iRam0211d838) = 0;
    iVar3 = *piVar1;
    iVar4 = *(int *)(iVar3 + 0x74);
    if (iVar4 == 0) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uVar5 + 10) * 0x40) = 1;
      func_0211d910((int)*(short *)(*piVar1 + 0x88));
    }
    else if (iVar4 == 1) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uVar5 + 10) * 0x40) = 1;
      func_0211d844((int)*(short *)(*piVar1 + 0x8a));
    }
    else if (iVar4 == 2) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uVar5 + 10) * 0x40) = 1;
      iVar4 = *piVar1;
      uVar2 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(iVar4 + 0x1c),
                         *(undefined2 *)(*(int *)(iRam0211d83c + 0xc) + 4));
      func_0212426c(1,10,*(undefined4 *)(*piRam0211d82c + 0xc),uVar2,*(undefined4 *)(iVar4 + 4),
                    *(undefined4 *)(iVar4 + 0x14));
    }
    piVar1 = piRam0211d82c;
    iVar3 = *piRam0211d82c;
    iVar4 = *(int *)(iVar3 + 0x78);
    if ((iVar4 == 0) || (iVar4 == 1)) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uVar5 + 0xb) * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piRam0211d82c + 0x14) + (uVar5 + 0xc) * 0x40) = 0;
    }
    else if (iVar4 == 2) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uVar5 + 0xb) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar5 + 0xc) * 0x40) = 1;
    }
  }
  else {
    iVar3 = *(int *)(iVar4 + 0x74);
    if ((iVar3 == 0) || (iVar3 == 1)) {
      *(undefined4 *)(*(int *)(iVar4 + 0x14) + (uVar5 + 9) * 0x40) = 1;
      piVar1 = piRam0211d82c;
      *(undefined4 *)(*(int *)(*piRam0211d82c + 0x14) + (uVar5 + 10) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar5 + 8) * 0x40) = 1;
    }
    else if (iVar3 == 2) {
      *(undefined4 *)(*(int *)(iVar4 + 0x14) + (uVar5 + 9) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar5 + 10) * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar5 + 8) * 0x40) = 0;
    }
    piVar1 = piRam0211d82c;
    iVar3 = *piRam0211d82c;
    iVar4 = *(int *)(iVar3 + 0x78);
    if ((iVar4 == 0) || (iVar4 == 1)) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uVar5 + 0xb) * 0x40) = 1;
      *(undefined4 *)(*(int *)(*piRam0211d82c + 0x14) + (uVar5 + 0xc) * 0x40) = 0;
    }
    else if (iVar4 == 2) {
      *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uVar5 + 0xb) * 0x40) = 0;
      *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar5 + 0xc) * 0x40) = 1;
    }
  }
  iVar4 = iRam0211d840;
  piVar1 = piRam0211d82c;
  if (*(int *)(*piRam0211d82c + 0x2c) == 3) {
    *(undefined4 *)
     (*(int *)(*piRam0211d82c + 0x14) + (uVar5 + *(ushort *)(iRam0211d840 + 2)) * 0x40) = 0;
    *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uVar5 + *(ushort *)(iVar4 + 10)) * 0x40) = 0;
  }
  return;
}

