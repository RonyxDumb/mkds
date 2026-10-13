/* Decompiled C draft; module arm9; ROM address 02033840. No matching claim. */
#include "types.h"
#include "deps/02033840_func_02033840.h"

void func_02033840(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = *piRam020338f0;
  iVar2 = *(int *)(iVar4 + 0xd4);
  uVar1 = *(ushort *)(iRam020338f4 + (iVar2 + -2) * 2);
  *(undefined2 *)(iVar4 + 0xcc) = 0x46;
  *(undefined2 *)(*piRam020338f0 + 0xce) = 0x50;
  iVar6 = 0;
  iVar5 = 0;
  do {
    *(undefined4 *)(*(int *)(iVar4 + 0x60) + iVar5) = 0;
    iVar5 = iVar5 + 0x40;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x46);
  iVar5 = *(int *)(*piRam020338f0 + 0xd4);
  uVar3 = (uint)*(ushort *)(iRam020338f4 + (iVar5 + -2) * 2);
  if ((int)uVar3 < (int)(uVar3 + iVar5 * 2)) {
    iVar6 = uVar3 << 6;
    do {
      *(undefined4 *)(*(int *)(iVar4 + 0x60) + iVar6) = 1;
      iVar6 = iVar6 + 0x40;
      uVar3 = uVar3 + 1;
      iVar5 = *(int *)(*piRam020338f0 + 0xd4);
    } while ((int)uVar3 < (int)((uint)*(ushort *)(iRam020338f4 + (iVar5 + -2) * 2) + iVar5 * 2));
  }
  iVar4 = 0;
  if (0 < iVar5) {
    do {
      func_02033ab8(0,iVar4,iVar2 + (uint)uVar1 + iVar4,iVar2 < 5);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(*piRam020338f0 + 0xd4));
  }
  return;
}

