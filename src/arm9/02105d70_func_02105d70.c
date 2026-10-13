/* Decompiled C draft; module arm9; ROM address 02105d70. No matching claim. */
#include "types.h"
#include "deps/02105d70_func_02105d70.h"

void func_02105d70(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar1 = func_0210d960();
  *(undefined4 *)(iRam02105e84 + 0x20) = 1;
  func_0210d970(10);
  if (*(uint *)(uRam02105e88 & 0xfffffffc) >> (uRam02105e88 & 3) * 8 != 0 ||
      *(uint *)(uRam02105e88 & 0xfffffffc) << (uRam02105e88 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uRam02105e88,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uRam02105e88,0,0x11);
  uVar8 = iRam02105e84 + 0xcU & 3;
  uVar2 = *(uint *)(iRam02105e84 + 0xcU & 0xfffffffc);
  if ((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) == 2) {
    return;
  }
  func_0210d9a0(uRam02105e8c,5);
  iVar5 = iRam02105e90;
  iVar6 = 0;
  if (*(char *)(iRam02105e84 + 0x16) == '\x01') {
    *(undefined1 *)(iRam02105e84 + 0x16) = 3;
  }
  do {
    uVar3 = func_0210d960();
    func_0212c620(iVar5,0,uVar3);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar6 < 0xc);
  uVar3 = func_0210d960();
  uVar2 = uRam02105e94;
  uVar8 = uRam02105e94 + 0xc & 3;
  uVar7 = *(uint *)(uRam02105e94 + 0xc & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  iVar5 = 0;
  if (0 < (int)(*(uint *)(uRam02105e94 & 0xfffffffc) >> (uRam02105e94 & 3) * 8 |
               *(uint *)(uRam02105e94 & 0xfffffffc) << (uRam02105e94 & 3) * -8 + 0x20)) {
    do {
      func_0212c620(uVar8,0,uVar3);
      uVar7 = uVar2 + 0x10 & 3;
      uVar4 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
      iVar5 = iVar5 + 1;
      uVar8 = uVar8 + (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20);
    } while (iVar5 < (int)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20));
  }
  func_0210d970(uVar1);
  return;
}

