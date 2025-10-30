#ifndef __tcp_client_h_
#define __tcp_client_h_

/* #define _POSIX_C_SOURCE 200809L */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>

typedef void (*tcp_client_callback)(const char* _data, size_t _length, void* _context);

typedef struct
{ 
    int fd;

} TCP_Client;

/** Initiates a TCP client using predeclared struct */
int tcp_client_initiate(TCP_Client* _Client, int _fd);

/** Initiates a TCP client on the heap 
 * Needs to be disposed with tcp_client_dispose_heap */
int tcp_client_initiate_heap(TCP_Client** _Client_Ptr, int _fd);

/** Writes buffer to open TCP socket connection */
int tcp_client_write(TCP_Client* _Client, const uint8_t* buf, int len);

/** Reads buffer from open TCP socket connection */
int tcp_client_read(TCP_Client* _Client, uint8_t* buf, int len);

/** Disposes of TCP client initiated using heap function */
void tcp_client_dispose_heap(TCP_Client** _Client_Ptr);

/** Disposes of TCP client initiated using regular function */
void tcp_client_dispose(TCP_Client* _Client);

#endif 
