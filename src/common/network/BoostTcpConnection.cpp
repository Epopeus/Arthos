#include "BoostTcpConnection.h"

BoostTcpConnection::BoostTcpConnection(boost::asio::ip::tcp::socket& socket_):socket(socket_) {

}

void BoostTcpConnection::send(Bytes& bytes) {

}

void BoostTcpConnection::read(VoidCallback<Bytes&> onBytesReceived) {

}
