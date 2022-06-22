#ifndef __MQTT_H__
#define __MQTT_H__

// 登录
void MQTT_Login(char *client_id, char *username, char *password);

// 心跳包
void MQTT_Heart();

// 发布消息
void MQTT_Pub(char *topic, char *msg);

// 订阅主题
void MQTT_Sub(char *topic);

#endif