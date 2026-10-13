/* Decompiled C draft; module arm9; ROM address 020ab11c. No matching claim. */
#include "types.h"
#include "deps/020ab11c_func_020ab11c.h"

void func_020ab11c(uint *param_1,uint *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = iRam020ab188;
  if ((((*(byte **)(iRam020ab188 + 0x44) != (byte *)0x0) && (param_1 != (uint *)0x0)) &&
      (param_2 != (uint *)0x0)) && ((param_3 != (int *)0x0 && (param_4 != (int *)0x0)))) {
    *param_1 = (uint)**(byte **)(iRam020ab188 + 0x44);
    *param_2 = (uint)*(byte *)(*(int *)(iVar1 + 0x44) + 1);
    *param_3 = (uint)**(byte **)(iVar1 + 0x44) + (uint)(*(byte **)(iVar1 + 0x44))[2];
    *param_4 = (uint)*(byte *)(*(int *)(iVar1 + 0x44) + 1) +
               (uint)*(byte *)(*(int *)(iVar1 + 0x44) + 3);
    piVar2 = piRam020ab18c;
    if (*(ushort *)(*(int *)(iVar1 + 0x44) + 6) < 0x100) {
      *param_1 = *param_1 + *piRam020ab18c;
      piVar3 = piRam020ab190;
      *param_2 = *param_2 + *piRam020ab190;
      *param_3 = *param_3 + *piVar2;
      *param_4 = *param_4 + *piVar3;
    }
  }
  return;
}

