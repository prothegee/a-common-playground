#define _POSIX_C_SOURCE 199309L // required for clock_gettime, CLOCK_REALTIME

#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

// --------------------------------------------------------- //

#define RET_ERROR -1
#define RET_UNDEFINED 0 // or false
#define RET_FALSE 0 // or undefined
#define RET_OK 1

// --------------------------------------------------------- //

typedef struct _data_log_thread_t {
    int32_t random_number;
    uint8_t thread_id;
    const char* timestamp;
} data_log_thread_t;

// --------------------------------------------------------- //

int timestamp_nanoseconds(char* buffer, size_t len) {
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        return RET_ERROR;
    }

    struct tm tmi;
    if (gmtime_r(&ts.tv_sec, &tmi) == nullptr) {
        return RET_ERROR;
    }

    char base[32];
    if (strftime(base, sizeof(base), "%Y-%m-%d %H:%M:%S", &tmi) == 0) {
        return RET_ERROR;
    }

    int written = snprintf(buffer, len, "%s.%09ld", base, ts.tv_nsec);
    return (written < 0 || (size_t)written >= len) ? RET_ERROR : RET_OK;
}

// --------------------------------------------------------- //

/// TODO:
/// - [?] get total thread count
/// - [?] create savely log console where:
///     - `YYYY-MM-DD hh:mm:ss.ns | THREAD_ID | RANDOM_DATA`
int main() {
    printf("run parallel_task.c\n");

    return RET_OK;
}

