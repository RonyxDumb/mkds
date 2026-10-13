/* Decompiled C draft; module arm9; ROM address 020cfca4. No matching claim. */
#include "types.h"
#include "deps/020cfca4_func_020cfca4.h"

void func_020cfca4(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_28 [6];
  
  uVar2 = uRam020cff94;
  uVar3 = *(uint *)(uRam020cff90 & 0xfffffffc) >> (uRam020cff90 & 3) * 8 |
          *(uint *)(uRam020cff90 & 0xfffffffc) << (uRam020cff90 & 3) * -8 + 0x20;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 0x1d) {
    if ((int)uVar4 < 0x1c) {
      if (((int)uVar4 < 0x12) && (0xe < (int)uVar4)) {
        if (uVar4 == 0xf) {
          iVar8 = 0;
          iVar5 = 0;
          iVar6 = 0;
          do {
            iVar7 = 0;
            do {
              iVar9 = iVar7 + iVar5;
              iVar1 = iVar7 * 2;
              iVar7 = iVar7 + 1;
              *(undefined2 *)
               (iVar6 + (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar1 + 2) =
                   *(undefined2 *)(&DAT_05000400 + (iVar9 + 0x40) * 2);
            } while (iVar7 < 3);
            iVar8 = iVar8 + 1;
            iVar5 = iVar5 + 0x10;
            iVar6 = iVar6 + 6;
          } while (iVar8 < 9);
        }
        else if (uVar4 == 0x11) {
          iVar6 = 0;
          do {
            iVar8 = local_28[iVar6];
            iVar5 = 0;
            do {
              iVar7 = iVar5 * 2;
              iVar5 = iVar5 + 1;
              *(undefined2 *)
               (iVar6 * 8 +
                (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar7 + 2) =
                   *(undefined2 *)(&DAT_05000400 + (iVar8 + 0x80) * 2);
              iVar8 = iVar8 + 1;
            } while (iVar5 < 4);
            iVar6 = iVar6 + 1;
          } while (iVar6 < 5);
        }
      }
    }
    else {
      iVar6 = 0;
      do {
        iVar8 = iVar6 + 0x78;
        iVar5 = iVar6 * 2;
        iVar6 = iVar6 + 1;
        *(undefined2 *)
         ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 2) =
             *(undefined2 *)(&DAT_05000400 + iVar8 * 2);
      } while (iVar6 < 0x14);
      *(undefined2 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x2a) = *puRam020cff9c;
    }
  }
  else if ((int)uVar4 < 0x21) {
    if (0x1e < (int)uVar4) {
      if (uVar4 == 0x1f) {
        iVar6 = 0;
        do {
          iVar8 = iVar6 + 0x46;
          iVar5 = iVar6 * 2;
          iVar6 = iVar6 + 1;
          *(undefined2 *)
           ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 2) =
               *(undefined2 *)(&DAT_05000400 + iVar8 * 2);
        } while (iVar6 < 3);
      }
      else if (uVar4 == 0x20) {
        iVar6 = 0;
        do {
          iVar8 = iVar6 + 0x54;
          iVar5 = iVar6 * 2;
          iVar6 = iVar6 + 1;
          *(undefined2 *)
           ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 2) =
               *(undefined2 *)(&DAT_05000400 + iVar8 * 2);
          uVar4 = uRam020cff94;
        } while (iVar6 < 6);
        iVar6 = 0;
        iVar8 = 0;
        iVar5 = 0;
        do {
          iVar7 = 0;
          do {
            iVar9 = iVar7 + iVar8;
            uVar2 = uVar4 & 3;
            uVar3 = *(uint *)(uVar4 & 0xfffffffc);
            iVar1 = iVar7 * 2;
            iVar7 = iVar7 + 1;
            *(undefined2 *)(iVar5 + (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + iVar1 + 0xe)
                 = *(undefined2 *)(&DAT_05000400 + (iVar9 + 0x5a) * 2);
            uVar2 = uRam020cff94;
          } while (iVar7 < 3);
          iVar6 = iVar6 + 1;
          iVar8 = iVar8 + 3;
          iVar5 = iVar5 + 6;
        } while (iVar6 < 2);
        iVar6 = 0;
        do {
          iVar5 = iVar6 * 2;
          uVar4 = uVar2 & 3;
          uVar3 = *(uint *)(uVar2 & 0xfffffffc);
          iVar8 = iVar6 * 2;
          iVar6 = iVar6 + 1;
          *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar8 + 0x1a) =
               *(undefined2 *)(&DAT_05000400 + iVar5);
        } while (iVar6 < 2);
      }
    }
  }
  else if (uVar4 == 0x2e) {
    iVar6 = 0;
    do {
      iVar8 = iVar6 + 0xfb;
      iVar5 = iVar6 * 2;
      iVar6 = iVar6 + 1;
      *(undefined2 *)
       ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
        *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar5 + 2) =
           *(undefined2 *)(&DAT_05000400 + iVar8 * 2);
    } while (iVar6 < 5);
  }
  *(undefined2 *)
   (*(uint *)(uRam020cff94 & 0xfffffffc) >> (uRam020cff94 & 3) * 8 |
   *(uint *)(uRam020cff94 & 0xfffffffc) << (uRam020cff94 & 3) * -8 + 0x20) = 0;
  return;
}

