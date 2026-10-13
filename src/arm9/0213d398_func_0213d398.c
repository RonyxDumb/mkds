/* Decompiled C draft; module arm9; ROM address 0213d398. No matching claim. */
#include "types.h"
#include "deps/0213d398_func_0213d398.h"

wchar_t * func_0213d398(undefined4 param_1,undefined4 param_2,int param_3,uint param_4,uint param_5,
                       undefined4 param_6,uint param_7)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  size_t sVar5;
  int iVar6;
  uint *puVar7;
  uint *__s;
  uint uVar8;
  wchar_t *pwVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined1 auStack_236 [510];
  uint uStack_38;
  undefined4 uStack_4;
  
  param_5 = param_5 >> 0x10;
  uVar10 = (int)&uStack_4 + 3U & 3;
  uVar8 = (param_4 >> uVar10 * 8 | param_4 << uVar10 * -8 + 0x20) & 0xff;
  uVar10 = (int)&uStack_4 + 1U & 3;
  uVar10 = (param_4 >> uVar10 * 8 | param_4 << uVar10 * -8 + 0x20) & 0xff;
  if (iRam0213dcb0 < (int)param_7) {
    return (wchar_t *)0x0;
  }
  uStack_260 = uStack_260 & 0xffffff00;
  uStack_4 = param_4;
  func_02140c28((int)(uintptr_t)(&uStack_260),param_1,param_2,(int)(uintptr_t)(&uStack_25c));
  uVar11 = uStack_38;
  uVar2 = (int)&uStack_258 + (uStack_258 & 0xff) + 1;
  while ((1 < (uStack_258 & 0xff) &&
         (uVar2 = uVar2 - 1,
         ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) & 0xff) == 0x30))) {
    uStack_258 = (uStack_258 & 0xff) - 1 & 0xff | uStack_258 & 0xffffff00;
    uStack_25c = CONCAT22(MKDS_SLICE_2(uStack_25c,2) + 1,(undefined2)uStack_25c);
  }
  uVar2 = (int)&uStack_258 + 1U & 3;
  uVar2 = (uStack_258 >> uVar2 * 8 | uStack_258 << uVar2 * -8 + 0x20) & 0xff;
  if (uVar2 == 0x30) {
    uStack_25c = uStack_25c & 0xffff;
  }
  else {
    if (uVar2 == 0x49) {
      iVar6 = FUN_02131ce8(param_1,param_2,0,0);
      if (iVar6 == 0) {
        if (0x7f < param_5) {
          uVar1 = 0;
        }
        else {
          uVar1 = *(ushort *)(iRam0213dcb4 + param_5 * 2);
        }
        pwVar9 = (wchar_t *)(param_3 + -8);
        if (0x7f >= param_5) {
          uVar1 = uVar1 & 0x200;
        }
        if (uVar1 == 0) {
          wcscpy(pwVar9,pwRam0213dcc4);
        }
        else {
          wcscpy(pwVar9,pwRam0213dcc0);
        }
      }
      else {
        if (0x7f < param_5) {
          uVar1 = 0;
        }
        else {
          uVar1 = *(ushort *)(iRam0213dcb4 + param_5 * 2);
        }
        pwVar9 = (wchar_t *)(param_3 + -10);
        if (0x7f >= param_5) {
          uVar1 = uVar1 & 0x200;
        }
        if (uVar1 == 0) {
          wcscpy(pwVar9,pwRam0213dcbc);
        }
        else {
          wcscpy(pwVar9,pwRam0213dcb8);
        }
      }
      return pwVar9;
    }
    if (uVar2 == 0x4e) {
      wcscpy((wchar_t *)(param_3 + -8),pwRam0213dcc8);
      return (wchar_t *)(param_3 + -8);
    }
  }
  uStack_25c = CONCAT22(MKDS_SLICE_2(uStack_25c,2) + (((ushort)uStack_258 & 0xff) - 1),(undefined2)uStack_25c)
  ;
  __s = (uint *)((int)&uStack_38 + 1);
  uVar3 = (uStack_38 >> ((uint)__s & 3) * 8 | uStack_38 << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00
  ;
  uVar2 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
  uStack_38._1_3_ = (uint3)(uVar3 >> uVar2) | (uint3)(uVar3 << 0x20 - uVar2);
  MKDS_SLICE_1(uStack_38,0) = (undefined1)uVar11;
  if (param_5 < 0x66) {
    if (param_5 < 0x65) {
      if ((0x47 < param_5) || (param_5 < 0x45)) goto LAB_0213dc74;
      if (param_5 != 0x45) {
        if (param_5 != 0x46) {
          if (param_5 != 0x47) goto LAB_0213dc74;
          goto LAB_0213d64c;
        }
        goto LAB_0213d98c;
      }
    }
LAB_0213d6cc:
    if ((int)(param_7 + 1) < (int)(uStack_258 & 0xff)) {
      func_0213dcd4(&uStack_25c);
    }
    iVar6 = (int)MKDS_SLICE_2(uStack_25c,2);
    uVar11 = 0x2b;
    iVar13 = 0;
    if (iVar6 < 0) {
      iVar6 = -iVar6;
      uVar11 = 0x2d;
    }
    for (; (iVar6 != 0 || (iVar13 < 2)); iVar13 = iVar13 + 1) {
      __s = (uint *)((int)__s + -1);
      uVar3 = (iVar6 - iRam0213dcd0 *
                       ((int)((longlong)iRam0213dccc * (longlong)iVar6 >> 0x22) - (iVar6 >> 0x1f)))
              + 0x30U & 0xff |
              (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
              *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00;
      uVar2 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
      *__s = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
      iVar6 = (int)((longlong)iRam0213dccc * (longlong)iVar6 >> 0x22) - (iVar6 >> 0x1f);
    }
    puVar7 = (uint *)((int)__s + -1);
    uVar11 = uVar11 | (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                      *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) &
                      0xffffff00;
    uVar2 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar11 >> uVar2 | uVar11 << 0x20 - uVar2;
    puVar7 = (uint *)((int)__s + -2);
    uVar2 = param_5 & 0xff |
            (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
            *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00;
    uVar11 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
    *puVar7 = uVar2 >> uVar11 | uVar2 << 0x20 - uVar11;
    if (iRam0213dcb0 < (int)(auStack_236 + (param_7 - (int)puVar7))) {
      return (wchar_t *)0x0;
    }
    if ((int)(uStack_258 & 0xff) < (int)(param_7 + 1)) {
      for (iVar6 = (param_7 - (uStack_258 & 0xff)) + 1; iVar6 != 0; iVar6 = iVar6 + -1) {
        puVar7 = (uint *)((int)puVar7 + -1);
        uVar2 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
                *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00
                | 0x30;
        uVar11 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
        *puVar7 = uVar2 >> uVar11 | uVar2 << 0x20 - uVar11;
      }
    }
    uVar11 = uStack_258 & 0xff;
    uVar2 = (int)&uStack_258 + uVar11 + 1;
    while (uVar11 = uVar11 - 1, uVar11 != 0) {
      uVar2 = uVar2 - 1;
      puVar7 = (uint *)((int)puVar7 + -1);
      uVar4 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
              *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00;
      uVar3 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
      *puVar7 = uVar4 >> uVar3 | uVar4 << 0x20 - uVar3;
    }
    if ((param_7 != 0) || (uVar8 != 0)) {
      puVar7 = (uint *)((int)puVar7 + -1);
      uVar11 = (*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 |
               *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20) & 0xffffff00
               | 0x2e;
      uVar8 = (4 - ((uint)puVar7 & 3)) * 8 & 0x1f;
      *puVar7 = uVar11 >> uVar8 | uVar11 << 0x20 - uVar8;
    }
    uVar8 = (int)&uStack_258 + 1U & 3;
    __s = (uint *)((int)puVar7 + -1);
    uVar11 = (uStack_258 >> uVar8 * 8 | uStack_258 << uVar8 * -8 + 0x20) & 0xff |
             (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
             *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00;
    uVar8 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
    *__s = uVar11 >> uVar8 | uVar11 << 0x20 - uVar8;
    if ((uStack_25c & 0xff) == 0) {
      if (uVar10 == 1) {
        __s = (uint *)((int)puVar7 + -2);
        uVar8 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
                *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 |
                0x2b;
        uVar10 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
        *__s = uVar8 >> uVar10 | uVar8 << 0x20 - uVar10;
      }
      else if (uVar10 == 2) {
        __s = (uint *)((int)puVar7 + -2);
        uVar8 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
                *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 |
                0x20;
        uVar10 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
        *__s = uVar8 >> uVar10 | uVar8 << 0x20 - uVar10;
      }
    }
    else {
      __s = (uint *)((int)puVar7 + -2);
      uVar8 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
              *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 | 0x2d;
      uVar10 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
      *__s = uVar8 >> uVar10 | uVar8 << 0x20 - uVar10;
    }
  }
  else {
    if (param_5 < 0x67) {
      if (param_5 != 0x66) goto LAB_0213dc74;
    }
    else {
      if (param_5 != 0x67) goto LAB_0213dc74;
LAB_0213d64c:
      if ((int)param_7 < (int)(uStack_258 & 0xff)) {
        func_0213dcd4((int)(uintptr_t)(&uStack_25c),param_7);
      }
      iVar6 = (int)MKDS_SLICE_2(uStack_25c,2);
      if ((iVar6 < -4) || ((int)param_7 <= iVar6)) {
        if (uVar8 == 0) {
          param_7 = uStack_258 & 0xff;
        }
        param_7 = param_7 - 1;
        if (param_5 == 0x67) {
          param_5 = 0x65;
        }
        else {
          param_5 = 0x45;
        }
        goto LAB_0213d6cc;
      }
      if (uVar8 == 0) {
        param_7 = (uStack_258 & 0xff) - (iVar6 + 1);
        if ((int)param_7 < 0) {
          param_7 = 0;
        }
      }
      else {
        param_7 = param_7 - (iVar6 + 1);
      }
    }
LAB_0213d98c:
    iVar6 = (int)MKDS_SLICE_2(uStack_25c,2);
    uVar11 = uStack_258 & 0xff;
    iVar13 = (uVar11 - iVar6) + -1;
    if (iVar13 < 0) {
      iVar13 = 0;
    }
    if ((int)param_7 < iVar13) {
      func_0213dcd4((int)(uintptr_t)(&uStack_25c),uVar11 - (iVar13 - param_7));
      iVar6 = (int)MKDS_SLICE_2(uStack_25c,2);
      uVar11 = uStack_258 & 0xff;
      iVar13 = (uVar11 - iVar6) + -1;
      if (iVar13 < 0) {
        iVar13 = 0;
      }
    }
    iVar6 = iVar6 + 1;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (iRam0213dcb0 < iVar6 + iVar13) {
      return (wchar_t *)0x0;
    }
    uVar11 = (int)&uStack_258 + uVar11 + 1;
    iVar12 = 0;
    if (0 < (int)(param_7 - iVar13)) {
      do {
        __s = (uint *)((int)__s + -1);
        iVar12 = iVar12 + 1;
        uVar3 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
                *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 |
                0x30;
        uVar2 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
        *__s = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
      } while (iVar12 < (int)(param_7 - iVar13));
    }
    for (iVar12 = 0; (iVar12 < iVar13 && (iVar12 < (int)(uStack_258 & 0xff))); iVar12 = iVar12 + 1)
    {
      uVar11 = uVar11 - 1;
      __s = (uint *)((int)__s + -1);
      uVar3 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
              *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
              *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00;
      uVar2 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
      *__s = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    }
    for (; iVar12 < iVar13; iVar12 = iVar12 + 1) {
      __s = (uint *)((int)__s + -1);
      uVar3 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
              *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 | 0x30;
      uVar2 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
      *__s = uVar3 >> uVar2 | uVar3 << 0x20 - uVar2;
    }
    if ((param_7 != 0) || (uVar8 != 0)) {
      __s = (uint *)((int)__s + -1);
      uVar2 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
              *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 | 0x2e;
      uVar8 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
      *__s = uVar2 >> uVar8 | uVar2 << 0x20 - uVar8;
    }
    if (iVar6 == 0) {
      __s = (uint *)((int)__s + -1);
      uVar11 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
               *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 | 0x30
      ;
      uVar8 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
      *__s = uVar11 >> uVar8 | uVar11 << 0x20 - uVar8;
    }
    else {
      iVar13 = 0;
      if (0 < (int)(iVar6 - (uStack_258 & 0xff))) {
        do {
          __s = (uint *)((int)__s + -1);
          uVar2 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
                  *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 |
                  0x30;
          uVar8 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
          *__s = uVar2 >> uVar8 | uVar2 << 0x20 - uVar8;
          iVar13 = iVar13 + 1;
        } while (iVar13 < (int)(iVar6 - (uStack_258 & 0xff)));
      }
      for (; iVar13 < iVar6; iVar13 = iVar13 + 1) {
        uVar11 = uVar11 - 1;
        __s = (uint *)((int)__s + -1);
        uVar2 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) & 0xff |
                (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
                *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00;
        uVar8 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
        *__s = uVar2 >> uVar8 | uVar2 << 0x20 - uVar8;
      }
    }
    if ((uStack_25c & 0xff) == 0) {
      if (uVar10 == 1) {
        __s = (uint *)((int)__s + -1);
        uVar8 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
                *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 |
                0x2b;
        uVar10 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
        *__s = uVar8 >> uVar10 | uVar8 << 0x20 - uVar10;
      }
      else if (uVar10 == 2) {
        __s = (uint *)((int)__s + -1);
        uVar8 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
                *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 |
                0x20;
        uVar10 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
        *__s = uVar8 >> uVar10 | uVar8 << 0x20 - uVar10;
      }
    }
    else {
      __s = (uint *)((int)__s + -1);
      uVar8 = (*(uint *)((uint)__s & 0xfffffffc) >> ((uint)__s & 3) * 8 |
              *(uint *)((uint)__s & 0xfffffffc) << ((uint)__s & 3) * -8 + 0x20) & 0xffffff00 | 0x2d;
      uVar10 = (4 - ((uint)__s & 3)) * 8 & 0x1f;
      *__s = uVar8 >> uVar10 | uVar8 << 0x20 - uVar10;
    }
  }
LAB_0213dc74:
  sVar5 = strlen((char *)__s);
  pwVar9 = (wchar_t *)(param_3 + sVar5 * -2 + -2);
  sVar5 = strlen((char *)__s);
  func_02134bd4((undefined2 *)(void *)(pwVar9),(char *)(void *)(__s),sVar5);
  return pwVar9;
}

