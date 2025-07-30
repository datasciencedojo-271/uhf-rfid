FROM ubuntu:20.04
RUN apt-get update && apt-get install -y gcc-arm-none-eabi make
WORKDIR /app
COPY . .
CMD ["make"]