#pragma once

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>

class BoostTcpConnection : public boost::enable_shared_from_this<BoostTcpConnection>{
public:
    typedef boost::shared_ptr<BoostTcpConnection> pointer;

    static pointer create(boost::asio::io_service& io_service)
    {
        return pointer(new BoostTcpConnection(io_service));
    }

    boost::asio::ip::tcp::socket& socket()
    {
        return socket_;
    }

    void start()
    {
        message_ = "Test";

        boost::asio::async_write(socket_, boost::asio::buffer(message_),
                                 boost::bind(&BoostTcpConnection::handle_write, shared_from_this(),
                                             boost::asio::placeholders::error,
                                             boost::asio::placeholders::bytes_transferred));
    }

private:
    BoostTcpConnection(boost::asio::io_service& io_service)
    : socket_(io_service)
            {
            }

    void handle_write(const boost::system::error_code& /*error*/,
                      size_t /*bytes_transferred*/)
    {
    }

    boost::asio::ip::tcp::socket socket_;
    std::string message_;
};

