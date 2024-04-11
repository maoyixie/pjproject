#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <pjlib.h>
#include <pjlib-util.h>

#include <pjnath.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    pj_pool_t *pool;
    pj_stun_msg *msg;
    pj_stun_msg *response;
    pj_size_t parsed_len;
    pj_status_t status;

    // Initialize the pool factory
    pj_caching_pool cp;
    pj_caching_pool_init(&cp, NULL, 0);

    // Create a pool
    pool = pj_pool_create(&cp.factory, "stun_msg_fuzz", 512, 512, NULL);
    if (!pool)
    {
        pj_caching_pool_destroy(&cp);
        return 0;
    }

    // Fuzz the pj_stun_msg_decode function
    status = pj_stun_msg_decode(pool, (const pj_uint8_t *)Data, Size, 0, &msg, &parsed_len, &response);

    // Cleanup
    pj_pool_release(pool);
    pj_caching_pool_destroy(&cp);

    return 0;
}