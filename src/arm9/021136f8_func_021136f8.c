/* Decompiled C draft; module arm9; ROM address 021136f8. No matching claim. */
#include "types.h"
#include "deps/021136f8_func_021136f8.h"

void func_021136f8(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = func_02113790();
  if (iVar5 != 0) {
    iVar5 = *piRam0211378c;
    if (*(int *)(iVar5 + 0x70) == 7) {
      *(undefined2 *)(iVar5 + 0x74) = *(undefined2 *)(iVar5 + 0x68);
      func_02113a3c();
    }
    else {
      uVar1 = *(ushort *)(*(int *)(iVar5 + 8) + 6);
      uVar2 = *(ushort *)(*(int *)(iVar5 + 0x18) + 6);
      uVar6 = func_02116d10(7 - *(int *)(iVar5 + 0x70),0);
      piVar4 = piRam0211378c;
      *(undefined4 *)(*piRam0211378c + 0x5c) = uVar6;
      uVar3 = (undefined2)uVar6;
      *(undefined2 *)(*(int *)(*piVar4 + 0x14) + 0xc6) = uVar3;
      *(undefined2 *)(*(int *)(*piVar4 + 0x14) + (uint)uVar1 * 0x40 + 6) = uVar3;
      *(undefined2 *)(*(int *)(*piVar4 + 0x24) + 0x46) = uVar3;
      *(undefined2 *)(*(int *)(*piVar4 + 0x24) + (uint)uVar2 * 0x40 + 6) = uVar3;
    }
    *(int *)(*piRam0211378c + 0x70) = *(int *)(*piRam0211378c + 0x70) + -1;
    return;
  }
  iVar5 = *piRam0211378c;
  if ((*(short *)(iVar5 + 0x68) != 5) && (*(short *)(iVar5 + 0x68) != *(short *)(iVar5 + 0x74))) {
    *(undefined4 *)(iVar5 + 0x70) = 7;
  }
  return;
}

