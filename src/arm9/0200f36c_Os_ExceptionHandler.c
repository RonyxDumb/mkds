/* Decompiled C draft; module arm9; ROM address 0200f36c. No matching claim. */
#include "types.h"
#include "deps/0200f36c_Os_ExceptionHandler.h"

/* WARNING: Removing unreachable block (ram,0x0200f3b0) */
/* WARNING: Removing unreachable block (ram,0x0200f3a0) */

void Os_ExceptionHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 in_lr;
  
  UNRECOVERED_JUMPTABLE =
       (code *)(*(uint *)(uRam0200f3d8 & 0xfffffffc) >> (uRam0200f3d8 & 3) * 8 |
               *(uint *)(uRam0200f3d8 & 0xfffffffc) << (uRam0200f3d8 & 3) * -8 + 0x20);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    *(undefined4 *)(iRam0200f3dc + -4) = in_lr;
    *(BADSPACEBASE **)(iRam0200f3dc + -8) = register0x00000054;
    *(undefined4 *)(iRam0200f3dc + -0xc) = param_4;
    *(undefined4 *)(iRam0200f3dc + -0x10) = param_3;
    *(undefined4 *)(iRam0200f3dc + -0x14) = param_2;
    *(undefined4 *)(iRam0200f3dc + -0x18) = param_1;
    do {
    } while (*(uint *)(uRam0200f3d8 & 0xfffffffc) >> (uRam0200f3d8 & 3) * 8 == 0 &&
             *(uint *)(uRam0200f3d8 & 0xfffffffc) << (uRam0200f3d8 & 3) * -8 + 0x20 == 0);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
                    /* WARNING: Could not recover jumptable at 0x0200f37c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

