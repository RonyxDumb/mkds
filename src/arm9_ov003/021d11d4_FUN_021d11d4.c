/* Decompiled C draft; module arm9_ov003; ROM address 021d11d4. No matching claim. */
#include "types.h"
#include "deps/021d11d4_FUN_021d11d4.h"

undefined4 FUN_021d11d4(void)

{
  char cVar1;
  
  cVar1 = *(char *)(*DAT_021d1210 + DAT_021d1214);
  if (((cVar1 != '\x01') && (cVar1 != '\x1a')) && (cVar1 != '\x1d')) {
    return 0;
  }
  FUN_021d1218();
  FUN_021cfde4();
  *(undefined1 *)(*DAT_021d1210 + DAT_021d1214) = 2;
  return 1;
}

