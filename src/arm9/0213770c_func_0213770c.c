/* Decompiled C draft; module arm9; ROM address 0213770c. No matching claim. */
#include "types.h"
#include "deps/0213770c_func_0213770c.h"

int func_0213770c(int param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  byte bVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char local_20;
  char cStack_1f;
  char cStack_1e;
  char cStack_1d;
  char local_1c;
  char cStack_1b;
  undefined1 uStack_1a;
  byte bStack_19;
  uint local_18;
  uint local_14;
  
  bVar6 = bStack_19;
  local_20 = '\x01';
  cStack_1f = '\x01';
  cStack_1e = '\x01';
  cStack_1d = '\x01';
  local_18 = 0;
  local_14 = 0;
  uVar11 = param_1 + 1;
  local_1c = '\0';
  uStack_1a = 0;
  uVar10 = param_1 + 1U & 3;
  uVar9 = *(uint *)(param_1 + 1U & 0xfffffffc);
  uVar10 = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 0xff;
  if (uVar10 == 0x25) {
    *param_3 = 0x1010101;
    param_3[1] = 0x250000;
    param_3[2] = (uint)bStack_19;
    param_3[3] = 0;
    return param_1 + 2;
  }
  do {
    cVar3 = cStack_1d;
    cVar2 = cStack_1e;
    bVar1 = true;
    if (uVar10 < 0x2c) {
      if (uVar10 < 0x2b) {
        if ((0x23 < uVar10) || (uVar10 < 0x20)) goto LAB_021379a4;
        if (uVar10 == 0x20) {
          if (cStack_1f != '\x01') {
            cStack_1f = local_20;
            cStack_1e = '\x02';
            cStack_1d = cVar2;
            local_1c = cVar3;
          }
        }
        else {
          if (uVar10 != 0x23) goto LAB_021379a4;
          uStack_1a = 1;
          cStack_1d = local_20;
          local_1c = cStack_1f;
        }
      }
      else {
        cStack_1f = local_20;
        cStack_1e = '\x01';
        cStack_1d = cVar2;
        local_1c = cVar3;
      }
    }
    else if ((uVar10 < 0x31) && (0x2c < uVar10)) {
      if (uVar10 == 0x2d) {
        uVar9 = CONCAT13(cStack_1d,CONCAT12(cStack_1e,CONCAT11(cStack_1f,local_20))) & 0xffffff00;
        local_20 = '\0';
        cStack_1f = (char)(uVar9 >> 8);
        cStack_1e = (char)(uVar9 >> 0x10);
        cStack_1d = (char)(uVar9 >> 0x18);
      }
      else {
        if (uVar10 != 0x30) goto LAB_021379a4;
        if (local_20 != '\0') {
          uVar9 = CONCAT13(cStack_1d,CONCAT12(cStack_1e,CONCAT11(cStack_1f,local_20))) & 0xffffff00;
          local_20 = '\x02';
          cStack_1f = (char)(uVar9 >> 8);
          cStack_1e = (char)(uVar9 >> 0x10);
          cStack_1d = (char)(uVar9 >> 0x18);
        }
      }
    }
    else {
LAB_021379a4:
      bVar1 = false;
    }
    uVar4 = uStack_1a;
    if (!bVar1) break;
    uVar11 = uVar11 + 1;
    uVar10 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
             *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) & 0xff;
  } while( true );
  if (uVar10 == 0x2a) {
    *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) + 4;
    uVar10 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
             *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) - 4;
    uVar9 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    local_18 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
    if ((int)local_18 < 0) {
      uVar10 = CONCAT13(cStack_1d,CONCAT12(cStack_1e,CONCAT11(cStack_1f,local_20))) & 0xffffff00;
      local_18 = -local_18;
      local_20 = '\0';
      cStack_1f = (char)(uVar10 >> 8);
      cStack_1e = (char)(uVar10 >> 0x10);
      cStack_1d = (char)(uVar10 >> 0x18);
    }
    uVar11 = uVar11 + 1;
    uVar10 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
             *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) & 0xff;
  }
  else {
    while( true ) {
      if (uVar10 < 0x80) {
        uVar7 = *(ushort *)(DAT_021382a0 + uVar10 * 2) & 8;
      }
      else {
        uVar7 = 0;
      }
      if (uVar7 == 0) break;
      local_18 = local_18 * 10 + (uVar10 - 0x30);
      uVar11 = uVar11 + 1;
      uVar10 = (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
               *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) & 0xff;
    }
  }
  if (DAT_021382a4 < (int)local_18) {
    local_18 = CONCAT31(local_18._1_3_,bStack_19);
    *param_3 = CONCAT13(cStack_1d,CONCAT12(cStack_1e,CONCAT11(cStack_1f,local_20)));
    param_3[1] = CONCAT13(uStack_1a,CONCAT12(0xff,CONCAT11(local_1c,local_1c)));
    param_3[2] = local_18;
    param_3[3] = 0;
    return uVar11 + 1;
  }
  uVar9 = uVar11;
  if (uVar10 == 0x2e) {
    cStack_1e = local_20;
    cStack_1d = cStack_1f;
    local_1c = '\x01';
    uVar9 = uVar11 + 1;
    uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
             *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) & 0xff;
    if (uVar10 == 0x2a) {
      *param_2 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
                 *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) + 4;
      uVar10 = (*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) - 4;
      uVar9 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      local_14 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
      local_1c = -1 < (int)local_14;
      uVar9 = uVar11 + 2;
      uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
               *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) & 0xff;
    }
    else {
      while( true ) {
        if (uVar10 < 0x80) {
          uVar7 = *(ushort *)(DAT_021382a0 + uVar10 * 2) & 8;
        }
        else {
          uVar7 = 0;
        }
        if (uVar7 == 0) break;
        local_14 = local_14 * 10 + (uVar10 - 0x30);
        uVar9 = uVar9 + 1;
        uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) & 0xff;
      }
    }
  }
  bVar1 = true;
  if (uVar10 < 0x6d) {
    if (uVar10 < 0x68) {
      if (uVar10 != 0x4c) goto LAB_02137da0;
      local_1c = '\b';
    }
    else if (uVar10 == 0x68) {
      local_1c = '\x02';
      uVar11 = uVar9 + 1 & 3;
      uVar8 = *(uint *)(uVar9 + 1 & 0xfffffffc);
      if (((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) & 0xff) == 0x68) {
        local_1c = '\x01';
        uVar9 = uVar9 + 1;
        uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) & 0xff;
      }
    }
    else if (uVar10 == 0x6a) {
      local_1c = '\x04';
    }
    else {
      if (uVar10 != 0x6c) goto LAB_02137da0;
      local_1c = '\x03';
      uVar11 = uVar9 + 1 & 3;
      uVar8 = *(uint *)(uVar9 + 1 & 0xfffffffc);
      if (((uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) & 0xff) == 0x6c) {
        local_1c = '\a';
        uVar9 = uVar9 + 1;
        uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) & 0xff;
      }
    }
  }
  else if (uVar10 < 0x75) {
    if (uVar10 == 0x74) {
      local_1c = '\x06';
    }
    else {
LAB_02137da0:
      bVar1 = false;
    }
  }
  else {
    if (uVar10 != 0x7a) goto LAB_02137da0;
    local_1c = '\x05';
  }
  if (bVar1) {
    uVar9 = uVar9 + 1;
    uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
             *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) & 0xff;
  }
  cStack_1b = local_1c;
  uStack_1a = (undefined1)uVar10;
  uVar5 = uStack_1a;
  bStack_19 = uVar4;
  local_18 = CONCAT31(local_18._1_3_,bVar6);
  if (uVar10 < 0x62) {
    if (0x60 < uVar10) {
LAB_02137f94:
      if (cStack_1e == '\0') {
        local_14 = 0xd;
      }
      if ((((local_1c == '\x02') || (local_1c == '\x04')) || (local_1c == '\x05')) ||
         (((local_1c == '\x06' || (local_1c == '\a')) || (local_1c == '\x01')))) {
        uStack_1a = 0xff;
        bStack_19 = uVar5;
        local_18 = CONCAT31(local_18._1_3_,uVar4);
      }
      goto LAB_02138284;
    }
    if (uVar10 < 0x48) {
      switch(uVar10) {
      case 0x41:
        goto LAB_02137f94;
      case 0x42:
        break;
      case 0x43:
        break;
      case 0x44:
        break;
      case 0x45:
        goto LAB_0213801c;
      case 0x46:
        goto LAB_02137f30;
      case 0x47:
        goto LAB_0213800c;
      }
    }
    else if (uVar10 == 0x58) goto LAB_02137e9c;
    goto switchD_02137df4_default;
  }
  if (uVar10 < 100) {
    if (uVar10 == 99) {
      if (local_1c == '\x03') {
        uVar10 = CONCAT13(uVar4,CONCAT12(uStack_1a,0x303)) & 0xffffff00;
        local_1c = '\t';
        cStack_1b = (char)(uVar10 >> 8);
        uStack_1a = (undefined1)(uVar10 >> 0x10);
        bStack_19 = (byte)(uVar10 >> 0x18);
      }
      else if ((cStack_1e != '\0') || (local_1c != '\0')) {
        uStack_1a = 0xff;
        bStack_19 = uVar5;
        local_18 = CONCAT31(local_18._1_3_,uVar4);
      }
      goto LAB_02138284;
    }
    goto switchD_02137df4_default;
  }
  switch(uVar10) {
  case 100:
    goto LAB_02137e9c;
  case 0x65:
    goto LAB_0213801c;
  case 0x66:
LAB_02137f30:
    if ((local_1c == '\x02') || ((byte)(local_1c - 4U) < 4)) {
      uStack_1a = 0xff;
      bStack_19 = uVar5;
      local_18 = CONCAT31(local_18._1_3_,uVar4);
    }
    else if (cStack_1e == '\0') {
      local_14 = 6;
    }
    goto LAB_02138284;
  case 0x67:
LAB_0213800c:
    if (local_14 == 0) {
      local_14 = 1;
    }
LAB_0213801c:
    if (((((local_1c == '\x02') || (local_1c == '\x04')) || (local_1c == '\x05')) ||
        ((local_1c == '\x06' || (local_1c == '\a')))) || (local_1c == '\x01')) {
      uStack_1a = 0xff;
      bStack_19 = uVar5;
      local_18 = CONCAT31(local_18._1_3_,uVar4);
    }
    else if (cStack_1e == '\0') {
      local_14 = 6;
    }
    goto LAB_02138284;
  case 0x68:
    break;
  case 0x69:
    goto LAB_02137e9c;
  case 0x6a:
    break;
  case 0x6b:
    break;
  case 0x6c:
    break;
  case 0x6d:
    break;
  case 0x6e:
    if (local_1c == '\b') {
      uStack_1a = 0xff;
      bStack_19 = uVar5;
      local_18 = CONCAT31(local_18._1_3_,uVar4);
    }
    goto LAB_02138284;
  case 0x6f:
    goto LAB_02137e9c;
  case 0x70:
    local_18 = CONCAT31(local_18._1_3_,uVar4);
    cStack_1d = local_20;
    uStack_1a = 1;
    local_1c = '\x03';
    local_14 = 8;
    cStack_1b = cStack_1e;
    bStack_19 = uVar5;
    goto LAB_02138284;
  case 0x71:
    break;
  case 0x72:
    break;
  case 0x73:
    if (local_1c == '\x03') {
      uVar10 = CONCAT13(uVar4,CONCAT12(uStack_1a,0x303)) & 0xffffff00;
      local_1c = '\t';
      cStack_1b = (char)(uVar10 >> 8);
      uStack_1a = (undefined1)(uVar10 >> 0x10);
      bStack_19 = (byte)(uVar10 >> 0x18);
    }
    else if (local_1c != '\0') {
      uStack_1a = 0xff;
      bStack_19 = uVar5;
      local_18 = CONCAT31(local_18._1_3_,uVar4);
    }
    goto LAB_02138284;
  case 0x74:
    break;
  case 0x75:
    goto LAB_02137e9c;
  case 0x76:
    break;
  case 0x77:
    break;
  case 0x78:
LAB_02137e9c:
    if (local_1c == '\b') {
      uStack_1a = 0xff;
      bStack_19 = uVar5;
      local_18 = CONCAT31(local_18._1_3_,uVar4);
    }
    else if (cStack_1e == '\0') {
      local_14 = 1;
    }
    else if (local_20 == '\x02') {
      uVar10 = CONCAT13(cStack_1d,CONCAT12(cStack_1e,CONCAT11(cStack_1f,2))) & 0xffffff00;
      local_20 = '\x01';
      cStack_1f = (char)(uVar10 >> 8);
      cStack_1e = (char)(uVar10 >> 0x10);
      cStack_1d = (char)(uVar10 >> 0x18);
    }
    goto LAB_02138284;
  }
switchD_02137df4_default:
  uStack_1a = 0xff;
  bStack_19 = uVar5;
  local_18 = CONCAT31(local_18._1_3_,uVar4);
LAB_02138284:
  *param_3 = CONCAT13(cStack_1d,CONCAT12(cStack_1e,CONCAT11(cStack_1f,local_20)));
  param_3[1] = CONCAT13(bStack_19,CONCAT12(uStack_1a,CONCAT11(cStack_1b,local_1c)));
  param_3[2] = local_18;
  param_3[3] = local_14;
  return uVar9 + 1;
}

