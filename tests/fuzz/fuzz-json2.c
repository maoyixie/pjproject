#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <pjlib.h>
#include <pjlib-util.h>

extern int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    pj_pool_t *pool;
    pj_json_elem *elem;
    pj_json_err_info err_info;
    char *buffer;
    unsigned int buf_size;

    // Initialize the pool
    pool = pj_pool_create(NULL, "json_pool", 4096, 4096, NULL);
    if (!pool)
    {
        return 0;
    }

    // Allocate buffer and copy input data
    buffer = (char *)pj_pool_alloc(pool, Size);
    if (!buffer)
    {
        pj_pool_release(pool);
        return 0;
    }
    memcpy(buffer, Data, Size);

    // Set buffer size
    buf_size = (unsigned int)Size;

    // Call pj_json_parse with the given input
    elem = pj_json_parse(pool, buffer, &buf_size, &err_info);

    // Cleanup
    pj_pool_release(pool);

    // If we reached this point, the fuzzing was successful
    return 0;
}