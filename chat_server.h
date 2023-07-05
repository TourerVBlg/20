#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H

#include <boost/asio.hpp>
#include "chat_peer.h"

class ChatServer {
public:
    ChatServer(boost::asio::io_context& ioContext, const tcp::endpoint& endpoint);

private:
    void startAccept();

    tcp::acceptor acceptor_;
    tcp::socket socket_;
    std::vector<std::shared_ptr<ChatPeer>> connectedPeers_;
};

#endif // CHAT_SERVER_H
