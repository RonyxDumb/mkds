/* Decompiled C draft; module arm9; ROM address 0211baec. No matching claim. */
#include "types.h"
#include "deps/0211baec_func_0211baec.h"

void func_0211baec(void)

{
  int *piVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int local_40;
  int local_3c;
  ushort *local_38;
  ushort *local_34;
  ushort *local_30;
  ushort *local_2c;
  int local_24;
  
  piVar1 = piRam0211bcd0;
  local_40 = 0;
  *(undefined4 *)(*piRam0211bcd0 + 0x34) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  *(int *)(*piVar1 + 0x5c) = *(short *)(*piVar1 + 0x58) + -0xc0;
  *(int *)(*piVar1 + 0x5c) = *(short *)(*piVar1 + 0x58) + -0xc0;
  iVar4 = *piVar1;
  uVar2 = (uint)*(ushort *)(*(int *)(iVar4 + 4) + 6);
  *(short *)(*(int *)(iVar4 + 0x14) + iRam0211bcd4) = *(short *)(iVar4 + 0x58) + 0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bcd8) = *(short *)(*piVar1 + 0x58) + 0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bcdc) = *(short *)(*piVar1 + 0x58) + 0xc0;
  local_38 = puRam0211bce0;
  local_34 = puRam0211bce4;
  local_30 = puRam0211bce8;
  local_2c = puRam0211bcec;
  do {
    local_3c = 0;
    puVar3 = local_30;
    puVar5 = local_34;
    puVar6 = local_38;
    do {
      *(short *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar6 * 0x40 + 6) =
           *(short *)(*piVar1 + 0x58) + -0xc0;
      *(short *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40 + 6) =
           *(short *)(*piVar1 + 0x58) + -0xc0;
      *(short *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar3 * 0x40 + 6) =
           *(short *)(*piVar1 + 0x58) + -0xc0;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + 1;
      local_3c = local_3c + 1;
    } while (local_3c < 2);
    iVar4 = 0;
    puVar3 = local_2c;
    do {
      *(short *)(*(int *)(*piVar1 + 0x14) + (uVar2 + *puVar3) * 0x40 + 6) =
           *(short *)(*piVar1 + 0x58) + -0xc0;
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    local_38 = local_38 + 2;
    local_34 = local_34 + 2;
    local_30 = local_30 + 2;
    local_2c = local_2c + 2;
    local_40 = local_40 + 1;
  } while (local_40 < 5);
  *(short *)(*(int *)(*piVar1 + 0x14) + (uVar2 + 10) * 0x40 + 6) =
       *(short *)(*piVar1 + 0x58) + -0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + (uVar2 + 0xc) * 0x40 + 6) =
       *(short *)(*piVar1 + 0x58) + -0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bcf0) = *(short *)(*piVar1 + 0x58) + -0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bcf4) = *(short *)(*piVar1 + 0x58) + -0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bcf8) = *(short *)(*piVar1 + 0x58) + -0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bcfc) = *(short *)(*piVar1 + 0x58) + -0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bd00) = *(short *)(*piVar1 + 0x58) + -0xc0;
  *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211bd04) = *(short *)(*piVar1 + 0x58) + -0xc0;
  piVar1 = piRam0211bcd0;
  local_24 = 0;
  puVar3 = puRam0211bd08;
  do {
    iVar4 = 0;
    puVar5 = puVar3;
    do {
      *(short *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar5 * 0x40 + 6) =
           *(short *)(*piVar1 + 0x58) + -0xc0;
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    puVar3 = puVar3 + 2;
    local_24 = local_24 + 1;
  } while (local_24 < 2);
  if (*(int *)(*piRam0211bd0c + 0x20) != 2) {
    *(short *)(*(int *)(*piVar1 + 0x14) + (uVar2 + 0xd) * 0x40 + 6) =
         *(short *)(*piVar1 + 0x58) + 0xc0;
    *(short *)(*(int *)(*piVar1 + 0x14) + (uVar2 + 8) * 0x40 + 6) =
         *(short *)(*piVar1 + 0x58) + 0xc0;
    return;
  }
  *(short *)(*(int *)(*piVar1 + 0x14) + (uVar2 + 0xe) * 0x40 + 6) =
       *(short *)(*piVar1 + 0x58) + 0xc0;
  return;
}

