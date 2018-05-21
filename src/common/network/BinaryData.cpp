#include "BinaryData.h"

BinaryData::BinaryData():data() {
}

BinaryData::BinaryData(std::vector<uint8> data_):data(data_) {
}

BinaryData::~BinaryData() {
}