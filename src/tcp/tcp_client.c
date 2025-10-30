#include "tcp_client.h"

int tcp_client_Initiate(TCP_Client* _Client, int fd)
{
	_Client->fd = fd;
	return 0;
}

int tcp_client_Connect(TCP_Client* _Client, const char *host, const char *port)
{
	if(_Client->fd >= 0)
		return -1;

    struct addrinfo hints = {0};
	  struct addrinfo* res = NULL;

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
	  hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, port, &hints, &res) != 0)
        return -1;
	
    int fd = -1;
    for (struct addrinfo *rp = res; rp; rp = rp->ai_next)
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

int tcp_client_Write(TCP_Client* _Client, const uint8_t* buf, int len)
{
  return send(_Client->fd, buf, len, MSG_NOSIGNAL);
}

int tcp_client_Read(TCP_Client* _Client, uint8_t* buf, int len)
{
  return recv(_Client->fd, buf, len, MSG_DONTWAIT); // icke-blockerande läsning
}

void tcp_client_Disconnect(TCP_Client* _Client)
{
  if (_Client->fd >= 0)
    close(_Client->fd);

  _Client->fd = -1;
}

void tcp_client_Dispose(TCP_Client* _Client)
{
	tcp_client_Disconnect(_Client);
}
