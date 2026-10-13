/* Decompiled C draft; module arm9_ov001; ROM address 02195e38. No matching claim. */
#include "types.h"
#include "deps/02195e38_FUN_02195e38.h"

void FUN_02195e38(void)

{
  int iVar1;
  
  iVar1 = func_0x02125f54();
  if (iVar1 != 0) {
    iVar1 = func_0x02125f60();
    if (iVar1 == 0) {
      iVar1 = func_0x02060268(*(undefined4 *)(DAT_02195e98 + *(int *)(*DAT_02195e94 + 0x6c) * 4));
      if (iVar1 == 0) {
        func_0x02060004(*(undefined4 *)(DAT_02195e98 + *(int *)(*DAT_02195e94 + 0x6c) * 4));
        func_0x02057d9c();
        if (*(int *)(*DAT_02195e9c + 0xc) != 0) {
          func_0x02145d38();
        }
      }
      *(undefined4 *)(*DAT_02195e94 + 0x74) = 1;
    }
    FUN_02196e88();
  }
  return;
}

