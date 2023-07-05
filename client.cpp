#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context ioContext;

        // Устанавливаем соединение с сервером
        tcp::socket socket(ioContext);
        tcp::resolver resolver(ioContext);
        boost::asio::connect(socket, resolver.resolve("localhost", "12345"));

        while (true) {
            // Читаем пользовательский ввод
            std::string message;
            std::cout << "> ";
            std::getline(std::cin, message);

            if (message == "exit") {
                break;  // Если пользователь ввел "exit", выходим из цикла
            }

            // Отправляем сообщение на сервер
            boost::asio::write(socket, boost::asio::buffer(message + '\n'));

            // Читаем ответ от сервера
            std::string response;
            boost::asio::read_until(socket, boost::asio::dynamic_buffer(response), '\n');

            // Выводим ответ на экран
            std::cout << response;
        }

        // Закрываем соединение
        socket.close();
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
