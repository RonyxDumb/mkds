/* Decompiled C draft; module arm9; ROM address 02034f60. No matching claim. */
#include "types.h"
#include "deps/02034f60_func_02034f60.h"

void func_02034f60(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = piRam02034fe4;
  iVar2 = *piRam02034fe4;
  iVar3 = iVar2 + 0x9c + *(int *)(iVar2 + 0x80) * 0x3c;
  iVar5 = (uint)*(ushort *)(*(int *)(iVar2 + 0x38) + 6) +
          (uint)*(ushort *)(*(int *)(iVar2 + 0x40) + 6);
  iVar6 = 0;
  if (iVar5 != 0) {
    iVar4 = 0;
    do {
      *(uint *)(*(int *)(iVar2 + 0x44) + iVar4) = (uint)(-1 < *(int *)(*piVar1 + 0x80));
      iVar4 = iVar4 + 0x40;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  if (-1 < *(int *)(*piRam02034fe4 + 0x80)) {
    func_0202de00(*piRam02034fe4 + 0x2c,uRam02034fe8,iVar3,*(undefined4 *)(iVar3 + 0x18),
                  *(undefined4 *)(iVar3 + 0x1c),*(undefined4 *)(iVar3 + 0x20),iVar3 + 0x24);
  }
  return;
}

