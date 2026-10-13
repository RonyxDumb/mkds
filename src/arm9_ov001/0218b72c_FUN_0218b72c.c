/* Decompiled C draft; module arm9_ov001; ROM address 0218b72c. No matching claim. */
#include "types.h"
#include "deps/0218b72c_FUN_0218b72c.h"

void FUN_0218b72c(int param_1)

{
  undefined4 uVar1;
  
  func_0x020ac588(DAT_0218b768,0x32,param_1);
  func_0x020364e8();
  uVar1 = func_0x020364e0();
  uVar1 = func_0x02036bec(uVar1,0x44);
  *(undefined4 *)(param_1 + 0x94) = uVar1;
  func_0x02109110(*(undefined4 *)(param_1 + 0x94),0xf,param_1 + 4);
  *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(DAT_0218b76c + 0x3c);
  return;
}

