/* Decompiled C draft; module arm9; ROM address 02085d1c. No matching claim. */
#include "types.h"
#include "deps/02085d1c_func_02085d1c.h"

void func_02085d1c(void)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_18;
  
  piVar2 = piRam02085df0;
  uVar3 = 0;
  *(undefined2 *)(*piRam02085df0 + iRam02085df4) = 0;
  iVar4 = iRam02085df8;
  local_18 = 0;
  do {
    *(undefined2 *)(*piVar2 + uVar3 * 2 + iVar4) = 0;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 2);
  iVar4 = *piRam02085dfc;
  if (*(char *)(iVar4 + iRam02085e00) != '\0') {
    do {
      if (*(char *)(iVar4 + 0x58) == '\0') {
        bVar1 = false;
        uVar3 = *(uint *)(iVar4 + local_18 * 0x30 + 0x70);
        if ((uVar3 < 4) && ((1 << (uVar3 & 0xff) & 0xdU) != 0)) {
          bVar1 = true;
        }
        if (bVar1) {
          *(short *)(*piRam02085df0 + iRam02085df4) = *(short *)(*piRam02085df0 + iRam02085df4) + 1;
        }
      }
      else {
        uVar3 = 0;
        iVar4 = iVar4 + local_18 * 0x30;
        uVar5 = *(uint *)(iVar4 + 0x70);
        do {
          bVar1 = false;
          if ((uVar5 < 4) && ((1 << (uVar5 & 0xff) & 0xdU) != 0)) {
            bVar1 = true;
          }
          if ((bVar1) && (uVar3 == *(uint *)(iVar4 + 0x74))) {
            iVar4 = *piRam02085df0 + uVar3 * 2;
            *(short *)(iVar4 + iRam02085df8) = *(short *)(iVar4 + iRam02085df8) + 1;
            break;
          }
          uVar3 = uVar3 + 1 & 0xffff;
        } while (uVar3 < 2);
      }
      local_18 = local_18 + 1 & 0xffff;
      iVar4 = *piRam02085dfc;
    } while (local_18 < *(byte *)(iVar4 + iRam02085e00));
  }
  return;
}

