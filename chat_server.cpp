#include "chat_server.h"

using boost::asio::ip::tcp;

ChatServer::ChatServer(boost::asio::io_context& ioContext, const tcp::endpoint& endpoint)
    : acceptor_(ioContext, endpoint),
      socket_(ioContext) {
    startAccept();
}

void ChatServer::startAccept() {
    // Реализация метода startAccept
}
