#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <pjmedia.h>
#include <pjlib.h>

#include <pjmedia/sdp.h>
#include <pjmedia/sdp_neg.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    pj_pool_t *pool;
    pjmedia_sdp_session *sdp;
    pj_status_t status;
    char *buf;

    // Initialize the pool
    pool = pj_pool_create_on_buf("fuzz_pool", NULL, PJ_POOL_SIZE);

    // Ensure the buffer is properly NULL-terminated
    buf = (char *)pj_pool_alloc(pool, Size + 1);
    memcpy(buf, Data, Size);
    buf[Size] = '\0';

    // Call the target function
    status = pjmedia_sdp_parse(pool, buf, Size, &sdp);

    // Clean up the pool
    pj_pool_release(pool);

    // Return 0 to indicate success
    return 0;
}