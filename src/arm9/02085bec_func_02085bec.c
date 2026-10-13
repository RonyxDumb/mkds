/* Decompiled C draft; module arm9; ROM address 02085bec. No matching claim. */
#include "types.h"
#include "deps/02085bec_func_02085bec.h"

void func_02085bec(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = iRam02085cf8;
  piVar2 = piRam02085cf4;
  uVar5 = 0;
  iVar7 = 0;
  iVar8 = 0;
  uVar6 = 0;
  do {
    *(undefined4 *)(*piVar2 + uVar5 * 4 + iVar3) = 0;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 2);
  *(undefined4 *)(*piVar2 + iRam02085cfc) = 1;
  *(undefined4 *)(*piVar2 + iRam02085d00) = 0;
  iVar3 = *piRam02085d04;
  if (*(int *)(iVar3 + 8) == 0) {
    if (*(char *)(iVar3 + iRam02085d08) != '\0') {
      do {
        iVar3 = func_0205d3f0(uVar6 & 0xffff);
        bVar1 = false;
        iVar4 = *piRam02085d04;
        uVar5 = *(uint *)(iVar4 + (uVar6 & 0xffff) * 0x30 + 0x70);
        if ((uVar5 < 4) && ((1 << (uVar5 & 0xff) & 0xdU) != 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          if (iVar7 < iVar3) {
            iVar7 = iVar3;
          }
        }
        else {
          if (iVar8 < iVar3) {
            iVar8 = iVar3;
          }
          if (uVar6 == (int)*(char *)(iVar4 + iRam02085d0c)) {
            *(int *)(*piRam02085cf4 + iRam02085cf8) = iVar3;
          }
          else if (uVar6 == (int)*(char *)(iVar4 + iRam02085d10)) {
            *(int *)(*piRam02085cf4 + iRam02085d14) = iVar3;
          }
        }
        uVar6 = (int)((uVar6 + 1) * 0x10000) >> 0x10;
        iVar3 = *piRam02085d04;
      } while ((int)uVar6 < (int)(uint)*(byte *)(iVar3 + iRam02085d08));
    }
    piVar2 = piRam02085cf4;
    if (iVar7 - iVar8 < -4) {
      if (1 < *(byte *)(iVar3 + iRam02085d18)) {
        *(undefined4 *)(*piRam02085cf4 + iRam02085cfc) = 0;
        iVar3 = *piVar2;
        if (*(int *)(iVar3 + iRam02085d14) < *(int *)(iVar3 + iRam02085cf8)) {
          *(undefined4 *)(iVar3 + iRam02085d00) = 1;
          return;
        }
      }
    }
    else if ((*(int *)(iVar3 + 0x14) != 1) && (3 < iVar7 - iVar8)) {
      *(undefined4 *)(*piRam02085cf4 + iRam02085cfc) = 2;
    }
  }
  return;
}

