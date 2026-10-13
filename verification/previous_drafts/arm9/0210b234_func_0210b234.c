/* Decompiled C draft; module arm9; ROM address 0210b234. No matching claim. */
#include "types.h"
#include "deps/0210b234_func_0210b234.h"

void func_0210b234(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
    return;
  }
  iVar2 = func_0210bafc(param_2,param_3,param_4);
  if (iVar2 != iRam0210b29c) {
    uVar3 = *(uint *)(uRam0210b2a0 & 0xfffffffc) >> (uRam0210b2a0 & 3) * 8 |
            *(uint *)(uRam0210b2a0 & 0xfffffffc) << (uRam0210b2a0 & 3) * -8 + 0x20;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 0x1d) {
      iVar2 = iRam0210b2a4;
    }
    DriverContext_MaybeQueuePlaySfx(param_1,iVar2,0x7f,0);
    return;
  }
  return;
}

