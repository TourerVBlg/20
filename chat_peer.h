#ifndef CHAT_PEER_H
#define CHAT_PEER_H

#include <boost/asio.hpp>

class ChatPeer {
public:
    ChatPeer(boost::asio::io_context& ioContext, tcp::socket socket);

    void startWithSocket(std::unordered_map<std::string, std::string>& users,
                         std::vector<std::shared_ptr<ChatPeer>>& connectedPeers);
    void sendMessage(const std::string& message);
    void sendPrompt(const std::string& prompt);
    void closeConnection();

private:
    tcp::socket socket_;
    std::string readBuffer_;
    std::string currentUser_;
};

#endif // CHAT_PEER_H
