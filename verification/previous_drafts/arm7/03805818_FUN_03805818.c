/* Decompiled C draft; module arm7; ROM address 03805818. No matching claim. */
#include "types.h"
#include "deps/03805818_FUN_03805818.h"

void FUN_03805818(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = (uVar2 << 0x12) >> 0x1a;
  switch(uVar1) {
  case 0:
    goto LAB_038058c0;
  case 1:
    goto LAB_038058c0;
  case 2:
    goto LAB_038058c0;
  case 3:
    goto LAB_038058c0;
  case 4:
    goto LAB_038058c0;
  case 5:
    goto LAB_038058c0;
  case 6:
    goto LAB_038058c0;
  case 7:
    goto LAB_038058c0;
  case 8:
    goto LAB_038058e4;
  case 9:
LAB_038058e4:
    if ((int)(uVar2 << 0x11) < 0) {
      *param_1 = uVar2 & 0xffffc0ff | (uVar1 + 0x18 & 0x3f) << 8;
      return;
    }
    return;
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
    goto LAB_038058c0;
  case 0x11:
LAB_038058c0:
    if ((int)(uVar2 << 0x11) < 0) {
      *param_1 = uVar2 & 0xffffc0ff | (uVar1 + 0x12 & 0x3f) << 8;
      return;
    }
    return;
  case 0x12:
    goto LAB_03805908;
  case 0x13:
    goto LAB_03805908;
  case 0x14:
    goto LAB_03805908;
  case 0x15:
    goto LAB_03805908;
  case 0x16:
    goto LAB_03805908;
  case 0x17:
    goto LAB_03805908;
  case 0x18:
    goto LAB_03805908;
  case 0x19:
    goto LAB_03805908;
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
    goto LAB_03805908;
  case 0x21:
    goto LAB_03805908;
  case 0x22:
    goto LAB_03805908;
  case 0x23:
LAB_03805908:
    *param_1 = uVar2 | 0x4000;
    return;
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffbfff;
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffc0ff;
  return;
}

