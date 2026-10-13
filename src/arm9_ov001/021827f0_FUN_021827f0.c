/* Decompiled C draft; module arm9_ov001; ROM address 021827f0. No matching claim. */
#include "types.h"
#include "deps/021827f0_FUN_021827f0.h"

void FUN_021827f0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = (int *)func_0x02100138(0x68);
  uVar1 = DAT_021828d0;
  if (piVar2 != (int *)0x0) {
    iVar5 = 0;
    for (iVar3 = 0;
        (iVar5 < (int)(uint)*(ushort *)(piVar2 + 1) &&
        (iVar4 = *(int *)(*piVar2 + iVar3), iVar4 != 0)); iVar3 = iVar3 + 4) {
      if ((*(int *)(iVar4 + 0xf8) == 9) && ((*(ushort *)(iVar4 + 2) & DAT_021828d4) == 0)) {
        *(undefined4 *)(iVar4 + 4) = **(undefined4 **)(iVar4 + 0x9c);
        *(int *)(iVar4 + 8) = *(int *)(*(int *)(iVar4 + 0x9c) + 4) + DAT_021828d8;
        *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(*(int *)(iVar4 + 0x9c) + 8);
        *(undefined4 *)(iVar4 + 0x10) = 0;
        *(undefined4 *)(iVar4 + 0x14) = uVar1;
        *(undefined4 *)(iVar4 + 0x18) = 0;
        *(int *)(iVar4 + 0xe4) = *(int *)(*(int *)(iVar4 + 0x9c) + 4) + DAT_021828dc;
        *(undefined4 *)(iVar4 + 0xf8) = 2;
        *(undefined4 *)(iVar4 + 0xb0) = DAT_021828e0;
        *(undefined2 *)(iVar4 + 0xa0) = 0;
        *(ushort *)(iVar4 + 2) = *(ushort *)(iVar4 + 2) & 0xfffe;
      }
      iVar5 = iVar5 + 1;
    }
  }
  piVar2 = (int *)func_0x02108e6c(2);
  if (((*DAT_021828e4 & 1) != 0) && (*(int *)(DAT_021828e8 + 0xc) != 0)) {
    if (*piVar2 != 0) {
      func_0x0212c6f0(piVar2,0);
    }
    if (*piVar2 != 0) {
      func_0x0212c6f0(piVar2,0);
    }
    func_0x0212ecc0((undefined4)(uintptr_t)(piVar2),0,DAT_021828ec);
  }
  return;
}

