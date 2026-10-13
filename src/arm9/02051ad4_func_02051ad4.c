/* Decompiled C draft; module arm9; ROM address 02051ad4. No matching claim. */
#include "types.h"
#include "deps/02051ad4_func_02051ad4.h"

void func_02051ad4(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  code *pcVar5;
  
  uVar4 = DAT_02051d0c;
  uVar1 = *(ushort *)(param_1 + 2);
  bVar9 = false;
  if (0xb < uVar1) {
    if (uVar1 != 0xc) goto LAB_02051cd8;
LAB_02051ca8:
    uVar4 = (*(uint *)(DAT_02051d0c & 0xfffffffc) >> (DAT_02051d0c & 3) * 8 |
            *(uint *)(DAT_02051d0c & 0xfffffffc) << (DAT_02051d0c & 3) * -8 + 0x20) + 0x44c;
    uVar6 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    pcVar5 = (code *)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    bVar9 = pcVar5 == (code *)0x0;
    if (!bVar9) {
      (*pcVar5)();
      *(undefined4 *)
       ((*(uint *)(DAT_02051d0c & 0xfffffffc) >> (DAT_02051d0c & 3) * 8 |
        *(uint *)(DAT_02051d0c & 0xfffffffc) << (DAT_02051d0c & 3) * -8 + 0x20) + 0x10) = 0;
    }
    goto LAB_02051cdc;
  }
  if (10 < uVar1) goto LAB_02051ca8;
  if (1 < uVar1) {
LAB_02051cd8:
    bVar9 = true;
    goto LAB_02051cdc;
  }
  if (uVar1 != 0) {
    if (uVar1 == 1) goto LAB_02051ca8;
    goto LAB_02051cd8;
  }
  switch(*(undefined2 *)(param_1 + 8)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    goto LAB_02051cdc;
  case 7:
    uVar6 = 0;
    *(undefined2 *)
     ((*(uint *)(DAT_02051d0c & 0xfffffffc) >> (DAT_02051d0c & 3) * 8 |
      *(uint *)(DAT_02051d0c & 0xfffffffc) << (DAT_02051d0c & 3) * -8 + 0x20) + 0x432) =
         *(undefined2 *)(param_1 + 10);
    *(undefined1 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x43a) = 0;
    iVar8 = DAT_02051d10;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    if (uVar4 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    }
    if (uVar7 == 1) {
      uVar6 = uVar4 + 0x18 & 3;
      uVar4 = *(uint *)(uVar4 + 0x18 & 0xfffffffc);
      uVar6 = (uint)*(ushort *)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0xc);
    }
    else if (uVar7 == 2) {
      uVar6 = uVar4 + 0x24 & 3;
      uVar4 = *(uint *)(uVar4 + 0x24 & 0xfffffffc);
      uVar6 = (uint)*(ushort *)((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x48);
    }
    uVar7 = *(uint *)(DAT_02051d0c & 0xfffffffc) >> (DAT_02051d0c & 3) * 8 |
            *(uint *)(DAT_02051d0c & 0xfffffffc) << (DAT_02051d0c & 3) * -8 + 0x20;
    *(uint *)(uVar7 + 0x1ee8) = uVar6 * 3 | uVar6 << 0x10;
    uVar2 = DAT_02051d14;
    iVar8 = uVar7 + iVar8;
    *(undefined4 *)(iVar8 + 4) = 0;
    uVar3 = DAT_02051d18;
    *(undefined4 *)(iVar8 + 8) = uVar2;
    uVar2 = DAT_02051d1c;
    *(undefined4 *)(iVar8 + 0xc) = uVar3;
    *(undefined4 *)(iVar8 + 0x10) = uVar2;
    *(undefined4 *)(iVar8 + 0x14) = 0;
    uVar4 = uVar7 + 0x448 & 3;
    uVar6 = *(uint *)(uVar7 + 0x448 & 0xfffffffc);
    pcVar5 = (code *)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)();
    }
    *(undefined4 *)
     ((*(uint *)(DAT_02051d0c & 0xfffffffc) >> (DAT_02051d0c & 3) * 8 |
      *(uint *)(DAT_02051d0c & 0xfffffffc) << (DAT_02051d0c & 3) * -8 + 0x20) + 0x10) = 0;
    goto LAB_02051cdc;
  case 8:
    goto LAB_02051cdc;
  case 9:
    bVar9 = *DAT_02051d20 == 2;
    if (bVar9) goto LAB_02051cdc;
    uVar6 = *(uint *)(DAT_02051d0c & 0xfffffffc) >> (DAT_02051d0c & 3) * 8 |
            *(uint *)(DAT_02051d0c & 0xfffffffc) << (DAT_02051d0c & 3) * -8 + 0x20;
    uVar4 = uVar6 + 0x450;
    uVar7 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    pcVar5 = (code *)(uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)();
      goto LAB_02051cdc;
    }
    uVar6 = uVar6 + 4;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    switch(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      goto LAB_02051c88;
    case 3:
      goto LAB_02051c88;
    case 4:
      goto LAB_02051c88;
    case 5:
      goto LAB_02051c88;
    case 6:
LAB_02051c88:
      func_020533a0();
      goto LAB_02051cdc;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      bVar9 = true;
      goto LAB_02051cdc;
    case 0xb:
      goto LAB_02051cdc;
    case 0xc:
      goto LAB_02051cdc;
    }
    bVar9 = true;
    goto LAB_02051cdc;
  }
  bVar9 = true;
LAB_02051cdc:
  if (bVar9) {
    func_02053fa8();
    uVar6 = DAT_02051d0c;
    *(undefined4 *)
     ((*(uint *)(DAT_02051d0c & 0xfffffffc) >> (DAT_02051d0c & 3) * 8 |
      *(uint *)(DAT_02051d0c & 0xfffffffc) << (DAT_02051d0c & 3) * -8 + 0x20) + 8) = 0;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined4 *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x10) = 0;
    return;
  }
  return;
}

