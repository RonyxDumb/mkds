/* Decompiled C draft; module arm9_ov003; ROM address 021d15f4. No matching claim. */
#include "types.h"
#include "deps/021d15f4_FUN_021d15f4.h"

void FUN_021d15f4(void)

{
  int *piVar1;
  
  func_0x020047ec(DAT_021d164c);
  func_0x02003d8c(*DAT_021d1650 + 0x88);
  func_0x02003f50(*DAT_021d1650 + 0x88);
  func_0x02004090((undefined4 *)(uintptr_t)(*DAT_021d1650 + 0x88));
  func_0x0200cd80(*(undefined2 *)(*DAT_021d1650 + 0xe4));
  piVar1 = DAT_021d1650;
  *(undefined2 *)(*DAT_021d1650 + 0xe4) = 0;
  FUN_021d2808((int *)(uintptr_t)(*piVar1));
  *(undefined4 *)*DAT_021d1650 = 0;
  FUN_021d2808();
  return;
}

