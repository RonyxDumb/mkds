/* Decompiled C draft; module arm9_ov000; ROM address 021adfc8. No matching claim. */
#include "types.h"
#include "deps/021adfc8_FUN_021adfc8.h"

undefined4 FUN_021adfc8(int *param_1,int param_2)

{
  if ((*(int *)(param_2 + 0x44) == 0) && (*(char *)(param_2 + 8) == '\x04')) {
    while ((*(int *)(param_2 + 0x44) == 0 && (*(char *)(param_2 + 8) == '\x04'))) {
      *(undefined4 *)(param_2 + 4) = 2;
      func_0x0200e01c(0);
    }
  }
  else {
    func_0x0200dd94();
  }
  *param_1 = *(int *)(param_2 + 0x44);
  if (*param_1 == 0) {
    return 0;
  }
  return *(undefined4 *)(param_2 + 0x40);
}

