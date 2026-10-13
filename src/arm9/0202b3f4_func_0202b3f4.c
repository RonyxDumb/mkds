/* Decompiled C draft; module arm9; ROM address 0202b3f4. No matching claim. */
#include "types.h"
#include "deps/0202b3f4_func_0202b3f4.h"

void func_0202b3f4(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  
  iVar4 = *piRam0202b4b0;
  uVar1 = *(ushort *)(*(int *)(iVar4 + 0x54) + 6);
  iVar6 = 0;
  psVar5 = psRam0202b4b4;
  if (0 < *(int *)(iVar4 + 0xb8)) {
    do {
      iVar3 = func_0201ea30(*(undefined4 *)(iVar4 + 0x54),(int)psVar5[3]);
      uVar2 = ComputeValueInterpolation_from_thumb
                        (1,0,(0x60 - (((int)*(short *)(iVar3 + 2) << 0x14) >> 0x14)) * 0x10000 >>
                             0x10,*(undefined4 *)(*piRam0202b4b0 + iRam0202b4b8),0x3c);
      *(undefined2 *)(*(int *)(iVar4 + 0x60) + psVar5[3] * 0x40 + 6) = uVar2;
      iVar3 = func_0201ea58(*(undefined4 *)(iVar4 + 0x5c),(int)*psVar5);
      uVar2 = ComputeValueInterpolation_from_thumb
                        (1,0,(0x60 - (((int)*(short *)(iVar3 + 2) << 0x14) >> 0x14)) * 0x10000 >>
                             0x10,*(undefined4 *)(*piRam0202b4b0 + iRam0202b4b8),0x3c);
      *(undefined2 *)(*(int *)(iVar4 + 0x60) + ((uint)uVar1 + (int)*psVar5) * 0x40 + 6) = uVar2;
      iVar6 = iVar6 + 1;
      psVar5 = psVar5 + 4;
    } while (iVar6 < *(int *)(*piRam0202b4b0 + 0xb8));
  }
  return;
}

