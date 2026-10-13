/* Decompiled C draft; module arm9; ROM address 02136850. No matching claim. */
#include "types.h"
#include "deps/02136850_func_02136850.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * func_02136850(uint param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,
                    undefined4 param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar13;
  ushort uStack_74;
  undefined2 uStack_72;
  undefined1 uStack_70;
  undefined1 uStack_6f;
  undefined1 uStack_6e;
  undefined1 uStack_6d;
  undefined1 uStack_6c;
  undefined1 uStack_6b;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_11;
  undefined4 uStack_10;
  undefined1 auStack_c [4];
  int iStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_7;
  uVar1 = (int)&param_5 + 1U & 3;
  uVar8 = (param_5 >> uVar1 * 8 | param_5 << uVar1 * -8 + 0x20) & 0xff;
  uVar1 = (int)&uStack_4 + 3U & 3;
  uVar10 = (int)&uStack_4 + 1U & 3;
  uVar10 = (param_4 >> uVar10 * 8 | param_4 << uVar10 * -8 + 0x20) & 0xff;
  if (iRam02136ee4 < param_7) {
    return (uint *)0x0;
  }
  _uStack_74 = CONCAT22(0x20,uStack_74 & 0xff00);
  uStack_10 = param_1;
  auStack_c = (undefined1  [4])param_2;
  iStack_8 = param_3;
  uStack_4 = param_4;
  func_02140c28((int)(uintptr_t)(&uStack_74),param_1,param_2,(int)(uintptr_t)(&uStack_60));
  uVar13 = func_021400c8(uStack_10,(undefined4)(uintptr_t)(auStack_c));
  iVar3 = FUN_02131bfc(0,0,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
  if (iVar3 != 0) {
    func_0213a2d0((uint *)(param_3 + -6),uRam02136ee8);
    return (uint *)(param_3 + -6);
  }
  uVar4 = (int)&uStack_5c + 1U & 3;
  uVar4 = (uStack_5c >> uVar4 * 8 | uStack_5c << uVar4 * -8 + 0x20) & 0xff;
  if (uVar4 == 0x49) {
    if ((uStack_60 & 0xff) == 0) {
      puVar9 = (uint *)(param_3 + -4);
      if (uVar8 == 0x41) {
        func_0213a2d0(puVar9,uRam02136ef4);
      }
      else {
        func_0213a2d0(puVar9,uRam02136ef8);
      }
    }
    else {
      puVar9 = (uint *)(param_3 + -5);
      if (uVar8 == 0x41) {
        func_0213a2d0(puVar9,uRam02136eec);
      }
      else {
        func_0213a2d0(puVar9,uRam02136ef0);
      }
    }
    return puVar9;
  }
  if (uVar4 == 0x4e) {
    if ((uStack_60 & 0xff) == 0) {
      puVar9 = (uint *)(param_3 + -4);
      if (uVar8 == 0x41) {
        func_0213a2d0(puVar9,uRam02136f04);
      }
      else {
        func_0213a2d0(puVar9,uRam02136f08);
      }
    }
    else {
      puVar9 = (uint *)(param_3 + -5);
      if (uVar8 == 0x41) {
        func_0213a2d0(puVar9,uRam02136efc);
      }
      else {
        func_0213a2d0(puVar9,uRam02136f00);
      }
    }
    return puVar9;
  }
  uVar5 = (uint)CONCAT12(uStack_6d,CONCAT11(uStack_6e,uStack_6f)) << 8 | 1;
  uStack_70 = 1;
  uVar4 = (uint)&uStack_6f & 3;
  uVar5 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xffffff00 | 1;
  uVar4 = (4 - ((uint)&uStack_6f & 3)) * 8 & 0x1f;
  uVar4 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
  uStack_6f = (undefined1)uVar4;
  uStack_6e = (undefined1)(uVar4 >> 8);
  uStack_6d = (undefined1)(uVar4 >> 0x10);
  uVar4 = (uint)&uStack_6e & 3;
  uVar5 = CONCAT13(uStack_6d,CONCAT12(uStack_6e,CONCAT11(uStack_6f,1)));
  iVar3 = 0;
  uVar5 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xffffff00;
  uVar4 = (4 - ((uint)&uStack_6e & 3)) * 8 & 0x1f;
  uVar4 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
  uStack_6e = (undefined1)uVar4;
  uStack_6d = (undefined1)(uVar4 >> 8);
  uVar4 = (uint)&uStack_6d & 3;
  uVar5 = CONCAT13(uStack_6d,CONCAT12(uStack_6e,CONCAT11(uStack_6f,1)));
  uVar5 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xffffff00;
  uVar4 = (4 - ((uint)&uStack_6d & 3)) * 8 & 0x1f;
  uVar4 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
  uStack_6d = (undefined1)uVar4;
  uStack_6c = 0;
  uStack_64 = 1;
  uVar5 = (uint)&uStack_6b & 3;
  uVar4 = (uint)CONCAT12(uStack_69,(short)(uVar4 >> 0x10)) << 8;
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xffffff00 | 100;
  uVar4 = (4 - ((uint)&uStack_6b & 3)) * 8 & 0x1f;
  uVar4 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
  uStack_6b = (undefined1)uVar4;
  uStack_6a = (undefined1)(uVar4 >> 8);
  uStack_69 = (undefined1)(uVar4 >> 0x10);
  uStack_68 = uVar4 >> 0x18;
  do {
    uVar6 = (int)&uStack_10 + iVar3 & 3;
    uVar11 = *(uint *)((int)&uStack_10 + iVar3 & 0xfffffffc);
    uVar5 = (uint)(auStack_c + -iVar3 + 3) & 3;
    uVar12 = *(uint *)((uint)(auStack_c + -iVar3 + 3) & 0xfffffffc);
    puVar9 = (uint *)((int)&uStack_10 + iVar3);
    puVar7 = (uint *)(auStack_c + -iVar3 + 3);
    uVar12 = (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) & 0xff |
             (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
             *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00;
    uVar5 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar12 >> uVar5 | uVar12 << 0x20 - uVar5;
    iVar3 = iVar3 + 1;
    uVar6 = (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) & 0xff |
            (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00;
    uVar5 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar6 >> uVar5 | uVar6 << 0x20 - uVar5;
  } while (iVar3 < 4);
  uVar5 = (int)&uStack_10 + 1U & 3;
  iVar3 = func_02137358((uRam02136f0c &
                        (uStack_10 << 0x19 |
                        ((uStack_10 >> uVar5 * 8 | uStack_10 << uVar5 * -8 + 0x20) & 0xff) << 0x11)
                        >> 0x15) + iRam02136f10,param_3,
                        CONCAT13(uStack_6d,CONCAT12(uStack_6e,CONCAT11(uStack_6f,1))),uVar4 << 8);
  if (uVar8 == 0x61) {
    puVar9 = (uint *)(iVar3 + -1);
    uVar5 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
            *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
            0x70;
    uVar4 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
  }
  else {
    puVar9 = (uint *)(iVar3 + -1);
    uVar5 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
            *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
            0x50;
    uVar4 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar5 >> uVar4 | uVar5 << 0x20 - uVar4;
  }
  puVar9 = (uint *)(iVar3 + -1);
  uVar4 = iVar2 * 4 + 0xb;
  iVar3 = iVar2;
  if (0 < iVar2) {
    do {
      if ((int)uVar4 < 0x40) {
        uVar5 = (int)&uStack_10 + ((int)uVar4 >> 3);
        uVar6 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar12 = 7 - (uVar4 & 7);
        uVar5 = (int)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xff) >> (uVar12 & 0xff) &
                0xff;
        if ((uVar4 & 0xfffffff8) != (uVar4 - 4 & 0xfffffff8)) {
          uVar6 = (uint)(&uStack_11 + ((int)uVar4 >> 3)) & 3;
          uVar11 = *(uint *)((uint)(&uStack_11 + ((int)uVar4 >> 3)) & 0xfffffffc);
          uVar5 = uVar5 | (int)(((uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) & 0xff) << 8)
                          >> (uVar12 & 0xff) & 0xffU;
        }
        uVar5 = uVar5 & 0xf;
        if (uVar5 < 10) {
          uVar5 = uVar5 + 0x30;
        }
        else if (uVar8 == 0x61) {
          uVar5 = uVar5 + 0x57;
        }
        else {
          uVar5 = uVar5 + 0x37;
        }
      }
      else {
        uVar5 = 0x30;
      }
      puVar9 = (uint *)((int)puVar9 + -1);
      iVar3 = iVar3 + -1;
      uVar5 = uVar5 | (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
                      *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) &
                      0xffffff00;
      uVar6 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
      *puVar9 = uVar5 >> uVar6 | uVar5 << 0x20 - uVar6;
      uVar4 = uVar4 - 4;
    } while (0 < iVar3);
  }
  if ((iVar2 != 0) || (((param_4 >> uVar1 * 8 | param_4 << uVar1 * -8 + 0x20) & 0xff) != 0)) {
    puVar9 = (uint *)((int)puVar9 + -1);
    uVar4 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
            *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
            0x2e;
    uVar1 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar4 >> uVar1 | uVar4 << 0x20 - uVar1;
  }
  puVar7 = (uint *)((int)puVar9 + -1);
  uVar4 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
          *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
          0x31;
  uVar1 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
  *puVar7 = uVar4 >> uVar1 | uVar4 << 0x20 - uVar1;
  if (uVar8 == 0x61) {
    puVar7 = (uint *)((int)puVar9 + -2);
    uVar8 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
            0x78;
    uVar1 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar8 >> uVar1 | uVar8 << 0x20 - uVar1;
  }
  else {
    puVar7 = (uint *)((int)puVar9 + -2);
    uVar8 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
            0x58;
    uVar1 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar8 >> uVar1 | uVar8 << 0x20 - uVar1;
  }
  puVar7 = (uint *)((int)puVar9 + -3);
  uVar8 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
          *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00 |
          0x30;
  uVar1 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
  *puVar7 = uVar8 >> uVar1 | uVar8 << 0x20 - uVar1;
  if ((uStack_60 & 0xff) != 0) {
    puVar9 = puVar9 + -1;
    uVar10 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
             *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
             0x2d;
    uVar1 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar10 >> uVar1 | uVar10 << 0x20 - uVar1;
    return puVar9;
  }
  if (uVar10 == 1) {
    puVar9 = puVar9 + -1;
    uVar10 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
             *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
             0x2b;
    uVar1 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
    *puVar9 = uVar10 >> uVar1 | uVar10 << 0x20 - uVar1;
    return puVar9;
  }
  if (uVar10 != 2) {
    return puVar7;
  }
  puVar9 = puVar9 + -1;
  uVar10 = (*(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
           *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20) & 0xffffff00 |
           0x20;
  uVar1 = (4 - ((uint)puVar9 & 3)) * 8 & 0x1f;
  *puVar9 = uVar10 >> uVar1 | uVar10 << 0x20 - uVar1;
  return puVar9;
}

