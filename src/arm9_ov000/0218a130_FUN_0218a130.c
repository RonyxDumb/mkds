/* Decompiled C draft; module arm9_ov000; ROM address 0218a130. No matching claim. */
#include "types.h"
#include "deps/0218a130_FUN_0218a130.h"

undefined4 FUN_0218a130(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_02188584(1);
  iVar2 = FUN_021874c0();
  if (iVar2 == 0) {
    return 0xe;
  }
  uVar3 = FUN_021884d8(*(undefined1 *)(param_1 + DAT_0218a188));
  if (*(byte *)(iVar1 + 0x15) == uVar3) {
    uVar4 = FUN_02187484();
    *(undefined4 *)(iVar1 + 0x10) = uVar4;
  }
  FUN_02188068();
  if (iVar2 != 0xb) {
    *(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + DAT_0218a18c) * 4 + DAT_0218a190) = 1;
    return 0xb;
  }
  return 0xf;
}

