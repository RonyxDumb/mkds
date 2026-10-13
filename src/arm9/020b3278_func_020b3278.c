/* Decompiled C draft; module arm9; ROM address 020b3278. No matching claim. */
#include "types.h"
#include "deps/020b3278_func_020b3278.h"

void func_020b3278(void)

{
  int iVar1;
  
  iVar1 = GetRaceMode();
  if (iVar1 == 5) {
    func_02105b64(4);
  }
  else {
    switch(*(undefined4 *)(*DAT_020b32e8 + 0x28)) {
    case 0:
    case 8:
      func_02105b64(0);
      break;
    case 1:
    case 3:
      func_02105b64(1);
      break;
    case 2:
    case 7:
    case 10:
      func_02105b64(5);
      break;
    case 4:
    case 5:
    case 6:
      func_02105b64(2);
      break;
    case 9:
      func_02105b64(3);
    }
  }
  return;
}

