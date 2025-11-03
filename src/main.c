#include <stdio.h>
#include "../include/http.h"

void simple_print_callback(HTTP_Response* ) {
    printf("\nCallback Received %zu bytes:\n%.*s\n", _len, (int)_len, _data);
}

int main(void)
{
  int result;

  HTTP_Request* Request;
  
  result = http_client_init_heap(&_Client);
  if (result != 0)
    return result;

  result = http_client_get(response, simple_print_callback);




  printf("");

  


  return 0;
}
