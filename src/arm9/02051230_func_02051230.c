/* Decompiled C draft; module arm9; ROM address 02051230. No matching claim. */
#include "types.h"
#include "deps/02051230_func_02051230.h"

void func_02051230(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = uRam02051358;
  iVar2 = 7;
  uVar5 = *(uint *)(uRam02051358 & 0xfffffffc) >> (uRam02051358 & 3) * 8 |
          *(uint *)(uRam02051358 & 0xfffffffc) << (uRam02051358 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  }
  iVar7 = uVar5 + 0x44;
  if (uVar4 == 1) {
    iVar6 = 0;
    if (*(byte *)(uVar5 + 0x84) != 0) {
      do {
        if (*(ushort *)(iVar7 + 6) != uRam0205135c) {
          *(char *)(uVar5 + 0x85) = (char)iVar6;
          *(undefined4 *)
           ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0xc) = 0x14;
          *(undefined4 *)
           ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10) = 1;
          iVar2 = func_021436d0(uRam02051360,*(undefined2 *)(iVar7 + 6));
          break;
        }
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 8;
      } while (iVar6 < (int)(uint)*(byte *)(uVar5 + 0x84));
    }
  }
  else if (uVar4 == 2) {
    *(undefined4 *)(uVar5 + 0xc) = 0x14;
    uVar1 = uRam02051360;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x10) = 1;
    iVar2 = func_021436d0(uVar1,0);
  }
  if (iVar2 != 0) {
    if (iVar2 == 2) {
      uVar3 = *(uint *)(uRam02051358 & 0xfffffffc) >> (uRam02051358 & 3) * 8 |
              *(uint *)(uRam02051358 & 0xfffffffc) << (uRam02051358 & 3) * -8 + 0x20;
      if (uVar3 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      }
      if (uVar5 == 2) {
        *(ushort *)(uVar3 + 0x436) = *(ushort *)(uVar3 + 0x436) | 2;
      }
      return;
    }
    if (iVar2 != 7) {
      func_020533a0();
      return;
    }
  }
  *(undefined4 *)
   ((*(uint *)(uRam02051358 & 0xfffffffc) >> (uRam02051358 & 3) * 8 |
    *(uint *)(uRam02051358 & 0xfffffffc) << (uRam02051358 & 3) * -8 + 0x20) + 0x10) = 0;
  return;
}

