/* Decompiled C draft; module arm9; ROM address 02138618. No matching claim. */
#include "types.h"
#include "deps/02138618_func_02138618.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int func_02138618(code *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint unaff_r6;
  uint uVar10;
  bool bVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  uint local_104;
  uint local_100;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  int local_e8;
  int local_e4;
  uint local_e0;
  uint local_dc;
  uint *local_b8;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  uint local_60;
  int local_5c;
  int local_58;
  undefined4 local_50;
  int local_4c;
  undefined1 auStack_48 [36];
  
  iVar5 = DAT_021393fc;
  uVar12 = CONCAT44(local_f8,local_dc);
  uVar10 = 0;
  local_e8 = 0;
  local_e4 = 0;
  uVar7 = (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) & 0xff;
  if (uVar7 == 0) {
LAB_021393bc:
    iVar5 = (*param_1)(param_2,0,2);
    if ((iVar5 != 0) && (local_e4 == 0)) {
      return -1;
    }
    return local_e8;
  }
  local_ac = 10;
  local_a0 = 0x10;
  local_a4 = 8;
  local_a8 = 0;
  local_b8 = (uint *)0x0;
  local_104 = param_3;
  local_100 = param_4;
LAB_021386dc:
  uVar1 = 0;
  if (uVar7 < 0x80) {
    uVar1 = *(ushort *)(iVar5 + uVar7 * 2) & 0x100;
  }
  if (uVar1 != 0) {
    do {
      local_104 = local_104 + 1;
      uVar7 = (*(uint *)(local_104 & 0xfffffffc) >> (local_104 & 3) * 8 |
              *(uint *)(local_104 & 0xfffffffc) << (local_104 & 3) * -8 + 0x20) & 0xff;
      uVar1 = 0;
      if (uVar7 < 0x80) {
        uVar1 = *(ushort *)(iVar5 + uVar7 * 2) & 0x100;
      }
    } while (uVar1 != 0);
    while( true ) {
      uVar7 = (*param_1)(param_2,0,0);
      uVar7 = uVar7 & 0xff;
      local_60 = uVar7 | local_60 & 0xffffff00;
      uVar1 = 0;
      if (uVar7 < 0x80) {
        uVar1 = *(ushort *)(iVar5 + uVar7 * 2) & 0x100;
      }
      if (uVar1 == 0) break;
      uVar10 = uVar10 + 1;
    }
    (*param_1)(param_2,uVar7,1);
    goto switchD_02139338_default;
  }
  if (uVar7 != 0x25) {
    uVar2 = (*param_1)(param_2,0,0);
    uVar2 = uVar2 & 0xff;
    local_60 = uVar2 | local_60 & 0xffffff00;
    if (uVar7 == uVar2) {
      uVar10 = uVar10 + 1;
      local_104 = local_104 + 1;
      goto switchD_02139338_default;
    }
    (*param_1)(param_2,uVar2,1);
    goto LAB_021393bc;
  }
  local_104 = func_02139400(local_104,&local_50);
  puVar8 = local_b8;
  if (((local_50 & 0xff) == 0) &&
     (uVar7 = (int)&local_50 + 3U & 3,
     ((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) != 0x25)) {
    puVar8 = (uint *)(*(uint *)(local_100 & 0xfffffffc) >> (local_100 & 3) * 8 |
                     *(uint *)(local_100 & 0xfffffffc) << (local_100 & 3) * -8 + 0x20);
    local_100 = local_100 + 4;
  }
  uVar7 = (int)&local_50 + 3U & 3;
  if ((((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) != 0x6e) &&
     (iVar3 = (*param_1)(param_2,0,2), iVar3 != 0)) goto LAB_021393bc;
  uVar7 = (int)&local_50 + 3U & 3;
  uVar7 = (local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff;
  uVar4 = local_a0;
  if (uVar7 < 0x5c) {
    if (0x5a < uVar7) {
LAB_02139088:
      if (puVar8 == (uint *)0x0) {
        local_5c = 0;
        while (((bVar11 = local_4c != 0, local_4c = local_4c + -1, bVar11 &&
                (unaff_r6 = (*param_1)(param_2,0,0), unaff_r6 != 0xffffffff)) &&
               (local_60 = unaff_r6 & 0xff | local_60 & 0xffffff00,
               uVar7 = (uint)(auStack_48 + ((int)(unaff_r6 & 0xff) >> 3)) & 3,
               uVar2 = *(uint *)((uint)(auStack_48 + ((int)(unaff_r6 & 0xff) >> 3)) & 0xfffffffc),
               (1 << (unaff_r6 & 7) & (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0xff) != 0
               ))) {
          local_5c = local_5c + 1;
        }
        local_60 = unaff_r6 & 0xff | local_60 & 0xffffff00;
        if (local_5c == 0) {
          (*param_1)(param_2,unaff_r6 & 0xff,1);
          goto switchD_02139338_default;
        }
      }
      else {
        local_5c = 0;
        while ((bVar11 = local_4c != 0, local_4c = local_4c + -1, bVar11 &&
               (unaff_r6 = (*param_1)(param_2,0,0), unaff_r6 != 0xffffffff))) {
          uVar2 = unaff_r6 & 0xff;
          local_60 = uVar2 | local_60 & 0xffffff00;
          uVar7 = (uint)(auStack_48 + ((int)uVar2 >> 3)) & 3;
          uVar6 = *(uint *)((uint)(auStack_48 + ((int)uVar2 >> 3)) & 0xfffffffc);
          if ((1 << (unaff_r6 & 7) & (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0xff) == 0)
          break;
          uVar7 = (int)&local_50 + 2U & 3;
          if (((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) == 10) {
            func_02134d08(puVar8,&local_60,1);
            puVar9 = (uint *)((int)puVar8 + 2);
          }
          else {
            uVar2 = uVar2 | (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                            *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20)
                            & 0xffffff00;
            uVar7 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
            puVar9 = (uint *)((int)puVar8 + 1);
            *puVar8 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
          }
          local_5c = local_5c + 1;
          puVar8 = puVar9;
        }
        local_60 = unaff_r6 & 0xff | local_60 & 0xffffff00;
        if (local_5c == 0) {
          (*param_1)(param_2,unaff_r6 & 0xff,1);
          goto LAB_021393bc;
        }
        uVar7 = (int)&local_50 + 2U & 3;
        if (((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) == 10) {
          *(undefined2 *)puVar8 = 0;
        }
        else {
          uVar2 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                  *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar7 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
          *puVar8 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
        }
        local_e8 = local_e8 + 1;
      }
      uVar10 = uVar10 + local_5c;
      if (-1 < local_4c) {
        (*param_1)(param_2,local_60 & 0xff,1);
      }
      local_e4 = local_e4 + 1;
      goto switchD_02139338_default;
    }
    if (0x47 < uVar7) {
      if (uVar7 == 0x58) goto LAB_02138b5c;
      goto LAB_021393bc;
    }
    switch(uVar7) {
    case 0x41:
      break;
    case 0x42:
      goto LAB_021393bc;
    case 0x43:
      goto LAB_021393bc;
    case 0x44:
      goto LAB_021393bc;
    case 0x45:
      break;
    case 0x46:
      break;
    case 0x47:
      break;
    default:
      if (uVar7 == 0x25) {
        while( true ) {
          uVar7 = (*param_1)(param_2,0,0);
          uVar7 = uVar7 & 0xff;
          local_60 = uVar7 | local_60 & 0xffffff00;
          uVar1 = 0;
          if (uVar7 < 0x80) {
            uVar1 = *(ushort *)(iVar5 + uVar7 * 2) & 0x100;
          }
          if (uVar1 == 0) break;
          uVar10 = uVar10 + 1;
        }
        if (uVar7 == 0x25) {
          uVar10 = uVar10 + 1;
          goto switchD_02139338_default;
        }
        (*param_1)(param_2,uVar7,1);
      }
      goto LAB_021393bc;
    }
LAB_02138d00:
    uVar13 = func_0213a550(local_4c,param_1,param_2,&local_5c);
    if (local_5c == 0) goto LAB_021393bc;
    uVar10 = uVar10 + local_5c;
    if (puVar8 != (uint *)0x0) {
      uVar7 = (int)&local_50 + 2U & 3;
      uVar7 = (local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff;
      if (uVar7 == 0) {
        uVar7 = func_0212fe20();
        *puVar8 = uVar7;
      }
      else if (uVar7 == 8) {
        *(undefined8 *)puVar8 = uVar13;
      }
      else if (uVar7 == 9) {
        *(undefined8 *)puVar8 = uVar13;
      }
      local_e8 = local_e8 + 1;
    }
    local_e4 = local_e4 + 1;
  }
  else {
    if (0x78 < uVar7) goto LAB_021393bc;
    switch(uVar7) {
    case 99:
      uVar7 = (int)&local_50 + 1U & 3;
      if (((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) == 0) {
        local_4c = 1;
      }
      if (puVar8 == (uint *)0x0) {
        local_5c = 0;
        while ((bVar11 = local_4c != 0, local_4c = local_4c + -1, bVar11 &&
               (unaff_r6 = (*param_1)(param_2,0,0), unaff_r6 != 0xffffffff))) {
          local_5c = local_5c + 1;
          local_60 = unaff_r6 & 0xff | local_60 & 0xffffff00;
        }
        local_60 = unaff_r6 & 0xff | local_60 & 0xffffff00;
        if (local_5c == 0) goto LAB_021393bc;
      }
      else {
        local_5c = 0;
        while ((bVar11 = local_4c != 0, local_4c = local_4c + -1, bVar11 &&
               (unaff_r6 = (*param_1)(param_2,0,0), unaff_r6 != 0xffffffff))) {
          local_60 = unaff_r6 & 0xff | local_60 & 0xffffff00;
          uVar7 = (int)&local_50 + 2U & 3;
          if (((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) == 10) {
            func_02134d08(puVar8,&local_60,1);
          }
          else {
            uVar2 = unaff_r6 & 0xff |
                    (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                    *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                    0xffffff00;
            uVar7 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
            *puVar8 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
          }
          puVar8 = (uint *)((int)puVar8 + 1);
          local_5c = local_5c + 1;
        }
        local_60 = unaff_r6 & 0xff | local_60 & 0xffffff00;
        if (local_5c == 0) goto LAB_021393bc;
        uVar10 = uVar10 + local_5c;
        local_e8 = local_e8 + 1;
      }
      local_e4 = local_e4 + 1;
      break;
    case 100:
      uVar4 = local_ac;
      goto LAB_02138988;
    case 0x65:
      goto LAB_02138d00;
    case 0x66:
      goto LAB_02138d00;
    case 0x67:
      goto LAB_02138d00;
    case 0x68:
      goto LAB_021393bc;
    case 0x69:
      uVar4 = local_a8;
LAB_02138988:
      uVar7 = (int)&local_50 + 2U & 3;
      if (((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) == 7) {
        uVar12 = func_0213c110(uVar4,local_4c,param_1,param_2);
      }
      else {
        local_e0 = func_0213c560(uVar4,local_4c,param_1,param_2);
      }
      local_f8 = (uint)((ulonglong)uVar12 >> 0x20);
      local_dc = (uint)uVar12;
      if (local_5c == 0) goto LAB_021393bc;
      uVar10 = uVar10 + local_5c;
      uVar7 = (int)&local_50 + 2U & 3;
      uVar7 = (local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff;
      if (uVar7 == 7) {
        if (local_58 == 0) {
          local_f0 = local_dc;
          local_ec = local_f8;
        }
        else {
          local_f0 = -local_dc;
          local_ec = -(local_f8 + (local_dc != 0));
        }
      }
      else if (local_58 == 0) {
        local_f4 = local_e0;
      }
      else {
        local_f4 = -local_e0;
      }
      if (puVar8 != (uint *)0x0) {
        switch(uVar7) {
        case 0:
          *puVar8 = local_f4;
          break;
        case 1:
          uVar2 = local_f4 & 0xff |
                  (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                  *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar7 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
          *puVar8 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
          break;
        case 2:
          *(short *)puVar8 = (short)local_f4;
          break;
        case 3:
          *puVar8 = local_f4;
          break;
        case 4:
          *puVar8 = local_f4;
          puVar8[1] = (int)local_f4 >> 0x1f;
          break;
        case 5:
          *puVar8 = local_f4;
          break;
        case 6:
          *puVar8 = local_f4;
          break;
        case 7:
          *puVar8 = local_f0;
          puVar8[1] = local_ec;
        }
        local_e8 = local_e8 + 1;
      }
      local_e4 = local_e4 + 1;
      break;
    case 0x6a:
      goto LAB_021393bc;
    case 0x6b:
      goto LAB_021393bc;
    case 0x6c:
      goto LAB_021393bc;
    case 0x6d:
      goto LAB_021393bc;
    case 0x6e:
      if (puVar8 != (uint *)0x0) {
        uVar7 = (int)&local_50 + 2U & 3;
        switch((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) {
        case 0:
          *puVar8 = uVar10;
          break;
        case 1:
          uVar2 = uVar10 & 0xff |
                  (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                  *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar7 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
          *puVar8 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
          break;
        case 2:
          *(short *)puVar8 = (short)uVar10;
          break;
        case 3:
          *puVar8 = uVar10;
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          *puVar8 = uVar10;
          puVar8[1] = (int)uVar10 >> 0x1f;
        }
      }
      break;
    case 0x6f:
      uVar4 = local_a4;
      goto LAB_02138b5c;
    case 0x70:
      goto LAB_021393bc;
    case 0x71:
      goto LAB_021393bc;
    case 0x72:
      goto LAB_021393bc;
    case 0x73:
      uVar7 = (*param_1)(param_2,0,0);
      local_60 = uVar7 & 0xff | local_60 & 0xffffff00;
      while( true ) {
        uVar7 = local_60 & 0xff;
        uVar1 = 0;
        if (uVar7 < 0x80) {
          uVar1 = *(ushort *)(iVar5 + uVar7 * 2) & 0x100;
        }
        if (uVar1 == 0) break;
        uVar10 = uVar10 + 1;
        uVar7 = (*param_1)(param_2,0,0);
        local_60 = uVar7 & 0xff | local_60 & 0xffffff00;
      }
      (*param_1)(param_2,uVar7,1);
      goto LAB_02139088;
    case 0x74:
      goto LAB_021393bc;
    case 0x75:
      uVar4 = local_ac;
      goto LAB_02138b5c;
    case 0x76:
      goto LAB_021393bc;
    case 0x77:
      goto LAB_021393bc;
    case 0x78:
LAB_02138b5c:
      uVar7 = (int)&local_50 + 2U & 3;
      if (((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) == 7) {
        uVar12 = func_0213c110(uVar4,local_4c,param_1,param_2);
      }
      else {
        local_e0 = func_0213c560(uVar4,local_4c,param_1,param_2);
      }
      local_f8 = (uint)((ulonglong)uVar12 >> 0x20);
      local_dc = (uint)uVar12;
      if (local_5c == 0) goto LAB_021393bc;
      uVar10 = uVar10 + local_5c;
      if (local_58 != 0) {
        uVar7 = (int)&local_50 + 2U & 3;
        if (((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) == 7) {
          uVar12 = CONCAT44(-(local_f8 + (local_dc != 0)),-local_dc);
        }
        else {
          local_e0 = -local_e0;
        }
      }
      if (puVar8 != (uint *)0x0) {
        uVar7 = (int)&local_50 + 2U & 3;
        switch((local_50 >> uVar7 * 8 | local_50 << uVar7 * -8 + 0x20) & 0xff) {
        case 0:
          *puVar8 = local_e0;
          break;
        case 1:
          uVar2 = local_e0 & 0xff |
                  (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                  *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar7 = (4 - ((uint)puVar8 & 3)) * 8 & 0x1f;
          *puVar8 = uVar2 >> uVar7 | uVar2 << 0x20 - uVar7;
          break;
        case 2:
          *(short *)puVar8 = (short)local_e0;
          break;
        case 3:
          *puVar8 = local_e0;
          break;
        case 4:
          *puVar8 = local_e0;
          puVar8[1] = 0;
          break;
        case 5:
          *puVar8 = local_e0;
          break;
        case 6:
          *puVar8 = local_e0;
          break;
        case 7:
          *(undefined8 *)puVar8 = uVar12;
        }
        local_e8 = local_e8 + 1;
      }
      local_e4 = local_e4 + 1;
      break;
    default:
      if (uVar7 != 0x61) goto LAB_021393bc;
      goto LAB_02138d00;
    }
  }
switchD_02139338_default:
  uVar7 = (*(uint *)(local_104 & 0xfffffffc) >> (local_104 & 3) * 8 |
          *(uint *)(local_104 & 0xfffffffc) << (local_104 & 3) * -8 + 0x20) & 0xff;
  if (uVar7 == 0) goto LAB_021393bc;
  goto LAB_021386dc;
}

