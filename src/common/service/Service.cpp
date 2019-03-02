#include "Service.h"

Service::Service(Repository& settingsRepository_, TcpServer& tcpServer_, TcpClient& tcpClient_, SignalListener& signalListener_):settingsRepository(settingsRepository_), tcpServer(tcpServer_), tcpClient(tcpClient_), signalListener(signalListener_) {

}