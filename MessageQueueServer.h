#ifndef MESSAGEQUEUESERVER_H
#define MESSAGEQUEUESERVER_H

#include "MessageQueue.h"

namespace mq
{

class MessageQueueServer : private MessageQueue, public IMessageQueueReceiver, public IMessageQueueSender
{
public:
    MessageQueueServer(const std::string& queueName, const Attributes& attrs);
    MessageQueueServer(const MessageQueueServer&) = delete;
    MessageQueueServer(MessageQueueServer&&) noexcept = delete;
    MessageQueueServer& operator=(const MessageQueueServer&) = delete;
    MessageQueueServer& operator=(MessageQueueServer&&) noexcept = delete;
    ~MessageQueueServer() noexcept override;

    void Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const noexcept(false) override;
    void Send(const std::vector<std::uint8_t>& buffer) const noexcept(false) override;
};

}

#endif //MESSAGEQUEUESERVER_H
