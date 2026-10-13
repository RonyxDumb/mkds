/* Decompiled C draft; module arm9; ROM address 020aa81c. No matching claim. */
#include "types.h"
#include "deps/020aa81c_func_020aa81c.h"

void func_020aa81c(void)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [8];
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  iVar1 = func_020ab604();
  if (iVar1 == 0) {
    local_14 = 0;
    local_12 = 3;
  }
  else {
    do {
      func_0214e8f4();
      iVar1 = func_0214e89c(auStack_20);
    } while (iVar1 != 0);
    func_0214e334(&local_18,auStack_20);
  }
  local_28 = CONCAT22(local_16,local_18);
  local_24 = CONCAT22(local_12,local_14);
  func_020aa89c(((*puRam020aa890 | *puRam020aa894) ^ uRam020aa898) & uRam020aa898 & 0xffff,local_28,
                local_24,auStack_20);
  return;
}

