/* Decompiled C draft; module arm9_ov003; ROM address 021d2c78. No matching claim. */
#include "types.h"
#include "deps/021d2c78_FUN_021d2c78.h"

void FUN_021d2c78(void)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  
  piVar2 = DAT_021d2d00;
  iVar3 = *DAT_021d2d00;
  uVar5 = ((*DAT_021d2d04 | *DAT_021d2d08) ^ DAT_021d2d0c) & DAT_021d2d0c;
  uVar1 = (ushort)uVar5;
  *(ushort *)(iVar3 + 0x32) = uVar1 & (uVar1 ^ *(ushort *)(iVar3 + 0x30));
  *(ushort *)(*piVar2 + 0x36) = *(ushort *)(iVar3 + 0x30) & (uVar1 ^ *(ushort *)(iVar3 + 0x30));
  *(ushort *)(*piVar2 + 0x30) = uVar1;
  *(undefined2 *)(*piVar2 + 0x34) = *(undefined2 *)(*piVar2 + 0x32);
  uVar7 = 0;
  pcVar6 = DAT_021d2d10;
  do {
    uVar4 = 1 << (uVar7 & 0xff);
    if ((uVar5 & 0xffff & uVar4 & 0xffff) == 0) {
      *pcVar6 = '\0';
    }
    else {
      *pcVar6 = *pcVar6 + '\x01';
      uVar1 = (ushort)uVar4;
      if (*pcVar6 == '(') {
        *(ushort *)(*piVar2 + 0x34) = *(ushort *)(*piVar2 + 0x34) | uVar1;
      }
      else if (*pcVar6 == '/') {
        *(ushort *)(*piVar2 + 0x34) = *(ushort *)(*piVar2 + 0x34) | uVar1;
        *pcVar6 = '(';
      }
    }
    pcVar6 = pcVar6 + 1;
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 0xe);
  return;
}

