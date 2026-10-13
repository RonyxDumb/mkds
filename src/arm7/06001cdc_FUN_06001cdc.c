/* Decompiled C draft; module arm7; ROM address 06001cdc. No matching claim. */
#include "types.h"
#include "deps/06001cdc_FUN_06001cdc.h"

void FUN_06001cdc(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_06000680();
  uVar3 = iVar1 + 0x154cU & 3;
  uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    return;
  }
  iVar1 = FUN_06000680();
  uVar3 = iVar1 + 0x154cU & 3;
  uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (*(short *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 1) {
    return;
  }
  uVar3 = (uint)*(ushort *)(param_1 + 0xc);
  if (DAT_06001e58 < (int)uVar3) {
    if (DAT_06001e5c < (int)uVar3) {
      if (uVar3 == DAT_06001e60) {
        FUN_06000d04(param_1);
        goto LAB_06001e48;
      }
    }
    else {
      if (DAT_06001e5c <= (int)uVar3) {
        FUN_06000f4c(param_1);
        goto LAB_06001e48;
      }
      if (uVar3 == 0x184) {
        FUN_0600166c(param_1);
        goto LAB_06001e48;
      }
    }
    goto switchD_06001d38_default;
  }
  if (DAT_06001e58 <= (int)uVar3) {
    FUN_060012c4(param_1);
    goto LAB_06001e48;
  }
  if (0x8d < uVar3) {
    if (uVar3 == 0x180) {
      FUN_06000e4c(param_1);
      goto LAB_06001e48;
    }
    goto switchD_06001d38_default;
  }
  switch(uVar3) {
  case 0x84:
    FUN_06000874(param_1);
    break;
  case 0x85:
    FUN_060008a8(param_1);
    break;
  case 0x86:
    FUN_06000b08(param_1);
    break;
  case 0x87:
    FUN_06000c9c(param_1);
    break;
  case 0x88:
    FUN_06000cd0(param_1);
    break;
  case 0x89:
  default:
switchD_06001d38_default:
    FUN_06001c94(param_1);
    break;
  case 0x8a:
    goto switchD_06001d38_default;
  case 0x8b:
    FUN_06001a7c(param_1);
    break;
  case 0x8c:
    FUN_06001c44(param_1);
    break;
  case 0x8d:
    FUN_06001acc(param_1);
  }
LAB_06001e48:
  FUN_06001c98(param_1);
  return;
}

