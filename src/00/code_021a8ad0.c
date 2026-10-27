#include "00/code_021a8ad0.h"
#include "00/code_021a8ab8.h"

void func_ov000_021a8ad0(Unk021a8ab8 **head, Unk021a8ab8 *node) {
    Unk021a8ab8 **link = func_ov000_021a8ab8(head, node);
    if (link != 0) {
        *link = node->mUnk_7c;
    }
    return;
}
