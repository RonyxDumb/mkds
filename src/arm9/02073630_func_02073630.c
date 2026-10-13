/* Decompiled C draft; module arm9; ROM address 02073630. No matching claim. */
#include "types.h"
#include "deps/02073630_func_02073630.h"

void func_02073630(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar11 = *(uint *)(DAT_02073880 & 0xfffffffc) >> (DAT_02073880 & 3) * 8 |
           *(uint *)(DAT_02073880 & 0xfffffffc) << (DAT_02073880 & 3) * -8 + 0x20;
  *DAT_02073888 = DAT_02073884;
  puVar5 = DAT_02073890;
  puVar7 = DAT_0207388c;
  uVar9 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
          *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
  uVar8 = 0;
  if ((uVar9 == 0x1d) || (uVar9 == 0x28)) {
    *DAT_02073888 = DAT_02073894;
  }
  *DAT_02073898 = 0;
  uVar6 = DAT_0207389c;
  puVar1 = DAT_02073888;
  uVar9 = uVar11 + 8 & 3;
  uVar10 = *(uint *)(uVar11 + 8 & 0xfffffffc);
  if (((uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) == 2) &&
     ((uVar9 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
               *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20, uVar9 == 0x2a ||
      (uVar9 == 0x2b)))) {
    *DAT_02073898 = 1;
    *puVar1 = uVar6;
  }
  do {
    uVar4 = DAT_020738d4;
    uVar3 = DAT_020738cc;
    uVar2 = DAT_020738c4;
    uVar6 = DAT_020738a4;
    switch(uVar8) {
    case 0:
      *puVar7 = DAT_020738a0;
      *puVar5 = uVar6;
      break;
    case 1:
    default:
      *puVar7 = DAT_020738e8;
      *puVar5 = uVar6;
      break;
    case 2:
      *puVar7 = DAT_020738a8;
      *puVar5 = uVar6;
      break;
    case 3:
      *puVar7 = DAT_020738ac;
      *puVar5 = uVar6;
      break;
    case 4:
      *puVar7 = DAT_020738b0;
      *puVar5 = uVar6;
      break;
    case 5:
      *puVar7 = DAT_020738b4;
      *puVar5 = uVar6;
      break;
    case 6:
      *puVar7 = DAT_020738b8;
      *puVar5 = uVar6;
      break;
    case 7:
      *puVar7 = DAT_020738bc;
      *puVar5 = uVar6;
      break;
    case 8:
      *puVar7 = DAT_020738c8;
      *puVar5 = uVar3;
      break;
    case 9:
      *puVar7 = DAT_020738c0;
      *puVar5 = uVar2;
      break;
    case 10:
      *puVar7 = DAT_020738d0;
      *puVar5 = uVar4;
      break;
    case 0xb:
      *puVar7 = DAT_020738d8;
      *puVar5 = uVar6;
      break;
    case 0xc:
      *puVar7 = DAT_020738dc;
      *puVar5 = uVar6;
      break;
    case 0xd:
      *puVar7 = DAT_020738e0;
      *puVar5 = uVar6;
      break;
    case 0xe:
      *puVar7 = DAT_020738e4;
      *puVar5 = uVar6;
    }
    uVar8 = uVar8 + 1;
    puVar7 = puVar7 + 1;
    puVar5 = puVar5 + 1;
  } while (uVar8 < 0xf);
  uVar9 = GetUnknownPhysicalParamValue();
  uVar6 = FX_Div(0x1000,(uint)((ulonglong)DAT_020738ec * (ulonglong)uVar9) >> 0xc |
                        (((int)uVar9 >> 0x1f) * DAT_020738ec +
                        (int)((ulonglong)DAT_020738ec * (ulonglong)uVar9 >> 0x20)) * 0x100000);
  *DAT_020738f0 = uVar6;
  return;
}

