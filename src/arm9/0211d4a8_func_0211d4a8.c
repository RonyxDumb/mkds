/* Decompiled C draft; module arm9; ROM address 0211d4a8. No matching claim. */
#include "types.h"
#include "deps/0211d4a8_func_0211d4a8.h"

void func_0211d4a8(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  piVar2 = piRam0211d55c;
  bVar1 = true;
  iVar3 = *piRam0211d55c;
  uVar4 = (uint)*(ushort *)(*(int *)(iVar3 + 4) + 6);
  if (*(int *)(iVar3 + 0x7c) == 0) {
    *(int *)(iVar3 + 0x60) = *(int *)(iVar3 + 0x60) + -1;
    iVar5 = *piVar2;
    iVar3 = *(int *)(iVar5 + 0x60);
    if (iVar3 < 0) {
      *(int *)(iVar5 + 0x60) = iVar3 + 1;
      *(undefined4 *)(*piVar2 + 0x7c) = 1;
      if (*psRam0211d564 != 2) {
        func_0212b7fc();
      }
    }
    else if ((*(int *)(*(int *)(iVar5 + 0x14) +
                      (uVar4 + *(ushort *)(iRam0211d560 + iVar3 * 4)) * 0x40) == 0) ||
            ((iVar3 = func_0211d650(), iVar3 == 8 && (*(int *)(*piRam0211d55c + 0x60) == 1)))) {
      bVar1 = false;
      func_0211d4a8();
    }
  }
  else {
    *(undefined4 *)(iVar3 + 0x60) = 4;
    *(undefined4 *)(*piVar2 + 0x7c) = 0;
    if ((*(int *)(*(int *)(*piVar2 + 0x14) +
                 (uVar4 + *(ushort *)(iRam0211d560 + *(int *)(*piVar2 + 0x60) * 4)) * 0x40) == 0) ||
       ((iVar3 = func_0211d650(), iVar3 == 8 && (*(int *)(*piRam0211d55c + 0x60) == 1)))) {
      bVar1 = false;
      func_0211d4a8();
    }
  }
  if (bVar1) {
    NNSi_MaybeSndPlayerStartSeq(uRam0211d568,0,0);
  }
  return;
}

