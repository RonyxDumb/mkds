/* Decompiled C draft; module arm9_ov000; ROM address 021896c4. No matching claim. */
#include "types.h"
#include "deps/021896c4_FUN_021896c4.h"

uint FUN_021896c4(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1 + DAT_02189708;
  uVar1 = FUN_0218954c();
  iVar2 = iVar2 + uVar1 * 0x24;
  if (((*(byte *)(param_1 + DAT_0218970c) & 0xf) == 0) ||
     ((*(byte *)(param_1 + DAT_0218970c) & 0xf) == 6)) {
    func_0x0214d1fc(DAT_02189710,iVar2 + 4,8);
    *(undefined1 *)(iVar2 + 3) = 8;
    *(undefined1 *)(iVar2 + 1) = 8;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return uVar1;
}

