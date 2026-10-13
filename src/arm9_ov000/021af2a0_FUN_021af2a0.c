/* Decompiled C draft; module arm9_ov000; ROM address 021af2a0. No matching claim. */
#include "types.h"
#include "deps/021af2a0_FUN_021af2a0.h"

void FUN_021af2a0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(DAT_021af344 + 8);
  while( true ) {
    if (iVar3 == 0) {
      return;
    }
    puVar2 = *(uint **)(iVar3 + 0xa4);
    if ((((puVar2 != (uint *)0x0) && (*puVar2 != 0)) && ((char)puVar2[2] == '\v')) &&
       ((((*puVar2 & 0xffff) == (uint)*(ushort *)(param_2 + 4) &&
         (*(short *)((int)puVar2 + 10) == *(short *)(param_2 + 6))) &&
        ((puVar2[0x11] == 0 &&
         (puVar2[7] ==
          (((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 | (*(ushort *)(param_1 + 0xc) & 0xff) << 8)
           << 0x10 |
          (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 | (*(ushort *)(param_1 + 0xe) & 0xff) << 8)))))
       )) break;
    iVar3 = *(int *)(iVar3 + 0x68);
  }
  uVar1 = param_3 - 8;
  if (puVar2[0xf] < uVar1) {
    puVar2[0x11] = puVar2[0xf];
  }
  else {
    puVar2[0x11] = uVar1;
  }
  func_0x0214d1fc(param_2 + 8,puVar2[0x10],puVar2[0x11],puVar2[7],uVar1);
  if (puVar2[1] != 3) {
    return;
  }
  puVar2[1] = 0;
  func_0x0200df68(*puVar2);
  return;
}

