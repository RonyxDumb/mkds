/* Decompiled C draft; module arm7; ROM address 06018064. No matching claim. */
#include "types.h"
#include "deps/06018064_FUN_06018064.h"

undefined4 FUN_06018064(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = *(uint *)(DAT_060181e0 & 0xfffffffc) >> (DAT_060181e0 & 3) * 8 |
          *(uint *)(DAT_060181e0 & 0xfffffffc) << (DAT_060181e0 & 3) * -8 + 0x20;
  iVar4 = uVar3 + DAT_060181e4;
  if (*(short *)(uVar3 + 0x34c) == 0x40) {
    iVar2 = FUN_0600a578(param_1 + 0x1e,uVar3 + 0x3a8);
    if ((iVar2 == 0) || (iVar2 = FUN_0600a578(param_1 + 0x24,uVar3 + 0x3c6), iVar2 == 0)) {
      uVar1 = 1;
    }
    else {
      if ((1 << (*(ushort *)(uVar3 + 0x3ae) & 0xff) & 0xffffU & (uint)*(ushort *)(param_1 + 0x2e))
          == 0) {
        *(undefined2 *)(iVar4 + 6) = 0;
      }
      else {
        *(undefined2 *)(iVar4 + 6) = 0x2000;
      }
      if (((*DAT_060181e8 & 0x8000) != 0) &&
         (*(short *)(&DAT_04804004 + (DAT_060181ec & *DAT_060181e8) * 2) != 0)) {
        *(ushort *)(iVar4 + 6) = *(ushort *)(iVar4 + 6) | 0x4000;
      }
      FUN_0600ea58(*(undefined2 *)(uVar3 + 0x3cc));
      *(short *)(param_1 + 6) = *(short *)(param_1 + 0x10) + -0x1c;
      *(short *)(param_1 + -4) = (short)DAT_060181f0;
      *(short *)(param_1 + -2) = (short)(*(ushort *)(param_1 + 6) + 0x31 >> 1);
      iVar2 = 0;
      for (uVar3 = (uint)*(ushort *)(param_1 + 0x2e); uVar3 != 0; uVar3 = (uVar3 << 0xf) >> 0x10) {
        if ((uVar3 & 1) != 0) {
          iVar2 = iVar2 + 1;
        }
      }
      *(ushort *)(param_1 + 8) =
           *(ushort *)(param_1 + 8) |
           *(ushort *)(iVar4 + 6) | (ushort)((int)(*DAT_060181e8 & 0x8000) >> 4) |
           (ushort)((int)(*DAT_060181f4 & 0x8000) >> 3);
      *(short *)(param_1 + 10) =
           *(short *)(param_1 + 0xc) +
           (short)(iVar2 * (*(ushort *)(param_1 + 0x2c) + 10) + 0xfc >> 4);
      FUN_0600f19c((*(uint *)(DAT_060181e0 & 0xfffffffc) >> (DAT_060181e0 & 3) * 8 |
                   *(uint *)(DAT_060181e0 & 0xfffffffc) << (DAT_060181e0 & 3) * -8 + 0x20) + 0x188);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

