FROM gcc:latest

COPY . /usr/src/mqtt_test

WORKDIR /usr/src/mqtt_test

RUN apt-get update && apt-get install -y  libmosquitto-dev

RUN  gcc mqtt_pub.c -o mqtt_pub -lmosquitto

CMD ["./mqtt_pub"]
