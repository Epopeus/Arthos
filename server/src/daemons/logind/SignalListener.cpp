#include "SignalListener.h"
#include <boost/asio.hpp>

SignalListener::SignalListener(boost::asio::io_service &ioService) : m_ioService(ioService) {}

SignalListener::~SignalListener() {
}

void SignalListener::startListeningForSignals(std::vector<int> signals, std::function<void()> callback) {
    boost::asio::signal_set signalSet(m_ioService);

    for (int signal : signals)
        signalSet.add(signal);

    signalSet.async_wait([&callback] (const boost::system::error_code&, int) {
        callback();
    });
}


