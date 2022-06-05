
import paho.mqtt.client as mqtt

def on_message(client, userdata, msg):
    print(msg.topic + ": " + msg.payload.decode())

def on_connect(mqttc, obj, flags, rc):
    print("rc: " + str(rc))

def on_subscribe(mqttc, obj, mid, granted_qos):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))

mqttc = mqtt.Client()
mqttc.on_message = on_message
mqttc.on_connect = on_connect
mqttc.on_subscribe = on_subscribe

mqttc.connect("localhost", 1883, 60)
mqttc.subscribe("Latitude")
mqttc.subscribe("Longitude")

mqttc.loop_forever()
