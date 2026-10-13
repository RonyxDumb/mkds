/* Decompiled C draft; module arm9_ov003; ROM address 021be1fc. No matching claim. */
#include "types.h"
#include "deps/021be1fc_FUN_021be1fc.h"

void FUN_021be1fc(void)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = true;
  if (*DAT_021be25c != 0) {
    iVar2 = FUN_021be820();
    if (iVar2 != 0) {
      do {
        func_0x0200dc3c(10);
        iVar2 = FUN_021be528();
        while (iVar2 != 0) {
          if ((iVar2 != 4) && (iVar2 != 5)) {
            if (iVar2 == 0xe) {
              bVar1 = false;
            }
            else {
              bVar1 = false;
            }
          }
          iVar2 = FUN_021be528();
        }
      } while (bVar1);
    }
    *DAT_021be25c = 0;
  }
  if (*DAT_021be260 != 0) {
    *DAT_021be260 = 0;
    func_0x021a8c8c();
  }
  return;
}

