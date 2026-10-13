/* Decompiled C draft; module arm9; ROM address 0214d9e8. No matching claim. */
#include "types.h"
#include "deps/0214d9e8_Rtc_FifoHandler.h"

void Rtc_FifoHandler(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  ushort *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint *puVar12;
  undefined4 uVar13;
  code *pcVar11;
  
  puVar3 = DAT_0214df74;
  uVar5 = DAT_0214df70;
  puVar9 = DAT_0214df68;
  if (param_3 != 0) {
    uVar5 = (uint)(DAT_0214df68 + 6) & 3;
    uVar7 = *(uint *)((uint)(DAT_0214df68 + 6) & 0xfffffffc);
    uVar8 = (uint)(DAT_0214df68 + 1) & 3;
    uVar10 = *(uint *)((uint)(DAT_0214df68 + 1) & 0xfffffffc);
    pcVar11 = (code *)(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20);
    if (uVar7 >> uVar5 * 8 != 0 || uVar7 << uVar5 * -8 + 0x20 != 0) {
      DAT_0214df68[6] = 0;
    }
    if (*(uint *)((uint)DAT_0214df68 & 0xfffffffc) >> ((uint)DAT_0214df68 & 3) * 8 != 0 ||
        *(uint *)((uint)DAT_0214df68 & 0xfffffffc) << ((uint)DAT_0214df68 & 3) * -8 + 0x20 != 0) {
      *DAT_0214df68 = 0;
    }
    if (pcVar11 == (code *)0x0) {
      return;
    }
    puVar1 = puVar9 + 4;
    uVar5 = (uint)puVar1 & 3;
    uVar8 = *(uint *)((uint)puVar1 & 0xfffffffc);
    puVar9[1] = 0;
    (*pcVar11)(6,uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    return;
  }
  if ((param_2 & 0x7f00) == 0x3000) {
    uVar5 = (uint)(DAT_0214df68 + 7) & 3;
    uVar8 = *(uint *)((uint)(DAT_0214df68 + 7) & 0xfffffffc);
    pcVar11 = (code *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    if (pcVar11 == (code *)0x0) {
      return;
    }
    (*pcVar11)();
    return;
  }
  if ((param_2 & 0xff) == 0) {
    uVar13 = 0;
    uVar8 = (uint)(DAT_0214df68 + 5) & 3;
    uVar7 = *(uint *)((uint)(DAT_0214df68 + 5) & 0xfffffffc);
    switch(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) {
    case 0:
      uVar5 = (uint)(DAT_0214df68 + 2) & 3;
      uVar8 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
      puVar9 = (undefined4 *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
      uVar4 = func_0214d964(*DAT_0214df6c);
      puVar2 = DAT_0214df6c;
      *puVar9 = uVar4;
      uVar5 = (uint)puVar2 & 3;
      uVar8 = *(uint *)((uint)puVar2 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 0x13) >> 0x1b);
      puVar2 = DAT_0214df6c;
      puVar9[1] = uVar4;
      uVar5 = (uint)puVar2 & 3;
      uVar8 = *(uint *)((uint)puVar2 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 10) >> 0x1a);
      puVar2 = DAT_0214df6c;
      puVar9[2] = uVar4;
      uVar5 = (uint)puVar2 & 3;
      uVar8 = *(uint *)((uint)puVar2 & 0xfffffffc);
      puVar9[3] = ((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 5) >> 0x1d;
      break;
    case 1:
      uVar5 = (uint)(DAT_0214df68 + 2) & 3;
      uVar8 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
      puVar9 = (undefined4 *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
      uVar4 = func_0214d964((*(uint *)(DAT_0214df70 & 0xfffffffc) >> (DAT_0214df70 & 3) * 8 |
                            *(uint *)(DAT_0214df70 & 0xfffffffc) << (DAT_0214df70 & 3) * -8 + 0x20)
                            & 0x3f);
      uVar8 = DAT_0214df70;
      *puVar9 = uVar4;
      uVar5 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 0x11) >> 0x19);
      uVar8 = DAT_0214df70;
      puVar9[1] = uVar4;
      uVar5 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 9) >> 0x19);
      puVar9[2] = uVar4;
      break;
    case 2:
      uVar5 = (uint)(DAT_0214df68 + 2) & 3;
      uVar8 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
      puVar9 = (undefined4 *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
      uVar4 = func_0214d964((*(uint *)((uint)DAT_0214df6c & 0xfffffffc) >>
                             ((uint)DAT_0214df6c & 3) * 8 |
                            *(uint *)((uint)DAT_0214df6c & 0xfffffffc) <<
                            ((uint)DAT_0214df6c & 3) * -8 + 0x20) & 0xff);
      puVar2 = DAT_0214df6c;
      *puVar9 = uVar4;
      uVar5 = (uint)puVar2 & 3;
      uVar8 = *(uint *)((uint)puVar2 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 0x13) >> 0x1b);
      puVar2 = DAT_0214df6c;
      puVar9[1] = uVar4;
      uVar5 = (uint)puVar2 & 3;
      uVar8 = *(uint *)((uint)puVar2 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 10) >> 0x1a);
      puVar2 = DAT_0214df6c;
      puVar9[2] = uVar4;
      uVar7 = DAT_0214df70;
      uVar5 = (uint)puVar2 & 3;
      uVar8 = *(uint *)((uint)puVar2 & 0xfffffffc);
      puVar9[3] = ((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 5) >> 0x1d;
      uVar8 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar5 = (uint)(DAT_0214df68 + 3) & 3;
      uVar10 = *(uint *)((uint)(DAT_0214df68 + 3) & 0xfffffffc);
      puVar9 = (undefined4 *)(uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20);
      uVar4 = func_0214d964((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) & 0x3f);
      uVar8 = DAT_0214df70;
      *puVar9 = uVar4;
      uVar5 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 0x11) >> 0x19);
      uVar8 = DAT_0214df70;
      puVar9[1] = uVar4;
      uVar5 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar4 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 9) >> 0x19);
      puVar9[2] = uVar4;
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      uVar5 = (uint)(DAT_0214df68 + 2) & 3;
      uVar8 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
      puVar9 = (undefined4 *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
      if ((*DAT_0214df74 & 0xf) == 4) {
        *puVar9 = 1;
      }
      else {
        *puVar9 = 0;
      }
      break;
    case 7:
      uVar5 = (uint)(DAT_0214df68 + 2) & 3;
      uVar8 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
      puVar9 = (undefined4 *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
      if ((int)((uint)*DAT_0214df74 << 0x19) < 0) {
        *puVar9 = 1;
      }
      else {
        *puVar9 = 0;
      }
      break;
    case 8:
      uVar8 = (uint)(DAT_0214df68 + 2) & 3;
      uVar7 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
      puVar12 = (uint *)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
      *puVar12 = (*(uint *)(DAT_0214df70 & 0xfffffffc) >> (DAT_0214df70 & 3) * 8 |
                 *(uint *)(DAT_0214df70 & 0xfffffffc) << (DAT_0214df70 & 3) * -8 + 0x20) & 7;
      uVar8 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = func_0214d964(((uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) << 0x12) >> 0x1a);
      uVar8 = DAT_0214df70;
      puVar12[1] = uVar5;
      uVar5 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar5 = func_0214d964(((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 9) >> 0x19);
      puVar12[2] = uVar5;
      uVar8 = DAT_0214df70;
      puVar12[3] = 0;
      uVar5 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      if ((int)((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) << 0x18) < 0) {
        uVar5 = (uint)(puVar12 + 3) & 3;
        uVar8 = *(uint *)((uint)(puVar12 + 3) & 0xfffffffc);
        puVar12[3] = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 1;
      }
      if ((int)((*(uint *)(DAT_0214df70 & 0xfffffffc) >> (DAT_0214df70 & 3) * 8 |
                *(uint *)(DAT_0214df70 & 0xfffffffc) << (DAT_0214df70 & 3) * -8 + 0x20) << 0x10) < 0
         ) {
        uVar5 = (uint)(puVar12 + 3) & 3;
        uVar8 = *(uint *)((uint)(puVar12 + 3) & 0xfffffffc);
        puVar12[3] = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 2;
      }
      if ((int)((*(uint *)(DAT_0214df70 & 0xfffffffc) >> (DAT_0214df70 & 3) * 8 |
                *(uint *)(DAT_0214df70 & 0xfffffffc) << (DAT_0214df70 & 3) * -8 + 0x20) << 8) < 0) {
        uVar5 = (uint)(puVar12 + 3) & 3;
        uVar8 = *(uint *)((uint)(puVar12 + 3) & 0xfffffffc);
        puVar12[3] = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 4;
      }
      break;
    case 9:
      uVar5 = (uint)(DAT_0214df68 + 6) & 3;
      uVar8 = *(uint *)((uint)(DAT_0214df68 + 6) & 0xfffffffc);
      if (uVar8 >> uVar5 * 8 == 0 && uVar8 << uVar5 * -8 + 0x20 == 0) {
        uVar5 = (uint)(DAT_0214df68 + 2) & 3;
        uVar8 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
        uVar8 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
        uVar5 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        if ((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) == 1) {
          if ((*DAT_0214df74 & 0xf) != 4) {
            DAT_0214df68[6] = 1;
            *puVar3 = *puVar3 & 0xfff0 | 4;
            iVar6 = Rtc_WriteRawStatus2Async();
            if (iVar6 == 0) {
              uVar13 = 3;
              DAT_0214df68[6] = 0;
            }
          }
        }
        else if ((*DAT_0214df74 & 0xf) != 0) {
          DAT_0214df68[6] = 1;
          *puVar3 = *puVar3 & 0xfff0;
          iVar6 = Rtc_WriteRawStatus2Async();
          if (iVar6 == 0) {
            uVar13 = 3;
            DAT_0214df68[6] = 0;
          }
        }
      }
      else {
        DAT_0214df68[6] = 0;
      }
      break;
    case 10:
      uVar5 = (uint)(DAT_0214df68 + 6) & 3;
      uVar8 = *(uint *)((uint)(DAT_0214df68 + 6) & 0xfffffffc);
      if (uVar8 >> uVar5 * 8 == 0 && uVar8 << uVar5 * -8 + 0x20 == 0) {
        uVar5 = (uint)(DAT_0214df68 + 2) & 3;
        uVar8 = *(uint *)((uint)(DAT_0214df68 + 2) & 0xfffffffc);
        uVar8 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
        uVar5 = uVar8 & 3;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc);
        if ((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) == 1) {
          if (-1 < (int)((uint)*DAT_0214df74 << 0x19)) {
            DAT_0214df68[6] = 1;
            *puVar3 = *puVar3 | 0x40;
            iVar6 = Rtc_WriteRawStatus2Async();
            if (iVar6 == 0) {
              uVar13 = 3;
              DAT_0214df68[6] = 0;
            }
          }
        }
        else if ((int)((uint)*DAT_0214df74 << 0x19) < 0) {
          DAT_0214df68[6] = 1;
          *puVar3 = *puVar3 & 0xffbf;
          iVar6 = Rtc_WriteRawStatus2Async();
          if (iVar6 == 0) {
            uVar13 = 3;
            DAT_0214df68[6] = 0;
          }
        }
      }
      else {
        DAT_0214df68[6] = 0;
      }
      break;
    case 0xb:
      break;
    case 0xc:
      break;
    case 0xd:
      break;
    case 0xe:
      break;
    case 0xf:
      break;
    default:
      DAT_0214df68[6] = 0;
      uVar13 = 4;
    }
  }
  else {
    DAT_0214df68[6] = 0;
    switch(param_2 & 0xff) {
    case 1:
      uVar13 = 4;
      break;
    case 2:
      uVar13 = 5;
      break;
    case 3:
      uVar13 = 1;
      break;
    case 4:
    default:
      uVar13 = 6;
    }
  }
  puVar9 = DAT_0214df68;
  uVar5 = (uint)(DAT_0214df68 + 6) & 3;
  uVar8 = *(uint *)((uint)(DAT_0214df68 + 6) & 0xfffffffc);
  if (uVar8 >> uVar5 * 8 == 0 && uVar8 << uVar5 * -8 + 0x20 == 0) {
    uVar5 = (uint)(DAT_0214df68 + 1) & 3;
    uVar8 = *(uint *)((uint)(DAT_0214df68 + 1) & 0xfffffffc);
    pcVar11 = (code *)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    if (*(uint *)((uint)DAT_0214df68 & 0xfffffffc) >> ((uint)DAT_0214df68 & 3) * 8 != 0 ||
        *(uint *)((uint)DAT_0214df68 & 0xfffffffc) << ((uint)DAT_0214df68 & 3) * -8 + 0x20 != 0) {
      *DAT_0214df68 = 0;
    }
    if (pcVar11 == (code *)0x0) {
      return;
    }
    puVar1 = puVar9 + 4;
    uVar5 = (uint)puVar1 & 3;
    uVar8 = *(uint *)((uint)puVar1 & 0xfffffffc);
    puVar9[1] = 0;
    (*pcVar11)(uVar13,uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    return;
  }
  return;
}

