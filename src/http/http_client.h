#include "../tcp/tcp_client.h"

typedef void (*http_client_callback)(const char* _data, size_t _length, void* _context);

typedef enum
{
  Continue              = 100,
  OK                    = 200,
  Bad_Request           = 400,
  Not_Found             = 404,
  Internal_Server_Error = 500

} HTTP_Status_Code;

typedef struct
{
  char* method;
  char* host;
  char* port;
  char* body;

} HTTP_Request;

typedef struct
{
  HTTP_Request*         request;
  TCP_Client            tcp_client;
  HTTP_Status_Code      status_code;

  http_client_callback  on_response;

} HTTP_Client;

/** Initialize HTTP_Client (not for dynamic use) */
int http_client_init(HTTP_Client* _Client);

/** Client struct will be dynamically allocated
 * Needs to be disposed using heap function */
int http_client_init_heap(HTTP_Client** _Client_Ptr);

/** Make GET request */
int http_client_get(HTTP_Client* _Client, HTTP_Request* _Request);

/** Make POST request to passed */
int http_client_post(HTTP_Client* _Client, HTTP_Request* _Request);

/** Dispose of the client struct and it's members */
void http_client_dispose_heap(HTTP_Client** _Client_Ptr_Ptr);

/** Dispose of the client struct and it's members */
void http_client_dispose(HTTP_Client* _Client);
