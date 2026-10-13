/* Decompiled C draft; module arm9_ov000; ROM address 0219c0f4. No matching claim. */
#include "types.h"
#include "deps/0219c0f4_FUN_0219c0f4.h"

void FUN_0219c0f4(void)

{
  int *piVar1;
  
  if (*DAT_0219c1d4 != 0) {
    if (*(int *)(*DAT_0219c1d4 + DAT_0219c1d8) != 0) {
      FUN_021a47ac();
      *(undefined4 *)(*DAT_0219c1d4 + DAT_0219c1d8) = 0;
    }
    piVar1 = DAT_0219c1d4;
    *(undefined1 *)(*DAT_0219c1d4 + DAT_0219c1dc) = 0;
    if (*(int *)(*piVar1 + DAT_0219c1e0) != 0) {
      FUN_0218b64c();
      *(undefined4 *)(*DAT_0219c1d4 + DAT_0219c1e0) = 0;
    }
    FUN_0219b110();
    FUN_02197634();
    if (*(int *)(*DAT_0219c1d4 + 0x1c) != 0) {
      FUN_0218f21c(*DAT_0219c1d4 + 0x1c,0,0,0);
      FUN_0218f21c(*DAT_0219c1d4 + 0x1c,3,0,0);
      FUN_0218f21c(*DAT_0219c1d4 + 0x1c,1,0,0);
      FUN_0218f21c(*DAT_0219c1d4 + 0x1c,2,0,0);
      FUN_0218f268(*DAT_0219c1d4 + 0x1c);
      FUN_0218f2a0(*DAT_0219c1d4 + 0x1c);
      *(undefined4 *)(*DAT_0219c1d4 + 0x1c) = 0;
    }
    FUN_0219c954();
    FUN_0219d4f8();
    FUN_021a1430();
    FUN_021a2fec();
    if (*(int *)*DAT_0219c1d4 != 0) {
      FUN_02198ab0();
      *(undefined4 *)*DAT_0219c1d4 = 0;
    }
    *DAT_0219c1d4 = 0;
  }
  return;
}

