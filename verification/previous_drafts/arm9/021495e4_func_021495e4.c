/* Decompiled C draft; module arm9; ROM address 021495e4. No matching claim. */
#include "types.h"
#include "deps/021495e4_func_021495e4.h"

void func_021495e4(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  puVar3 = DAT_021497cc;
  uVar1 = DAT_021497cc[4];
  uVar2 = *DAT_021497cc;
  DAT_021497cc[4] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  if (param_1 == 0) {
    *DAT_021497d0 = *DAT_021497d0 & (ushort)DAT_021497d4;
    goto switchD_02149644_default;
  }
  *DAT_021497d0 = *DAT_021497d0 & 0xcfff | 1;
  puVar6 = DAT_021497e4;
  puVar5 = DAT_021497e0;
  puVar4 = DAT_021497dc;
  switch(param_1) {
  case 1:
    goto LAB_021497a8;
  case 2:
    goto LAB_02149774;
  case 3:
    goto LAB_0214979c;
  case 4:
    goto LAB_0214974c;
  case 5:
    *DAT_021497d8 = 0x83;
    *puVar4 = 0x8b;
    break;
  case 6:
    goto LAB_02149768;
  case 7:
    goto LAB_02149790;
  case 8:
    *DAT_021497e0 = 0x83;
    break;
  case 9:
    *DAT_021497d8 = 0x83;
    *puVar5 = 0x8b;
    break;
  case 10:
    *DAT_021497e4 = 0x83;
    *puVar5 = 0x8b;
    break;
  case 0xb:
    *DAT_021497d8 = 0x83;
    puVar4 = DAT_021497e0;
    *puVar6 = 0x8b;
    *puVar4 = 0x93;
    break;
  case 0xc:
    *DAT_021497e0 = 0x8b;
LAB_0214974c:
    *DAT_021497dc = 0x83;
    break;
  case 0xd:
    *DAT_021497d8 = 0x83;
    puVar5 = DAT_021497e0;
    *puVar4 = 0x8b;
    *puVar5 = 0x93;
    break;
  case 0xe:
    *DAT_021497e0 = 0x93;
LAB_02149768:
    *DAT_021497dc = 0x8b;
LAB_02149774:
    *DAT_021497e4 = 0x83;
    break;
  case 0xf:
    *DAT_021497e0 = 0x9b;
LAB_02149790:
    *DAT_021497dc = 0x93;
LAB_0214979c:
    *DAT_021497e4 = 0x8b;
LAB_021497a8:
    *DAT_021497d8 = 0x83;
  }
switchD_02149644_default:
  GX_VRAMCNT_SetLCDC_(*DAT_021497cc);
  return;
}

