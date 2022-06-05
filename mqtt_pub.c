#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <mosquitto.h>

float genRandPos(int min, int max) {
  
  float randVar = rand(); //used to achieve better random computation
  float randPos = min + (rand() / (float) RAND_MAX) * (max - min);
  
  return randPos;
}

int main() {

  srand((unsigned)time(NULL));

  float lat = genRandPos(-90, 90);
  float lon = genRandPos(-180, 180);

  char latChars[10];
  char lonChars[10];

  sprintf(latChars, "%.4f", lat);
  sprintf(lonChars, "%.4f", lon);

  printf("%s\n", latChars); //debug message

  int rc;
  struct mosquitto *mosq;

  mosquitto_lib_init();

  mosq = mosquitto_new("publisher-test", true, NULL);

  rc = mosquitto_connect(mosq, "localhost", 1883, 60);

  if(rc != 0) {
    printf("Client could not connect to broker. Error Code: %d\n", rc);
    mosquitto_destroy(mosq);
    return -1;
  }

  printf("Client connection to broker successful.\n");

  mosquitto_publish(mosq, NULL, "test/t1", 10, latChars, 0, false);
  mosquitto_publish(mosq, NULL, "test/t1", 10, lonChars, 0, false);

  mosquitto_disconnect(mosq);
  mosquitto_destroy(mosq);

  mosquitto_lib_cleanup();

  //mosquitto_loop_forever(mosq, 1000, 1);
  
  return 0;
}
