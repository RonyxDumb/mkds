/* Decompiled C draft; module arm9; ROM address 01fff95c. No matching claim. */
#include "types.h"
#include "deps/01fff95c_func_01fff95c.h"

undefined4 func_01fff95c(int param_1,int param_2,int param_3)

{
  uint uVar1;
  ushort uVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  code *pcVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  
  uVar10 = param_2 + 0x74U & 3;
  uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  *(uint *)(param_2 + 0x74) = (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0xfffff000;
  uVar10 = param_2 + 0x11cU & 3;
  uVar16 = *(uint *)(param_2 + 0x11cU & 0xfffffffc);
  if ((((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) == 1) &&
      (uVar10 = param_2 + 0x74U & 3, uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc),
      uVar10 = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20, (uVar10 & 0x8000000) != 0)) &&
     ((uVar10 & 0x10000000) == 0)) {
    func_020f0d04(param_2);
  }
  if (*(short *)(param_2 + 0x114) < 6) {
    *(short *)(param_2 + 0x114) = *(short *)(param_2 + 0x114) + 1;
  }
  if (*(short *)(param_2 + 0x116) < 6) {
    *(short *)(param_2 + 0x116) = *(short *)(param_2 + 0x116) + 1;
  }
  uVar10 = param_2 + 0x74U & 3;
  uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  if (((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0x8000) == 0) {
    *(undefined4 *)(param_2 + 0xfc) = 0;
  }
  uVar10 = param_2 + 0x74U & 3;
  uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  if (((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0x800000) == 0) {
    uVar10 = param_2 + 0x100U & 3;
    uVar16 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
    if ((uVar16 >> uVar10 * 8 == 0 && uVar16 << uVar10 * -8 + 0x20 == 0) &&
       (uVar10 = param_1 + 0x2cU & 3, uVar16 = *(uint *)(param_1 + 0x2cU & 0xfffffffc),
       iVar4 = func_020fa0b8(param_2,uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20,
                             uRam01fffe00), iVar4 != 0)) {
      func_020fa030(param_2);
    }
    else {
      uVar10 = param_2 + 0x74U & 3;
      uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
      if (((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0xc000) == 0) {
        uVar10 = param_1 + 0x30U & 3;
        uVar7 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
        uVar16 = param_1 + 0x34U & 3;
        uVar12 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
        iVar4 = func_020fa0b8(param_2,uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20,
                              uVar12 >> uVar16 * 8 | uVar12 << uVar16 * -8 + 0x20);
        if (iVar4 != 0) {
          func_020fa030(param_2);
        }
      }
      else {
        uVar10 = param_1 + 0x30U & 3;
        uVar16 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
        iVar4 = func_020fa0b8(param_2,uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20,
                              uRam01fffe04);
        iVar5 = func_020f9dc8(param_2);
        if ((iVar5 == 0) && (iVar4 != 0)) {
          func_020fa030(param_2);
        }
      }
    }
  }
  uVar10 = param_2 + 0x120U & 3;
  uVar16 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
  pcVar11 = (code *)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20);
  if (pcVar11 != (code *)0x0) {
    (*pcVar11)(param_2);
  }
  uVar10 = param_2 + 0x74U & 3;
  uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  uVar10 = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20;
  if ((uVar10 & 4) != 0) {
    return 1;
  }
  if (((uVar10 & 0x8000) == 0) && (*(short *)(param_2 + 0xda) != -1)) {
    if (param_3 == 0) {
      func_01ffd900((int)*(short *)(param_2 + 0xda),0x6000);
    }
    uVar7 = uRam01fffe14;
    uVar16 = uRam01fffe10;
    uVar10 = uRam01fffe0c;
    psVar3 = psRam01fffe08;
    iVar4 = 0;
    if (0 < *psRam01fffe08) {
      do {
        uVar12 = uVar7 & 3;
        uVar6 = *(uint *)(uVar7 & 0xfffffffc);
        uVar2 = *(ushort *)((uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + iVar4 * 2);
        if ((uVar2 & 0x4000) == 0) {
          if ((uVar2 & 0x2000) != 0) {
            uVar12 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                     *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + iVar4 * 4;
            uVar6 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            func_020f944c(param_2,uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
          }
LAB_01fffb50:
          if (*(short *)(param_2 + 0xda) == -1) break;
        }
        else {
          uVar12 = uVar16 & 3;
          uVar6 = *(uint *)(uVar16 & 0xfffffffc);
          if (*(short *)(param_2 + 0xda) !=
              *(short *)((uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + iVar4 * 2)) {
            uVar12 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                     *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + iVar4 * 4;
            uVar6 = uVar12 & 3;
            uVar12 = *(uint *)(uVar12 & 0xfffffffc);
            func_020f95d4(param_2,uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20);
            goto LAB_01fffb50;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *psVar3);
    }
  }
  uVar10 = param_2 + 0x74U & 3;
  uVar7 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  uVar16 = param_2 + 0xfcU & 3;
  uVar12 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
  uVar16 = uVar12 >> uVar16 * 8 | uVar12 << uVar16 * -8 + 0x20;
  if (((uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) & 0x8000) == 0) {
    func_0208ab98((ushort *)(uintptr_t)(param_2 + 0x7c),(uVar16 & 0x3c000000) >> 0x1a,0x5000);
  }
  else {
    func_0208ab98((ushort *)(uintptr_t)(param_2 + 0x7c),(uVar16 & 0x3c000000) >> 0x1a,0x800);
  }
  if ((uVar16 & uRam01fffe18) != 0) {
    *(undefined2 *)(param_2 + 0x114) = 0;
    if ((uVar16 & 0x1000000) != 0) {
      *(undefined2 *)(param_2 + 0x116) = 0;
    }
    if ((uVar16 & uRam01fffe1c) == 0) {
      uVar10 = param_2 + 0x74U & 3;
      uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
      *(uint *)(param_2 + 0x74) = (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0xbfffffff
      ;
    }
    else {
      if (((uVar16 & 0x400) != 0) && (*(short *)(param_2 + 0x118) == 0)) {
        uVar10 = param_2 + 0x74U & 3;
        uVar7 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
        if (((uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) & 0x8000) == 0) {
          *(undefined2 *)(param_2 + 0x118) = 2;
        }
        else {
          *(undefined2 *)(param_2 + 0x118) = 0xb4;
        }
      }
      if ((uVar16 & 0x80000) == 0) {
        uVar10 = param_2 + 0x74U & 3;
        uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
        *(uint *)(param_2 + 0x74) =
             (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0xbfffffff;
      }
      else {
        uVar10 = param_2 + 0x74U & 3;
        uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
        *(uint *)(param_2 + 0x74) = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20 | 0x40000000
        ;
      }
    }
  }
  if (((*(short *)(param_2 + 0x118) != 0) &&
      (uVar10 = param_2 + 0x74U & 3, uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc),
      ((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0x180000) == 0)) &&
     (*(short *)(param_2 + 0x118) = *(short *)(param_2 + 0x118) + -1,
     *(short *)(param_2 + 0x118) == 0)) {
    func_020f9b0c(param_2);
  }
  uVar10 = param_2 + 0x54U & 3;
  uVar16 = *(uint *)(param_2 + 0x54U & 0xfffffffc);
  if ((((int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) < 0) &&
      (uVar10 = param_2 + 0x44U & 3, uVar16 = *(uint *)(param_2 + 0x44U & 0xfffffffc),
      uVar10 = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20, uVar10 != 0xb)) &&
     (uVar10 != 10)) {
    func_020f7658(param_2,1);
  }
  iVar4 = iRam01fffe20;
  if (*(short *)(param_2 + 0x114) < 5) {
    uVar10 = param_2 + 0x74U & 3;
    uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0xfffdffff;
  }
  else {
    uVar10 = param_2 + 0x74U & 3;
    uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20 | 0x20000;
    uVar10 = param_2 + 0xf4U & 3;
    uVar16 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
    if (((int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) < iVar4) &&
       (uVar10 = param_2 + 0x74U & 3, uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc),
       ((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & uRam01fffe24) == 0)) {
      func_020eac20((uint *)(uintptr_t)(param_2 + 0xf0),0xcd);
    }
  }
  uVar10 = uRam01fffe28;
  if (*(short *)(param_2 + 0x116) < 5) {
    uVar16 = param_2 + 0x74U & 3;
    uVar7 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = uVar7 >> uVar16 * 8 | uVar7 << uVar16 * -8 + 0x20 | 0x40000;
  }
  else {
    uVar16 = param_2 + 0x74U & 3;
    uVar7 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = (uVar7 >> uVar16 * 8 | uVar7 << uVar16 * -8 + 0x20) & 0xfffbffff;
  }
  uVar16 = param_2 + 0x44U & 3;
  uVar12 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  uVar7 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = (uVar12 >> uVar16 * 8 | uVar12 << uVar16 * -8 + 0x20) * 0xa8 +
           (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x60;
  uVar16 = uVar10 & 3;
  uVar13 = *(uint *)(uVar10 & 0xfffffffc);
  uVar10 = param_2 + 0xe0U & 3;
  uVar14 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
  uVar7 = param_2 + 0xd0U & 3;
  uVar8 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
  uVar12 = param_1 + 0x38U & 3;
  uVar15 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar6 = param_1 + 0x3cU & 3;
  uVar17 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  uVar1 = param_1 + 0x28U & 3;
  uVar18 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar9 = (*(code *)(uVar18 >> uVar1 * 8 | uVar18 << uVar1 * -8 + 0x20))
                    (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,
                     (uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) *
                     (uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20),
                     uVar15 >> uVar12 * 8 | uVar15 << uVar12 * -8 + 0x20,
                     uVar17 >> uVar6 * 8 | uVar17 << uVar6 * -8 + 0x20);
  *(undefined4 *)(param_2 + 0xd4) = uVar9;
  uVar10 = param_2 + 0xd4U & 3;
  uVar16 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
  if (((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 3) == 0) {
    uVar10 = param_2 + 0x74U & 3;
    uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0xfffeffff;
  }
  else {
    uVar10 = param_2 + 0x74U & 3;
    uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
    *(uint *)(param_2 + 0x74) = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20 | 0x10000;
  }
  uVar10 = param_2 + 0x74U & 3;
  uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  if (((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0x400000) != 0) {
    func_020f90bc(param_2);
  }
  *(undefined4 *)(param_2 + 0xe4) = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)(param_2 + 0xe8) = *(undefined4 *)(param_2 + 0x54);
  *(undefined4 *)(param_2 + 0xec) = *(undefined4 *)(param_2 + 0x58);
  uVar10 = param_2 + 0x11cU & 3;
  uVar16 = *(uint *)(param_2 + 0x11cU & 0xfffffffc);
  *(uint *)(param_2 + 0x11c) = (uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) + 1;
  uVar2 = *(ushort *)(param_2 + 0x78);
  if ((uVar2 & 0x4000) != 0) {
    if ((uVar2 & 0x2000) == 0) {
      uVar10 = param_2 + 0x11cU & 3;
      uVar16 = *(uint *)(param_2 + 0x11cU & 0xfffffffc);
      if (0x1e < (int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20)) {
        *(ushort *)(param_2 + 0x78) = uVar2 & 0xbfff;
      }
    }
    else {
      uVar10 = param_2 + 0x11cU & 3;
      uVar16 = *(uint *)(param_2 + 0x11cU & 0xfffffffc);
      if ((4 < (int)(uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20)) &&
         (uVar10 = param_2 + 0x74U & 3, uVar16 = *(uint *)(param_2 + 0x74U & 0xfffffffc),
         ((uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20) & 0x20000) == 0)) {
        *(ushort *)(param_2 + 0x78) = uVar2 & 0xbfff;
      }
    }
  }
  return 0;
}

