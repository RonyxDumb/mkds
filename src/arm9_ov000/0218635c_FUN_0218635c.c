/* Decompiled C draft; module arm9_ov000; ROM address 0218635c. No matching claim. */
#include "types.h"
#include "deps/0218635c_FUN_0218635c.h"

void FUN_0218635c(int *param_1)

{
  int iVar1;
  
  if (*DAT_021863b0 == 0) {
    func_0x0214d168(param_1,0,DAT_021863b4);
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(*DAT_021863b0 + 8),param_1,DAT_021863b4);
  iVar1 = *param_1;
  if (iVar1 < 0) {
    if ((DAT_021863c4 < iVar1) || (iVar1 <= DAT_021863c8)) {
      *param_1 = DAT_021863c0;
    }
  }
  else if ((iVar1 < DAT_021863b8) || (DAT_021863bc <= iVar1)) {
    *param_1 = DAT_021863c0;
    return;
  }
  return;
}

