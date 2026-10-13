/* Decompiled C draft; module arm9_ov000; ROM address 021a8740. No matching claim. */
#include "types.h"
#include "deps/021a8740_FUN_021a8740.h"

undefined4 FUN_021a8740(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021a87b0;
  do {
    func_0x0200fca0();
    iVar2 = *piVar1;
    if (iVar2 != 0) {
      do {
        if ((iVar2 != *DAT_021a87b4) && ((*(ushort *)(iVar2 + 0x70) & 0x10) == 0)) break;
        iVar2 = *(int *)(iVar2 + 0x7c);
      } while (iVar2 != 0);
    }
    func_0x0200fcb4();
    if (iVar2 == 0) {
      iVar2 = *DAT_021a87b0;
      if (((iVar2 == 0) || ((iVar2 == *DAT_021a87b4 && (*(int *)(iVar2 + 0x7c) == 0)))) &&
         (*DAT_021a87b8 == 0)) {
        return 0;
      }
      return 0xffffffe6;
    }
    FUN_021a8604(iVar2);
  } while( true );
}

