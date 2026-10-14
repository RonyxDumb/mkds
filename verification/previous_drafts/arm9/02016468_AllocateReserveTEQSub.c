/* Decompiled C draft; module arm9; ROM address 02016468. No matching claim. */
#include "types.h"
#include "deps/02016468_AllocateReserveTEQSub.h"

undefined4
AllocateReserveTEQSub(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = iRam020164e4;
  iVar4 = StructTEQ_IsTEQSubListFull(iRam020164e4);
  if (iVar4 == 0) {
    puVar5 = (undefined4 *)StructTEQ_GetNextFreeTEQSub(iVar3);
    *puVar5 = param_1;
    puVar5[1] = param_3;
    puVar5[2] = param_2;
    puVar5[3] = param_4;
    StructTEQ_ReserveTEQSub(iVar3);
    uVar1 = iVar3 + 0x10U & 3;
    uVar7 = *(uint *)(iVar3 + 0x10U & 0xfffffffc);
    uVar2 = (uint)(puVar5 + 3) & 3;
    uVar6 = *(uint *)((uint)(puVar5 + 3) & 0xfffffffc);
    *(uint *)(iVar3 + 0x10) =
         (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) +
         (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    return 1;
  }
  return 0;
}

