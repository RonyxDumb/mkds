/* Decompiled C draft; module arm9_ov000; ROM address 0218e8c4. No matching claim. */
#include "types.h"
#include "deps/0218e8c4_FUN_0218e8c4.h"

void FUN_0218e8c4(void)

{
  int iVar1;
  longlong lVar2;
  
  iVar1 = func_0x0200f6e4();
  if (iVar1 != 1) {
    func_0x0213442c(DAT_0218e8f8,DAT_0218e8fc,0,DAT_0218e900);
  }
  lVar2 = func_0x0200f5ac();
  func_0x02132e40((int)(lVar2 << 6),(int)((ulonglong)(lVar2 << 6) >> 0x20),DAT_0218e904,0);
  return;
}

