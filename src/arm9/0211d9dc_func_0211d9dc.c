/* Decompiled C draft; module arm9; ROM address 0211d9dc. No matching claim. */
#include "types.h"
#include "deps/0211d9dc_func_0211d9dc.h"

void func_0211d9dc(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  
  piVar1 = piRam0211db1c;
  iVar5 = 0;
  puVar4 = puRam0211db18;
  do {
    iVar3 = *piVar1;
    if ((*(int *)(iVar3 + 0x7c) == 0) && (*(int *)(iVar3 + 0x60) == iVar5)) {
      func_02124100(*puVar4,1,*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x14),
                    *(undefined4 *)(iVar3 + 4));
    }
    else {
      iVar3 = *piVar1;
      func_02124100(*puVar4,0,*(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x14),
                    *(undefined4 *)(iVar3 + 4));
    }
    piVar2 = piRam0211db1c;
    puVar4 = puVar4 + 2;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  if (*(int *)(*piRam0211db20 + 0x20) != 2) {
    iVar5 = *piRam0211db1c;
    if ((*(int *)(iVar5 + 0x7c) == 0) || (*(int *)(iVar5 + 0x84) == 0)) {
      *(undefined4 *)(*(int *)(iVar5 + 0x14) + iRam0211db24) = 1;
      piVar1 = piRam0211db1c;
      *(undefined4 *)(*(int *)(*piRam0211db1c + 0x14) + iRam0211db28) = 0;
      iVar5 = *piVar1;
      func_02124100(0xd,0,*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x14),
                    *(undefined4 *)(iVar5 + 4));
    }
    else {
      *(undefined4 *)(*(int *)(iVar5 + 0x14) + iRam0211db24) = 0;
      *(undefined4 *)(*(int *)(*piVar2 + 0x14) + iRam0211db28) = 1;
      iVar5 = *piVar2;
      func_02124100(0xd,1,*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x14),
                    *(undefined4 *)(iVar5 + 4));
    }
  }
  piVar1 = piRam0211db1c;
  iVar5 = *piRam0211db1c;
  if ((*(int *)(iVar5 + 0x80) != *(int *)(iVar5 + 0x7c)) ||
     (*(int *)(iVar5 + 100) != *(int *)(iVar5 + 0x60))) {
    iVar5 = 0;
    do {
      func_0211db30(&local_28,iVar5);
      func_020b44a4(*(int *)(*piVar1 + 0x20) + 0xc,local_28,local_24,local_20,local_1c,local_18);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
    if (*(int *)(*piRam0211db1c + 0x7c) == 0) {
      func_0211db30(&local_28,*(undefined4 *)(*piRam0211db1c + 0x60));
      func_020b44a4(*(int *)(*piRam0211db1c + 0x20) + 0xc,local_28,local_24,local_20,local_1c,
                    local_16);
    }
    AllocateReserveTEQSub(0x1b,0,*(int *)(*piRam0211db1c + 0x20) + 0xc,uRam0211db2c);
  }
  return;
}

