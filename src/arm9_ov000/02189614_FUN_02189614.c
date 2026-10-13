/* Decompiled C draft; module arm9_ov000; ROM address 02189614. No matching claim. */
#include "types.h"
#include "deps/02189614_FUN_02189614.h"

uint FUN_02189614(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1 + DAT_021896b0;
  uVar1 = FUN_0218954c();
  iVar2 = iVar2 + uVar1 * 0x24;
  if (((*(byte *)(param_1 + DAT_021896b4) & 0xf) == 0) ||
     ((*(byte *)(param_1 + DAT_021896b4) & 0xf) == 4)) {
    func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021896b8),(uint *)(uintptr_t)(iVar2 + 4),8);
    *(undefined1 *)(iVar2 + 3) = 8;
    *(undefined1 *)(iVar2 + 1) = 6;
    uVar1 = uVar1 + 1 & 0xff;
    iVar2 = iVar2 + 0x24;
  }
  if (((*(byte *)(param_1 + DAT_021896b4) & 0xf) == 0) ||
     ((*(byte *)(param_1 + DAT_021896b4) & 0xf) == 7)) {
    func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021896bc),(uint *)(uintptr_t)(iVar2 + 4),8);
    *(undefined1 *)(iVar2 + 3) = 8;
    *(undefined1 *)(iVar2 + 1) = 9;
    uVar1 = uVar1 + 1 & 0xff;
    iVar2 = iVar2 + 0x24;
  }
  if (((*(byte *)(param_1 + DAT_021896b4) & 0xf) == 0) ||
     ((*(byte *)(param_1 + DAT_021896b4) & 0xf) == 8)) {
    func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021896c0),(uint *)(uintptr_t)(iVar2 + 4),0xb);
    *(undefined1 *)(iVar2 + 3) = 0xb;
    *(undefined1 *)(iVar2 + 1) = 10;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return uVar1;
}

