#pragma once
#ifndef S_MSGID_CACHE_H
#define S_MSGID_CACHE_H

#include <stdint.h>
#include <time.h>
#include <stdatomic.h>

extern const size_t DEFAULT_CAPACITY;
extern const time_t CLEANUP_INTERVAL;
extern const time_t ENTRY_TTL;

typedef enum
{
    CACHE_STATE_EMPTY = 0,  // запись отсутствует
    CACHE_STATE_EXISTS = 1, // запись найдена (replay!)
    CACHE_STATE_ERROR = 2   // ошибка выполнения
} cache_state_t;

struct s_msgid_cache_entry
{
    uint32_t msgid;
    time_t timestamp;
    uint32_t source_ip;
};

struct s_msgid_cache
{
    struct s_msgid_cache_entry *entries;
    size_t capacity;
    size_t count;

    _Atomic uint8_t state;           // 0, 1, 2
    _Atomic size_t total_operations; // общий счетчик операций
    _Atomic size_t add_operations;   // счетчик добавлений
    _Atomic size_t check_operations; // счетчик проверок
    _Atomic size_t replay_detected;  // счетчик обнаруженных replay

    time_t last_cleanup;
    time_t created_at;
};

int s_msgid_cache_init(void);
int s_msgid_cache_add(uint32_t msgid, uint32_t source_ip);
cache_state_t s_msgid_cache_check(uint32_t msgid, uint32_t source_ip);
void s_msgid_cache_cleanup_old(void);
void s_msgid_cache_stats(void);
void s_msgid_cache_destroy(void);

#endif