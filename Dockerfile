FROM debian:latest

ARG stage=dev
ARG version=master

#Install necessary libs
RUN apt-get update
RUN apt-get install -y python wget git cmake
RUN wget https://bootstrap.pypa.io/get-pip.py
RUN python get-pip.py
RUN pip install conan

#Checkout current source code at required version. Avoid unnecessary downloads with --depth 1.
RUN git clone --branch $version --depth 1 https://github.com/Toinouze/Arthos

#Build the server
RUN cmake -DCMAKE_BUILD_TYPE=Release Arthos/server
RUN cmake --build Arthos/server/cmake-build-release --target ArthosLogind -j4

#Expose Login daemon port
EXPOSE 3724

#Run !
ENTRYPOINT Arthos/server/cmake-build-release/bin
