/* Decompiled C draft; module arm9; ROM address 020bab54. No matching claim. */
#include "types.h"
#include "deps/020bab54_func_020bab54.h"

void func_020bab54(void)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar11;
  undefined4 uVar12;
  uint uVar5;
  uint uVar10;
  
  uVar9 = (*(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
          *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20) + 4;
  uVar4 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
  iVar2 = GetCurrentPlayerRacerId();
  uVar5 = DAT_020bb4f8;
  uVar6 = DAT_020bb4f4;
  iVar2 = iVar2 * 0x210;
  uVar3 = *(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
          *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20;
  uVar9 = (*(uint *)(DAT_020bb4f8 & 0xfffffffc) >> (DAT_020bb4f8 & 3) * 8 |
          *(uint *)(DAT_020bb4f8 & 0xfffffffc) << (DAT_020bb4f8 & 3) * -8 + 0x20) + iVar2 + 0x28;
  uVar4 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar11 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
  uVar9 = uVar3 + 0x10;
  uVar4 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar8 = 0x13;
  *(uint *)(uVar3 + 0x14) = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
  uVar3 = DAT_020bb4f4;
  uVar9 = uVar5 & 3;
  uVar4 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  uVar9 = uVar5 + iVar2;
  uVar4 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if ((uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) == 1) {
    uVar9 = uVar5 + iVar2 + 4;
    uVar4 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 4) =
         uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    uVar9 = uVar6 + 4;
    uVar4 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
    *(undefined4 *)(uVar6 + 0x10) = 1;
    goto LAB_020bafbc;
  }
  if (uVar10 == 0) {
    *(undefined4 *)
     ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
      *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10) = 0;
    uVar9 = 0;
    goto LAB_020bafbc;
  }
  if (((int)uVar10 < 1) || (0xd5 < (int)uVar10)) {
    if (((int)uVar10 < 0xd6) || ((int)(uVar11 + 0xd5) <= (int)uVar10)) {
      uVar12 = func_02108e88();
      func_0212c6f0(uVar12,0);
      uVar6 = DAT_020bb4f8;
      uVar4 = DAT_020bb4f4;
      *(undefined4 *)
       ((*(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
        *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20) + 4) = 0;
      uVar9 = uVar6 & 3;
      uVar3 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar4 & 3;
      uVar5 = *(uint *)(uVar4 & 0xfffffffc);
      uVar9 = (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) + iVar2 + 0xc;
      uVar4 = uVar9 & 3;
      uVar3 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 4;
      uVar6 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
      if ((int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 9) {
        uVar3 = *(uint *)(DAT_020bb4fc & 0xfffffffc) >> (DAT_020bb4fc & 3) * 8 |
                *(uint *)(DAT_020bb4fc & 0xfffffffc) << (DAT_020bb4fc & 3) * -8 + 0x20;
        uVar4 = uVar3 + 0xc & 3;
        uVar6 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
        if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) != 2) {
          uVar12 = 0x3f;
          if ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) == 0x21) {
            uVar12 = DAT_020bb50c;
          }
          if (((*(uint *)(DAT_020bb500 & 0xfffffffc) >> (DAT_020bb500 & 3) * 8 |
               *(uint *)(DAT_020bb500 & 0xfffffffc) << (DAT_020bb500 & 3) * -8 + 0x20) & 1) != 0) {
            func_02108ea0(0);
            uVar6 = GetSomeSndPlayer();
            uVar4 = DAT_020bb508 + 0xcU & 3;
            uVar3 = *(uint *)(DAT_020bb508 + 0xcU & 0xfffffffc);
            if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
              if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
                  *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
                func_0212c6f0(uVar6,0);
              }
              if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
                  *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
                func_0212c6f0(uVar6,0);
              }
              NNSi_MaybeSndPlayerStartSeq(uVar6,0,uVar12);
            }
          }
        }
      }
      else {
        uVar3 = *(uint *)(DAT_020bb4fc & 0xfffffffc) >> (DAT_020bb4fc & 3) * 8 |
                *(uint *)(DAT_020bb4fc & 0xfffffffc) << (DAT_020bb4fc & 3) * -8 + 0x20;
        uVar4 = uVar3 + 0xc & 3;
        uVar6 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
        if ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) != 2) {
          uVar12 = 0x40;
          if ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) == 0x21) {
            uVar12 = DAT_020bb504;
          }
          if (((*(uint *)(DAT_020bb500 & 0xfffffffc) >> (DAT_020bb500 & 3) * 8 |
               *(uint *)(DAT_020bb500 & 0xfffffffc) << (DAT_020bb500 & 3) * -8 + 0x20) & 1) != 0) {
            func_02108ea0(0);
            uVar6 = GetSomeSndPlayer();
            uVar4 = DAT_020bb508 + 0xcU & 3;
            uVar3 = *(uint *)(DAT_020bb508 + 0xcU & 0xfffffffc);
            if (uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0) {
              if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
                  *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
                func_0212c6f0(uVar6,0);
              }
              if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
                  *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
                func_0212c6f0(uVar6,0);
              }
              NNSi_MaybeSndPlayerStartSeq(uVar6,0,uVar12);
            }
          }
        }
      }
      *(undefined4 *)
       ((*(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
        *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20) + 0x10) = 0;
    }
    else {
      uVar6 = *(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
              *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20;
      uVar9 = uVar6 + 4;
      uVar4 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      *(uint *)(uVar6 + 4) = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) + 1;
      uVar9 = uVar3 & 3;
      uVar4 = *(uint *)(uVar3 & 0xfffffffc);
      uVar6 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
      uVar9 = uVar6 + 4;
      uVar4 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
      *(undefined4 *)(uVar6 + 0x10) = 1;
    }
    goto LAB_020bafbc;
  }
  uVar3 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar9 = uVar3 + 4;
  uVar4 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  *(uint *)(uVar3 + 4) = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) + 1;
  uVar4 = DAT_020bb4f4;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar9 = uVar6 + 4 & 3;
  uVar3 = *(uint *)(uVar6 + 4 & 0xfffffffc);
  uVar9 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  if (0x5e < (int)uVar9) {
    if (0x96 < (int)uVar9) {
      if ((int)uVar9 < 0xb7) {
        if ((0xb5 < (int)uVar9) || (uVar9 == 0xa6)) goto LAB_020badf0;
      }
      else if ((int)uVar9 < 199) {
        if (uVar9 == 0xc6) goto LAB_020badf0;
      }
      else if (uVar9 == 0xd6) goto LAB_020badf0;
      goto switchD_020bac3c_default;
    }
    if ((int)uVar9 < 0x96) {
      if (0x6e < (int)uVar9) {
        if ((int)uVar9 < 0x77) {
          if (uVar9 == 0x76) goto LAB_020badf0;
        }
        else if (uVar9 == 0x86) goto LAB_020badf0;
        goto switchD_020bac3c_default;
      }
      if (((int)uVar9 < 0x6e) && (uVar9 != 0x66)) goto switchD_020bac3c_default;
    }
    goto LAB_020badf0;
  }
  if (0x5d < (int)uVar9) goto LAB_020badf0;
  if (0x42 < (int)uVar9) {
    if ((int)uVar9 < 0x4b) {
      if ((0x49 < (int)uVar9) || (uVar9 == 0x46)) goto LAB_020badf0;
    }
    else if ((int)uVar9 < 0x4f) {
      if (uVar9 == 0x4e) goto LAB_020badf0;
    }
    else if (uVar9 == 0x56) goto LAB_020badf0;
    goto switchD_020bac3c_default;
  }
  if (0x41 < (int)uVar9) goto LAB_020badf0;
  if (0x36 < (int)uVar9) {
    if ((int)uVar9 < 0x3b) {
      if (uVar9 == 0x3a) goto LAB_020badf0;
    }
    else if (uVar9 == 0x3e) goto LAB_020badf0;
    goto switchD_020bac3c_default;
  }
  if (0x35 < (int)uVar9) goto LAB_020badf0;
  switch(uVar9) {
  case 0:
    break;
  case 1:
    goto LAB_020badf0;
  case 2:
    goto LAB_020badf0;
  case 3:
    goto LAB_020badf0;
  case 4:
    goto LAB_020badf0;
  case 5:
    goto LAB_020badf0;
  case 6:
    goto LAB_020badf0;
  case 7:
    break;
  case 8:
    goto LAB_020badf0;
  case 9:
    break;
  case 10:
    goto LAB_020badf0;
  case 0xb:
    break;
  case 0xc:
    goto LAB_020badf0;
  case 0xd:
    break;
  case 0xe:
    goto LAB_020badf0;
  case 0xf:
    break;
  case 0x10:
    goto LAB_020badf0;
  case 0x11:
    break;
  case 0x12:
    goto LAB_020badf0;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    goto LAB_020badf0;
  case 0x17:
    break;
  case 0x18:
    break;
  case 0x19:
    break;
  case 0x1a:
    goto LAB_020badf0;
  case 0x1b:
    break;
  case 0x1c:
    break;
  case 0x1d:
    break;
  case 0x1e:
    goto LAB_020badf0;
  case 0x1f:
    break;
  case 0x20:
    break;
  case 0x21:
    break;
  case 0x22:
    goto LAB_020badf0;
  case 0x23:
    break;
  case 0x24:
    break;
  case 0x25:
    break;
  case 0x26:
    goto LAB_020badf0;
  case 0x27:
    break;
  case 0x28:
    break;
  case 0x29:
    break;
  case 0x2a:
    goto LAB_020badf0;
  case 0x2b:
    break;
  case 0x2c:
    break;
  case 0x2d:
    break;
  case 0x2e:
    goto LAB_020badf0;
  case 0x2f:
    break;
  case 0x30:
    break;
  case 0x31:
    break;
  case 0x32:
LAB_020badf0:
    *(undefined4 *)(uVar6 + 4) = 0xd6;
    uVar9 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar6 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
    uVar9 = uVar6 + 4 & 3;
    uVar4 = *(uint *)(uVar6 + 4 & 0xfffffffc);
    uVar9 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  }
switchD_020bac3c_default:
  *(undefined4 *)(uVar6 + 0x10) = 1;
LAB_020bafbc:
  uVar6 = *(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
          *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20;
  uVar4 = uVar6 + 0x14;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (((uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) &&
      (uVar6 = uVar6 + 0x10, uVar4 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
      uVar6 >> uVar4 * 8 != 0 || uVar6 << uVar4 * -8 + 0x20 != 0)) &&
     (uVar4 = (*(uint *)(DAT_020bb4fc & 0xfffffffc) >> (DAT_020bb4fc & 3) * 8 |
              *(uint *)(DAT_020bb4fc & 0xfffffffc) << (DAT_020bb4fc & 3) * -8 + 0x20) + 0xc,
     uVar6 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
     (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) != 2)) {
    uVar6 = func_02108e88();
    uVar3 = *(uint *)(DAT_020bb4fc & 0xfffffffc) >> (DAT_020bb4fc & 3) * 8 |
            *(uint *)(DAT_020bb4fc & 0xfffffffc) << (DAT_020bb4fc & 3) * -8 + 0x20;
    uVar12 = 0x3e;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 0x21) {
      uVar12 = 0x1c4;
    }
    if ((((*(uint *)(DAT_020bb500 & 0xfffffffc) >> (DAT_020bb500 & 3) * 8 |
          *(uint *)(DAT_020bb500 & 0xfffffffc) << (DAT_020bb500 & 3) * -8 + 0x20) & 1) != 0) &&
       (uVar4 = DAT_020bb508 + 0xcU & 3, uVar3 = *(uint *)(DAT_020bb508 + 0xcU & 0xfffffffc),
       uVar3 >> uVar4 * 8 != 0 || uVar3 << uVar4 * -8 + 0x20 != 0)) {
      if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar6,0);
      }
      if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar6,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar6,0,uVar12);
    }
  }
  uVar3 = DAT_020bb4f8;
  uVar5 = *(uint *)(DAT_020bb4f8 & 0xfffffffc) >> (DAT_020bb4f8 & 3) * 8 |
          *(uint *)(DAT_020bb4f8 & 0xfffffffc) << (DAT_020bb4f8 & 3) * -8 + 0x20;
  uVar4 = uVar5 + iVar2;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  iVar7 = uVar5 + iVar2;
  if (uVar4 >> uVar6 * 8 == 0 && uVar4 << uVar6 * -8 + 0x20 == 0) {
    uVar4 = iVar7 + 0x30U & 3;
    uVar6 = *(uint *)(iVar7 + 0x30U & 0xfffffffc);
    uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    if (uVar4 == 0x13) {
      uVar4 = iVar7 + 0x14U & 3;
      uVar6 = *(uint *)(iVar7 + 0x14U & 0xfffffffc);
      uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    }
    *(uint *)((*(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
              *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20) + 0xc) = uVar4
    ;
    goto LAB_020bb2c8;
  }
  if (0x5e < (int)uVar9) {
    if (0x96 < (int)uVar9) {
      if ((int)uVar9 < 0xb7) {
        if ((0xb5 < (int)uVar9) || (uVar9 == 0xa6)) goto LAB_020bb288;
      }
      else if ((int)uVar9 < 199) {
        if (uVar9 == 0xc6) goto LAB_020bb288;
      }
      else if (uVar9 == 0xd6) goto LAB_020bb288;
      goto switchD_020bb0d8_default;
    }
    if ((int)uVar9 < 0x96) {
      if (0x6e < (int)uVar9) {
        if ((int)uVar9 < 0x77) {
          if (uVar9 == 0x76) goto LAB_020bb288;
        }
        else if (uVar9 == 0x86) goto LAB_020bb288;
        goto switchD_020bb0d8_default;
      }
      if (((int)uVar9 < 0x6e) && (uVar9 != 0x66)) goto switchD_020bb0d8_default;
    }
    goto LAB_020bb288;
  }
  if (0x5d < (int)uVar9) goto LAB_020bb288;
  if (0x42 < (int)uVar9) {
    if ((int)uVar9 < 0x4b) {
      if ((0x49 < (int)uVar9) || (uVar9 == 0x46)) goto LAB_020bb288;
    }
    else if ((int)uVar9 < 0x4f) {
      if (uVar9 == 0x4e) goto LAB_020bb288;
    }
    else if (uVar9 == 0x56) goto LAB_020bb288;
    goto switchD_020bb0d8_default;
  }
  if (0x41 < (int)uVar9) goto LAB_020bb288;
  if (0x3a < (int)uVar9) {
    if (uVar9 != 0x3e) goto switchD_020bb0d8_default;
    goto LAB_020bb288;
  }
  if (0x39 < (int)uVar9) goto LAB_020bb288;
  switch(uVar9) {
  case 0:
    goto LAB_020bb288;
  case 1:
    goto LAB_020bb288;
  case 2:
    goto LAB_020bb288;
  case 3:
    goto LAB_020bb288;
  case 4:
    goto LAB_020bb288;
  case 5:
    goto LAB_020bb288;
  case 6:
    goto LAB_020bb288;
  case 7:
    break;
  case 8:
    goto LAB_020bb288;
  case 9:
    break;
  case 10:
    goto LAB_020bb288;
  case 0xb:
    break;
  case 0xc:
    goto LAB_020bb288;
  case 0xd:
    break;
  case 0xe:
    goto LAB_020bb288;
  case 0xf:
    break;
  case 0x10:
    goto LAB_020bb288;
  case 0x11:
    break;
  case 0x12:
    goto LAB_020bb288;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    goto LAB_020bb288;
  case 0x17:
    break;
  case 0x18:
    break;
  case 0x19:
    break;
  case 0x1a:
    goto LAB_020bb288;
  case 0x1b:
    break;
  case 0x1c:
    break;
  case 0x1d:
    break;
  case 0x1e:
    goto LAB_020bb288;
  case 0x1f:
    break;
  case 0x20:
    break;
  case 0x21:
    break;
  case 0x22:
    goto LAB_020bb288;
  case 0x23:
    break;
  case 0x24:
    break;
  case 0x25:
    break;
  case 0x26:
    goto LAB_020bb288;
  case 0x27:
    break;
  case 0x28:
    break;
  case 0x29:
    break;
  case 0x2a:
    goto LAB_020bb288;
  case 0x2b:
    break;
  case 0x2c:
    break;
  case 0x2d:
    break;
  case 0x2e:
    goto LAB_020bb288;
  case 0x2f:
    break;
  case 0x30:
    break;
  case 0x31:
    break;
  case 0x32:
    goto LAB_020bb288;
  case 0x33:
    break;
  case 0x34:
    break;
  case 0x35:
    break;
  case 0x36:
LAB_020bb288:
    uVar4 = iVar7 + 0xcU & 3;
    uVar6 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
    *(uint *)((*(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
              *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20) + 0xc) =
         uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    uVar4 = uVar3 & 3;
    uVar6 = *(uint *)(uVar3 & 0xfffffffc);
    func_020f830c((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + iVar2);
  }
switchD_020bb0d8_default:
  uVar4 = (*(uint *)(DAT_020bb4f8 & 0xfffffffc) >> (DAT_020bb4f8 & 3) * 8 |
          *(uint *)(DAT_020bb4f8 & 0xfffffffc) << (DAT_020bb4f8 & 3) * -8 + 0x20) + iVar2 + 0xc;
  uVar6 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar8 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  *(undefined4 *)
   ((*(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
    *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20) + 0x18) = 0;
LAB_020bb2c8:
  uVar6 = DAT_020bb510;
  uVar4 = DAT_020bb4f4;
  if ((int)uVar9 < 6) {
    iVar7 = 0;
  }
  else if ((int)uVar9 < 0x12) {
    iVar7 = (int)((uVar9 - 6 & 1) << 5) >> 1;
  }
  else if ((int)uVar9 < 0x4e) {
    iVar7 = (int)((uVar9 - 0x12 & 3) << 5) >> 2;
  }
  else if ((int)uVar9 < 0x76) {
    iVar7 = (int)((uVar9 - 0x4e & 7) << 5) >> 3;
  }
  else if ((int)uVar9 < 0xd6) {
    iVar7 = (int)((uVar9 - 0x76 & 0xf) << 5) >> 4;
  }
  else if ((int)uVar9 < (int)(uVar11 + 0xd6)) {
    iVar7 = (*(uint *)(DAT_020bb4f8 & 0xfffffffc) >> (DAT_020bb4f8 & 3) * 8 |
            *(uint *)(DAT_020bb4f8 & 0xfffffffc) << (DAT_020bb4f8 & 3) * -8 + 0x20) + iVar2;
    uVar3 = iVar7 + 0x28;
    uVar5 = uVar3 & 3;
    uVar11 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = iVar7 + 0x2c;
    uVar10 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    iVar7 = (int)((uVar9 - 0xd6 & (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) - 1) << 5) >>
            ((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) & 0xff);
  }
  else {
    iVar7 = 0;
  }
  uVar5 = *(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
          *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20;
  uVar9 = uVar5 + 0x18 & 3;
  uVar3 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
  if (uVar3 >> uVar9 * 8 != 0 || uVar3 << uVar9 * -8 + 0x20 != 0) {
    uVar9 = uVar5 + 0x20 & 3;
    uVar11 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar3 = uVar5 + 0x24 & 3;
    uVar10 = *(uint *)(uVar5 + 0x24 & 0xfffffffc);
    *(uint *)(uVar5 + 0x20) =
         (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
         (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
    uVar9 = uVar5 + 0x28 & 3;
    uVar11 = *(uint *)(uVar5 + 0x28 & 0xfffffffc);
    uVar3 = uVar5 + 0x20 & 3;
    uVar10 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    uVar3 = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) -
            (uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20);
    lVar1 = (ulonglong)uVar6 * (ulonglong)uVar3;
    uVar9 = uVar5 + 0x24 & 3;
    uVar10 = *(uint *)(uVar5 + 0x24 & 0xfffffffc);
    *(uint *)(uVar5 + 0x24) =
         (uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) +
         ((uint)lVar1 >> 0xc |
         (((int)uVar3 >> 0x1f) * uVar6 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
    uVar9 = uVar5 + 0x24 & 3;
    uVar6 = *(uint *)(uVar5 + 0x24 & 0xfffffffc);
    uVar9 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
    lVar1 = (ulonglong)uVar9 * 0xc00;
    *(uint *)(uVar5 + 0x24) =
         (uint)lVar1 >> 0xc |
         (((int)uVar9 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar9 = uVar5 + 0x28 & 3;
    uVar6 = *(uint *)(uVar5 + 0x28 & 0xfffffffc);
    uVar3 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
    uVar9 = uVar5 + 0x20 & 3;
    uVar6 = *(uint *)(uVar5 + 0x20 & 0xfffffffc);
    *(uint *)(uVar5 + 0x1c) =
         ((uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14) -
         (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
    uVar3 = DAT_020bb514;
    uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    uVar9 = uVar5 + 0x18;
    uVar6 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    *(uint *)(uVar5 + 0x18) = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + 1;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    uVar9 = uVar4 + 0x28 & 3;
    uVar6 = *(uint *)(uVar4 + 0x28 & 0xfffffffc);
    uVar9 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
    if ((uVar9 == uVar3) &&
       (uVar6 = uVar4 + 0x18 & 3, uVar3 = *(uint *)(uVar4 + 0x18 & 0xfffffffc),
       7 < (int)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20))) {
      *(undefined4 *)(uVar4 + 0x28) = 0x1000;
    }
    else if ((uVar9 == 0x1000) &&
            (uVar9 = uVar4 + 0x18 & 3, uVar6 = *(uint *)(uVar4 + 0x18 & 0xfffffffc),
            10 < (int)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20))) {
      *(undefined4 *)(uVar4 + 0x18) = 0;
    }
  }
  uVar12 = DAT_020bb518;
  uVar6 = DAT_020bb514;
  uVar4 = DAT_020bb4f4;
  iVar2 = (*(uint *)(DAT_020bb4f8 & 0xfffffffc) >> (DAT_020bb4f8 & 3) * 8 |
          *(uint *)(DAT_020bb4f8 & 0xfffffffc) << (DAT_020bb4f8 & 3) * -8 + 0x20) + iVar2;
  uVar9 = iVar2 + 0x204U & 3;
  uVar3 = *(uint *)(iVar2 + 0x204U & 0xfffffffc);
  if (uVar3 >> uVar9 * 8 != 0 || uVar3 << uVar9 * -8 + 0x20 != 0) {
    uVar9 = iVar2 + 0x30U & 3;
    uVar3 = *(uint *)(iVar2 + 0x30U & 0xfffffffc);
    uVar9 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
    if (uVar9 == 0x13) {
      uVar9 = iVar2 + 0x14U & 3;
      uVar3 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
      uVar9 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
    }
    if (uVar9 == 0xd) {
      uVar5 = *(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
              *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20;
      uVar9 = uVar5 + 0x18;
      uVar3 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      *(uint *)(uVar5 + 0x18) = (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + 1;
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x1c) = 0x1000;
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x20) = 0x1000;
      *(undefined4 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x24) = uVar12;
      *(uint *)((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x28) = uVar6;
    }
  }
  uVar4 = DAT_020bb4f4;
  *(int *)(*(uint *)(DAT_020bb4f4 & 0xfffffffc) >> (DAT_020bb4f4 & 3) * 8 |
          *(uint *)(DAT_020bb4f4 & 0xfffffffc) << (DAT_020bb4f4 & 3) * -8 + 0x20) = iVar7;
  uVar9 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) + 8) = uVar8;
  return;
}

