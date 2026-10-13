/* Decompiled C draft; module arm7; ROM address 03805584. No matching claim. */
#include "types.h"
#include "deps/03805584_FUN_03805584.h"

void FUN_03805584(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_038056b8;
  if (param_3 != 0) {
    return;
  }
  uVar1 = ((param_2 & 0x7f00) << 8) >> 0x10;
  switch(uVar1) {
  case 0:
    goto LAB_03805650;
  case 1:
    goto LAB_03805650;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    break;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    goto LAB_03805650;
  case 0x11:
    goto LAB_03805650;
  case 0x12:
    goto LAB_03805650;
  case 0x13:
    goto LAB_03805650;
  case 0x14:
    goto LAB_03805650;
  case 0x15:
    goto LAB_03805650;
  case 0x16:
    goto LAB_03805650;
  case 0x17:
    goto LAB_03805650;
  case 0x18:
    goto LAB_03805650;
  case 0x19:
    goto LAB_03805650;
  case 0x1a:
    break;
  case 0x1b:
    break;
  case 0x1c:
    break;
  case 0x1d:
    break;
  case 0x1e:
    break;
  case 0x1f:
    break;
  case 0x20:
    break;
  case 0x21:
    break;
  case 0x22:
    break;
  case 0x23:
    goto LAB_03805650;
  case 0x24:
    goto LAB_03805650;
  case 0x25:
    goto LAB_03805650;
  case 0x26:
    goto LAB_03805650;
  case 0x27:
    goto LAB_03805650;
  case 0x28:
    goto LAB_03805650;
  case 0x29:
LAB_03805650:
    uVar2 = DAT_038056b8 + 0x1d4U & 3;
    uVar4 = *(uint *)(DAT_038056b8 + 0x1d4U & 0xfffffffc);
    if (uVar4 >> uVar2 * 8 != 0 || uVar4 << uVar2 * -8 + 0x20 != 0) {
      FUN_03805544(uVar1,3);
      return;
    }
    *(undefined4 *)(DAT_038056b8 + 0x1d4) = 1;
    *(short *)(DAT_038056bc + 0xd8) = (short)((param_2 & 0x7f00) >> 8);
    iVar3 = FUN_037f9854(iVar3,0,0);
    if (iVar3 != 0) {
      return;
    }
    FUN_03805544(uVar1,4);
    return;
  }
  FUN_03805544(uVar1,1);
  return;
}

