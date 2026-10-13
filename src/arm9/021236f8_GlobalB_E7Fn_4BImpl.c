/* Decompiled C draft; module arm9; ROM address 021236f8. No matching claim. */
#include "types.h"
#include "deps/021236f8_GlobalB_E7Fn_4BImpl.h"

undefined4 GlobalB_E7Fn_4BImpl(void)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  func_02122818();
  func_02122960();
  uVar2 = (*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
          *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) + 0x1950;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  switch(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) {
  case 0:
    func_0212357c();
    break;
  case 1:
    func_02123384();
    break;
  case 2:
    func_021225ac(DAT_02123a38);
    uVar2 = DAT_02123a34;
    if (*(char *)((*(uint *)(DAT_02123a3c & 0xfffffffc) >> (DAT_02123a3c & 3) * 8 |
                  *(uint *)(DAT_02123a3c & 0xfffffffc) << (DAT_02123a3c & 3) * -8 + 0x20) + 0x28) ==
        '\0') {
      uVar5 = *(uint *)(DAT_02123a40 & 0xfffffffc) >> (DAT_02123a40 & 3) * 8 |
              *(uint *)(DAT_02123a40 & 0xfffffffc) << (DAT_02123a40 & 3) * -8 + 0x20;
      uVar3 = uVar5 + 0xc;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0) {
        uVar3 = 0;
      }
      else {
        uVar5 = uVar5 + 0x10;
        uVar3 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
      }
    }
    else {
      uVar3 = 1;
    }
    if (uVar3 == 0) {
      *(undefined4 *)
       ((*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
        *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) + 0x1980) = 0;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x1950) = 5;
    }
    break;
  case 3:
    func_0212320c();
    break;
  case 4:
    func_02123098();
    break;
  case 5:
    func_02122f38();
    break;
  case 6:
    func_021225ac(DAT_02123a38);
    uVar2 = GetSomeRacerIndex();
    if (uVar2 < *(byte *)((*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
                          *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) +
                         0x1f53)) {
      uVar1 = func_0x0219bb50();
      iVar6 = func_0x0219bb50();
      uVar5 = DAT_02123a34;
      iVar4 = (*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
              *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) + DAT_02123a44
      ;
      *(undefined4 *)(iVar4 + iVar6 * 0x44) = 4;
      iVar4 = iVar4 + iVar6 * 0x44;
      *(undefined4 *)(iVar4 + 4) = 0x44;
      *(undefined1 *)(iVar4 + 8) = uVar1;
      *(char *)(iVar4 + 9) = (char)uVar2;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(undefined1 *)(iVar4 + 10) =
           *(undefined1 *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x1f55);
      iVar6 = func_0x0219bb50();
      func_0x021a32a0(uVar2,iVar6 * 0x44 +
                            (*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
                            *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20)
                            + DAT_02123a44);
    }
    iVar6 = func_02121580();
    uVar2 = DAT_02123a34;
    if (iVar6 != 0) {
      *(undefined1 *)
       ((*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
        *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) + 0x19aa) = 0;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(undefined1 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x19ab) = 0;
      func_02122b14();
      uVar3 = DAT_02123a34;
      *(undefined4 *)
       ((*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
        *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) + 0x1950) = 7;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(undefined4 *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x1980) = 0;
    }
    break;
  case 7:
    func_021225ac(DAT_02123a38);
    uVar2 = GetSomeRacerIndex();
    if (uVar2 < *(byte *)((*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
                          *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) +
                         0x1f53)) {
      uVar1 = func_0x0219bb50();
      iVar6 = func_0x0219bb50();
      uVar5 = DAT_02123a34;
      iVar4 = (*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
              *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) + DAT_02123a44
      ;
      *(undefined4 *)(iVar4 + iVar6 * 0x44) = 5;
      iVar4 = iVar4 + iVar6 * 0x44;
      *(undefined4 *)(iVar4 + 4) = 0x44;
      *(undefined1 *)(iVar4 + 8) = uVar1;
      *(char *)(iVar4 + 9) = (char)uVar2;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(undefined1 *)(iVar4 + 10) =
           *(undefined1 *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x1f55);
      iVar6 = func_0x0219bb50();
      func_0x021a32a0(uVar2,iVar6 * 0x44 +
                            (*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
                            *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20)
                            + DAT_02123a44);
    }
    iVar6 = func_02121580();
    if (iVar6 != 0) {
      iVar6 = func_0x0219bb50();
      uVar5 = DAT_02123a34;
      uVar7 = *(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
              *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20;
      uVar2 = iVar6 * 0x44 + uVar7 + 0x1e48;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if (uVar2 >> uVar3 * 8 != 0 || uVar2 << uVar3 * -8 + 0x20 != 0) {
        *(undefined1 *)(uVar7 + 0x19aa) = 0;
        *(undefined1 *)
         ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x19ab) = 0;
        *(undefined4 *)
         ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x1950) = 8;
        *(undefined4 *)
         ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x1980) = 0;
      }
    }
    break;
  case 8:
    func_02122d74();
    break;
  case 9:
    func_02122bf0();
    break;
  case 10:
    break;
  case 0xb:
    func_021225ac(DAT_02123a38);
    iVar6 = func_0x0219bb68();
    uVar2 = DAT_02123a34;
    if (iVar6 < 2) {
      *(undefined4 *)
       ((*(uint *)(DAT_02123a34 & 0xfffffffc) >> (DAT_02123a34 & 3) * 8 |
        *(uint *)(DAT_02123a34 & 0xfffffffc) << (DAT_02123a34 & 3) * -8 + 0x20) + 0x1980) = 0;
      uVar3 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(undefined4 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x1950) = 0xc;
    }
    break;
  case 0xc:
  }
  return 0;
}

