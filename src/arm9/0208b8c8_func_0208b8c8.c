/* Decompiled C draft; module arm9; ROM address 0208b8c8. No matching claim. */
#include "types.h"
#include "deps/0208b8c8_func_0208b8c8.h"

void func_0208b8c8(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)(*(uint *)(uRam0208b924 & 0xfffffffc) >> (uRam0208b924 & 3) * 8 |
                   *(uint *)(uRam0208b924 & 0xfffffffc) << (uRam0208b924 & 3) * -8 + 0x20);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  func_0201873c(*(uint *)(uRam0208b928 & 0xfffffffc) >> (uRam0208b928 & 3) * 8 |
                *(uint *)(uRam0208b928 & 0xfffffffc) << (uRam0208b928 & 3) * -8 + 0x20);
  func_0201873c(*(uint *)(uRam0208b92c & 0xfffffffc) >> (uRam0208b92c & 3) * 8 |
                *(uint *)(uRam0208b92c & 0xfffffffc) << (uRam0208b92c & 3) * -8 + 0x20);
  if (*(uint *)(uRam0208b930 & 0xfffffffc) >> (uRam0208b930 & 3) * 8 != 0 ||
      *(uint *)(uRam0208b930 & 0xfffffffc) << (uRam0208b930 & 3) * -8 + 0x20 != 0) {
    func_0201873c();
    return;
  }
  return;
}

