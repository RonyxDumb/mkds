/* Decompiled C draft; module arm9_ov000; ROM address 021a8994. No matching claim. */
#include "types.h"
#include "deps/021a8994_FUN_021a8994.h"

uint FUN_021a8994(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar2 = FUN_021a8a80();
  if (iVar2 == 0) {
    if ((*(ushort *)(param_1 + 0x70) & 0x40) != 0) {
      uVar4 = 0x20;
    }
    if ((*(char *)(param_1 + 0x73) == '\x01') || ((*(ushort *)(param_1 + 0x70) & 4) != 0)) {
      uVar3 = func_0x0200fca0();
      iVar2 = FUN_021a8960(param_1);
      if (0 < iVar2) {
        uVar4 = uVar4 | 1;
      }
      iVar2 = FUN_021a8118(param_1);
      if (0 < iVar2) {
        uVar4 = uVar4 | 8;
      }
      func_0x0200fcb4(uVar3);
    }
    bVar1 = true;
    if ((*(char *)(param_1 + 0x73) != '\0') && (*(char *)(param_1 + 0x73) != '\x04')) {
      bVar1 = false;
    }
    if (bVar1) {
      if ((((*(ushort *)(param_1 + 0x70) & 4) != 0) && (*(char *)(param_1 + 8) != '\x04')) &&
         ((uVar4 & 1) == 0)) {
        *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x70) & 0xfff9;
      }
      if (((*(ushort *)(param_1 + 0x70) & 2) == 0) && ((*(ushort *)(param_1 + 0x70) & 4) == 0)) {
        uVar4 = uVar4 | 0x40;
      }
    }
    return uVar4;
  }
  return 0x80;
}

