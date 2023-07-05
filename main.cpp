#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include "chat_server.h"

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context ioContext;
        tcp::endpoint endpoint(tcp::v4(), 12345);  // Порт для прослушивания

        ChatServer chatServer(ioContext, endpoint);

        // Запускаем сервер в отдельном потоке
        std::thread thread([&ioContext]() { ioContext.run(); });
        thread.join();
    } catch (const std::exception& ex) {
        std::cerr << "Исключение при запуске сервера: " << ex.what() << std::endl;
    }

    return 0;
}
