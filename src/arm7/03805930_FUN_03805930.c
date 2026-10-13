/* Decompiled C draft; module arm7; ROM address 03805930. No matching claim. */
#include "types.h"
#include "deps/03805930_FUN_03805930.h"

void FUN_03805930(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  switch((uVar1 << 0x12) >> 0x1a) {
  case 0:
    goto LAB_038059d8;
  case 1:
    goto LAB_038059d8;
  case 2:
    goto LAB_038059d8;
  case 3:
    goto LAB_038059d8;
  case 4:
    goto LAB_038059d8;
  case 5:
    goto LAB_038059d8;
  case 6:
    goto LAB_038059d8;
  case 7:
    goto LAB_038059d8;
  case 8:
    goto LAB_038059d8;
  case 9:
    goto LAB_038059d8;
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
    goto LAB_038059d8;
  case 0x11:
LAB_038059d8:
    *param_1 = uVar1 & 0xffffbfff;
    return;
  case 0x12:
    goto LAB_038059e4;
  case 0x13:
    goto LAB_038059e4;
  case 0x14:
    goto LAB_038059e4;
  case 0x15:
    goto LAB_038059e4;
  case 0x16:
    goto LAB_038059e4;
  case 0x17:
    goto LAB_038059e4;
  case 0x18:
    goto LAB_038059e4;
  case 0x19:
    goto LAB_038059e4;
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
    goto LAB_03805a10;
  case 0x21:
LAB_03805a10:
    *param_1 = uVar1 | 0x4000;
    uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    *param_1 = uVar1 & 0xffffc0ff | (((uVar1 << 0x12) >> 0x1a) - 0x18 & 0x3f) << 8;
    return;
  case 0x22:
    goto LAB_038059e4;
  case 0x23:
LAB_038059e4:
    *param_1 = uVar1 | 0x4000;
    uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
    *param_1 = uVar1 & 0xffffc0ff | (((uVar1 << 0x12) >> 0x1a) - 0x12 & 0x3f) << 8;
    return;
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffbfff;
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffc0ff;
  return;
}

