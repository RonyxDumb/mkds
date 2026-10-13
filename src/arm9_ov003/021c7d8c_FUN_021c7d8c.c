/* Decompiled C draft; module arm9_ov003; ROM address 021c7d8c. No matching claim. */
#include "types.h"
#include "deps/021c7d8c_FUN_021c7d8c.h"

undefined4 FUN_021c7d8c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_021cdb6c();
  if (*(char *)(iVar1 + 0x40) == '\0') {
    return 0;
  }
  if (((*(char *)(iVar1 + 0xf6) == '\0') && (iVar2 = func_0x02151620((byte *)(uintptr_t)(iVar1 + 200)), iVar2 == 0)) &&
     (iVar2 = func_0x02151620((byte *)(uintptr_t)(iVar1 + 0xcc)), iVar2 == 0)) {
    return 0;
  }
  if (*(char *)(iVar1 + 0xf5) == '\0') {
    iVar2 = func_0x02151620((byte *)(uintptr_t)(iVar1 + 0xc0));
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = func_0x02151620((byte *)(uintptr_t)(iVar1 + 0xc4));
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = func_0x02151640(iVar1 + 0xc0,iVar1 + 0xf0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

