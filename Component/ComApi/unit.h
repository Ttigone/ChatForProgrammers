#ifndef UNIT_H
#define UNIT_H

typedef enum {
    Text,                           // 文本消息
    Picture,                        // 图片消息
    File                            // 文件消息
} MsgType;

typedef enum {
    Server,                         // 服务器
    Client,                         // 客户端
    System                          // 系统
} MsgSender;

typedef enum {
    Self,                           // 自己
    FileTransferAssistant,          // 文件传输助手
    AloneChat,                      // 独聊
    GroupChat                       // 群聊
} UserType;
#endif // UNIT_H
