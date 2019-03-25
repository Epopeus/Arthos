#include "SignalListener.h"

SignalListener::SignalListener(boost::asio::io_context& ioContext_) : ioContext(ioContext_) {}

SignalListener::~SignalListener() {
}

void SignalListener::startListeningForSignals(std::vector<int> signals, std::function<void()> callback) {
    boost::asio::signal_set signalSet(ioContext);

    for (int signal : signals)
        signalSet.add(signal);

    signalSet.async_wait([&callback] (const boost::system::error_code&, int) {
        callback();
    });
}


