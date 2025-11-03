#include "../../include/http.h"

#include <stdlib.h>

/* =============== Internal functions =============== */


/* ================================================== */

int http_client_init(HTTP_Client* _Client, http_client_callback _callback)
{
  if (_Client == NULL)
    return -1;

  int fd = -1;
  HTTP_Response Response = {0};
  TCP_Client TCP;

  if (tcp_client_initiate(&TCP, fd) != 0)
    return -2;

  _Client->response = Response;
  _Client->status_code = Continue;

  return 0;
}

int http_client_init_heap(HTTP_Client** _Client_Ptr)
{
  *_Client_Ptr = malloc(sizeof(HTTP_Client*));

  if (*_Client_Ptr == NULL)
    return -1;

  if (http_client_init(*_Client_Ptr) != 0)
    return -2;

  return 0;
}

int http_client_get(HTTP_Client* _Client, HTTP_Request _Request)
{
  int result;

  HTTP_Response

  _Client->response

  TCP_Client* TCP;
  int fd;

  result = 

  if (result != 0)
  {
    tcp_client_dispose(TCP);
    return result;
  }

  


  return 0;
}

int http_client_post(HTTP_Client* _Client, HTTP_Request* _Request)
{

  return 0;
}

void http_client_dispose_heap(HTTP_Client** _Client_Ptr)
{
  http_client_dispose(*_Client_Ptr);

  free(*_Client_Ptr);
}
void http_client_dispose(HTTP_Client* _Client)
{

}
