#ifndef __MQTT_H__
#define __MQTT_H__

// ��¼
void MQTT_Login(char *client_id, char *username, char *password);

// ������
void MQTT_Heart();

// ������Ϣ
void MQTT_Pub(char *topic, char *msg);

// ��������
void MQTT_Sub(char *topic);

#endif