#include "chat_peer.h"

using boost::asio::ip::tcp;

ChatPeer::ChatPeer(boost::asio::io_context& ioContext, tcp::socket socket)
    : socket_(std::move(socket)) {}

void ChatPeer::startWithSocket(std::unordered_map<std::string, std::string>& users,
                               std::vector<std::shared_ptr<ChatPeer>>& connectedPeers) {
    // Реализация метода startWithSocket
}

void ChatPeer::sendMessage(const std::string& message) {
    // Реализация метода sendMessage
}

void ChatPeer::sendPrompt(const std::string& prompt) {
    // Реализация метода sendPrompt
}

void ChatPeer::closeConnection() {
    socket_.close();
}
