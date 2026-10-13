/* Decompiled C draft; module arm9; ROM address 02106efc. No matching claim. */
#include "types.h"
#include "deps/02106efc_func_02106efc.h"

void func_02106efc(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = uRam02106ff0;
  *(undefined4 *)(iRam02106fec + 0xc) = 1;
  func_0210d65c(uVar2);
  uVar1 = uRam02106ff4 & 3;
  uVar4 = *(uint *)(uRam02106ff4 & 0xfffffffc);
  *(undefined4 *)(iRam02106ff8 + 8) = 1;
  if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02106ffc,0x14);
  }
  iVar3 = iRam02107004;
  uVar4 = *(uint *)(uRam02107000 & 0xfffffffc) >> (uRam02107000 & 3) * 8 |
          *(uint *)(uRam02107000 & 0xfffffffc) << (uRam02107000 & 3) * -8 + 0x20;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != 0x22) {
    return;
  }
  iVar6 = 7;
  do {
    func_0212c6f0(iVar3 + iVar6 * 4,0);
    uVar1 = uRam02106ffc;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xc);
  if (((*(uint *)(uRam02107008 & 0xfffffffc) >> (uRam02107008 & 3) * 8 |
       *(uint *)(uRam02107008 & 0xfffffffc) << (uRam02107008 & 3) * -8 + 0x20) & 1) != 0) {
    uVar4 = iRam0210700c + 0xcU & 3;
    uVar5 = *(uint *)(iRam0210700c + 0xcU & 0xfffffffc);
    if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
      if (*(uint *)(uRam02106ffc & 0xfffffffc) >> (uRam02106ffc & 3) * 8 != 0 ||
          *(uint *)(uRam02106ffc & 0xfffffffc) << (uRam02106ffc & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uRam02106ffc,0);
      }
      if (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 != 0 ||
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar1,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar1,0,0x1c0);
      return;
    }
    return;
  }
  return;
}

