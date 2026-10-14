/* Decompiled C draft; module arm9; ROM address 021499b4. No matching claim. */
#include "types.h"
#include "deps/021499b4_func_021499b4.h"

void func_021499b4(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  
  puVar3 = DAT_02149b08;
  uVar1 = DAT_02149b08[2];
  uVar2 = *DAT_02149b08;
  DAT_02149b08[2] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  puVar4 = DAT_02149b1c;
  if (0x30 < param_1) {
    if (param_1 < 0x51) {
      if (param_1 < 0x50) {
        if (param_1 == 0x40) {
          *DAT_02149b0c = 0x82;
        }
      }
      else {
        *DAT_02149b0c = 0x92;
        *puVar4 = 0x82;
      }
      goto switchD_02149a00_default;
    }
    if (param_1 < 0x61) {
      if (param_1 != 0x60) goto switchD_02149a00_default;
      *DAT_02149b0c = 0x8a;
      goto LAB_02149ae4;
    }
    if (param_1 != 0x70) goto switchD_02149a00_default;
    *DAT_02149b0c = 0x9a;
LAB_02149aa0:
    *DAT_02149b18 = 0x92;
LAB_02149aac:
    *DAT_02149b1c = 0x82;
    goto switchD_02149a00_default;
  }
  if (0x2f < param_1) goto LAB_02149aa0;
  if (0x10 < param_1) {
    if (param_1 != 0x20) goto switchD_02149a00_default;
LAB_02149ae4:
    *DAT_02149b18 = 0x82;
    goto switchD_02149a00_default;
  }
  if (0xf < param_1) goto LAB_02149aac;
  switch(param_1) {
  case 0:
    break;
  case 1:
    goto LAB_02149a74;
  case 2:
    *DAT_02149b10 = 0x82;
    break;
  case 3:
    *DAT_02149b10 = 0x8a;
LAB_02149a74:
    *DAT_02149b14 = 0x82;
  }
switchD_02149a00_default:
  GX_VRAMCNT_SetLCDC_(*DAT_02149b08);
  return;
}

