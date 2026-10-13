/* Decompiled C draft; module arm9_ov000; ROM address 021897bc. No matching claim. */
#include "types.h"
#include "deps/021897bc_FUN_021897bc.h"

byte FUN_021897bc(void)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  
  iVar1 = FUN_02188584(0x10);
  bVar3 = 9;
  uVar2 = FUN_021a5bfc();
  switch(uVar2) {
  case 3:
    bVar3 = *(byte *)(iVar1 + DAT_02189858);
    if (((uint)*(byte *)(iVar1 + DAT_0218985c) << 0x18) >> 0x1e == 1) {
      *(undefined1 *)(iVar1 + (uint)*(byte *)(iVar1 + DAT_02189860) * 4 + data_ov000_02189864) = 0;
      bVar3 = 7;
    }
    else if ((2 < bVar3) && (bVar3 < 6)) {
      FUN_02189d2c(bVar3);
    }
    break;
  case 6:
    FUN_021a6024();
    break;
  case 9:
    FUN_021a5db0();
    break;
  case 0xb:
    FUN_02188508(0);
    bVar3 = 0x11;
    break;
  case 0xc:
    FUN_021a5c24();
    FUN_02188508(4);
    bVar3 = 0x11;
  }
  return bVar3;
}

