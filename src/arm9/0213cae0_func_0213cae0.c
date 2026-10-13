/* Decompiled C draft; module arm9; ROM address 0213cae0. No matching claim. */
#include "types.h"
#include "deps/0213cae0_func_0213cae0.h"

uint func_0213cae0(code *param_1,uint param_2,short *param_3,undefined4 param_4)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  wchar_t *pwVar6;
  size_t sVar7;
  int iVar8;
  undefined4 uVar9;
  wchar_t *pwVar10;
  void *pvVar11;
  wchar_t wVar12;
  uint uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  wchar_t *unaff_r5;
  undefined4 *puVar16;
  uint uVar17;
  char *__s;
  undefined4 auStack_3c [2];
  undefined4 uStack_14;
  code *pcStack_10;
  uint uStack_c;
  short *psStack_8;
  undefined4 uStack_4;
  
  iVar3 = -DAT_0213d388;
  *(undefined2 *)(&stack0x00000002 + iVar3) = 0x20;
  pcStack_10 = param_1;
  uStack_c = param_2;
  psStack_8 = param_3;
  uStack_4 = param_4;
  *(short **)(&stack0xffffffd8 + iVar3) = param_3;
  sVar1 = *param_3;
  *(undefined4 *)(&stack0xffffffdc + iVar3) = 0;
  if (sVar1 == 0) {
LAB_0213d370:
    uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
    return uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
  }
  *(undefined4 *)((int)&psStack_8 + iVar3) = 0;
  *(undefined4 *)((int)&pcStack_10 + iVar3) = 0x25;
  uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
  uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
  *(uint *)((int)&uStack_c + iVar3) = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
  *(undefined4 *)((int)&uStack_4 + iVar3) = 0x30;
LAB_0213cb3c:
  uVar17 = (uint)(&stack0xffffffd8 + iVar3) & 3;
  uVar5 = *(uint *)((uint)(&stack0xffffffd8 + iVar3) & 0xfffffffc);
  uVar4 = (int)&pcStack_10 + iVar3 & 3;
  uVar13 = *(uint *)((int)&pcStack_10 + iVar3 & 0xfffffffc);
  pwVar6 = wcschr((wchar_t *)(uVar5 >> uVar17 * 8 | uVar5 << uVar17 * -8 + 0x20),
                  uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20);
  *(wchar_t **)((int)&uStack_14 + iVar3) = pwVar6;
  if (pwVar6 == (wchar_t *)0x0) {
    uVar17 = (uint)(&stack0xffffffd8 + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0xffffffd8 + iVar3) & 0xfffffffc);
    sVar7 = wcslen((wchar_t *)(uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20));
    uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
    *(uint *)(&stack0xffffffdc + iVar3) =
         (uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) + sVar7;
    if ((sVar7 != 0) &&
       (uVar17 = (uint)(&stack0xffffffd8 + iVar3) & 3,
       uVar4 = *(uint *)((uint)(&stack0xffffffd8 + iVar3) & 0xfffffffc),
       iVar8 = (*param_1)(param_2,uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20), iVar8 == 0)) {
      return 0xffffffff;
    }
    goto LAB_0213d370;
  }
  uVar17 = (uint)(&stack0xffffffd8 + iVar3) & 3;
  uVar4 = *(uint *)((uint)(&stack0xffffffd8 + iVar3) & 0xfffffffc);
  iVar8 = (int)((int)pwVar6 - (uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20)) / 2;
  uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
  uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
  *(uint *)(&stack0xffffffdc + iVar3) = (uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) + iVar8;
  if ((iVar8 != 0) &&
     (uVar17 = (uint)(&stack0xffffffd8 + iVar3) & 3,
     uVar4 = *(uint *)((uint)(&stack0xffffffd8 + iVar3) & 0xfffffffc),
     iVar8 = (*param_1)(param_2,uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20), iVar8 == 0)) {
    return 0xffffffff;
  }
  uVar17 = (int)&uStack_14 + iVar3 & 3;
  uVar4 = *(uint *)((int)&uStack_14 + iVar3 & 0xfffffffc);
  uVar9 = func_0213e468(uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20,&stack0x00000448 + iVar3,
                        &stack0x00000008 + iVar3);
  uVar2 = *(ushort *)(&stack0x0000000e + iVar3);
  *(undefined4 *)(&stack0xffffffd8 + iVar3) = uVar9;
  if (uVar2 < 100) {
    uVar17 = 1;
    if (uVar2 < 99) {
      if (0x47 < uVar2) {
        if (uVar2 != 0x58) goto LAB_0213d1ac;
        goto LAB_0213cdd8;
      }
      if (0x44 < uVar2) {
        if (((uVar2 != 0x45) && (uVar2 != 0x46)) && (uVar2 != 0x47)) goto LAB_0213d1ac;
        goto LAB_0213cedc;
      }
      if (uVar2 != 0x25) goto LAB_0213d1ac;
      uVar4 = (int)&pcStack_10 + iVar3 & 3;
      uVar5 = *(uint *)((int)&pcStack_10 + iVar3 & 0xfffffffc);
      *(ushort *)(&stack0x00000018 + iVar3) =
           (ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20);
      unaff_r5 = (wchar_t *)(&stack0x00000018 + iVar3);
    }
    else {
      unaff_r5 = (wchar_t *)(&stack0x00000018 + iVar3);
      uVar4 = (uint)(&stack0x0000000c + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0x0000000c + iVar3) & 0xfffffffc);
      if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xff) == 6) {
        uVar4 = (uint)(&stack0x00000448 + iVar3) & 3;
        uVar5 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
        uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
        *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 4;
        *(ushort *)unaff_r5 =
             (ushort)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8) |
             (ushort)(*(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20);
      }
      else {
        uVar17 = (uint)(&stack0x00000448 + iVar3) & 3;
        uVar4 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
        uVar4 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
        *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 4;
        uVar17 = (int)&stack0x00000000 + iVar3 & 3;
        uVar5 = *(uint *)((int)&stack0x00000000 + iVar3 & 0xfffffffc);
        uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xff |
                (uVar5 >> uVar17 * 8 | uVar5 << uVar17 * -8 + 0x20) & 0xffffff00;
        uVar17 = (4 - ((int)&stack0x00000000 + iVar3 & 3U)) * 8 & 0x1f;
        *(uint *)(&stack0x00000000 + iVar3) = uVar4 >> uVar17 | uVar4 << 0x20 - uVar17;
        uVar17 = func_02134d08(unaff_r5,&stack0x00000000 + iVar3,1);
      }
    }
    goto LAB_0213d208;
  }
  if (0x78 < uVar2) goto LAB_0213d1ac;
  switch(uVar2) {
  case 0x65:
    goto LAB_0213cedc;
  case 0x66:
    goto LAB_0213cedc;
  case 0x67:
LAB_0213cedc:
    uVar17 = (uint)(&stack0x0000000c + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0x0000000c + iVar3) & 0xfffffffc);
    if (((uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff) == 5) {
      uVar17 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar4 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 8;
      uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      uVar17 = uVar4 + 4 & 3;
      uVar4 = *(uint *)(uVar4 + 4 & 0xfffffffc);
      uVar17 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
    }
    else {
      uVar17 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar4 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 8;
      uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      uVar17 = uVar4 + 4 & 3;
      uVar4 = *(uint *)(uVar4 + 4 & 0xfffffffc);
      uVar17 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
    }
    puVar16 = (undefined4 *)((int)auStack_3c + iVar3 + 4);
    uVar9 = *(undefined4 *)(&stack0x0000000c + iVar3);
    uVar14 = *(undefined4 *)(&stack0x00000010 + iVar3);
    uVar15 = *(undefined4 *)(&stack0x00000014 + iVar3);
    *puVar16 = *(undefined4 *)(&stack0x00000008 + iVar3);
    *(undefined4 *)(&stack0xffffffcc + iVar3) = uVar9;
    *(undefined4 *)(&stack0xffffffd0 + iVar3) = uVar14;
    *(undefined4 *)(&stack0xffffffd4 + iVar3) = uVar15;
    unaff_r5 = (wchar_t *)func_0213d398(uVar5,uVar17,&stack0x00000418 + iVar3,*puVar16);
    if (unaff_r5 == (wchar_t *)0x0) break;
    uVar17 = (int)(&stack0x00000416 + (iVar3 - (int)unaff_r5)) / 2;
LAB_0213d208:
    uVar4 = (uint)(&stack0x00000008 + iVar3) & 3;
    uVar5 = *(uint *)((uint)(&stack0x00000008 + iVar3) & 0xfffffffc);
    uVar5 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xff;
    uVar4 = uVar17;
    if (uVar5 != 0) {
      uVar13 = 0x20;
      if (uVar5 == 2) {
        uVar5 = (int)&uStack_4 + iVar3 & 3;
        uVar13 = *(uint *)((int)&uStack_4 + iVar3 & 0xfffffffc);
        uVar13 = uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20;
      }
      *(short *)(&stack0x00000002 + iVar3) = (short)uVar13;
      uVar2 = (ushort)*unaff_r5;
      if ((((uVar2 == 0x2b) || (uVar2 == 0x2d)) || (uVar2 == 0x20)) && (uVar13 == 0x30)) {
        iVar8 = (*param_1)(param_2,unaff_r5,1);
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        unaff_r5 = (wchar_t *)((int)unaff_r5 + 2);
        uVar4 = uVar17 - 1;
      }
      uVar5 = (uint)(&stack0x00000010 + iVar3) & 3;
      uVar13 = *(uint *)((uint)(&stack0x00000010 + iVar3) & 0xfffffffc);
      if ((int)uVar17 < (int)(uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20)) {
        do {
          iVar8 = (*param_1)(param_2,&stack0x00000002 + iVar3,1);
          if (iVar8 == 0) {
            return 0xffffffff;
          }
          uVar17 = uVar17 + 1;
          uVar5 = (uint)(&stack0x00000010 + iVar3) & 3;
          uVar13 = *(uint *)((uint)(&stack0x00000010 + iVar3) & 0xfffffffc);
        } while ((int)uVar17 < (int)(uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20));
      }
    }
    if ((uVar4 != 0) && (iVar8 = (*param_1)(param_2,unaff_r5,uVar4), iVar8 == 0)) {
      return 0xffffffff;
    }
    uVar4 = (uint)(&stack0x00000008 + iVar3) & 3;
    uVar5 = *(uint *)((uint)(&stack0x00000008 + iVar3) & 0xfffffffc);
    if ((((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xff) == 0) &&
       (uVar4 = (uint)(&stack0x00000010 + iVar3) & 3,
       uVar5 = *(uint *)((uint)(&stack0x00000010 + iVar3) & 0xfffffffc),
       (int)uVar17 < (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))) {
      do {
        *(undefined2 *)(&stack0x00000004 + iVar3) = 0x20;
        iVar8 = (*param_1)(param_2,&stack0x00000004 + iVar3,1);
        if (iVar8 == 0) {
          return 0xffffffff;
        }
        uVar17 = uVar17 + 1;
        uVar4 = (uint)(&stack0x00000010 + iVar3) & 3;
        uVar5 = *(uint *)((uint)(&stack0x00000010 + iVar3) & 0xfffffffc);
      } while ((int)uVar17 < (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20));
    }
    uVar4 = (uint)(&stack0xffffffdc + iVar3) & 3;
    uVar5 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
    *(uint *)(&stack0xffffffdc + iVar3) = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + uVar17
    ;
switchD_0213d0bc_default:
    uVar17 = (uint)(&stack0xffffffd8 + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0xffffffd8 + iVar3) & 0xfffffffc);
    if (*(short *)(uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) == 0) goto LAB_0213d370;
    goto LAB_0213cb3c;
  case 0x68:
    break;
  case 0x69:
    goto LAB_0213ccd4;
  case 0x6a:
    break;
  case 0x6b:
    break;
  case 0x6c:
    break;
  case 0x6d:
    break;
  case 0x6e:
    uVar17 = (uint)(&stack0x00000448 + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
    uVar17 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
    *(uint *)(&stack0x00000448 + iVar3) = uVar17 + 4;
    unaff_r5 = (wchar_t *)
               (*(uint *)(uVar17 & 0xfffffffc) >> (uVar17 & 3) * 8 |
               *(uint *)(uVar17 & 0xfffffffc) << (uVar17 & 3) * -8 + 0x20);
    uVar17 = (uint)(&stack0x0000000c + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0x0000000c + iVar3) & 0xfffffffc);
    switch((uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff) {
    case 0:
      uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
      *unaff_r5 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
      break;
    case 1:
      break;
    case 2:
      uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
      *(ushort *)unaff_r5 = (ushort)(uVar4 >> uVar17 * 8) | (ushort)(uVar4 << uVar17 * -8 + 0x20);
      break;
    case 3:
      uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
      *unaff_r5 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
      break;
    case 4:
      uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
      wVar12 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
      *unaff_r5 = wVar12;
      unaff_r5[1] = wVar12 >> 0x1f;
    }
    goto switchD_0213d0bc_default;
  case 0x6f:
    goto LAB_0213cdd8;
  case 0x70:
    break;
  case 0x71:
    break;
  case 0x72:
    break;
  case 0x73:
    uVar17 = (uint)(&stack0x0000000c + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0x0000000c + iVar3) & 0xfffffffc);
    if (((uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff) == 6) {
      uVar17 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar17 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar17 + 4;
      pwVar6 = (wchar_t *)
               (*(uint *)(uVar17 & 0xfffffffc) >> (uVar17 & 3) * 8 |
               *(uint *)(uVar17 & 0xfffffffc) << (uVar17 & 3) * -8 + 0x20);
      if (pwVar6 == (wchar_t *)0x0) {
        pwVar6 = DAT_0213d390;
      }
      uVar17 = (uint)(&stack0x0000000b + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0x0000000b + iVar3) & 0xfffffffc);
      if (((uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff) == 0) {
        uVar17 = (uint)(&stack0x0000000a + iVar3) & 3;
        uVar4 = *(uint *)((uint)(&stack0x0000000a + iVar3) & 0xfffffffc);
        unaff_r5 = pwVar6;
        if (((uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff) == 0) {
          uVar17 = wcslen(pwVar6);
        }
        else {
          uVar17 = (uint)(&stack0x00000014 + iVar3) & 3;
          uVar4 = *(uint *)((uint)(&stack0x00000014 + iVar3) & 0xfffffffc);
          uVar17 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
          uVar4 = (int)&uStack_c + iVar3 & 3;
          uVar5 = *(uint *)((int)&uStack_c + iVar3 & 0xfffffffc);
          pwVar10 = wmemchr(pwVar6,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,uVar17);
          if (pwVar10 != (wchar_t *)0x0) {
            uVar17 = ((int)pwVar10 - (int)pwVar6) / 2;
          }
        }
      }
      else {
        unaff_r5 = (wchar_t *)((int)pwVar6 + 2);
        uVar17 = (ushort)*pwVar6 & 0xff;
        uVar4 = (uint)(&stack0x0000000a + iVar3) & 3;
        uVar5 = *(uint *)((uint)(&stack0x0000000a + iVar3) & 0xfffffffc);
        if ((((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xff) != 0) &&
           (uVar4 = (uint)(&stack0x00000014 + iVar3) & 3,
           uVar5 = *(uint *)((uint)(&stack0x00000014 + iVar3) & 0xfffffffc),
           uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20, (int)uVar4 < (int)uVar17)) {
          uVar17 = uVar4;
        }
      }
    }
    else {
      uVar17 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar17 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar17 + 4;
      __s = (char *)(*(uint *)(uVar17 & 0xfffffffc) >> (uVar17 & 3) * 8 |
                    *(uint *)(uVar17 & 0xfffffffc) << (uVar17 & 3) * -8 + 0x20);
      if (__s == (char *)0x0) {
        __s = DAT_0213d394;
      }
      uVar17 = (uint)(&stack0x0000000b + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0x0000000b + iVar3) & 0xfffffffc);
      if (((uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff) == 0) {
        uVar17 = (uint)(&stack0x0000000a + iVar3) & 3;
        uVar4 = *(uint *)((uint)(&stack0x0000000a + iVar3) & 0xfffffffc);
        if (((uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff) == 0) {
          uVar17 = strlen(__s);
        }
        else {
          uVar17 = (uint)(&stack0x00000014 + iVar3) & 3;
          uVar4 = *(uint *)((uint)(&stack0x00000014 + iVar3) & 0xfffffffc);
          uVar17 = uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
          uVar4 = (int)&psStack_8 + iVar3 & 3;
          uVar5 = *(uint *)((int)&psStack_8 + iVar3 & 0xfffffffc);
          pvVar11 = memchr(__s,uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20,uVar17);
          if (pvVar11 != (void *)0x0) {
            uVar17 = (int)pvVar11 - (int)__s;
          }
        }
      }
      else {
        uVar17 = (ushort)*unaff_r5 & 0xff;
        uVar4 = (uint)(&stack0x0000000a + iVar3) & 3;
        uVar5 = *(uint *)((uint)(&stack0x0000000a + iVar3) & 0xfffffffc);
        if ((((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xff) != 0) &&
           (uVar4 = (uint)(&stack0x00000014 + iVar3) & 3,
           uVar5 = *(uint *)((uint)(&stack0x00000014 + iVar3) & 0xfffffffc),
           uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20, (int)uVar4 < (int)uVar17)) {
          uVar17 = uVar4;
        }
      }
      uVar17 = func_02134bd4(&stack0x00000018 + iVar3,__s,uVar17);
      if ((int)uVar17 < 0) break;
      unaff_r5 = (wchar_t *)(&stack0x00000018 + iVar3);
    }
    goto LAB_0213d208;
  case 0x74:
    break;
  case 0x75:
    goto LAB_0213cdd8;
  case 0x76:
    break;
  case 0x77:
    break;
  case 0x78:
LAB_0213cdd8:
    uVar17 = (uint)(&stack0x0000000c + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0x0000000c + iVar3) & 0xfffffffc);
    uVar17 = (uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff;
    if (uVar17 == 3) {
      uVar4 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 4;
      *(uint *)(&stack0xffffffe0 + iVar3) =
           *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    else if (uVar17 == 4) {
      uVar4 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar5 + 8;
      *(uint *)(&stack0xffffffe4 + iVar3) =
           *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
           *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      uVar4 = uVar5 + 4 & 3;
      uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc);
      *(uint *)(&stack0xffffffe8 + iVar3) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    }
    else {
      uVar4 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 4;
      *(uint *)(&stack0xffffffe0 + iVar3) =
           *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    if (uVar17 == 2) {
      uVar4 = (uint)(&stack0xffffffe0 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0xffffffe0 + iVar3) & 0xfffffffc);
      *(uint *)(&stack0xffffffe0 + iVar3) =
           (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & 0xffff;
    }
    if (uVar17 == 4) {
      puVar16 = (undefined4 *)((int)auStack_3c + iVar3 + 4);
      uVar9 = *(undefined4 *)(&stack0x0000000c + iVar3);
      uVar14 = *(undefined4 *)(&stack0x00000010 + iVar3);
      uVar15 = *(undefined4 *)(&stack0x00000014 + iVar3);
      *puVar16 = *(undefined4 *)(&stack0x00000008 + iVar3);
      *(undefined4 *)(&stack0xffffffcc + iVar3) = uVar9;
      *(undefined4 *)(&stack0xffffffd0 + iVar3) = uVar14;
      *(undefined4 *)(&stack0xffffffd4 + iVar3) = uVar15;
      uVar17 = (uint)(&stack0xffffffe4 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0xffffffe4 + iVar3) & 0xfffffffc);
      uVar4 = (uint)(&stack0xffffffe8 + iVar3) & 3;
      uVar13 = *(uint *)((uint)(&stack0xffffffe8 + iVar3) & 0xfffffffc);
      unaff_r5 = (wchar_t *)
                 func_0213deec(uVar5 >> uVar17 * 8 | uVar5 << uVar17 * -8 + 0x20,
                               uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20,
                               &stack0x00000418 + iVar3,*puVar16);
    }
    else {
      uVar9 = *(undefined4 *)(&stack0x00000010 + iVar3);
      uVar14 = *(undefined4 *)(&stack0x00000014 + iVar3);
      *(undefined4 *)((int)auStack_3c + iVar3) = *(undefined4 *)(&stack0x00000008 + iVar3);
      *(undefined4 *)((int)auStack_3c + iVar3 + 4) = *(undefined4 *)(&stack0x0000000c + iVar3);
      *(undefined4 *)(&stack0xffffffcc + iVar3) = uVar9;
      *(undefined4 *)(&stack0xffffffd0 + iVar3) = uVar14;
      uVar17 = (uint)(&stack0xffffffe0 + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0xffffffe0 + iVar3) & 0xfffffffc);
      unaff_r5 = (wchar_t *)
                 func_0213e1f0(uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20,
                               &stack0x00000418 + iVar3,*(undefined4 *)((int)auStack_3c + iVar3),
                               *(undefined4 *)((int)auStack_3c + iVar3 + 4));
    }
    if (unaff_r5 == (wchar_t *)0x0) break;
    uVar17 = (int)(&stack0x00000416 + (iVar3 - (int)unaff_r5)) / 2;
    goto LAB_0213d208;
  default:
    if (uVar2 != 100) break;
LAB_0213ccd4:
    uVar17 = (uint)(&stack0x0000000c + iVar3) & 3;
    uVar4 = *(uint *)((uint)(&stack0x0000000c + iVar3) & 0xfffffffc);
    uVar17 = (uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) & 0xff;
    if (uVar17 == 3) {
      uVar4 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 4;
      *(uint *)(&stack0xffffffe0 + iVar3) =
           *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    else if (uVar17 == 4) {
      uVar4 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar5 + 8;
      *(uint *)(&stack0xffffffe4 + iVar3) =
           *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
           *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      uVar4 = uVar5 + 4 & 3;
      uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc);
      *(uint *)(&stack0xffffffe8 + iVar3) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    }
    else {
      uVar4 = (uint)(&stack0x00000448 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0x00000448 + iVar3) & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(&stack0x00000448 + iVar3) = uVar4 + 4;
      *(uint *)(&stack0xffffffe0 + iVar3) =
           *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    if (uVar17 == 2) {
      uVar4 = (uint)(&stack0xffffffe0 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0xffffffe0 + iVar3) & 0xfffffffc);
      *(int *)(&stack0xffffffe0 + iVar3) =
           (int)(short)((ushort)(uVar5 >> uVar4 * 8) | (ushort)(uVar5 << uVar4 * -8 + 0x20));
    }
    if (uVar17 == 4) {
      puVar16 = (undefined4 *)((int)auStack_3c + iVar3 + 4);
      uVar9 = *(undefined4 *)(&stack0x0000000c + iVar3);
      uVar14 = *(undefined4 *)(&stack0x00000010 + iVar3);
      uVar15 = *(undefined4 *)(&stack0x00000014 + iVar3);
      *puVar16 = *(undefined4 *)(&stack0x00000008 + iVar3);
      *(undefined4 *)(&stack0xffffffcc + iVar3) = uVar9;
      *(undefined4 *)(&stack0xffffffd0 + iVar3) = uVar14;
      *(undefined4 *)(&stack0xffffffd4 + iVar3) = uVar15;
      uVar17 = (uint)(&stack0xffffffe4 + iVar3) & 3;
      uVar5 = *(uint *)((uint)(&stack0xffffffe4 + iVar3) & 0xfffffffc);
      uVar4 = (uint)(&stack0xffffffe8 + iVar3) & 3;
      uVar13 = *(uint *)((uint)(&stack0xffffffe8 + iVar3) & 0xfffffffc);
      unaff_r5 = (wchar_t *)
                 func_0213deec(uVar5 >> uVar17 * 8 | uVar5 << uVar17 * -8 + 0x20,
                               uVar13 >> uVar4 * 8 | uVar13 << uVar4 * -8 + 0x20,
                               &stack0x00000418 + iVar3,*puVar16);
    }
    else {
      uVar9 = *(undefined4 *)(&stack0x00000010 + iVar3);
      uVar14 = *(undefined4 *)(&stack0x00000014 + iVar3);
      *(undefined4 *)((int)auStack_3c + iVar3) = *(undefined4 *)(&stack0x00000008 + iVar3);
      *(undefined4 *)((int)auStack_3c + iVar3 + 4) = *(undefined4 *)(&stack0x0000000c + iVar3);
      *(undefined4 *)(&stack0xffffffcc + iVar3) = uVar9;
      *(undefined4 *)(&stack0xffffffd0 + iVar3) = uVar14;
      uVar17 = (uint)(&stack0xffffffe0 + iVar3) & 3;
      uVar4 = *(uint *)((uint)(&stack0xffffffe0 + iVar3) & 0xfffffffc);
      unaff_r5 = (wchar_t *)
                 func_0213e1f0(uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20,
                               &stack0x00000418 + iVar3,*(undefined4 *)((int)auStack_3c + iVar3),
                               *(undefined4 *)((int)auStack_3c + iVar3 + 4));
    }
    if (unaff_r5 == (wchar_t *)0x0) break;
    uVar17 = (int)(&stack0x00000416 + (iVar3 - (int)unaff_r5)) / 2;
    goto LAB_0213d208;
  }
LAB_0213d1ac:
  uVar17 = (int)&uStack_14 + iVar3 & 3;
  uVar4 = *(uint *)((int)&uStack_14 + iVar3 & 0xfffffffc);
  sVar7 = wcslen((wchar_t *)(uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20));
  uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
  uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
  *(uint *)(&stack0xffffffdc + iVar3) = (uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20) + sVar7;
  if ((sVar7 != 0) &&
     (uVar17 = (int)&uStack_14 + iVar3 & 3, uVar4 = *(uint *)((int)&uStack_14 + iVar3 & 0xfffffffc),
     iVar8 = (*param_1)(param_2,uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20), iVar8 == 0)) {
    return 0xffffffff;
  }
  uVar17 = (uint)(&stack0xffffffdc + iVar3) & 3;
  uVar4 = *(uint *)((uint)(&stack0xffffffdc + iVar3) & 0xfffffffc);
  return uVar4 >> uVar17 * 8 | uVar4 << uVar17 * -8 + 0x20;
}

