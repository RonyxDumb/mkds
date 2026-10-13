/* Decompiled C draft; module arm9_ov003; ROM address 021cab4c. No matching claim. */
#include "types.h"
#include "deps/021cab4c_FUN_021cab4c.h"

void FUN_021cab4c(int param_1)

{
  char *pcVar1;
  bool bVar2;
  
  pcVar1 = DAT_021caca0;
  bVar2 = true;
  switch(*DAT_021caca0) {
  case '\0':
    *(undefined1 *)(*DAT_021caca4 + 0x1c) = 0;
    if (param_1 == 0) {
      *pcVar1 = '\x02';
    }
    else if (param_1 == 2) {
      *pcVar1 = '\x01';
    }
    else if (param_1 == 1) {
      *pcVar1 = '\x03';
    }
    else {
      *pcVar1 = '\x04';
    }
    break;
  case '\x01':
    *(undefined1 *)(*DAT_021caca4 + 0x1c) = 1;
    if (param_1 == 0) {
      *pcVar1 = '\0';
    }
    else if (param_1 == 2) {
      *pcVar1 = '\x02';
    }
    else if (param_1 == 1) {
      *pcVar1 = '\x03';
    }
    else {
      *pcVar1 = '\x05';
    }
    break;
  case '\x02':
    *(undefined1 *)(*DAT_021caca4 + 0x1c) = 2;
    if (param_1 == 0) {
      *pcVar1 = '\x01';
    }
    else if (param_1 == 2) {
      *pcVar1 = '\0';
    }
    else if (param_1 == 1) {
      *pcVar1 = '\x03';
    }
    else {
      *pcVar1 = '\x06';
    }
    break;
  case '\x03':
    if (param_1 == 1) {
      *DAT_021caca0 = *(char *)(*DAT_021caca4 + 0x1c) + '\x04';
    }
    else if (param_1 == 3) {
      *DAT_021caca0 = *(char *)(*DAT_021caca4 + 0x1c);
    }
    else {
      bVar2 = false;
    }
    break;
  case '\x04':
    *(undefined1 *)(*DAT_021caca4 + 0x1c) = 0;
    if (param_1 == 0) {
      *pcVar1 = '\x06';
    }
    else if (param_1 == 2) {
      *pcVar1 = '\x05';
    }
    else if (param_1 == 1) {
      *pcVar1 = '\0';
    }
    else {
      *pcVar1 = '\x03';
    }
    break;
  case '\x05':
    *(undefined1 *)(*DAT_021caca4 + 0x1c) = 1;
    if (param_1 == 0) {
      *pcVar1 = '\x04';
    }
    else if (param_1 == 2) {
      *pcVar1 = '\x06';
    }
    else if (param_1 == 1) {
      *pcVar1 = '\x01';
    }
    else {
      *pcVar1 = '\x03';
    }
    break;
  case '\x06':
    *(undefined1 *)(*DAT_021caca4 + 0x1c) = 2;
    if (param_1 == 0) {
      *pcVar1 = '\x05';
    }
    else if (param_1 == 2) {
      *pcVar1 = '\x04';
    }
    else if (param_1 == 1) {
      *pcVar1 = '\x02';
    }
    else {
      *pcVar1 = '\x03';
    }
  }
  if (bVar2) {
    FUN_021cdc10(8);
    FUN_021caca8();
  }
  return;
}

