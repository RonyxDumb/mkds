/* Decompiled C draft; module arm9; ROM address 0210449c. No matching claim. */
#include "types.h"
#include "deps/0210449c_func_0210449c.h"

void func_0210449c(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 0x2cU & 3;
  uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) - 1;
  uVar5 = param_1 + 0x2cU & 3;
  uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  if (uVar3 >> uVar5 * 8 != 0 || uVar3 << uVar5 * -8 + 0x20 != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x24) = uRam02104590;
  iVar1 = func_0203c5e4();
  if (iVar1 != 0) {
    return;
  }
  uVar5 = uRam02104598;
  if (*(uint *)(uRam02104594 & 0xfffffffc) >> (uRam02104594 & 3) * 8 == 0 &&
      *(uint *)(uRam02104594 & 0xfffffffc) << (uRam02104594 & 3) * -8 + 0x20 == 0) {
    uVar5 = 0xee;
  }
  if (uVar5 == 1) {
    return;
  }
  if (((*(uint *)(uRam0210459c & 0xfffffffc) >> (uRam0210459c & 3) * 8 |
       *(uint *)(uRam0210459c & 0xfffffffc) << (uRam0210459c & 3) * -8 + 0x20) & 1) == 0) {
    return;
  }
  func_02108ea0(0);
  uVar2 = GetSomeSndPlayer();
  uVar3 = iRam021045a0 + 0xcU & 3;
  uVar4 = *(uint *)(iRam021045a0 + 0xcU & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uVar2,0);
  }
  if (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 != 0 ||
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uVar2,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uVar2,0,uVar5 & 0xffff);
  return;
}

