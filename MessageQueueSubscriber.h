#ifndef MESSAGEQUEUESUBSCRIBER_H
#define MESSAGEQUEUESUBSCRIBER_H

#include "MessageQueue.h"

namespace mq
{

class MessageQueueSubscriber : private MessageQueue, public IMessageQueueReceiver
{
public:
    explicit MessageQueueSubscriber(const std::string& queueName);
    MessageQueueSubscriber(const MessageQueueSubscriber&) = delete;
    MessageQueueSubscriber(MessageQueueSubscriber&&) noexcept = delete;
    MessageQueueSubscriber& operator=(const MessageQueueSubscriber&) = delete;
    MessageQueueSubscriber& operator=(MessageQueueSubscriber&&) noexcept = delete;
    ~MessageQueueSubscriber() noexcept override = default;

    void Receive(std::vector<std::uint8_t>& buffer, std::size_t length) const noexcept(false) override;
};

}

#endif //MESSAGEQUEUESUBSCRIBER_H
