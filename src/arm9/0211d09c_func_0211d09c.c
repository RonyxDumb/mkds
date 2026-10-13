/* Decompiled C draft; module arm9; ROM address 0211d09c. No matching claim. */
#include "types.h"
#include "deps/0211d09c_func_0211d09c.h"

void func_0211d09c(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  
  uVar4 = 2;
  uVar2 = func_0211d650();
  piVar1 = DAT_0211d168;
  uVar5 = 0;
  *(undefined2 *)(*DAT_0211d168 + 0xac) = 0;
  *(undefined2 *)(*piVar1 + 0xae) = 0;
  if (0 < (int)uVar2) {
    do {
      switch(*(undefined4 *)(*piVar1 + 0x2c)) {
      case 0:
      case 1:
        uVar4 = func_020ae3b4(2);
        break;
      case 2:
      case 3:
      case 4:
      case 5:
        iVar6 = *DAT_0211d16c;
        iVar3 = iVar6 + DAT_0211d170;
        lVar7 = Multiply64(*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 0xc),
                           *(undefined4 *)(iVar6 + DAT_0211d170),*(undefined4 *)(iVar3 + 4));
        lVar7 = lVar7 + *(longlong *)(iVar3 + 0x10);
        *(int *)(iVar6 + DAT_0211d170) = (int)lVar7;
        *(int *)(iVar3 + 4) = (int)((ulonglong)lVar7 >> 0x20);
        uVar4 = *(uint *)(iVar3 + 4) >> 0x1f;
      }
      if (uVar2 >> 1 <= (uint)*(ushort *)(*piVar1 + uVar4 * 2 + 0xac)) {
        uVar4 = func_0211d3f4(uVar4);
      }
      func_0211d428(uVar5 & 0xffff,uVar4);
      iVar3 = *piVar1 + uVar4 * 2;
      *(short *)(iVar3 + 0xac) = *(short *)(iVar3 + 0xac) + 1;
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < (int)uVar2);
  }
  return;
}

