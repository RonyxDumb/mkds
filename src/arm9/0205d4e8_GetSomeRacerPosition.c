/* Decompiled C draft; module arm9; ROM address 0205d4e8. No matching claim. */
#include "types.h"
#include "deps/0205d4e8_GetSomeRacerPosition.h"

undefined1 GetSomeRacerPosition(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(uRam0205d550 & 0xfffffffc) >> (uRam0205d550 & 3) * 8 |
          *(uint *)(uRam0205d550 & 0xfffffffc) << (uRam0205d550 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (((uVar3 != 0) && (uVar3 != 3)) && (uVar3 != 5)) {
    return 0;
  }
  iVar4 = *(ushort *)(uVar5 + 0x60) - 1;
  iVar2 = iVar4 >> 0x1f;
  return *(undefined1 *)
          ((param_1 & 0xff) * 10 +
           (((uint)(iVar4 * 0x40000000 + iVar2) >> 0x1e | iVar2 << 2) - iVar2 & 0xff) * 0x50 +
           (*(uint *)(uRam0205d554 & 0xfffffffc) >> (uRam0205d554 & 3) * 8 |
           *(uint *)(uRam0205d554 & 0xfffffffc) << (uRam0205d554 & 3) * -8 + 0x20) + 2);
}

