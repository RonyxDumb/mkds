/* Decompiled C draft; module arm9; ROM address 0204d110. No matching claim. */
#include "types.h"
#include "deps/0204d110_func_0204d110.h"

void func_0204d110(uint *param_1,undefined4 *param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  
  Os_DisableIrq();
  puVar2 = (uint *)(*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                   *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  if (puVar2 == param_3) {
    *param_1 = *(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20;
    *param_3 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    *param_2 = param_3;
  }
  else {
    do {
      puVar1 = puVar2;
      if (puVar1 == (uint *)0x0) goto LAB_0204d180;
      puVar2 = (uint *)(*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
                       *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20);
    } while (puVar2 != param_3);
    *puVar1 = *(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
              *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20;
    *param_3 = *(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
               *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20;
    *param_2 = param_3;
  }
LAB_0204d180:
  Os_RestoreIrq();
  return;
}

