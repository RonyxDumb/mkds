/* Decompiled C draft; module arm9; ROM address 02106c64. No matching claim. */
#include "types.h"
#include "deps/02106c64_func_02106c64.h"

void func_02106c64(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  *(undefined4 *)(iRam02106da0 + 0xc) = 2;
  uVar1 = func_0210dc48();
  func_0210d590(uRam02106da4,uVar1);
  NNS_SndPlayerSetTrackMute(uRam02106da8,uRam02106dac,0);
  func_0212c6f0(uRam02106db0,0);
  if (*(uint *)((uint)puRam02106db4 & 0xfffffffc) >> ((uint)puRam02106db4 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam02106db4 & 0xfffffffc) << ((uint)puRam02106db4 & 3) * -8 + 0x20 != 0) {
    uVar7 = iRam02106da0 + 0xcU & 3;
    uVar2 = *(uint *)(iRam02106da0 + 0xcU & 0xfffffffc);
    if ((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) == 1) {
      func_0210d5c0(uRam02106da4);
      uVar7 = iRam02106db8 + 4U & 3;
      uVar2 = *(uint *)(iRam02106db8 + 4U & 0xfffffffc);
      func_0212c678(uRam02106da8,(int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) >> 0xc);
      func_0212c494(uRam02106da8,300);
      func_0210faac();
    }
    *puRam02106db4 = 0;
  }
  iVar4 = iRam02106dbc;
  uVar7 = iRam02106dbc + 4U & 3;
  uVar2 = *(uint *)(iRam02106dbc + 4U & 0xfffffffc);
  *(undefined1 *)(iRam02106da0 + 0x17) = 0;
  if ((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) == 2) {
    func_0210d9a0(iVar4,3);
  }
  iVar5 = 0;
  iVar4 = iRam02106dc0;
  do {
    uVar1 = func_0210dc48();
    func_0212c6f0(iVar4,uVar1);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar5 < 0xc);
  uVar1 = func_0210dc48();
  uVar2 = uRam02106dc4;
  uVar7 = uRam02106dc4 + 0xc & 3;
  uVar6 = *(uint *)(uRam02106dc4 + 0xc & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  iVar4 = 0;
  if (0 < (int)(*(uint *)(uRam02106dc4 & 0xfffffffc) >> (uRam02106dc4 & 3) * 8 |
               *(uint *)(uRam02106dc4 & 0xfffffffc) << (uRam02106dc4 & 3) * -8 + 0x20)) {
    do {
      func_0212c6f0(uVar7,uVar1);
      uVar6 = uVar2 + 0x10 & 3;
      uVar3 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
      iVar4 = iVar4 + 1;
      uVar7 = uVar7 + (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    } while (iVar4 < (int)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20));
    return;
  }
  return;
}

