/* Decompiled C draft; module arm9; ROM address 020f03f8. No matching claim. */
#include "types.h"
#include "deps/020f03f8_func_020f03f8.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020f03f8(uint param_1)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int unaff_r7;
  int iVar15;
  uint uVar16;
  uint local_34;
  uint uVar10;
  
  uVar13 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
  uVar13 = param_1 + 0x20 & 3;
  uVar9 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  uVar10 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
  uVar13 = param_1 + 0x14 & 3;
  uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  local_34 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
  if ((1 < (int)uVar10) &&
     (uVar13 = param_1 + 0x1c & 3, uVar9 = *(uint *)(param_1 + 0x1c & 0xfffffffc),
     (int)(uVar10 - (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20)) < 2)) {
    uVar13 = param_1 + 0x18 & 3;
    uVar9 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
    uVar13 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
    iVar5 = func_02061f90();
    if (iVar5 == 0) {
      uVar13 = param_1 + 0x20 & 3;
      uVar11 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
      uVar9 = param_1 + 0x1c & 3;
      uVar10 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
      if (((int)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) -
                (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20)) < 1) &&
         (uVar13 = param_1 + 0x14 & 3, uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc),
         0 < (int)(uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20))) {
        uVar13 = param_1 + 4 & 3;
        uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
        uVar9 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
        uVar13 = uVar9 & 3;
        uVar9 = *(uint *)(uVar9 & 0xfffffffc);
        func_020f9ba8(uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20);
      }
    }
    else {
      if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 2) {
        uVar13 = uVar13 - 3;
      }
      func_020f0684(uVar4,iVar5,uVar13,7);
    }
  }
  uVar13 = (*(uint *)(uRam020f067c & 0xfffffffc) >> (uRam020f067c & 3) * 8 |
           *(uint *)(uRam020f067c & 0xfffffffc) << (uRam020f067c & 3) * -8 + 0x20) + 8;
  uVar9 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  if ((uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) != 5) {
    iVar5 = 0;
    if (0 < (int)local_34) {
      do {
        uVar13 = uVar4 + iVar5 * 4;
        uVar9 = uVar13 & 3;
        uVar13 = *(uint *)(uVar13 & 0xfffffffc);
        iVar6 = func_01fff95c(param_1,uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20,0);
        if (iVar6 != 0) {
          uVar13 = param_1 + 0x14 & 3;
          uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
          local_34 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
          iVar5 = iVar5 + -1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)local_34);
      return;
    }
    return;
  }
  iVar5 = 0;
  if ((int)local_34 < 1) {
    return;
  }
  do {
    iVar6 = iRam020f0680;
    uVar13 = uVar4 + iVar5 * 4;
    uVar9 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    uVar9 = uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20;
    uVar3 = *(ushort *)(uVar9 + 0x7a);
    uVar13 = uVar3 & 0xffff7fff;
    if ((uVar3 & 0x7fff) == 0 || (int)uVar13 < 0) {
      iVar6 = func_01fff95c(param_1,uVar9,0);
      if (iVar6 != 0) {
        uVar13 = param_1 + 0x14 & 3;
        uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
        local_34 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
        iVar5 = iVar5 + -1;
      }
    }
    else {
      if ((uVar3 & 0x8000) == 0) {
        iVar15 = 2;
        while (uVar13 = (int)uVar13 >> 2, uVar13 != 0) {
          iVar15 = iVar15 + 1;
        }
      }
      else {
        *(short *)(uVar9 + 0x7a) = (short)uVar13;
        iVar15 = uVar13 + 1;
        unaff_r7 = iVar6;
      }
      uVar13 = uVar9 + 0xe0 & 3;
      uVar10 = *(uint *)(uVar9 + 0xe0 & 0xfffffffc);
      func_020d5180(uVar9 + 0x50,
                    iVar15 * 0xa000 + (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20),0x6000);
      *(short *)(uVar9 + 0x7a) = *(short *)(uVar9 + 0x7a) + 1;
      do {
        *(short *)(uVar9 + 0x7a) = *(short *)(uVar9 + 0x7a) + -1;
        iVar6 = func_01fff95c(param_1,uVar9,1);
        if (iVar6 != 0) {
          uVar13 = param_1 + 0x14 & 3;
          uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
          local_34 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
          iVar5 = iVar5 + -1;
          break;
        }
        iVar6 = unaff_r7;
        if ((uVar3 & 0x8000) != 0) {
          uVar13 = uVar9 + 0xd0 & 3;
          uVar10 = *(uint *)(uVar9 + 0xd0 & 0xfffffffc);
          uVar14 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
          iVar7 = GetDriverEntry(*(ushort *)(uVar9 + 0x78) & 0xff);
          uVar13 = iVar7 + 0x98U & 3;
          uVar11 = *(uint *)(iVar7 + 0x98U & 0xfffffffc);
          uVar10 = iVar7 + 0x9cU & 3;
          uVar8 = *(uint *)(iVar7 + 0x9cU & 0xfffffffc);
          iVar6 = (int)((uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) -
                       (*(uint *)(uVar14 & 0xfffffffc) >> (uVar14 & 3) * 8 |
                       *(uint *)(uVar14 & 0xfffffffc) << (uVar14 & 3) * -8 + 0x20)) >> 0xc;
          uVar13 = iVar7 + 0xa0U & 3;
          uVar12 = *(uint *)(iVar7 + 0xa0U & 0xfffffffc);
          uVar11 = uVar14 + 4 & 3;
          uVar16 = *(uint *)(uVar14 + 4 & 0xfffffffc);
          uVar2 = uVar14 + 8 & 3;
          uVar14 = *(uint *)(uVar14 + 8 & 0xfffffffc);
          iVar7 = (int)((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) -
                       (uVar16 >> uVar11 * 8 | uVar16 << uVar11 * -8 + 0x20)) >> 0xc;
          iVar1 = (int)((uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) -
                       (uVar14 >> uVar2 * 8 | uVar14 << uVar2 * -8 + 0x20)) >> 0xc;
          iVar6 = iVar1 * iVar1 + iVar6 * iVar6 + iVar7 * iVar7;
          if (unaff_r7 <= iVar6) break;
        }
        iVar15 = iVar15 + -1;
        unaff_r7 = iVar6;
      } while (0 < iVar15);
    }
    iVar5 = iVar5 + 1;
    if ((int)local_34 <= iVar5) {
      return;
    }
  } while( true );
}

