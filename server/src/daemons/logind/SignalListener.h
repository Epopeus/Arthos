#pragma once
#include <vector>
#include <functional>
#include <boost/asio.hpp>

class SignalListener {
public:
    SignalListener(boost::asio::io_service &ioService);
    ~SignalListener();

    void startListeningForSignals(std::vector<int> signals, std::function<void()> callback);

private:
    boost::asio::io_service& m_ioService;

    void onSignal(boost::system::error_code &errorCode, int signalNumber);
};

