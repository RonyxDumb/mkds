/* Decompiled C draft; module arm9; ROM address 020b6430. No matching claim. */
#include "types.h"
#include "deps/020b6430_func_020b6430.h"

undefined4 func_020b6430(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = GetCurrentInternalCourseId_0();
  if (0x22 < iVar1) {
    if (iVar1 < 0x31) {
      if ((iVar1 < 0x30) && (iVar1 != 0x28)) {
        return 0;
      }
    }
    else if (iVar1 != 0x32) {
      return 0;
    }
    goto LAB_020b64d8;
  }
  if (0x21 < iVar1) goto LAB_020b64d8;
  if (iVar1 < 2) {
    if (iVar1 != 1) {
      return 0;
    }
    goto LAB_020b64d8;
  }
  switch(iVar1) {
  case 0xb:
    goto LAB_020b64d8;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    break;
  case 0x10:
    goto LAB_020b64d8;
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
    goto LAB_020b64d8;
  case 0x18:
    goto LAB_020b64d8;
  case 0x19:
    goto LAB_020b64d8;
  case 0x1a:
    goto LAB_020b64d8;
  case 0x1b:
LAB_020b64d8:
    uVar2 = 1;
  }
  return uVar2;
}

