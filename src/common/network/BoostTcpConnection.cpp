#include "BoostTcpConnection.h"

BoostTcpConnection::BoostTcpConnection(/*boost::asio::ip::tcp::socket& socket_*/int test_):/*socket(socket_)*/test(test_) {

}

void BoostTcpConnection::send(Bytes& bytes) {

}

void BoostTcpConnection::read(VoidCallback<Bytes&> onBytesReceived) {

}
