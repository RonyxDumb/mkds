/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_RemoveMutexLinkFromQueue FUN_037f9584
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>

#pragma thumb off
    OSMutex * OSi_RemoveMutexLinkFromQueue (OSMutexQueue * queue)
    {
        OSMutex * t = queue->head;

        if (t) {
            OSMutex * next = t->link.next;

            queue->head = next;

            if (next) {
                next->link.prev = NULL;
            } else {
                queue->tail = NULL;
            }
        }

        return t;
    }
