/* Decompiled C draft; module arm9_ov001; ROM address 0218e474. No matching claim. */
#include "types.h"
#include "deps/0218e474_FUN_0218e474.h"

void FUN_0218e474(int param_1)

{
  undefined4 uVar1;
  
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  uVar1 = func_0x02036bec(uVar1,0x44);
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  func_0x02109110(*(undefined4 *)(param_1 + 0x94),0xe,param_1 + 4);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(DAT_0218e4a8 + 0x18);
  return;
}

