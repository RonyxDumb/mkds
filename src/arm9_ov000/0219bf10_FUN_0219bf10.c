/* Decompiled C draft; module arm9_ov000; ROM address 0219bf10. No matching claim. */
#include "types.h"
#include "deps/0219bf10_FUN_0219bf10.h"

void FUN_0219bf10(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = FUN_0219c0c8();
  if (iVar1 != 0) {
    FUN_0219c0c4();
  }
  if (*DAT_0219c09c == 0) {
    return;
  }
  if (*(int *)(*DAT_0219c09c + 0x24) == 0) {
    return;
  }
  iVar1 = FUN_0219c39c();
  if (iVar1 != 0) {
    return;
  }
  switch(*(undefined4 *)(*DAT_0219c09c + 0x24)) {
  case 1:
    iVar1 = FUN_0218d574();
    if (iVar1 == 1) {
      FUN_0218f2b8(*DAT_0219c09c + 0x1c,*(undefined4 *)(*DAT_0219c09c + 0x8c),0);
      iVar1 = FUN_0219b77c();
      if (iVar1 != 0) {
        return;
      }
      FUN_0218f21c((int *)(uintptr_t)(*DAT_0219c09c + 0x1c),0,DAT_0219c0a0,0);
      iVar1 = FUN_0219b77c();
      if (iVar1 != 0) {
        return;
      }
      FUN_0218f21c((int *)(uintptr_t)(*DAT_0219c09c + 0x1c),3,DAT_0219c0a4,0);
      iVar1 = FUN_0219b77c();
      if (iVar1 != 0) {
        return;
      }
      FUN_0218f21c((int *)(uintptr_t)(*DAT_0219c09c + 0x1c),1,DAT_0219c0a8,0);
      iVar1 = FUN_0219b77c();
      if (iVar1 != 0) {
        return;
      }
      FUN_0218f21c((int *)(uintptr_t)(*DAT_0219c09c + 0x1c),2,DAT_0219c0ac,0);
      iVar1 = FUN_0219b77c();
      if (iVar1 != 0) {
        return;
      }
      FUN_0219b8a8(2);
      FUN_0219ca84();
    }
    else {
      if (iVar1 == 2) {
        FUN_0219c990(3,DAT_0219c0b0);
        return;
      }
      if (iVar1 == 3) {
        FUN_0219c990(4,DAT_0219c0b4);
        return;
      }
    }
    break;
  case 2:
    FUN_0219c9d8();
    break;
  case 3:
  case 4:
    FUN_0219d81c();
    FUN_021a1ef4(0);
    break;
  case 5:
    FUN_021a1ef4(1);
    FUN_0219d81c();
    break;
  case 6:
    FUN_021a3030();
    FUN_0219d81c();
    pcVar2 = (char *)(*DAT_0219c09c + DAT_0219c0b8);
    if ((*pcVar2 == '\x02') || (*pcVar2 == '\x03')) {
      FUN_021a1ef4(1);
    }
    else if (*(int *)*DAT_0219c09c != 0) {
      FUN_021a1ef4(0);
    }
  }
  if (*(char *)(*DAT_0219c09c + DAT_0219c0bc) == '\x01') {
    if (*(int *)(*DAT_0219c09c + DAT_0219c0c0) != 0) {
      FUN_021a47ac();
      *(undefined4 *)(*DAT_0219c09c + DAT_0219c0c0) = 0;
    }
    *(undefined1 *)(*DAT_0219c09c + DAT_0219c0bc) = 0;
  }
  return;
}

