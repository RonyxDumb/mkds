/* Decompiled C draft; module arm9_ov000; ROM address 02188008. No matching claim. */
#include "types.h"
#include "deps/02188008_FUN_02188008.h"

void FUN_02188008(void)

{
  int iVar1;
  
  if ((*(int *)(*DAT_02188050 + DAT_02188054) == 0) ||
     (iVar1 = func_0x0200e070(*DAT_02188050 + DAT_02188058), iVar1 != 0)) {
    iVar1 = *DAT_02188050;
    func_0x0200e28c(iVar1 + DAT_02188058,DAT_02188060,iVar1,iVar1 + DAT_02188064,DAT_0218805c,0x10);
    func_0x0200df68(*DAT_02188050 + DAT_02188058);
  }
  return;
}

