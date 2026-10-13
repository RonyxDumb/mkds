/* Decompiled C draft; module arm9_ov001; ROM address 0218e650. No matching claim. */
#include "types.h"
#include "deps/0218e650_FUN_0218e650.h"

undefined4 FUN_0218e650(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0xb0) == 0x32) {
    local_18 = *DAT_0218e68c;
    local_10 = DAT_0218e68c[2];
    local_c = DAT_0218e68c[3];
    local_14 = param_1 + 4;
    local_c = func_0x020d4ef4(local_14,local_c,&stack0xfffffff8,DAT_0218e68c + 4);
    uVar1 = func_0x02108e7c();
    func_0x0210b734((uint)(uintptr_t)(&local_18),uVar1);
  }
  return 0;
}

