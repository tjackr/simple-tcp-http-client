#include <stdio.h>
#include "http/http_client.h"

void simple_print_callback(const char* _data, size_t _len, void* _context) {
    (void)_context;
    printf("\nCallback Received %zu bytes:\n%.*s\n", _len, (int)_len, _data);
}

int main(void)
{


  printf("gabagool\n");
  return 0;
}
