/* Decompiled C draft; module arm9; ROM address 020fecdc. No matching claim. */
#include "types.h"
#include "deps/020fecdc_func_020fecdc.h"

char * func_020fecdc(byte *param_1,int param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  int *piVar5;
  undefined2 *puVar6;
  
  if (param_2 != 0) {
    if (param_3 != 0) {
      param_1 = pbRam020fefe4;
    }
    param_1 = param_1 + 1;
  }
  if (param_2 == 0) {
    puVar4 = (ushort *)0x0;
  }
  else {
    puVar4 = (ushort *)(param_2 + 0x4e);
  }
  if (puVar4 != (ushort *)0x0) {
    iVar2 = param_2;
    if (param_3 != 0) {
      iVar2 = (int)(short)*puVar4;
    }
    if (param_3 != 0) {
      *param_1 = (byte)iVar2;
    }
    else {
      *puVar4 = (ushort)*param_1;
    }
  }
  if (param_2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(param_2 + 0x74);
  }
  if (piVar5 != (int *)0x0) {
    if (param_3 == 0) {
      *piVar5 = (uint)*(ushort *)(param_1 + 1) << 0xc;
    }
    else {
      *(ushort *)(param_1 + 1) =
           (ushort)((*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                    *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) >> 0xc);
    }
  }
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0x50;
  }
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
  }
  else if (param_2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(param_2 + 0x50);
  }
  if (piVar5 != (int *)0x0) {
    if (param_3 == 0) {
      *piVar5 = (int)*(short *)(param_1 + 3) << 9;
    }
    else {
      *(short *)(param_1 + 3) =
           (short)((int)(*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                        *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) >> 9
                  );
    }
  }
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0x50;
  }
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    if (param_2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_2 + 0x50;
    }
    piVar5 = (int *)(iVar2 + 4);
  }
  if (piVar5 != (int *)0x0) {
    if (param_3 == 0) {
      *piVar5 = (int)*(short *)(param_1 + 5) << 9;
    }
    else {
      *(short *)(param_1 + 5) =
           (short)((int)(*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                        *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) >> 9
                  );
    }
  }
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0x50;
  }
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    if (param_2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_2 + 0x50;
    }
    piVar5 = (int *)(iVar2 + 8);
  }
  if (piVar5 != (int *)0x0) {
    if (param_3 == 0) {
      *piVar5 = (int)*(short *)(param_1 + 7) << 9;
    }
    else {
      *(short *)(param_1 + 7) =
           (short)((int)(*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                        *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) >> 9
                  );
    }
  }
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0xe4;
  }
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2 + 0x50;
  }
  pcVar1 = (char *)func_020ff0b0(param_1 + 9,iVar3,iVar2,param_3);
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0x5c;
  }
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
  }
  else if (param_2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(param_2 + 0x5c);
  }
  if (piVar5 != (int *)0x0) {
    if (param_3 == 0) {
      *piVar5 = (int)*pcVar1 << 10;
    }
    else {
      *pcVar1 = (char)((int)(*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                            *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20)
                      >> 10);
    }
  }
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0x5c;
  }
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    if (param_2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_2 + 0x5c;
    }
    piVar5 = (int *)(iVar2 + 4);
  }
  if (piVar5 != (int *)0x0) {
    if (param_3 == 0) {
      *piVar5 = (int)pcVar1[1] << 9;
    }
    else {
      pcVar1[1] = (char)((int)(*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                              *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20
                              ) >> 9);
    }
  }
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 + 0x5c;
  }
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    if (param_2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = param_2 + 0x5c;
    }
    piVar5 = (int *)(iVar2 + 8);
  }
  if (piVar5 != (int *)0x0) {
    if (param_3 == 0) {
      *piVar5 = (int)pcVar1[2] << 10;
    }
    else {
      pcVar1[2] = (char)((int)(*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                              *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20
                              ) >> 10);
    }
  }
  if (param_2 == 0) {
    puVar6 = (undefined2 *)0x0;
  }
  else {
    puVar6 = (undefined2 *)(param_2 + 0x78);
  }
  if (puVar6 != (undefined2 *)0x0) {
    if (param_3 == 0) {
      *puVar6 = *(undefined2 *)(pcVar1 + 3);
    }
    else {
      *(undefined2 *)(pcVar1 + 3) = *puVar6;
    }
  }
  return pcVar1 + 5;
}

