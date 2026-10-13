/* Decompiled C draft; module arm9; ROM address 020336ec. No matching claim. */
#include "types.h"
#include "deps/020336ec_func_020336ec.h"

void func_020336ec(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_28;
  undefined4 local_20;
  
  iVar4 = *piRam0203382c;
  local_28 = (uint)(*(int *)(iVar4 + 0xdc) != 3);
  iVar8 = 0;
  iVar2 = *(int *)(iVar4 + 0xd4);
  uVar1 = *(ushort *)(iRam02033830 + (iVar2 + -1) * 2);
  if (5 < iVar2) {
    local_20 = 0x39;
  }
  else {
    local_20 = 0x38;
  }
  *(undefined2 *)(iVar4 + 0xcc) = 0x3a;
  *(undefined2 *)(*piRam0203382c + 0xce) = 0x44;
  iVar7 = 0;
  iVar5 = 0;
  do {
    *(undefined4 *)(*(int *)(iVar4 + 0x60) + iVar5) = 0;
    iVar5 = iVar5 + 0x40;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x38);
  iVar7 = *piRam0203382c;
  iVar5 = *(int *)(iVar7 + 0xd4);
  uVar3 = (uint)*(ushort *)(iRam02033830 + (iVar5 + -1) * 2);
  if ((int)uVar3 < (int)(uVar3 + iVar5 * 2)) {
    iVar6 = uVar3 << 6;
    do {
      *(undefined4 *)(*(int *)(iVar4 + 0x60) + iVar6) = 1;
      iVar6 = iVar6 + 0x40;
      uVar3 = uVar3 + 1;
      iVar7 = *piRam0203382c;
      iVar5 = *(int *)(iVar7 + 0xd4);
    } while ((int)uVar3 < (int)((uint)*(ushort *)(iRam02033830 + (iVar5 + -1) * 2) + iVar5 * 2));
  }
  if ((*(int *)(iVar7 + 0xdc) == 3) &&
     (uVar3 = (uint)*(ushort *)(iRam02033830 + (iVar5 + -1) * 2), (int)uVar3 < (int)(iVar5 + uVar3))
     ) {
    do {
      func_02025c48(uVar3,local_20,*(undefined4 *)(iVar4 + 0x54));
      uVar3 = uVar3 + 1;
      iVar7 = *piRam0203382c;
    } while ((int)uVar3 <
             (int)(*(int *)(iVar7 + 0xd4) +
                  (uint)*(ushort *)(iRam02033830 + (*(int *)(iVar7 + 0xd4) + -1) * 2)));
  }
  uVar3 = 0;
  if (0 < *(int *)(iVar7 + 0xd8)) {
    do {
      if (local_28 == *(uint *)(*piRam02033834 + (uVar3 & 0xffff) * 0x30 + 0x74)) {
        func_02033ab8(0,uVar3,iVar2 + (uint)uVar1 + iVar8,5 >= iVar2);
        iVar8 = iVar8 + 1;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < *(int *)(*piRam0203382c + 0xd8));
  }
  iVar2 = iRam02033838;
  *(undefined4 *)(*(int *)(iVar4 + 0x60) + iRam02033838) = 0;
  *(undefined4 *)(*(int *)(iVar4 + 0x60) + iRam0203383c) =
       *(undefined4 *)(*(int *)(iVar4 + 0x60) + iVar2);
  return;
}

