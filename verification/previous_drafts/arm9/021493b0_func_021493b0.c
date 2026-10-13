/* Decompiled C draft; module arm9; ROM address 021493b0. No matching claim. */
#include "types.h"
#include "deps/021493b0_func_021493b0.h"

void func_021493b0(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  
  puVar3 = DAT_021494d8;
  uVar1 = DAT_021494d8[6];
  uVar2 = *DAT_021494d8;
  DAT_021494d8[6] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  puVar3 = DAT_021494e4;
  switch(param_1) {
  case 0:
    *DAT_021494e4 = *DAT_021494e4 & 0xbfff;
    break;
  case 1:
    *DAT_021494dc = 0x9b;
    *puVar3 = *puVar3 | 0x4000;
    break;
  case 2:
    goto LAB_02149424;
  case 3:
    *DAT_021494dc = 0x93;
LAB_02149424:
    puVar3 = DAT_021494e4;
    *DAT_021494e0 = 0x9b;
    *puVar3 = *puVar3 | 0x4000;
    break;
  case 4:
    *DAT_021494e8 = 0x9b;
    *puVar3 = *puVar3 | 0x4000;
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    goto LAB_02149450;
  case 9:
    break;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    *DAT_021494e8 = 0x93;
LAB_02149450:
    puVar3 = DAT_021494e4;
    *DAT_021494ec = 0x9b;
    *puVar3 = *puVar3 | 0x4000;
  }
  GX_VRAMCNT_SetLCDC_(*DAT_021494d8);
  return;
}

