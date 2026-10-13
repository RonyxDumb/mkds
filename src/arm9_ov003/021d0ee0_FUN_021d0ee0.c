/* Decompiled C draft; module arm9_ov003; ROM address 021d0ee0. No matching claim. */
#include "types.h"
#include "deps/021d0ee0_FUN_021d0ee0.h"

void FUN_021d0ee0(void)

{
  int *piVar1;
  int iVar2;
  int extraout_r1;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  
  iVar2 = DAT_021d1190;
  piVar1 = DAT_021d118c;
  iVar3 = *DAT_021d118c;
  switch(*(undefined1 *)(iVar3 + DAT_021d1190)) {
  case 1:
    pcVar4 = (char *)(iVar3 + DAT_021d1194);
    if (*pcVar4 == '\x01') {
      *pcVar4 = '\0';
      FUN_021d11d4();
      return;
    }
    if (*pcVar4 == '\x02') {
      *pcVar4 = '\0';
      *(undefined1 *)(*piVar1 + iVar2) = 0x22;
      return;
    }
    break;
  case 2:
    FUN_021d0df8();
    return;
  case 3:
    FUN_021d0dd8();
    *(undefined1 *)(*DAT_021d118c + DAT_021d1190) = 4;
    return;
  case 4:
    *(int *)(iVar3 + DAT_021d1198) = *(int *)(iVar3 + DAT_021d1198) + 1;
    FUN_021d0c84();
    return;
  case 5:
  case 6:
    FUN_021d0c84();
    return;
  case 7:
    FUN_021d0c58();
    return;
  case 8:
  case 9:
  case 10:
    FUN_021d0acc();
    return;
  case 0xb:
    FUN_021d0ab8();
    return;
  case 0x10:
    *(undefined4 *)(iVar3 + DAT_021d119c) = 0;
    *(undefined1 *)(*piVar1 + iVar2) = 0x11;
    return;
  case 0x11:
    uVar5 = *(uint *)(iVar3 + DAT_021d119c);
    *(uint *)(iVar3 + DAT_021d119c) = uVar5 + 1;
    if (0x1e < uVar5) {
      FUN_021d0a88();
      return;
    }
    break;
  case 0x12:
    func_0x02009c04();
    piVar1 = DAT_021d118c;
    *(undefined4 *)(*DAT_021d118c + DAT_021d119c) = 0;
    *(undefined1 *)(*piVar1 + DAT_021d1190) = 0x16;
    return;
  case 0x13:
    uVar5 = *(uint *)(iVar3 + DAT_021d119c);
    *(uint *)(iVar3 + DAT_021d119c) = uVar5 + 1;
    if ((0x1e < uVar5) && (iVar2 = FUN_021d010c(), iVar2 == 1)) {
      FUN_021cfa68();
      *(undefined1 *)(*DAT_021d118c + DAT_021d1190) = 0x14;
      return;
    }
    break;
  case 0x15:
    FUN_021cfaa8();
    piVar1 = DAT_021d118c;
    *(undefined4 *)(*DAT_021d118c + DAT_021d119c) = 0;
    *(undefined1 *)(*piVar1 + DAT_021d1190) = 0x16;
    return;
  case 0x16:
    uVar5 = *(uint *)(iVar3 + DAT_021d119c);
    *(uint *)(iVar3 + DAT_021d119c) = uVar5 + 1;
    if ((0x1e < uVar5) && (iVar2 = FUN_021d010c(), iVar2 == 1)) {
      FUN_021cfa68();
      *(undefined1 *)(*DAT_021d118c + DAT_021d1190) = 0x17;
      return;
    }
    break;
  case 0x18:
    FUN_021cfaa8();
    piVar1 = DAT_021d118c;
    *(undefined4 *)(*DAT_021d118c + DAT_021d119c) = 0;
    *(undefined1 *)(*piVar1 + DAT_021d1190) = 0x19;
    return;
  case 0x19:
    uVar5 = *(uint *)(iVar3 + DAT_021d119c);
    *(uint *)(iVar3 + DAT_021d119c) = uVar5 + 1;
    if ((0x1e < uVar5) && (iVar2 = FUN_021d010c(), iVar2 == 1)) {
      FUN_021cfa68();
      *(undefined1 *)(*DAT_021d118c + DAT_021d1190) = 0x1a;
      return;
    }
    break;
  case 0x1b:
    FUN_021cfaa8();
    piVar1 = DAT_021d118c;
    *(undefined4 *)(*DAT_021d118c + DAT_021d119c) = 0;
    *(undefined1 *)(*piVar1 + DAT_021d1190) = 0x1c;
    return;
  case 0x1c:
    uVar5 = *(uint *)(iVar3 + DAT_021d119c);
    *(uint *)(iVar3 + DAT_021d119c) = uVar5 + 1;
    if (0x1e < uVar5) {
      iVar2 = FUN_021d010c();
      if (iVar2 == 1) {
        FUN_021cfa68();
        *(undefined1 *)(*DAT_021d118c + DAT_021d1190) = 0x1d;
        return;
      }
      uVar5 = *(uint *)(*DAT_021d118c + DAT_021d119c);
      func_0x02133274(uVar5,0x1e);
      if ((extraout_r1 == 1) && (0x37 < uVar5)) {
        FUN_021cfaa8();
        return;
      }
    }
    break;
  case 0x1e:
    FUN_021cfaa8();
    break;
  case 0x20:
    FUN_021cfaa8();
    piVar1 = DAT_021d118c;
    *(undefined4 *)(*DAT_021d118c + DAT_021d119c) = 0;
    *(undefined1 *)(*piVar1 + DAT_021d1190) = 0x21;
    return;
  case 0x21:
    uVar5 = *(uint *)(iVar3 + DAT_021d119c);
    *(uint *)(iVar3 + DAT_021d119c) = uVar5 + 1;
    if ((0x1e < uVar5) && (iVar2 = FUN_021d010c(), iVar2 == 1)) {
      FUN_021cfa68();
      *(undefined1 *)(*DAT_021d118c + DAT_021d1190) = 0x22;
      return;
    }
  }
  return;
}

