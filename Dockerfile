FROM debian:latest

ARG buildtype=dev
ARG version=1.0

RUN apt-get update

RUN pip install conan

#Checkout current source code at required version. Avoid unnecessary downloads with --depth 1.
RUN git clone --branch $version --depth 1 https://github.com/Toinouze/Arthos

RUN cd Arthos/server
#Build the server

cmake -DCMAKE_BUILD_TYPE=Release .
cmake --build build-$buildtype --target ArthosLogind -j4

#Expose Login daemon port
EXPOSE 3724

#Run !
ENTRYPOINT Arthos/server/cmake-build-release/bin
