/* Decompiled C draft; module arm9_ov003; ROM address 021c7eec. No matching claim. */
#include "types.h"
#include "deps/021c7eec_FUN_021c7eec.h"

/* WARNING: Removing unreachable block (ram,0x021c7f1c) */

void FUN_021c7eec(int param_1)

{
  char cVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = FUN_021cdb6c();
  piVar3 = DAT_021c80f0;
  bVar2 = false;
  cVar1 = *DAT_021c80e8;
  if ((cVar1 == '\b') && (*(char *)(iVar4 + 0xf5) == '\0')) {
    if (param_1 == 0) {
      return;
    }
    if (param_1 == 2) {
      return;
    }
  }
  if (cVar1 == '\0') {
    if (param_1 == 1) {
      *DAT_021c80e8 = '\v';
    }
    else if (param_1 == 3) {
      *DAT_021c80ec = *DAT_021c80ec + 1;
    }
    else {
      bVar2 = true;
    }
  }
  else {
    switch(cVar1) {
    case '\n':
      if (param_1 == 1) {
        *DAT_021c80ec = *DAT_021c80ec - 1;
      }
      else if (param_1 == 3) {
        *DAT_021c80e8 = *(char *)(*DAT_021c80f0 + 0x42);
      }
      else {
        bVar2 = true;
      }
      break;
    case '\v':
      if (param_1 == 1) {
        if (*(char *)(*DAT_021c80f0 + 0x47) != '\0') {
          return;
        }
        FUN_021cdc10(9);
        *(undefined1 *)(*DAT_021c80f0 + 0x47) = 1;
        return;
      }
      if (param_1 == 3) {
        *DAT_021c80e8 = '\0';
        *DAT_021c80ec = 0;
        *DAT_021c80f4 = 0;
        FUN_021c8b94();
        thunk_FUN_021cca74(0);
      }
      else {
        bVar2 = true;
      }
      break;
    case '\f':
    case '\r':
      *(char *)(*DAT_021c80f0 + 0x42) = cVar1;
      if (param_1 == 1) {
        *DAT_021c80e8 = '\n';
        *DAT_021c80ec = 3;
        *DAT_021c80f4 = 0x91;
        FUN_021c8b94();
        thunk_FUN_021cca74(0x37);
      }
      else {
        if (param_1 == 3) {
          if (*(char *)(*piVar3 + 0x47) != '\0') {
            return;
          }
          FUN_021cdc10(9);
          *(undefined1 *)(*DAT_021c80f0 + 0x47) = 1;
          return;
        }
        if (cVar1 == '\f') {
          *DAT_021c80e8 = '\r';
        }
        else {
          *DAT_021c80e8 = '\f';
        }
      }
      break;
    default:
      if (param_1 == 1) {
        if (*DAT_021c80ec == 0) {
          FUN_021cdc10(0x13);
          uVar5 = FUN_021d3544(0,DAT_021c80f8,0,0x78);
          *(undefined4 *)(*DAT_021c80f0 + 0x38) = uVar5;
          return;
        }
        *DAT_021c80ec = *DAT_021c80ec - 1;
      }
      else if (param_1 == 3) {
        if (2 < *DAT_021c80ec) {
          FUN_021cdc10(0x13);
          uVar5 = FUN_021d3544(0,DAT_021c80fc,0,0x78);
          *(undefined4 *)(*DAT_021c80f0 + 0x38) = uVar5;
          return;
        }
        *DAT_021c80ec = *DAT_021c80ec + 1;
      }
      else {
        bVar2 = true;
        if (cVar1 == '\x02') {
          *DAT_021c80e8 = '\x03';
        }
        else if (cVar1 == '\x03') {
          *DAT_021c80e8 = '\x02';
        }
        else if (cVar1 == '\a') {
          *DAT_021c80e8 = '\b';
        }
        else {
          if (cVar1 != '\b') break;
          *DAT_021c80e8 = '\a';
        }
        FUN_021cdc10(8);
        FUN_021c81b8();
      }
    }
  }
  if ((!bVar2) && (FUN_021cdc10(8), !bVar2)) {
    FUN_021c812c();
  }
  return;
}

