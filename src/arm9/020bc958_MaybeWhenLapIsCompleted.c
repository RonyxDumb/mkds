/* Decompiled C draft; module arm9; ROM address 020bc958. No matching claim. */
#include "types.h"
#include "deps/020bc958_MaybeWhenLapIsCompleted.h"

void MaybeWhenLapIsCompleted(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar6;
  uint uVar5;
  
  uVar3 = *(uint *)(DAT_020bcb44 & 0xfffffffc) >> (DAT_020bcb44 & 3) * 8 |
          *(uint *)(DAT_020bcb44 & 0xfffffffc) << (DAT_020bcb44 & 3) * -8 + 0x20;
  uVar1 = uVar3 + 8;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar1 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  if (uVar1 == 2) {
    return;
  }
  if (uVar1 != 4) goto LAB_020bc9cc;
  switch(*(undefined1 *)(uVar3 + 0x2f)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    goto LAB_020bc9cc;
  case 3:
    break;
  case 4:
    goto LAB_020bc9cc;
  case 5:
    break;
  case 6:
    goto LAB_020bc9cc;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
LAB_020bc9cc:
    uVar1 = *(uint *)(DAT_020bcb48 & 0xfffffffc) >> (DAT_020bcb48 & 3) * 8 |
            *(uint *)(DAT_020bcb48 & 0xfffffffc) << (DAT_020bcb48 & 3) * -8 + 0x20;
    *(uint *)(uVar1 + 4) =
         *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    GetCurrentPlayerRacerId();
    iVar2 = func_0203c8c0();
    uVar4 = DAT_020bcb48;
    *(int *)(*(uint *)(DAT_020bcb48 & 0xfffffffc) >> (DAT_020bcb48 & 3) * 8 |
            *(uint *)(DAT_020bcb48 & 0xfffffffc) << (DAT_020bcb48 & 3) * -8 + 0x20) = iVar2 + -1;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    uVar1 = uVar5 + 4 & 3;
    uVar4 = *(uint *)(uVar5 + 4 & 0xfffffffc);
    if ((uVar3 != (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) &&
       (uVar1 = uVar5 + 8 & 3, uVar4 = *(uint *)(uVar5 + 8 & 0xfffffffc),
       uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20, 0 < (int)uVar1)) {
      if ((int)uVar3 < (int)uVar1) {
        uVar4 = *(uint *)(DAT_020bcb44 & 0xfffffffc) >> (DAT_020bcb44 & 3) * 8 |
                *(uint *)(DAT_020bcb44 & 0xfffffffc) << (DAT_020bcb44 & 3) * -8 + 0x20;
        uVar1 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar6 = 0x41;
        if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 0x21) {
          uVar6 = DAT_020bcb50;
        }
        if (((*(uint *)(DAT_020bcb4c & 0xfffffffc) >> (DAT_020bcb4c & 3) * 8 |
             *(uint *)(DAT_020bcb4c & 0xfffffffc) << (DAT_020bcb4c & 3) * -8 + 0x20) & 1) != 0) {
          func_02108ea0(0);
          uVar4 = GetSomeSndPlayer();
          uVar1 = DAT_020bcb54 + 0xcU & 3;
          uVar3 = *(uint *)(DAT_020bcb54 + 0xcU & 0xfffffffc);
          if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
            if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
              func_0212c6f0(uVar4,0);
            }
            if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
              func_0212c6f0(uVar4,0);
            }
            NNSi_MaybeSndPlayerStartSeq(uVar4,0,uVar6);
          }
        }
      }
      *(undefined4 *)
       ((*(uint *)(DAT_020bcb48 & 0xfffffffc) >> (DAT_020bcb48 & 3) * 8 |
        *(uint *)(DAT_020bcb48 & 0xfffffffc) << (DAT_020bcb48 & 3) * -8 + 0x20) + 0xc) = 1;
    }
    uVar3 = *(uint *)(DAT_020bcb48 & 0xfffffffc) >> (DAT_020bcb48 & 3) * 8 |
            *(uint *)(DAT_020bcb48 & 0xfffffffc) << (DAT_020bcb48 & 3) * -8 + 0x20;
    uVar1 = uVar3 + 0xc & 3;
    uVar4 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
    uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    if (uVar1 != 0) {
      iVar2 = uVar1 - 1;
      if (iVar2 - DAT_020bcb5c *
                  ((int)((longlong)DAT_020bcb58 * (longlong)iVar2 >> 0x21) - (iVar2 >> 0x1f)) < 8) {
        *(undefined4 *)(uVar3 + 0x10) = 1;
      }
      else {
        *(undefined4 *)(uVar3 + 0x10) = 0;
      }
      uVar3 = DAT_020bcb48;
      uVar5 = *(uint *)(DAT_020bcb48 & 0xfffffffc) >> (DAT_020bcb48 & 3) * 8 |
              *(uint *)(DAT_020bcb48 & 0xfffffffc) << (DAT_020bcb48 & 3) * -8 + 0x20;
      uVar1 = uVar5 + 0xc;
      uVar4 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      *(uint *)(uVar5 + 0xc) = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) + 1;
      uVar1 = uVar3 & 3;
      uVar4 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
      uVar1 = uVar3 + 0xc;
      uVar4 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      if (0x78 < (int)(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20)) {
        *(undefined4 *)(uVar3 + 0xc) = 0;
      }
      return;
    }
    *(undefined4 *)(uVar3 + 0x10) = 1;
    return;
  }
  return;
}

