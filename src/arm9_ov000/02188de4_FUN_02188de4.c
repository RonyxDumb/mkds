/* Decompiled C draft; module arm9_ov000; ROM address 02188de4. No matching claim. */
#include "types.h"
#include "deps/02188de4_FUN_02188de4.h"

undefined4 FUN_02188de4(int param_1,undefined4 param_2,byte *param_3)

{
  switch(param_2) {
  case 2:
    param_1 = param_1 + DAT_02188e94;
  case 1:
    param_1 = param_1 + DAT_02188e94;
  case 0:
    *param_3 = *(byte *)(param_1 + 0xe6) & 3;
    func_0x0214d1fc((ushort *)(uintptr_t)(param_1 + 0x80),(uint *)(void *)(param_3 + 2),0x50);
    break;
  case 5:
    param_1 = param_1 + DAT_02188e94;
  case 4:
    param_1 = param_1 + DAT_02188e94;
  case 3:
    *param_3 = 1;
    func_0x0214d1fc((ushort *)(uintptr_t)(param_1 + 0xd1),(uint *)(void *)(param_3 + 2),0x14);
    param_3[0x16] = 0;
    break;
  case 6:
    *param_3 = 2;
    FUN_0218a64c(param_1 + DAT_02188e98 + (uint)*(byte *)(param_1 + DAT_02188e9c) * 0xc0,param_3 + 2
                );
    break;
  case 7:
    *param_3 = 2;
    FUN_0218a6ac(param_1 + DAT_02188e98 + (uint)*(byte *)(param_1 + DAT_02188e9c) * 0xc0,(undefined4)(uintptr_t)(param_3 + 2)
                );
  }
  if (*param_3 != 0) {
    return 1;
  }
  return 0;
}

