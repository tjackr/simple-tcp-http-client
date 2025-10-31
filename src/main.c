#include <stdio.h>
#include "http/http_client.h"

void simple_print_callback(const char* _data, size_t _len, void* _context) {
    (void)_context;
    printf("\nCallback Received %zu bytes:\n%.*s\n", _len, (int)_len, _data);
}

int main(void)
{
  int result;

  HTTP_Client* Client;
  result = http_client_init(&Client, simple_print_callback);

  if (result != 0)
  {
    http_client_dispose(&Client);
    printf("HTTP Client failed to initialize.\n");
    return result;
  }

  HTTP_Request* Request;

  printf("

  


  return 0;
}
