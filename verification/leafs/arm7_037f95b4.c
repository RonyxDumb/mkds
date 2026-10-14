/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_RemoveLinkFromQueue FUN_037f95b4
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>

#pragma thumb off
OSThread * OSi_RemoveLinkFromQueue (OSThreadQueue * queue)
    {
        OSThread * t = queue->head;

        if (t) {
            OSThread * next = t->link.next;

            queue->head = next;

            if (next) {
                next->link.prev = NULL;
            } else {
                queue->tail = NULL;
                t->queue = NULL;
            }
        }

        return t;
    }
