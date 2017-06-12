#ifndef MESSAGEQUEUECLIENT_H
#define MESSAGEQUEUECLIENT_H

#include "MessageQueue.h"

namespace mq
{

class MessageQueueClient : private MessageQueue, public IMessageQueueSender
{
public:
    explicit MessageQueueClient(const std::string& queueName);
    MessageQueueClient(const MessageQueueClient&) = delete;
    MessageQueueClient(MessageQueueClient&&) noexcept = delete;
    MessageQueueClient& operator=(const MessageQueueClient&) = delete;
    MessageQueueClient& operator=(MessageQueueClient&&) noexcept = delete;
    ~MessageQueueClient() noexcept override;

    void Send(const std::vector<std::uint8_t>& buffer) const noexcept(false) override;
};

}

#endif //MESSAGEQUEUECLIENT_H
