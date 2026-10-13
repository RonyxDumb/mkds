/* Decompiled C draft; module arm9; ROM address 02085ad8. No matching claim. */
#include "types.h"
#include "deps/02085ad8_func_02085ad8.h"

void func_02085ad8(void)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_1c [2];
  
  uVar9 = 0;
  uVar10 = 0;
  local_1c[0] = (uint)*(byte *)(*piRam02085bd8 + iRam02085bdc);
  IntrusiveListWrapper_InitializeEmpty(*piRam02085be0 + iRam02085be4,4);
  piVar2 = piRam02085be0;
  uVar4 = 0;
  iVar6 = *piRam02085bd8;
  do {
    if (-1 < *(char *)(iVar6 + uVar4 + iRam02085be8)) {
      uVar9 = uVar9 + 1 & 0xffff;
    }
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 2);
  uVar7 = 0;
  uVar4 = (uint)*(byte *)(iVar6 + iRam02085bdc);
  if (uVar4 != 0) {
    do {
      bVar1 = false;
      uVar8 = *(uint *)(iVar6 + uVar7 * 0x30 + 0x70);
      if ((uVar8 < 4) && ((1 << (uVar8 & 0xff) & 0xdU) != 0)) {
        bVar1 = true;
      }
      if (bVar1) {
        uVar10 = uVar10 + 1 & 0xffff;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < uVar4);
  }
  uVar10 = (uVar4 - uVar10) - uVar9 & 0xffff;
  uVar4 = 0;
  if (uVar10 != 0) {
    do {
      *(uint *)(*piVar2 + uVar4 * 0xc + 0xb0) = uVar4 + uVar9 + 1 & 0xffff;
      iVar6 = *piVar2;
      IntrusiveListWrapper_InsertLast(iVar6 + iRam02085be4,iVar6 + 0xb0 + uVar4 * 0xc);
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < uVar10);
  }
  piVar3 = piRam02085be0;
  iVar6 = iRam02085bdc;
  piVar2 = piRam02085bd8;
  uVar4 = 0;
  iVar5 = *piRam02085bd8;
  if (*(char *)(iVar5 + iRam02085bdc) != '\0') {
    do {
      uVar9 = uVar4;
      if (*(int *)(iVar5 + 8) != 1) {
        uVar9 = func_02085984(uVar4,local_1c);
      }
      *(uint *)(*piVar3 + uVar4 * 4 + 0x90) = uVar9;
      iVar5 = *piVar2;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < *(byte *)(iVar5 + iVar6));
  }
  return;
}

