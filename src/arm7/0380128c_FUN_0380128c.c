/* Decompiled C draft; module arm7; ROM address 0380128c. No matching claim. */
#include "types.h"
#include "deps/0380128c_FUN_0380128c.h"

void FUN_0380128c(void)

{
  undefined4 uVar1;
  uint local_18 [2];
  
  uVar1 = DAT_038012f4;
  do {
    FUN_037f97b4(uVar1,local_18,1);
    switch(*(uint *)(local_18[0] & 0xfffffffc) >> (local_18[0] & 3) * 8 |
           *(uint *)(local_18[0] & 0xfffffffc) << (local_18[0] & 3) * -8 + 0x20) {
    case 0:
      FUN_038017ec();
      break;
    case 1:
      FUN_0380405c();
      break;
    case 2:
      FUN_03802f5c();
      break;
    case 3:
      FUN_03802388();
    }
  } while( true );
}

