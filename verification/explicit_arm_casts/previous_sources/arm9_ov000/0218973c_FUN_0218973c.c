/* Decompiled C draft; module arm9_ov000; ROM address 0218973c. No matching claim. */
#include "types.h"
#include "deps/0218973c_FUN_0218973c.h"

undefined1 FUN_0218973c(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_02188584(0x10);
  func_0x0214d018(0,iVar2 + DAT_021897a4,DAT_021897a8);
  if (param_1 == 0) {
    uVar1 = FUN_021896c4(iVar2);
    *(undefined1 *)(iVar2 + DAT_021897ac) = uVar1;
  }
  else if (param_1 == 1) {
    uVar1 = FUN_021894e4(*(undefined1 *)(iVar2 + DAT_021897b0),iVar2 + DAT_021897b4,
                         iVar2 + DAT_021897a4,iVar2 + DAT_021897b8);
    *(undefined1 *)(iVar2 + DAT_021897ac) = uVar1;
  }
  else if (param_1 == 2) {
    uVar1 = FUN_02189614(iVar2);
    *(undefined1 *)(iVar2 + DAT_021897ac) = uVar1;
  }
  return *(undefined1 *)(iVar2 + DAT_021897ac);
}

