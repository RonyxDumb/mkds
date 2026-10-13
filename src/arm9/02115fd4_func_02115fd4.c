/* Decompiled C draft; module arm9; ROM address 02115fd4. No matching claim. */
#include "types.h"
#include "deps/02115fd4_func_02115fd4.h"

void func_02115fd4(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = func_0211606c();
  if (iVar5 != 0) {
    iVar5 = *piRam02116068;
    if (*(int *)(iVar5 + 0x7c) == 7) {
      *(undefined2 *)(iVar5 + 0x80) = *(undefined2 *)(iVar5 + 0x74);
      func_021162cc();
    }
    else {
      uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + 6);
      uVar2 = *(ushort *)(*(int *)(iVar5 + 0x18) + 6);
      uVar6 = func_02116d10(7 - *(int *)(iVar5 + 0x7c),0);
      piVar4 = piRam02116068;
      *(undefined4 *)(*piRam02116068 + 100) = uVar6;
      uVar3 = (undefined2)uVar6;
      *(undefined2 *)(*(int *)(*piVar4 + 0x14) + 0xc6) = uVar3;
      *(undefined2 *)(*(int *)(*piVar4 + 0x14) + (uint)uVar1 * 0x40 + 6) = uVar3;
      *(undefined2 *)(*(int *)(*piVar4 + 0x24) + 0x46) = uVar3;
      *(undefined2 *)(*(int *)(*piVar4 + 0x24) + (uint)uVar2 * 0x40 + 6) = uVar3;
    }
    *(int *)(*piRam02116068 + 0x7c) = *(int *)(*piRam02116068 + 0x7c) + -1;
    return;
  }
  iVar5 = *piRam02116068;
  if ((*(short *)(iVar5 + 0x74) != 5) && (*(short *)(iVar5 + 0x74) != *(short *)(iVar5 + 0x80))) {
    *(undefined4 *)(iVar5 + 0x7c) = 7;
  }
  return;
}

