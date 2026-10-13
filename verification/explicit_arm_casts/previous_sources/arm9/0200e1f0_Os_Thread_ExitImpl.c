/* Decompiled C draft; module arm9; ROM address 0200e1f0. No matching claim. */
#include "types.h"
#include "deps/0200e1f0_Os_Thread_ExitImpl.h"

void Os_Thread_ExitImpl(uint *param_1,uint param_2)

{
  if (*(uint *)(uRam0200e258 & 0xfffffffc) >> (uRam0200e258 & 3) * 8 != 0 ||
      *(uint *)(uRam0200e258 & 0xfffffffc) << (uRam0200e258 & 3) * -8 + 0x20 != 0) {
    Arm_Context_Create(param_1,uRam0200e25c);
    param_1[1] = param_2;
    *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 0x80;
    param_1[0x19] = 1;
    Arm_Context_Load(param_1);
    return;
  }
  Os_DisposeCurrentThread(param_2);
  return;
}

