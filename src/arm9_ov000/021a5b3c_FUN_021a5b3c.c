/* Decompiled C draft; module arm9_ov000; ROM address 021a5b3c. No matching claim. */
#include "types.h"
#include "deps/021a5b3c_FUN_021a5b3c.h"

uint FUN_021a5b3c(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  func_0x0200fca0();
  iVar1 = *DAT_021a5bc8;
  uVar3 = *(uint *)(iVar1 + DAT_021a5bcc);
  if (iVar1 == 0) {
    func_0x0200fcb4();
    return 0;
  }
  uVar2 = 0;
  if (((param_1 & DAT_021a5bd0) != 0) && (uVar2 = DAT_021a5bd4, (param_1 & DAT_021a5bd4) == 0)) {
    param_1 = param_1 | DAT_021a5bd8;
  }
  if ((param_1 & DAT_021a5bdc) != 0) {
    uVar2 = uVar2 | DAT_021a5be0;
  }
  if ((param_1 & DAT_021a5be4) != 0) {
    uVar2 = uVar2 | DAT_021a5be8;
  }
  if ((param_1 & DAT_021a5bec) != 0) {
    uVar2 = uVar2 | DAT_021a5bf0;
  }
  if ((param_1 & DAT_021a5bf4) != 0) {
    uVar2 = uVar2 | DAT_021a5bf8;
  }
  *(uint *)(iVar1 + DAT_021a5bcc) = param_1 | uVar3 & ~uVar2;
  func_0x0200fcb4();
  return uVar3;
}

