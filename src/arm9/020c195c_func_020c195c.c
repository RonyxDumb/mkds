/* Decompiled C draft; module arm9; ROM address 020c195c. No matching claim. */
#include "types.h"
#include "deps/020c195c_func_020c195c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020c195c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar3;
  
  uVar1 = uRam020c1ba4;
  uVar8 = *(uint *)(uRam020c1ba4 & 0xfffffffc) >> (uRam020c1ba4 & 3) * 8 |
          *(uint *)(uRam020c1ba4 & 0xfffffffc) << (uRam020c1ba4 & 3) * -8 + 0x20;
  uVar2 = uVar8 + 0xb0;
  uVar9 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
  *(uint *)(uVar8 + 0xb0) = uVar3 + 1;
  uVar9 = uRam020c1bac;
  uVar2 = uRam020c1ba8;
  if ((int)uVar3 < 0x5a) {
    uVar8 = 0;
    uVar10 = *(uint *)(uRam020c1ba8 & 0xfffffffc) >> (uRam020c1ba8 & 3) * 8 |
             *(uint *)(uRam020c1ba8 & 0xfffffffc) << (uRam020c1ba8 & 3) * -8 + 0x20;
    if (*(char *)(uVar10 + 0x3d0) != '\0') {
      do {
        uVar11 = uVar10 + 0x1c & 3;
        uVar4 = *(uint *)(uVar10 + 0x1c & 0xfffffffc);
        if (((uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) == 1) ||
           (uVar11 = uVar10 + 8 & 3, uVar10 = *(uint *)(uVar10 + 8 & 0xfffffffc),
           (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) == 2)) {
          uVar5 = Int32ToInt8(uVar8);
          iVar6 = GetSomeLUMaxIndex();
          iVar7 = Int32ToInt8(uVar5);
          *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar8 * 4 + 0x20) =
               (uint)*(byte *)(iVar7 * 10 +
                               iVar6 * 0x50 +
                               (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                               *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 5);
        }
        else {
          uVar5 = Int32ToInt8(uVar8);
          iVar6 = GetSomeLUMaxIndex();
          iVar7 = Int32ToInt8(uVar5);
          *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar8 * 4 + 0x20) =
               (uint)*(ushort *)
                      (iVar6 * 0x50 +
                       (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                       *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iVar7 * 10);
        }
        uVar10 = uVar2 & 3;
        uVar11 = *(uint *)(uVar2 & 0xfffffffc);
        uVar10 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
        uVar8 = uVar8 + 1 & 0xffff;
      } while (uVar8 < *(byte *)(uVar10 + 0x3d0));
    }
  }
  else {
    uVar2 = *(uint *)(uRam020c1ba8 & 0xfffffffc) >> (uRam020c1ba8 & 3) * 8 |
            *(uint *)(uRam020c1ba8 & 0xfffffffc) << (uRam020c1ba8 & 3) * -8 + 0x20;
    if (*(char *)(uVar2 + 0x58) == '\0') {
      if (*(short *)(uVar2 + 0x60) == 1) {
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xac) = uRam020c1bb4;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xb0) = 0;
      }
      else {
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xac) = uRam020c1bb8;
        *(undefined4 *)
         ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xb0) = 0;
      }
    }
    else {
      *(undefined4 *)
       ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xac) = uRam020c1bb0;
      *(undefined4 *)
       ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xb0) = 0;
    }
  }
  uVar2 = uRam020c1ba4;
  if ((*(ushort *)(iRam020c1bbc + 0x2e0) & 1) == 0) {
    return;
  }
  if ((int)uVar3 < 0x2d) {
    return;
  }
  uVar9 = *(uint *)(uRam020c1ba8 & 0xfffffffc) >> (uRam020c1ba8 & 3) * 8 |
          *(uint *)(uRam020c1ba8 & 0xfffffffc) << (uRam020c1ba8 & 3) * -8 + 0x20;
  if (*(char *)(uVar9 + 0x58) != '\0') {
    *(undefined4 *)
     ((*(uint *)(uRam020c1ba4 & 0xfffffffc) >> (uRam020c1ba4 & 3) * 8 |
      *(uint *)(uRam020c1ba4 & 0xfffffffc) << (uRam020c1ba4 & 3) * -8 + 0x20) + 0xac) = uRam020c1bb0
    ;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xb0) = 0;
    return;
  }
  if (*(short *)(uVar9 + 0x60) == 1) {
    *(undefined4 *)
     ((*(uint *)(uRam020c1ba4 & 0xfffffffc) >> (uRam020c1ba4 & 3) * 8 |
      *(uint *)(uRam020c1ba4 & 0xfffffffc) << (uRam020c1ba4 & 3) * -8 + 0x20) + 0xac) = uRam020c1bb4
    ;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xb0) = 0;
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020c1ba4 & 0xfffffffc) >> (uRam020c1ba4 & 3) * 8 |
    *(uint *)(uRam020c1ba4 & 0xfffffffc) << (uRam020c1ba4 & 3) * -8 + 0x20) + 0xac) = uRam020c1bb8;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xb0) = 0;
  return;
}

