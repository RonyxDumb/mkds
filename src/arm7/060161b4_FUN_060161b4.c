/* Decompiled C draft; module arm7; ROM address 060161b4. No matching claim. */
#include "types.h"
#include "deps/060161b4_FUN_060161b4.h"

void FUN_060161b4(uint param_1)

{
  uint uVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar4 = *(uint *)(DAT_060164f0 & 0xfffffffc) >> (DAT_060164f0 & 3) * 8 |
          *(uint *)(DAT_060164f0 & 0xfffffffc) << (DAT_060164f0 & 3) * -8 + 0x20;
  uVar9 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(uVar4 + 0x3be);
  if ((*(ushort *)(param_1 + 0xc) & 0x800) != 0) {
    *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 1;
  }
  puVar7 = (ushort *)(param_1 + 0xc);
  for (uVar8 = (uint)*(ushort *)(param_1 + 8); 0 < (int)uVar8; uVar8 = uVar8 - (uVar6 + 2)) {
    iVar5 = FUN_060096c4((ushort *)(uintptr_t)(uVar9));
    iVar10 = uVar9 + 2;
    uVar6 = FUN_060096c4((ushort *)(uintptr_t)(uVar9 + 1));
    switch(iVar5) {
    case 0:
      if (uVar6 < 0x21) {
        *puVar7 = *puVar7 | 1;
        *(uint *)(param_1 + 0x1c) = uVar9;
        if ((uVar6 == 0) && ((*(ushort *)(param_1 + 0xc) & 0x800) != 0)) {
          *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 1;
        }
        else {
          *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) & 0xfffe;
          iVar5 = FUN_0600a5b4(uVar6 & 0xffff,iVar10);
          if (iVar5 != 0) {
            *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 1;
          }
        }
      }
      break;
    case 1:
      if (uVar6 != 0) {
        *puVar7 = *puVar7 | 4;
        FUN_0600a49c(uVar9,(ushort *)(uintptr_t)(param_1 + 0x14));
        uVar2 = *(ushort *)(uVar4 + 0x3a4);
        if (((*(ushort *)(param_1 + 0x14) & ~(uVar2 | *(ushort *)(uVar4 + 0x3a6))) == 0) &&
           (uVar2 == (uVar2 & (*(ushort *)(param_1 + 0x14) | *(ushort *)(param_1 + 0x16))))) {
          *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 4;
        }
        else {
          *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) & 0xfffb;
        }
      }
      break;
    case 2:
      break;
    case 3:
      if (uVar6 != 0) {
        *puVar7 = *puVar7 | 2;
        uVar3 = FUN_060096c4((ushort *)(uintptr_t)(iVar10));
        *(undefined2 *)(param_1 + 0x12) = uVar3;
        uVar9 = (*(uint *)(DAT_060164f0 & 0xfffffffc) >> (DAT_060164f0 & 3) * 8 |
                *(uint *)(DAT_060164f0 & 0xfffffffc) << (DAT_060164f0 & 3) * -8 + 0x20) + 0x41c;
        uVar1 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        if (*(short *)(param_1 + 0x12) ==
            *(short *)((uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + 0x4a)) {
          *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 2;
        }
        else {
          *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) & 0xfffd;
        }
      }
      break;
    case 4:
      if (5 < uVar6) {
        *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x200;
        *(uint *)(param_1 + 0x20) = uVar9;
      }
      break;
    case 5:
      if (2 < uVar6) {
        *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x100;
        *(uint *)(param_1 + 0x24) = uVar9;
      }
      break;
    case 6:
      break;
    default:
      if (iVar5 == 0xdd) {
        if ((((uVar6 < 8) || (iVar5 = FUN_060096c4((ushort *)(uintptr_t)(iVar10)), iVar5 != 0)) ||
            (iVar5 = FUN_060096c4((ushort *)(uintptr_t)(uVar9 + 3)), iVar5 != 9)) ||
           ((iVar5 = FUN_060096c4((ushort *)(uintptr_t)(uVar9 + 4)), iVar5 != 0xbf ||
            (iVar5 = FUN_060096c4((ushort *)(uintptr_t)(uVar9 + 5)), iVar5 != 0)))) {
          *(short *)(param_1 + 0x18) = *(short *)(param_1 + 0x18) + 1;
          *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + (short)uVar6 + 2;
        }
        else {
          *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x400;
          *(uint *)(param_1 + 0x28) = uVar9;
        }
      }
      else {
        *(short *)(param_1 + 0x18) = *(short *)(param_1 + 0x18) + 1;
        *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + (short)uVar6 + 2;
      }
    }
    uVar9 = iVar10 + uVar6;
  }
  if (((*(ushort *)(param_1 + 0xc) & 8) != 0) &&
     (((*(ushort *)(uVar4 + 0x3a8) & 1) != 0 || ((*(ushort *)(param_1 + 4) & 0x8000) != 0)))) {
    *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 8;
  }
  if ((*(ushort *)(param_1 + 0xc) & 0x30) != 0) {
    if ((*(ushort *)(param_1 + 6) & 3) == (*(ushort *)(uVar4 + 0x3c0) & 3)) {
      *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 0x10;
    }
    if ((*(ushort *)(param_1 + 6) & 0x10) == (*(ushort *)(uVar4 + 0x3c0) & 0x10)) {
      *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 0x20;
    }
  }
  return;
}

