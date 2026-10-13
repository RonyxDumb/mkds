/* Decompiled C draft; module arm9_ov000; ROM address 0218e320. No matching claim. */
#include "types.h"
#include "deps/0218e320_FUN_0218e320.h"

void FUN_0218e320(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  iVar1 = func_0x0200f6e4();
  if (iVar1 != 1) {
    func_0x0213442c(DAT_0218e358,DAT_0218e35c,0,DAT_0218e360);
  }
  lVar3 = func_0x0200f5ac();
  uVar2 = func_0x02132e40((int)(lVar3 << 6),(int)((ulonglong)(lVar3 << 6) >> 0x20),DAT_0218e364,0);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = uVar2;
  }
  return;
}

