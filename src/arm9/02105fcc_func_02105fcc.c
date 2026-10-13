/* Decompiled C draft; module arm9; ROM address 02105fcc. No matching claim. */
#include "types.h"
#include "deps/02105fcc_func_02105fcc.h"

void func_02105fcc(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if ((*psRam021060b8 == 2) && (iVar2 = GetCurrentSceneId(), iVar2 == 6)) {
    return;
  }
  uVar3 = uRam021060c0;
  iVar2 = iRam021060bc;
  *(undefined4 *)(iRam021060bc + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  func_0210d58c(uVar3);
  func_0210d9a0(uRam021060c4,4);
  iVar5 = 0;
  iVar2 = iRam021060c8;
  do {
    uVar3 = func_0210d960();
    func_0212c6f0(iVar2,uVar3);
    iVar5 = iVar5 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar5 < 0xc);
  uVar3 = func_0210d960();
  uVar1 = uRam021060cc;
  uVar7 = uRam021060cc + 0xc & 3;
  uVar6 = *(uint *)(uRam021060cc + 0xc & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  iVar2 = 0;
  if (0 < (int)(*(uint *)(uRam021060cc & 0xfffffffc) >> (uRam021060cc & 3) * 8 |
               *(uint *)(uRam021060cc & 0xfffffffc) << (uRam021060cc & 3) * -8 + 0x20)) {
    do {
      func_0212c6f0(uVar7,uVar3);
      uVar6 = uVar1 + 0x10 & 3;
      uVar4 = *(uint *)(uVar1 + 0x10 & 0xfffffffc);
      iVar2 = iVar2 + 1;
      uVar7 = uVar7 + (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    } while (iVar2 < (int)(*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20));
  }
  func_0212c6f0(uRam021060d0,0xd);
  func_0212c6f0(uRam021060d4,0xd);
  *puRam021060d8 = 0;
  return;
}

