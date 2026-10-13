/* Decompiled C draft; module arm9; ROM address 0214ced0. No matching claim. */
#include "types.h"
#include "deps/0214ced0_func_0214ced0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0214ced0(undefined4 param_1,undefined4 param_2,int param_3,code *param_4,
                  undefined4 param_5)

{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = puRam0214cfd8;
  if (param_3 != 0) {
    do {
    } while (*(uint *)((uint)puRam0214cfd8 & 0xfffffffc) >> ((uint)puRam0214cfd8 & 3) * 8 != 0 ||
             *(uint *)((uint)puRam0214cfd8 & 0xfffffffc) << ((uint)puRam0214cfd8 & 3) * -8 + 0x20 !=
             0);
    do {
    } while ((((*(uint *)((uint)puRam0214cfdc & 0xfffffffc) >> ((uint)puRam0214cfdc & 3) * 8 |
               *(uint *)((uint)puRam0214cfdc & 0xfffffffc) << ((uint)puRam0214cfdc & 3) * -8 + 0x20)
              & 0x7000000) >> 0x18 & 2) == 0);
    puRam0214cfd8[4] = param_4;
    *puVar1 = 1;
    puVar1[1] = param_1;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    puVar1[5] = param_5;
    MIi_CheckDma0SourceAddress(param_1,param_2,param_3,0);
    MI_WaitDma(param_1);
    uVar3 = Os_DisableIrq();
    puRam0214cfd8[6] =
         (*(uint *)((uint)puRam0214cfdc & 0xfffffffc) >> ((uint)puRam0214cfdc & 3) * 8 |
         *(uint *)((uint)puRam0214cfdc & 0xfffffffc) << ((uint)puRam0214cfdc & 3) * -8 + 0x20) >>
         0x1e;
    uVar4 = Os_GetIrqHandler(0x200000);
    puVar2 = puRam0214cfdc;
    puRam0214cfd8[7] = uVar4;
    uVar4 = uRam0214cfe0;
    *puVar2 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0x3fffffff |
              0x40000000;
    Os_SetIrqHandler(0x200000,uVar4);
    Os_EnableIrqHandler(0x200000);
    func_0214ce08();
    Os_RestoreIrq(uVar3);
    return;
  }
  if (param_4 == (code *)0x0) {
    return;
  }
  (*param_4)(param_5);
  return;
}

