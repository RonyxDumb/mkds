/* Decompiled C draft; module arm9; ROM address 0214ccd4. No matching claim. */
#include "types.h"
#include "deps/0214ccd4_func_0214ccd4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0214ccd4(undefined4 param_1,undefined4 param_2,uint param_3,code *param_4,
                  undefined4 param_5)

{
  undefined4 *puVar1;
  
  puVar1 = puRam0214cd88;
  if (param_3 != 0) {
    do {
    } while (*(uint *)((uint)puRam0214cd88 & 0xfffffffc) >> ((uint)puRam0214cd88 & 3) * 8 != 0 ||
             *(uint *)((uint)puRam0214cd88 & 0xfffffffc) << ((uint)puRam0214cd88 & 3) * -8 + 0x20 !=
             0);
    *puRam0214cd88 = 1;
    puVar1[1] = param_1;
    puVar1[4] = param_4;
    puVar1[5] = param_5;
    MIi_CheckAnotherAutoDMA(param_1,0x38000000);
    MIi_CheckDma0SourceAddress(param_1,param_2,param_3,0);
    MI_WaitDma(param_1);
    OSi_EnterDmaCallback(param_1,uRam0214cd8c,0);
    func_01ffff38(param_1,param_2,uRam0214cd90,param_3 >> 2 | 0xfc400000);
    return;
  }
  if (param_4 != (code *)0x0) {
    (*param_4)(param_5);
    return;
  }
  return;
}

