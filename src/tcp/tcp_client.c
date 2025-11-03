#include "../../include/tcp.h"

#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>

void tcp_client_disconnect(TCP_Client* _Client);

int tcp_client_init(TCP_Client* _Client, int fd)
{
	_Client->fd = fd;
	return 0;
}

int tcp_client_connect(TCP_Client* _Client, const char* _host, const char* _port)
{
	if(_Client->fd >= 0)
	  return -1;

  struct addrinfo hints = {0};
  struct addrinfo* res = NULL;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  if (getaddrinfo(_host, _port, &hints, &res) != 0)
    return -1;

  int fd = -1;
  for (struct addrinfo* rp = res; rp; rp = rp->ai_next)
  {
    fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

    if (fd < 0)
      continue;

    if (connect(fd, rp->ai_addr, rp->ai_addrlen) == 0)
      break;

    close(fd);
    fd = -1;
  }

  freeaddrinfo(res);
  if (fd < 0)
    return -1;

  _Client->fd = fd;
  return 0;
}

int tcp_client_write(TCP_Client* _Client, const uint8_t* buf, int len)
{
  return send(_Client->fd, buf, len, MSG_NOSIGNAL);
}

int tcp_client_read(TCP_Client* _Client, uint8_t* buf, int len)
{
  return recv(_Client->fd, buf, len, MSG_DONTWAIT); // icke-blockerande läsning
}

void tcp_client_disconnect(TCP_Client* _Client)
{
  if (_Client->fd >= 0)
    close(_Client->fd);

  _Client->fd = -1;
}

void tcp_client_dispose(TCP_Client* _Client)
{
	tcp_client_disconnect(_Client);
}
