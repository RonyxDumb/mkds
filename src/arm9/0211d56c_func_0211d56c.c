/* Decompiled C draft; module arm9; ROM address 0211d56c. No matching claim. */
#include "types.h"
#include "deps/0211d56c_func_0211d56c.h"

void func_0211d56c(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  piVar2 = piRam0211d61c;
  bVar1 = true;
  iVar3 = *piRam0211d61c;
  uVar4 = (uint)*(ushort *)(*(int *)(iVar3 + 4) + 6);
  if (*(int *)(iVar3 + 0x7c) == 0) {
    *(int *)(iVar3 + 0x60) = *(int *)(iVar3 + 0x60) + 1;
    iVar5 = *piVar2;
    iVar3 = *(int *)(iVar5 + 0x60);
    if (iVar3 < 5) {
      if ((*(int *)(*(int *)(iVar5 + 0x14) + (uVar4 + *(ushort *)(iRam0211d620 + iVar3 * 4)) * 0x40)
           == 0) ||
         ((iVar3 = func_0211d650(), iVar3 == 8 && (*(int *)(*piRam0211d61c + 0x60) == 1)))) {
        bVar1 = false;
        func_0211d56c();
      }
    }
    else {
      *(int *)(iVar5 + 0x60) = iVar3 + -1;
      *(undefined4 *)(*piVar2 + 0x7c) = 1;
      if (*psRam0211d624 != 2) {
        func_0212b7fc();
      }
    }
  }
  else {
    *(undefined4 *)(iVar3 + 0x60) = 0;
    *(undefined4 *)(*piVar2 + 0x7c) = 0;
    if ((*(int *)(*(int *)(*piVar2 + 0x14) +
                 (uVar4 + *(ushort *)(iRam0211d620 + *(int *)(*piVar2 + 0x60) * 4)) * 0x40) == 0) ||
       ((iVar3 = func_0211d650(), iVar3 == 8 && (*(int *)(*piRam0211d61c + 0x60) == 1)))) {
      bVar1 = false;
      func_0211d56c();
    }
  }
  if (bVar1) {
    NNSi_MaybeSndPlayerStartSeq(uRam0211d628,0,0);
  }
  return;
}

