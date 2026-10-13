/* Decompiled C draft; module arm9_ov003; ROM address 021cfe40. No matching claim. */
#include "types.h"
#include "deps/021cfe40_FUN_021cfe40.h"

int FUN_021cfe40(uint param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  piVar1 = DAT_021cfecc;
  iVar2 = 0;
  uVar3 = 0;
  uVar4 = 0;
  do {
    if ((param_1 & 1 << (uVar4 & 0xff)) != 0) {
      iVar2 = (int)((uVar4 + 1) * 0x10000) >> 0x10;
      uVar3 = uVar3 + 1 & 0xffff;
    }
    uVar4 = (int)((uVar4 + 1) * 0x10000) >> 0x10;
  } while ((int)uVar4 < 0x10);
  if (1 < uVar3) {
    *(int *)(*DAT_021cfecc + 0x58) = DAT_021cfed0 * *(int *)(*DAT_021cfecc + 0x58) + DAT_021cfed4;
    uVar3 = (*(uint *)(*piVar1 + 0x58) & 0xff) * uVar3 * 0x100 >> 0x10;
    iVar2 = 0;
    do {
      if ((param_1 & 1) != 0) {
        if (uVar3 == 0) {
          return (iVar2 + 1) * 0x10000 >> 0x10;
        }
        uVar3 = uVar3 - 1 & 0xffff;
      }
      param_1 = (param_1 << 0xf) >> 0x10;
      iVar2 = (iVar2 + 1) * 0x10000 >> 0x10;
    } while (iVar2 < 0x10);
    iVar2 = 0;
  }
  return iVar2;
}

