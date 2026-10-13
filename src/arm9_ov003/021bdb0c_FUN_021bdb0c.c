/* Decompiled C draft; module arm9_ov003; ROM address 021bdb0c. No matching claim. */
#include "types.h"
#include "deps/021bdb0c_FUN_021bdb0c.h"

byte * FUN_021bdb0c(ushort *param_1,uint param_2,ushort *param_3,uint param_4,int param_5)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  
  uVar4 = 0;
  *(undefined1 *)param_3 = 0;
  *(undefined1 *)((int)param_3 + 1) = 0;
  *(undefined1 *)(param_3 + 1) = 0;
  *(undefined1 *)((int)param_3 + 3) = 0;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 5) = 0;
  *(undefined1 *)(param_3 + 3) = 0;
  *(undefined1 *)((int)param_3 + 7) = 0;
  uVar3 = param_4 - 8 & 0xffff;
  *param_3 = (ushort)(uVar3 >> 8) | (ushort)(uVar3 << 8) & (ushort)DAT_021bdbcc;
  if (param_5 == 0) {
    func_0x02134eb8((uint *)(void *)(param_1 + 3),(uint)(uintptr_t)(param_3),param_4);
  }
  else {
    FUN_021bccd0((undefined1 *)(void *)(param_1 + 3),(undefined4)(uintptr_t)(param_3),param_4,param_5,0x10);
    param_4 = param_4 + 8;
  }
  *(byte *)param_1 = 0;
  *(byte *)((int)param_1 + 1) = 0;
  *(byte *)(param_1 + 1) = 0;
  *(byte *)((int)param_1 + 3) = 0;
  *(byte *)(param_1 + 2) = 0;
  *(byte *)((int)param_1 + 5) = 0;
  uVar1 = (ushort)DAT_021bdbcc;
  *param_1 = (ushort)((param_2 & 0xffff) >> 8) | (ushort)((param_2 & 0xffff) << 8) & uVar1;
  param_1[1] = (ushort)((param_4 & 0xffff) >> 8) | (ushort)((param_4 & 0xffff) << 8) & uVar1;
  puVar5 = (ushort *)((int)param_1 + param_4 + 6);
  puVar2 = param_1;
  if (param_1 < puVar5) {
    do {
      uVar4 = uVar4 + (byte)*puVar2;
      puVar2 = (ushort *)((int)puVar2 + 1);
    } while (puVar2 < puVar5);
  }
  *puVar5 = (ushort)((uVar4 & 0xffff) >> 8) | (ushort)((uVar4 & 0xffff) << 8) & (ushort)DAT_021bdbcc
  ;
  return (byte *)((int)puVar5 + (2 - (int)param_1));
}

