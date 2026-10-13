/* Decompiled C draft; module arm9_ov001; ROM address 0218e298. No matching claim. */
#include "types.h"
#include "deps/0218e298_FUN_0218e298.h"

void FUN_0218e298(int param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_02182bbc(*(uint *)(*(int *)(param_1 + 0xa0) + DAT_0218e31c) & 0xffff);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218e320);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + DAT_0218e324) = 0xc;
  *(undefined4 *)(param_1 + DAT_0218e32c) = DAT_0218e328;
  FUN_02188200(param_1,DAT_0218e330);
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_0218e334,DAT_0218e338);
  func_0x02068a10(param_2);
  FUN_021888a4(param_1,0,DAT_0218e33c);
  *(undefined4 *)(param_1 + 0xa8) = 1;
  if (*(int *)(*DAT_0218e340 + 8) == 4) {
    iVar1 = func_0x020a126c();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 == 0) {
    func_0x02061874();
  }
  return;
}

