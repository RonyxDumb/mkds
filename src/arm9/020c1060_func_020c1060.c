/* Decompiled C draft; module arm9; ROM address 020c1060. No matching claim. */
#include "types.h"
#include "deps/020c1060_func_020c1060.h"

void func_020c1060(void)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint unaff_r5;
  uint unaff_r6;
  uint uVar13;
  uint uStack_50;
  uint uStack_4c;
  int local_48 [9];
  
  uVar5 = uRam020c13c4;
  uVar13 = 0;
  uVar10 = *(uint *)(uRam020c13c0 & 0xfffffffc) >> (uRam020c13c0 & 3) * 8 |
           *(uint *)(uRam020c13c0 & 0xfffffffc) << (uRam020c13c0 & 3) * -8 + 0x20;
  uVar11 = (uint)*(byte *)(uVar10 + 0x3d0);
  if (uVar11 != 0) {
    do {
      uVar11 = uVar10 + 0x1c & 3;
      uVar6 = *(uint *)(uVar10 + 0x1c & 0xfffffffc);
      if (((uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) == 1) ||
         (uVar11 = uVar10 + 8 & 3, uVar6 = *(uint *)(uVar10 + 8 & 0xfffffffc),
         (uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) == 2)) {
        uVar10 = uVar13 * 0x30 + uVar10 + 0x70;
        uVar11 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
        bVar4 = 0;
        if ((uVar10 < 4) && ((1 << (uVar10 & 0xff) & 0xdU) != 0)) {
          bVar4 = 1;
        }
        uVar7 = Int32ToInt8(uVar13);
        iVar8 = GetSomeLUMaxIndex();
        iVar9 = Int32ToInt8(uVar7);
        bVar2 = *(byte *)(iVar9 * 10 +
                          iVar8 * 0x50 +
                          (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 5);
        iVar8 = GetDriverPlace(uVar13);
        local_48[uVar13] = ((uint)bVar2 * 0x10 + (uint)bVar4 * 8 + 8) - iVar8;
      }
      else {
        uVar10 = uVar13 * 0x30 + uVar10 + 0x70;
        uVar11 = uVar10 & 3;
        uVar10 = *(uint *)(uVar10 & 0xfffffffc);
        uVar10 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
        bVar4 = 0;
        if ((uVar10 < 4) && ((1 << (uVar10 & 0xff) & 0xdU) != 0)) {
          bVar4 = 1;
        }
        uVar7 = Int32ToInt8(uVar13);
        iVar8 = GetSomeLUMaxIndex();
        iVar9 = Int32ToInt8(uVar7);
        uVar3 = *(ushort *)
                 (iVar8 * 0x50 +
                  (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                  *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + iVar9 * 10);
        iVar8 = GetDriverPlace(uVar13);
        local_48[uVar13] = ((uint)uVar3 * 0x10 + (uint)bVar4 * 8 + 8) - iVar8;
        uVar7 = Int32ToInt8(uVar13);
        iVar8 = GetSomeLUMaxIndex();
        iVar9 = Int32ToInt8(uVar7);
        *(uint *)((*(uint *)(uRam020c13c8 & 0xfffffffc) >> (uRam020c13c8 & 3) * 8 |
                  *(uint *)(uRam020c13c8 & 0xfffffffc) << (uRam020c13c8 & 3) * -8 + 0x20) +
                  uVar13 * 4 + 0x20) =
             (uint)*(ushort *)
                    (iVar8 * 0x50 +
                     (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                     *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + iVar9 * 10);
      }
      uVar10 = *(uint *)(uRam020c13c0 & 0xfffffffc) >> (uRam020c13c0 & 3) * 8 |
               *(uint *)(uRam020c13c0 & 0xfffffffc) << (uRam020c13c0 & 3) * -8 + 0x20;
      uVar11 = (uint)*(byte *)(uVar10 + 0x3d0);
      uVar13 = uVar13 + 1 & 0xffff;
    } while (uVar13 < uVar11);
  }
  uVar10 = uRam020c13c8;
  uVar5 = uRam020c13c0;
  uVar13 = 0;
  if (uVar11 != 0) {
    do {
      uVar11 = uVar10 & 3;
      uVar6 = *(uint *)(uVar10 & 0xfffffffc);
      *(uint *)((uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) + uVar13 * 4 + 0x40) = uVar13;
      local_48[uVar13] = -local_48[uVar13];
      uVar11 = uVar5 & 3;
      uVar6 = *(uint *)(uVar5 & 0xfffffffc);
      uVar13 = uVar13 + 1 & 0xffff;
    } while (uVar13 < *(byte *)((uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20) + 0x3d0));
  }
  func_020ae770((*(uint *)(uRam020c13c8 & 0xfffffffc) >> (uRam020c13c8 & 3) * 8 |
                *(uint *)(uRam020c13c8 & 0xfffffffc) << (uRam020c13c8 & 3) * -8 + 0x20) + 0x40,
                local_48);
  uVar5 = uRam020c13c8;
  uVar13 = 0;
  uVar10 = *(uint *)(uRam020c13c0 & 0xfffffffc) >> (uRam020c13c0 & 3) * 8 |
           *(uint *)(uRam020c13c0 & 0xfffffffc) << (uRam020c13c0 & 3) * -8 + 0x20;
  uVar11 = (uint)*(byte *)(uVar10 + 0x3d0);
  if (uVar11 == 0) {
    return;
  }
  uStack_4c = 0;
  uStack_50 = 0;
  do {
    if (uVar11 != 0) {
      uVar11 = uStack_50;
      do {
        uVar6 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + uVar11 * 4 + 0x40;
        uVar1 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        if (uVar13 == (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20)) {
          func_0205d76c(uVar13,uVar11 + 1 & 0xff);
          *(uint *)((*(uint *)(uRam020c13cc & 0xfffffffc) >> (uRam020c13cc & 3) * 8 |
                    *(uint *)(uRam020c13cc & 0xfffffffc) << (uRam020c13cc & 3) * -8 + 0x20) +
                    uVar13 * 4 + 0xec) = uVar11;
          unaff_r6 = uVar11;
          break;
        }
        uVar11 = uVar11 + 1 & 0xffff;
      } while (uVar11 < *(byte *)(uVar10 + 0x3d0));
    }
    uVar10 = *(uint *)(uRam020c13c0 & 0xfffffffc) >> (uRam020c13c0 & 3) * 8 |
             *(uint *)(uRam020c13c0 & 0xfffffffc) << (uRam020c13c0 & 3) * -8 + 0x20;
    uVar6 = unaff_r5;
    if (*(char *)(uVar10 + 0x3d0) != '\0') {
      uVar11 = uStack_4c;
      do {
        uVar6 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + uVar11 * 4 + 0x60;
        uVar1 = uVar6 & 3;
        uVar12 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar11;
        if (uVar13 == (uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20)) break;
        uVar11 = uVar11 + 1 & 0xffff;
        uVar6 = unaff_r5;
      } while (uVar11 < *(byte *)(uVar10 + 0x3d0));
    }
    if ((int)unaff_r6 < (int)uVar6) {
      *(undefined4 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + uVar13 * 4 + 0x80) = 1;
    }
    else if ((int)uVar6 < (int)unaff_r6) {
      *(undefined4 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + uVar13 * 4 + 0x80) = 0;
    }
    else {
      *(undefined4 *)
       ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + uVar13 * 4 + 0x80) = 2;
    }
    uVar10 = *(uint *)(uRam020c13c0 & 0xfffffffc) >> (uRam020c13c0 & 3) * 8 |
             *(uint *)(uRam020c13c0 & 0xfffffffc) << (uRam020c13c0 & 3) * -8 + 0x20;
    uVar11 = (uint)*(byte *)(uVar10 + 0x3d0);
    uVar13 = uVar13 + 1 & 0xffff;
    unaff_r5 = uVar6;
    if (uVar11 <= uVar13) {
      return;
    }
  } while( true );
}

