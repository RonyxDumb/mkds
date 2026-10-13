/* Decompiled C draft; module arm9_ov001; ROM address 02199420. No matching claim. */
#include "types.h"
#include "deps/02199420_FUN_02199420.h"

void FUN_02199420(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*DAT_02199460 + 0xc);
  if (iVar1 == 0) {
    func_0x02108e94(1);
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      return;
    }
    func_0x02108e94(2);
    return;
  }
  func_0x02108e94(0);
  return;
}

