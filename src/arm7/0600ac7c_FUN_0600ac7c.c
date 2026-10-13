/* Decompiled C draft; module arm7; ROM address 0600ac7c. No matching claim. */
#include "types.h"
#include "deps/0600ac7c_FUN_0600ac7c.h"

undefined4 FUN_0600ac7c(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_0600ace0;
  uVar2 = *(uint *)(DAT_0600acdc & 0xfffffffc) >> (DAT_0600acdc & 3) * 8 |
          *(uint *)(DAT_0600acdc & 0xfffffffc) << (DAT_0600acdc & 3) * -8 + 0x20;
  if (param_1 == DAT_0600ace0) {
    *(undefined2 *)(uVar2 + 0x338) = 0xff;
    *(short *)(uVar2 + 0x3d0) = (short)iVar1;
  }
  else {
    uVar3 = thunk_FUN_03806d38(param_1 * (uint)*(ushort *)(uVar2 + 0x3b2),100);
    if (0x10000 < uVar3) {
      return 5;
    }
    *(short *)(uVar2 + 0x338) = (short)param_1;
    *(short *)(uVar2 + 0x3d0) = (short)uVar3;
  }
  return 0;
}

