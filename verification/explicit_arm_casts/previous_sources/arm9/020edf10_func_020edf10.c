/* Decompiled C draft; module arm9; ROM address 020edf10. No matching claim. */
#include "types.h"
#include "deps/020edf10_func_020edf10.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020edf10(int param_1)

{
  ushort uVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 uStack_28;
  
  uVar11 = param_1 + 0x10U & 3;
  uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar5 = param_1 + 0x20U & 3;
  uVar12 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar12 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
  iVar4 = StructMQRacerEntry_SomeFn_71(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20);
  uVar11 = param_1 + 0x10U & 3;
  uVar5 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  iVar6 = StructMQRacerEntry_SomeFn_83(uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20);
  iVar13 = iRam020ee14c;
  iVar10 = 0;
  if (0 < (int)uVar12) {
    do {
      uVar11 = param_1 + 0x14 + iVar10 * 4;
      uVar5 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar3 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
      uVar11 = uVar3 + 0x11c & 3;
      uVar5 = *(uint *)(uVar3 + 0x11c & 0xfffffffc);
      *(uint *)(uVar3 + 0x11c) = (uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20) + 1;
      VecFx32_Subtract(uVar3 + 0x50,uVar3 + 0xe4,uVar3 + 0x5c);
      *(undefined4 *)(uVar3 + 0xe4) = *(undefined4 *)(uVar3 + 0x50);
      *(undefined4 *)(uVar3 + 0xe8) = *(undefined4 *)(uVar3 + 0x54);
      *(undefined4 *)(uVar3 + 0xec) = *(undefined4 *)(uVar3 + 0x58);
      uVar11 = param_1 + 0x24U & 3;
      uVar5 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
      uVar11 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20;
      if (uVar11 == 0) {
        uVar7 = *(undefined4 *)(param_1 + 0x3c);
        uVar8 = *(undefined4 *)(param_1 + 0x40);
        *(undefined4 *)(uVar3 + 0xf0) = *(undefined4 *)(param_1 + 0x38);
        *(undefined4 *)(uVar3 + 0xf4) = uVar7;
        *(undefined4 *)(uVar3 + 0xf8) = uVar8;
        uVar11 = uVar3 + 0xf4 & 3;
        uVar5 = *(uint *)(uVar3 + 0xf4 & 0xfffffffc);
        uVar11 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20;
        if ((int)uVar11 < iVar13) {
          uVar11 = uVar3 + 0x74 & 3;
          uVar5 = *(uint *)(uVar3 + 0x74 & 0xfffffffc);
          uVar11 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20 | 0x80;
          *(uint *)(uVar3 + 0x74) = uVar11;
        }
      }
      if (iVar4 != 0) {
        uVar11 = uVar3 + 0x74 & 3;
        uVar5 = *(uint *)(uVar3 + 0x74 & 0xfffffffc);
        uVar11 = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20;
      }
      iVar10 = iVar10 + 1;
      if (iVar4 != 0) {
        *(uint *)(uVar3 + 0x74) = uVar11 | 0x40000;
      }
      else {
        uVar11 = uVar3 + 0x74 & 3;
        uVar5 = *(uint *)(uVar3 + 0x74 & 0xfffffffc);
        *(uint *)(uVar3 + 0x74) = (uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20) & 0xfffbffff;
      }
      if (iVar6 == 0) {
        uVar11 = uVar3 + 0x74 & 3;
        uVar5 = *(uint *)(uVar3 + 0x74 & 0xfffffffc);
        *(uint *)(uVar3 + 0x74) = (uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20) & 0xfffeffff;
      }
      else {
        uVar11 = uVar3 + 0x74 & 3;
        uVar5 = *(uint *)(uVar3 + 0x74 & 0xfffffffc);
        *(uint *)(uVar3 + 0x74) = uVar5 >> uVar11 * 8 | uVar5 << uVar11 * -8 + 0x20 | 0x10000;
      }
    } while (iVar10 < (int)uVar12);
  }
  uVar5 = uRam020ee158;
  psVar2 = psRam020ee154;
  uVar11 = uRam020ee150;
  iVar13 = uVar12 - 1;
  if (iVar13 < 0) {
    return;
  }
  uStack_28 = 0;
  do {
    uVar3 = param_1 + 0x14 + iVar13 * 4;
    uVar12 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20;
    if (*(short *)(uVar3 + 0xda) == -1) {
      iVar4 = func_020f91e0(uVar3);
      if ((iVar4 != 0) &&
         (uVar12 = uVar3 + 0x44 & 3, uVar9 = *(uint *)(uVar3 + 0x44 & 0xfffffffc),
         uVar12 = (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) * 0xa8 +
                  (*(uint *)(uRam020ee15c & 0xfffffffc) >> (uRam020ee15c & 3) * 8 |
                  *(uint *)(uRam020ee15c & 0xfffffffc) << (uRam020ee15c & 3) * -8 + 0x20) + 0x68,
         uVar9 = uVar12 & 3, uVar12 = *(uint *)(uVar12 & 0xfffffffc),
         uVar12 >> uVar9 * 8 != 0 || uVar12 << uVar9 * -8 + 0x20 != 0)) {
        func_020f9ca8(uVar3);
      }
    }
    else {
      func_01ffd900((int)*(short *)(uVar3 + 0xda),0x6000);
      iVar4 = uStack_28;
      if (0 < *psVar2) {
        do {
          uVar12 = uVar5 & 3;
          uVar9 = *(uint *)(uVar5 & 0xfffffffc);
          uVar1 = *(ushort *)((uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) + iVar4 * 2);
          if ((uVar1 & 0x4000) == 0) {
            if ((uVar1 & 0x2000) != 0) {
              uVar12 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                       *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + iVar4 * 4;
              uVar9 = uVar12 & 3;
              uVar12 = *(uint *)(uVar12 & 0xfffffffc);
              uVar12 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
              iVar6 = func_020d2234(uVar12,uVar3);
              if (iVar6 == 0) goto LAB_020ee128;
              func_020f944c(uVar3,uVar12);
            }
LAB_020ee118:
            if (*(short *)(uVar3 + 0xda) == -1) break;
          }
          else {
            uVar12 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                     *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + iVar4 * 4;
            uVar9 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            uVar12 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
            if ((*(short *)(uVar12 + 0xda) != -1) &&
               ((uVar1 = *(ushort *)(uVar12 + 0x78), (uVar1 & 0x4000) == 0 ||
                (*(ushort *)(param_1 + 0x28) != (uVar1 & 0xff))))) {
              func_020ee160(uVar3);
              goto LAB_020ee118;
            }
          }
LAB_020ee128:
          iVar4 = iVar4 + 1;
        } while (iVar4 < *psVar2);
      }
    }
    iVar13 = iVar13 + -1;
    if (iVar13 < 0) {
      return;
    }
  } while( true );
}

