
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::udp;

int main() {
  char v[120];

  boost::asio::io_service my_io_service; // Conecta com o SO

  udp::endpoint local_endpoint(udp::v4(), 9001); // endpoint: contem
                                                // conf. da conexao (ip/port)

  udp::socket my_socket(my_io_service, // io service
                        local_endpoint); // endpoint

  udp::endpoint remote_endpoint; // vai conter informacoes de quem conectar

  std::cout << "Esperando mensagem!" << std::endl;

  my_socket.receive_from(boost::asio::buffer(v,120), // Local do buffer
                      remote_endpoint); // Confs. do Cliente

  std::cout << v << std::endl;
  std::cout << "Fim de mensagem!" << std::endl;


  // Respondendo a mensagem
  std::string msg("Recebido! Obrigado, cambio e desligo!");
  my_socket.send_to(boost::asio::buffer(msg), remote_endpoint);

  std::cout << "Mensagem de retorno enviada" << std::endl;


  return 0;
}
