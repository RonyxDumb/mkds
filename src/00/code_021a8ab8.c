#include "00/code_021a8ab8.h"
#include "00/types_021a8ab8.h"

Unk021a8ab8 **func_ov000_021a8ab8(Unk021a8ab8 **head, Unk021a8ab8 *node) {
    Unk021a8ab8 *entry = *head;
    while (entry != 0) {
        if (entry == node) {
            return head;
        }
        head = &entry->mUnk_7c;
        entry = entry->mUnk_7c;
    }
    return 0;
}
