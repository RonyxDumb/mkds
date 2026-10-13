/* Decompiled C draft; module arm9; ROM address 02105ec0. No matching claim. */
#include "types.h"
#include "deps/02105ec0_func_02105ec0.h"

void func_02105ec0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if ((*psRam02105fa8 == 2) && (iVar3 = GetCurrentSceneId(), iVar3 == 6)) {
    return;
  }
  uVar1 = uRam02105fb0;
  iVar3 = iRam02105fac;
  *(undefined4 *)(iRam02105fac + 0xc) = 0;
  *(undefined4 *)(iVar3 + 8) = 0;
  func_0210d570(uVar1,1);
  func_0210d9a0(uRam02105fb4,0);
  iVar5 = 0;
  iVar3 = iRam02105fb8;
  do {
    func_0212c6f0(iVar3,0);
    uVar2 = uRam02105fbc;
    iVar5 = iVar5 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar5 < 0xc);
  iVar3 = 0;
  uVar7 = uRam02105fbc + 0xc & 3;
  uVar6 = *(uint *)(uRam02105fbc + 0xc & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (0 < (int)(*(uint *)(uRam02105fbc & 0xfffffffc) >> (uRam02105fbc & 3) * 8 |
               *(uint *)(uRam02105fbc & 0xfffffffc) << (uRam02105fbc & 3) * -8 + 0x20)) {
    do {
      func_0212c6f0(uVar7,0);
      uVar6 = uVar2 + 0x10 & 3;
      uVar4 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
      iVar3 = iVar3 + 1;
      uVar7 = uVar7 + (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    } while (iVar3 < (int)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20));
  }
  uVar1 = uRam02105fc4;
  *puRam02105fc0 = 0;
  func_0212c6f0(uVar1);
  func_0212c6f0(uRam02105fc8,0);
  return;
}

