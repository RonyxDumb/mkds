/* Decompiled C draft; module arm9_ov000; ROM address 021a6bdc. No matching claim. */
#include "types.h"
#include "deps/021a6bdc_FUN_021a6bdc.h"

void FUN_021a6bdc(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_021a6c00;
  if (*DAT_021a6c00 == '\0') {
    *DAT_021a6c00 = '\x01';
    pcVar1[0x24] = '\0';
    pcVar1[0x25] = '\0';
    pcVar1[0x26] = '\0';
    pcVar1[0x27] = '\0';
    pcVar1[8] = '\0';
    pcVar1[9] = '\0';
    pcVar1[10] = '\0';
    pcVar1[0xb] = '\0';
    pcVar1[4] = '\0';
    pcVar1[5] = '\0';
    pcVar1[6] = '\0';
    pcVar1[7] = '\0';
    func_0x0200edc0(DAT_021a6c04);
  }
  return;
}

