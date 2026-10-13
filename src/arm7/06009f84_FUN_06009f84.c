/* Decompiled C draft; module arm7; ROM address 06009f84. No matching claim. */
#include "types.h"
#include "deps/06009f84_FUN_06009f84.h"

void FUN_06009f84(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0600a3b0 & 0xfffffffc) >> (DAT_0600a3b0 & 3) * 8 |
          *(uint *)(DAT_0600a3b0 & 0xfffffffc) << (DAT_0600a3b0 & 3) * -8 + 0x20;
  FUN_06009ecc();
  FUN_06009690((uint)*DAT_0600a3b4 + (uint)*DAT_0600a3b4 * 0x100,*DAT_0600a3b4);
  *(undefined2 *)(uVar1 + 0x3c0) = 1;
  if ((int)((uint)*(ushort *)(uVar1 + 0x33a) << 0x1d) < 0) {
    *(ushort *)(uVar1 + 0x3c0) = *(ushort *)(uVar1 + 0x3c0) | 0x20;
  }
  if (*(short *)(uVar1 + 0x334) != 0) {
    *(ushort *)(uVar1 + 0x3c0) = *(ushort *)(uVar1 + 0x3c0) | 0x10;
  }
  *(undefined2 *)(uVar1 + 0x356) = 0;
  *DAT_0600a3b8 = 0x8000;
  *DAT_0600a3c0 = (short)DAT_0600a3bc;
  *DAT_0600a3c4 = 0;
  *DAT_0600a3c8 = 0;
  *DAT_0600a3cc = 0xf;
  FUN_0600e32c();
  FUN_06018554();
  FUN_06012edc();
  FUN_060155bc();
  *DAT_0600a3d0 = 0x8000;
  *DAT_0600a3d4 = (short)DAT_0600a3bc;
  *DAT_0600a3dc = (short)DAT_0600a3d8;
  if ((*(ushort *)
        ((*(uint *)(DAT_0600a3b0 & 0xfffffffc) >> (DAT_0600a3b0 & 3) * 8 |
         *(uint *)(DAT_0600a3b0 & 0xfffffffc) << (DAT_0600a3b0 & 3) * -8 + 0x20) + 0x690) & 8) == 0)
  {
    *DAT_0600a3e0 = 0;
  }
  else {
    *DAT_0600a3e0 = 0x400;
  }
  *DAT_0600a3e4 = 0;
  *DAT_0600a3e8 = 0;
                    /* WARNING: Could not recover jumptable at 0x0600a0a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (*(ushort *)(uVar1 + 0x350) < 5) {
    (*(code *)((uint)*(ushort *)(uVar1 + 0x350) * 4 + 0x600a0b0))();
    return;
  }
  *DAT_0600a444 = 0;
  FUN_0600ac28();
  *DAT_0600a42c = 2;
  if (*(short *)(uVar1 + 0x352) == 1) {
    FUN_0600ae00();
  }
  FUN_0600f0ec();
  return;
}

