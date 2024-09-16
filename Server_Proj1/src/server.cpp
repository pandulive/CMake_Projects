#include<iostream>

#ifdef _WIN32
  #define _WIN32_WINNT 0X0A00
  #endif

#define ASIO_STANDALONE
#include<asio.hpp>
#include<asio/ts/buffer.hpp>
#include<asio/ts/internet.hpp>

int main(){
  
  asio::error_code ec;

  asio::io_context context;

  asio::ip::tcp::endpoint endpoint(asio::ip::make_address("103.160.106.28", ec), 80);

  asio::ip::tcp::socket socket(context);

  socket.connect(endpoint, ec);

  if(!ec)
  {
    std::cout<< "connected!" << std::endl;
  }
  else{
    std::cout<< "Failed to connect tot the address : \n" << ec.message() << std::endl;
  }
  // system("pause");

  if (socket.is_open()){ 
    std::string sRequest = 
      "GET /index.html HTTP/1.1\r\n"
      "HOST: embiottechnologies.com\r\n"
      "connection: close\r\n\r\n";

    socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

    size_t bytes = socket.available();
    std::cout << "Bytes available: " << bytes << std::endl; // (vBuffer.data(), vBuffer.size()), ec);

    if (bytes >0)
    {
      std::vector<char> vBuffer(bytes);
      socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);
    
    for (auto c : vBuffer)
        std::cout << c;
    }

  }

  return 0;

}
