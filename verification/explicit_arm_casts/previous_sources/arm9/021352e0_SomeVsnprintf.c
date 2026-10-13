/* Decompiled C draft; module arm9; ROM address 021352e0. No matching claim. */
#include "types.h"
#include "deps/021352e0_SomeVsnprintf.h"

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int SomeVsnprintf(code *param_1,undefined4 param_2,char *param_3,uint param_4)

{
  uint *puVar1;
  char *__s;
  size_t sVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *__s_00;
  undefined1 *puVar9;
  uint uVar10;
  uint unaff_r10;
  char *local_274;
  int local_270;
  uint uStack_26c;
  uint uStack_268;
  undefined1 *puStack_260;
  uint local_24c;
  undefined4 local_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  int iStack_23c;
  undefined1 *puStack_238;
  uint auStack_234 [127];
  undefined1 uStack_35;
  uint uStack_4;
  
  local_248 = local_248 & 0xffffff00 | 0x20;
  local_270 = 0;
  if (((*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
       *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) & 0xff) == 0) {
    return 0;
  }
  uVar10 = (int)&local_248 + 1;
  local_24c = 0x30;
  local_274 = param_3;
  uStack_4 = param_4;
LAB_02135378:
  __s = (char *)func_02139ffc(local_274,0x25);
  if (__s == (char *)0x0) {
    sVar2 = strlen(local_274);
    if (sVar2 == 0) {
      return local_270 + sVar2;
    }
    iVar3 = (*param_1)(param_2,local_274);
    if (iVar3 != 0) {
      return local_270 + sVar2;
    }
    return -1;
  }
  local_270 = local_270 + ((int)__s - (int)local_274);
  if (((int)__s - (int)local_274 != 0) && (iVar3 = (*param_1)(param_2,local_274), iVar3 == 0)) {
    return -1;
  }
  local_274 = (char *)func_0213770c(__s,&uStack_4,&uStack_244);
  uVar7 = (int)&uStack_240 + 1U & 3;
  uVar7 = (uStack_240 >> uVar7 * 8 | uStack_240 << uVar7 * -8 + 0x20) & 0xff;
  if (uVar7 < 0x62) {
    if (0x60 < uVar7) {
LAB_021357f8:
      if ((uStack_240 & 0xff) == 8) {
        uVar6 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
        uVar7 = uStack_4 + 4 & 3;
        uVar8 = *(uint *)(uStack_4 + 4 & 0xfffffffc);
        uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
      else {
        uVar6 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
        uVar7 = uStack_4 + 4 & 3;
        uVar8 = *(uint *)(uStack_4 + 4 & 0xfffffffc);
        uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
      }
      uStack_4 = uStack_4 + 8;
      __s_00 = (uint *)func_02136850(uVar6,uVar7,&stack0xffffffcc,uStack_244);
      if (__s_00 == (uint *)0x0) goto LAB_02135a58;
      puStack_260 = &uStack_35 + -(int)__s_00;
      goto LAB_02135aac;
    }
    if (0x47 < uVar7) {
      if (uVar7 != 0x58) goto LAB_02135a58;
      goto LAB_02135644;
    }
    switch(uVar7) {
    case 0x41:
      goto LAB_021357f8;
    case 0x42:
      goto LAB_02135a58;
    case 0x43:
      goto LAB_02135a58;
    case 0x44:
      goto LAB_02135a58;
    case 0x45:
      break;
    case 0x46:
      break;
    case 0x47:
      break;
    default:
      if (uVar7 != 0x25) goto LAB_02135a58;
      __s_00 = auStack_234;
      puStack_260 = (undefined1 *)0x1;
      auStack_234[0] = auStack_234[0] & 0xffffff00 | 0x25;
      goto LAB_02135aac;
    }
    goto LAB_02135778;
  }
  if (0x75 < uVar7) {
    if ((0x78 < uVar7) || (uVar7 != 0x78)) goto LAB_02135a58;
    goto LAB_02135644;
  }
  switch(uVar7) {
  case 100:
    goto LAB_0213550c;
  case 0x65:
    goto LAB_02135778;
  case 0x66:
    goto LAB_02135778;
  case 0x67:
LAB_02135778:
    if ((uStack_240 & 0xff) == 8) {
      uVar6 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
              *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uVar7 = uStack_4 + 4 & 3;
      uVar8 = *(uint *)(uStack_4 + 4 & 0xfffffffc);
      uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
    else {
      uVar6 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
              *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uVar7 = uStack_4 + 4 & 3;
      uVar8 = *(uint *)(uStack_4 + 4 & 0xfffffffc);
      uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
    uStack_4 = uStack_4 + 8;
    __s_00 = (uint *)func_02135c80(uVar6,uVar7,&stack0xffffffcc,uStack_244);
    if (__s_00 == (uint *)0x0) break;
    puStack_260 = &uStack_35 + -(int)__s_00;
    goto LAB_02135aac;
  case 0x68:
    break;
  case 0x69:
LAB_0213550c:
    uVar7 = uStack_240 & 0xff;
    if (uVar7 == 3) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    else if (uVar7 == 7) {
      uStack_26c = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                   *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uVar6 = uStack_4 + 4 & 3;
      uVar8 = *(uint *)(uStack_4 + 4 & 0xfffffffc);
      uStack_268 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      uStack_4 = uStack_4 + 8;
    }
    else if (uVar7 == 4) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 8;
    }
    else if (uVar7 == 5) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    else if (uVar7 == 6) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    else {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    if (uVar7 == 2) {
      unaff_r10 = (uint)(short)unaff_r10;
    }
    if (uVar7 == 1) {
      unaff_r10 = (uint)(char)unaff_r10;
    }
    if (uVar7 == 7) {
      __s_00 = (uint *)func_02136f14(uStack_26c,uStack_268,&stack0xffffffcc,uStack_244);
    }
    else {
      __s_00 = (uint *)func_02137358(unaff_r10,&stack0xffffffcc,uStack_244,uStack_240);
    }
    if (__s_00 == (uint *)0x0) break;
    puStack_260 = &uStack_35 + -(int)__s_00;
    goto LAB_02135aac;
  case 0x6a:
    break;
  case 0x6b:
    break;
  case 0x6c:
    break;
  case 0x6d:
    break;
  case 0x6e:
    uVar7 = uStack_4 + 4;
    piVar5 = (int *)(*(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                    *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20);
    uStack_4 = uVar7;
    switch(uStack_240 & 0xff) {
    case 0:
      *piVar5 = local_270;
      break;
    case 1:
      break;
    case 2:
      *(short *)piVar5 = (short)local_270;
      break;
    case 3:
      *piVar5 = local_270;
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      *piVar5 = local_270;
      piVar5[1] = local_270 >> 0x1f;
    }
    goto switchD_02135974_default;
  case 0x6f:
    goto LAB_02135644;
  case 0x70:
    break;
  case 0x71:
    break;
  case 0x72:
    break;
  case 0x73:
    if ((uStack_240 & 0xff) == 9) {
      uVar7 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
              *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      if (uVar7 == 0) {
        uVar7 = DAT_02135c78;
      }
      iVar3 = func_02134b18(auStack_234,uVar7,0x200);
      if (iVar3 < 0) break;
      __s_00 = auStack_234;
    }
    else {
      __s_00 = (uint *)(*(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                       *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20);
    }
    uStack_4 = uStack_4 + 4;
    if (__s_00 == (uint *)0x0) {
      __s_00 = DAT_02135c7c;
    }
    uVar7 = (int)&uStack_244 + 3U & 3;
    if (((uStack_244 >> uVar7 * 8 | uStack_244 << uVar7 * -8 + 0x20) & 0xff) == 0) {
      uVar7 = (int)&uStack_244 + 2U & 3;
      if (((uStack_244 >> uVar7 * 8 | uStack_244 << uVar7 * -8 + 0x20) & 0xff) == 0) {
        puStack_260 = (undefined1 *)strlen((char *)__s_00);
      }
      else {
        puStack_260 = puStack_238;
        pvVar4 = memchr(__s_00,0,(size_t)puStack_238);
        if (pvVar4 != (void *)0x0) {
          puStack_260 = (undefined1 *)((int)pvVar4 - (int)__s_00);
        }
      }
    }
    else {
      puVar1 = (uint *)((uint)__s_00 & 0xfffffffc);
      uVar7 = (uint)__s_00 & 3;
      __s_00 = (uint *)((int)__s_00 + 1);
      puStack_260 = (undefined1 *)((*puVar1 >> uVar7 * 8 | *puVar1 << uVar7 * -8 + 0x20) & 0xff);
      uVar7 = (int)&uStack_244 + 2U & 3;
      if ((((uStack_244 >> uVar7 * 8 | uStack_244 << uVar7 * -8 + 0x20) & 0xff) != 0) &&
         ((int)puStack_238 < (int)puStack_260)) {
        puStack_260 = puStack_238;
      }
    }
    goto LAB_02135aac;
  case 0x74:
    break;
  case 0x75:
LAB_02135644:
    uVar7 = uStack_240 & 0xff;
    if (uVar7 == 3) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    else if (uVar7 == 7) {
      uStack_26c = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                   *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uVar6 = uStack_4 + 4 & 3;
      uVar8 = *(uint *)(uStack_4 + 4 & 0xfffffffc);
      uStack_268 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      uStack_4 = uStack_4 + 8;
    }
    else if (uVar7 == 4) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 8;
    }
    else if (uVar7 == 5) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    else if (uVar7 == 6) {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    else {
      unaff_r10 = *(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
                  *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20;
      uStack_4 = uStack_4 + 4;
    }
    if (uVar7 == 2) {
      unaff_r10 = unaff_r10 & 0xffff;
    }
    if (uVar7 == 1) {
      unaff_r10 = unaff_r10 & 0xff;
    }
    if (uVar7 == 7) {
      __s_00 = (uint *)func_02136f14(uStack_26c,uStack_268,&stack0xffffffcc,uStack_244);
    }
    else {
      __s_00 = (uint *)func_02137358(unaff_r10,&stack0xffffffcc,uStack_244,uStack_240);
    }
    if (__s_00 == (uint *)0x0) break;
    puStack_260 = &uStack_35 + -(int)__s_00;
    goto LAB_02135aac;
  default:
    if (uVar7 != 99) break;
    __s_00 = auStack_234;
    auStack_234[0] =
         (*(uint *)(uStack_4 & 0xfffffffc) >> (uStack_4 & 3) * 8 |
         *(uint *)(uStack_4 & 0xfffffffc) << (uStack_4 & 3) * -8 + 0x20) & 0xff |
         auStack_234[0] & 0xffffff00;
    puStack_260 = (undefined1 *)0x1;
    uStack_4 = uStack_4 + 4;
LAB_02135aac:
    puVar9 = puStack_260;
    if ((uStack_244 & 0xff) != 0) {
      uVar7 = local_24c;
      if ((uStack_244 & 0xff) != 2) {
        uVar7 = 0x20;
      }
      local_248 = uVar7 | local_248 & 0xffffff00;
      uVar6 = (*(uint *)((uint)__s_00 & 0xfffffffc) >> ((uint)__s_00 & 3) * 8 |
              *(uint *)((uint)__s_00 & 0xfffffffc) << ((uint)__s_00 & 3) * -8 + 0x20) & 0xff;
      if ((((uVar6 == 0x2b) || (uVar6 == 0x2d)) || (uVar6 == 0x20)) && (uVar7 == 0x30)) {
        iVar3 = (*param_1)(param_2,__s_00,1);
        if (iVar3 == 0) {
          return -1;
        }
        __s_00 = (uint *)((int)__s_00 + 1);
        puStack_260 = puStack_260 + -1;
      }
      if ((int)puVar9 < iStack_23c) {
        do {
          iVar3 = (*param_1)(param_2,&local_248,1);
          if (iVar3 == 0) {
            return -1;
          }
          puVar9 = puVar9 + 1;
        } while ((int)puVar9 < iStack_23c);
      }
    }
    if ((puStack_260 != (undefined1 *)0x0) &&
       (iVar3 = (*param_1)(param_2,__s_00,puStack_260), iVar3 == 0)) {
      return -1;
    }
    if (((uStack_244 & 0xff) == 0) && ((int)puVar9 < iStack_23c)) {
      do {
        uVar6 = uStack_244;
        uVar8 = (local_248 >> (uVar10 & 3) * 8 | local_248 << (uVar10 & 3) * -8 + 0x20) & 0xffffff00
                | 0x20;
        uVar7 = (4 - (uVar10 & 3)) * 8 & 0x1f;
        MKDS_SLICE_1(uStack_244,0) =
             (byte)((uVar8 >> uVar7) >> 0x18) | (byte)((uVar8 << 0x20 - uVar7) >> 0x18);
        uStack_244._1_3_ = SUB43(uVar6,1);
        iVar3 = (*param_1)(param_2,uVar10,1);
        if (iVar3 == 0) {
          return -1;
        }
        puVar9 = puVar9 + 1;
      } while ((int)puVar9 < iStack_23c);
    }
    local_270 = local_270 + (int)puVar9;
switchD_02135974_default:
    if (((*(uint *)((uint)local_274 & 0xfffffffc) >> ((uint)local_274 & 3) * 8 |
         *(uint *)((uint)local_274 & 0xfffffffc) << ((uint)local_274 & 3) * -8 + 0x20) & 0xff) == 0)
    {
      return local_270;
    }
    goto LAB_02135378;
  }
LAB_02135a58:
  sVar2 = strlen(__s);
  if ((sVar2 != 0) && (iVar3 = (*param_1)(param_2,__s), iVar3 == 0)) {
    return -1;
  }
  return local_270 + sVar2;
}

