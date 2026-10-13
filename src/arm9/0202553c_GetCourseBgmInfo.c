/* Decompiled C draft; module arm9; ROM address 0202553c. No matching claim. */
#include "types.h"
#include "deps/0202553c_GetCourseBgmInfo.h"

int GetCourseBgmInfo(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0x36;
  switch(param_1) {
  case 0:
    break;
  case 1:
    iVar3 = 9;
    break;
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
    iVar3 = 0xc;
    break;
  case 10:
    iVar3 = 0x15;
    break;
  case 0xb:
    iVar3 = 0xd;
    break;
  case 0xc:
    iVar3 = 0x24;
    break;
  case 0xd:
    iVar3 = 0x19;
    break;
  case 0xe:
    iVar3 = 8;
    break;
  case 0xf:
    iVar3 = 0x16;
    break;
  case 0x10:
    iVar3 = 0xe;
    break;
  case 0x11:
    iVar3 = 0x21;
    break;
  case 0x12:
    iVar3 = 0x14;
    break;
  case 0x13:
    iVar3 = 0x10;
    break;
  case 0x14:
    iVar3 = 7;
    break;
  case 0x15:
    break;
  case 0x16:
    iVar3 = 0xb;
    break;
  case 0x17:
    iVar3 = 0x1d;
    break;
  case 0x18:
    iVar3 = 0x1b;
    break;
  case 0x19:
    iVar3 = 0x22;
    break;
  case 0x1a:
    iVar3 = 0x13;
    break;
  case 0x1b:
    iVar3 = 0x1f;
    break;
  case 0x1c:
    iVar3 = 0xf;
    break;
  case 0x1d:
    iVar3 = 0x23;
    break;
  case 0x1e:
    iVar3 = 0x1e;
    break;
  case 0x1f:
    iVar3 = 10;
    break;
  case 0x20:
    iVar3 = 0x25;
    break;
  case 0x21:
    iVar3 = 0x20;
    break;
  case 0x22:
    iVar3 = 0x11;
    break;
  case 0x23:
    iVar3 = 0x17;
    break;
  case 0x24:
    iVar3 = 0x1c;
    break;
  case 0x25:
    iVar3 = 0x1a;
    break;
  case 0x26:
    iVar3 = 0x12;
    break;
  case 0x27:
    iVar3 = 0x18;
    break;
  case 0x28:
    iVar3 = 0x26;
    break;
  case 0x29:
    goto LAB_02025724;
  case 0x2a:
    goto LAB_02025724;
  case 0x2b:
    goto LAB_02025724;
  case 0x2c:
    goto LAB_02025724;
  case 0x2d:
    goto LAB_02025724;
  case 0x2e:
    goto LAB_02025724;
  case 0x2f:
LAB_02025724:
    iVar3 = 0x27;
    break;
  case 0x30:
    goto LAB_0202572c;
  case 0x31:
    goto LAB_0202572c;
  case 0x32:
    goto LAB_0202572c;
  case 0x33:
LAB_0202572c:
    iVar3 = 0x28;
    break;
  case 0x34:
    iVar3 = 0x2a;
    break;
  case 0x35:
    iVar3 = 0x33;
  }
  if (param_2 != (undefined1 *)0x0) {
    iVar2 = DAT_02025778 + iVar3 * 4;
    uVar1 = *(undefined1 *)(iVar2 + 1);
    *param_2 = *(undefined1 *)(DAT_02025778 + iVar3 * 4);
    param_2[1] = uVar1;
    uVar1 = *(undefined1 *)(iVar2 + 3);
    param_2[2] = *(undefined1 *)(iVar2 + 2);
    param_2[3] = uVar1;
  }
  return iVar3;
}

