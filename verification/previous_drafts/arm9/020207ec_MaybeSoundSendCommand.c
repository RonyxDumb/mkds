/* Decompiled C draft; module arm9; ROM address 020207ec. No matching claim. */
#include "types.h"
#include "deps/020207ec_MaybeSoundSendCommand.h"

void MaybeSoundSendCommand
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  
  iVar1 = Sound_AllocateCommand(1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 4) = param_1;
    *(undefined4 *)(iVar1 + 8) = param_2;
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    *(undefined4 *)(iVar1 + 0x10) = param_4;
    *(undefined4 *)(iVar1 + 0x14) = param_5;
    func_020213a4();
    return;
  }
  return;
}

