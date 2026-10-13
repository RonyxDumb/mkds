/* Decompiled C draft; module arm9_ov001; ROM address 021828f0. No matching claim. */
#include "types.h"
#include "deps/021828f0_FUN_021828f0.h"

void FUN_021828f0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar3 = (int *)func_0x02100138(0x68);
  uVar2 = DAT_02182998;
  if (piVar3 != (int *)0x0) {
    iVar6 = 0;
    uVar1 = *DAT_02182994;
    for (iVar4 = 0;
        (iVar6 < (int)(uint)*(ushort *)(piVar3 + 1) &&
        (iVar5 = *(int *)(*piVar3 + iVar4), iVar5 != 0)); iVar4 = iVar4 + 4) {
      if ((*(int *)(iVar5 + 0xf8) == 0) && ((*(ushort *)(iVar5 + 2) & DAT_0218299c) == 0)) {
        *(undefined4 *)(iVar5 + 0x14) = uVar2;
        *(undefined2 *)(iVar5 + 0xa0) = 0x32;
        *(undefined4 *)(iVar5 + 0xf8) = 8;
        *(ushort *)(iVar5 + 2) = *(ushort *)(iVar5 + 2) | uVar1;
      }
      iVar6 = iVar6 + 1;
    }
  }
  piVar3 = (int *)func_0x02108e6c(2);
  if (((*DAT_021829a0 & 1) != 0) && (*(int *)(DAT_021829a4 + 0xc) != 0)) {
    if (*piVar3 != 0) {
      func_0x0212c6f0(piVar3,0);
    }
    if (*piVar3 != 0) {
      func_0x0212c6f0(piVar3,0);
    }
    func_0x0212ecc0(piVar3,0,DAT_021829a8);
  }
  return;
}

