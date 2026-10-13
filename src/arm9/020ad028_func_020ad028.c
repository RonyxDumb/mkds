/* Decompiled C draft; module arm9; ROM address 020ad028. No matching claim. */
#include "types.h"
#include "deps/020ad028_func_020ad028.h"

void func_020ad028(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(*DAT_020ad1ec + 0x68);
  iVar2 = func_020acbe8(*(undefined4 *)(*DAT_020ad1ec + 0x6c));
  iVar3 = 0;
  do {
    *(undefined4 *)(iVar5 + iVar3 * 0x40) = 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  iVar4 = 10;
  iVar3 = 0;
  do {
    *(undefined4 *)(iVar5 + iVar4 * 0x40) = 0;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xf);
  do {
    *(undefined4 *)(iVar5 + (iVar2 + iVar3) * 0x40) = 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  func_02124100(0,0xf,*(undefined4 *)(*DAT_020ad1ec + 0x74),iVar5,
                *(undefined4 *)(*DAT_020ad1ec + 0x6c));
  func_02124100(1,0xf,*(undefined4 *)(*DAT_020ad1ec + 0x74),iVar5,
                *(undefined4 *)(*DAT_020ad1ec + 0x6c));
  piVar1 = DAT_020ad1ec;
  iVar2 = *DAT_020ad1ec;
  switch(*(undefined4 *)(iVar2 + 0x54)) {
  case 0:
    if (*(int *)(iVar2 + 0xc) == 4) {
      *(undefined2 *)(iVar5 + 4) = *(undefined2 *)(iVar2 + 0x60);
      *(undefined2 *)(iVar5 + DAT_020ad1f0) = *(undefined2 *)(*piVar1 + 0x60);
      *(undefined2 *)(iVar5 + DAT_020ad1f4) = *(undefined2 *)(*piVar1 + 0x60);
    }
    if (((*(int *)(*DAT_020ad1ec + 0xc) != 4) || (*(int *)(*DAT_020ad1ec + 0x58) == 0)) ||
       (iVar2 = func_020adaf8(), 4 < iVar2)) {
      *(undefined4 *)(iVar5 + DAT_020ad1f8) = 0;
      *(undefined4 *)(iVar5 + DAT_020ad1fc) = 1;
    }
    break;
  case 1:
    if (*(int *)(iVar2 + 0xc) == 4) {
      *(undefined2 *)(iVar5 + 0x44) = *(undefined2 *)(iVar2 + 0x60);
      *(undefined2 *)(iVar5 + DAT_020ad200) = *(undefined2 *)(*piVar1 + 0x60);
      *(undefined2 *)(iVar5 + DAT_020ad204) = *(undefined2 *)(*piVar1 + 0x60);
    }
    if (((*(int *)(*DAT_020ad1ec + 0xc) != 4) || (*(int *)(*DAT_020ad1ec + 0x58) == 0)) ||
       (iVar2 = func_020adaf8(), 4 < iVar2)) {
      *(undefined4 *)(iVar5 + DAT_020ad208) = 0;
      *(undefined4 *)(iVar5 + DAT_020ad20c) = 1;
    }
    break;
  case 2:
    if (*(int *)(iVar2 + 0xc) == 4) {
      *(undefined2 *)(iVar5 + 0x84) = *(undefined2 *)(iVar2 + 0x60);
      *(undefined2 *)(iVar5 + DAT_020ad210) = *(undefined2 *)(*piVar1 + 0x60);
      *(undefined2 *)(iVar5 + DAT_020ad214) = *(undefined2 *)(*piVar1 + 0x60);
    }
    if (((*(int *)(*DAT_020ad1ec + 0xc) != 4) || (*(int *)(*DAT_020ad1ec + 0x58) == 0)) ||
       (iVar2 = func_020adaf8(), 4 < iVar2)) {
      *(undefined4 *)(iVar5 + DAT_020ad218) = 0;
      *(undefined4 *)(iVar5 + DAT_020ad21c) = 1;
    }
    break;
  case 3:
    if (((*(int *)(iVar2 + 0xc) != 4) || (*(int *)(iVar2 + 0x58) == 0)) ||
       (iVar2 = func_020adaf8(), 4 < iVar2)) {
      *(undefined4 *)(iVar5 + DAT_020ad220) = 0;
      *(undefined4 *)(iVar5 + DAT_020ad224) = 1;
      func_02124100(0,0xe,*(undefined4 *)(*DAT_020ad1ec + 0x74),iVar5,
                    *(undefined4 *)(*DAT_020ad1ec + 0x6c));
    }
    break;
  case 4:
    if (((*(int *)(iVar2 + 0xc) != 4) || (*(int *)(iVar2 + 0x58) == 0)) ||
       (iVar2 = func_020adaf8(), 4 < iVar2)) {
      *(undefined4 *)(iVar5 + DAT_020ad228) = 0;
      *(undefined4 *)(iVar5 + DAT_020ad22c) = 1;
      func_02124100(1,0xe,*(undefined4 *)(*DAT_020ad1ec + 0x74),iVar5,
                    *(undefined4 *)(*DAT_020ad1ec + 0x6c));
    }
  }
  return;
}

