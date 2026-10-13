/* Decompiled C draft; module arm9; ROM address 02032940. No matching claim. */
#include "types.h"
#include "deps/02032940_func_02032940.h"

void func_02032940(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  piVar2 = piRam0203299c;
  if (*psRam02032998 != 2) {
    iVar3 = *piRam0203299c;
    uVar1 = *(ushort *)(*(int *)(iVar3 + 0xc) + 6);
    uVar5 = (uint)*(ushort *)(*(int *)(iVar3 + 0x14) + 6);
    iVar6 = 0;
    if (uVar5 != 0) {
      do {
        *(short *)(*(int *)(iVar3 + 0x18) + (iVar6 + (uint)uVar1) * 0x40 + 6) =
             (short)*(undefined4 *)(*piVar2 + 0x60);
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uVar5);
    }
  }
  piVar2 = piRam0203299c;
  iVar6 = *piRam0203299c;
  uVar5 = (uint)*(ushort *)(*(int *)(iVar6 + 0x28) + 6);
  iVar3 = 0;
  if (uVar5 != 0) {
    iVar4 = 0;
    do {
      *(short *)(*(int *)(iVar6 + 0x34) + iVar4 + 4) = (short)*(undefined4 *)(*piVar2 + 0x5c);
      iVar4 = iVar4 + 0x40;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)uVar5);
  }
  return;
}

