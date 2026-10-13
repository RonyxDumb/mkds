/* Decompiled C draft; module arm9; ROM address 02149b20. No matching claim. */
#include "types.h"
#include "deps/02149b20_func_02149b20.h"

void func_02149b20(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  puVar3 = DAT_02149db8;
  uVar1 = DAT_02149db8[1];
  uVar2 = *DAT_02149db8;
  DAT_02149db8[1] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  puVar6 = DAT_02149dd4;
  puVar5 = DAT_02149dc4;
  puVar4 = DAT_02149dbc;
  if (0x40 < param_1) {
    if (param_1 < 0x61) {
      if (param_1 < 0x60) {
        if (param_1 == 0x50) {
          *DAT_02149dcc = 0x91;
          *puVar6 = 0x81;
        }
        goto switchD_02149b64_default;
      }
      *DAT_02149dcc = 0x89;
LAB_02149d84:
      *DAT_02149dd0 = 0x81;
      goto switchD_02149b64_default;
    }
    if (param_1 != 0x70) goto switchD_02149b64_default;
    *DAT_02149dcc = 0x99;
LAB_02149d40:
    *DAT_02149dd0 = 0x91;
LAB_02149d4c:
    *DAT_02149dd4 = 0x81;
    goto switchD_02149b64_default;
  }
  if (0x3f < param_1) {
    *DAT_02149dcc = 0x81;
    goto switchD_02149b64_default;
  }
  if (0x20 < param_1) {
    if (param_1 != 0x30) goto switchD_02149b64_default;
    goto LAB_02149d40;
  }
  switch(param_1) {
  case 0:
    break;
  case 1:
    goto LAB_02149c9c;
  case 2:
    goto LAB_02149c68;
  case 3:
    goto LAB_02149c90;
  case 4:
    goto LAB_02149c40;
  case 5:
    goto LAB_02149ce0;
  case 6:
    goto LAB_02149c5c;
  case 7:
    goto LAB_02149c84;
  case 8:
    *DAT_02149dbc = 0x81;
    break;
  case 9:
    *DAT_02149dc8 = 0x81;
    *puVar4 = 0x89;
    break;
  case 10:
    *DAT_02149dc4 = 0x81;
    *puVar4 = 0x89;
    break;
  case 0xb:
    *DAT_02149dc8 = 0x81;
    puVar4 = DAT_02149dbc;
    *puVar5 = 0x89;
    *puVar4 = 0x91;
    break;
  case 0xc:
    *DAT_02149dbc = 0x89;
LAB_02149c40:
    *DAT_02149dc0 = 0x81;
    break;
  case 0xd:
    *DAT_02149dbc = 0x91;
LAB_02149ce0:
    puVar4 = DAT_02149dc0;
    *DAT_02149dc8 = 0x81;
    *puVar4 = 0x89;
    break;
  case 0xe:
    *DAT_02149dbc = 0x91;
LAB_02149c5c:
    *DAT_02149dc0 = 0x89;
LAB_02149c68:
    *DAT_02149dc4 = 0x81;
    break;
  case 0xf:
    *DAT_02149dbc = 0x99;
LAB_02149c84:
    *DAT_02149dc0 = 0x91;
LAB_02149c90:
    *DAT_02149dc4 = 0x89;
LAB_02149c9c:
    *DAT_02149dc8 = 0x81;
    break;
  case 0x10:
    goto LAB_02149d4c;
  case 0x11:
    break;
  case 0x12:
    break;
  case 0x13:
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    break;
  case 0x17:
    break;
  case 0x18:
    break;
  case 0x19:
    break;
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
    goto LAB_02149d84;
  }
switchD_02149b64_default:
  GX_VRAMCNT_SetLCDC_(*DAT_02149db8);
  return;
}

